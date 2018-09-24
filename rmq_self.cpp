#include <bits/stdc++.h>

using namespace std;



int main()
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int len = 6;
	int value[len]={4,6,1,5,7,3};
	int sparse[(int)(log(len)/log(2))+1][len];

	for (int i = 0; i <= (int)(log(len)/log(2)); ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			sparse[i][j] = 0;
		}
	}


	for (int i = 0; i < len; ++i)
	{
		sparse[0][i] = i;
	}

	for (int i = 1; (int)(pow(2.0,i)) < len; ++i)//檢查長度
	{
		for (int j = 0; j+(int)(pow(2.0,i))-1 < len; ++j)//檢查往右有沒有超出範圍
		{
			int L = sparse[i-1][j];
			int R = sparse[i-1][j+(int)(pow(2.0,i-1))];
			if (value[L] <= value[R])
			{
				sparse[i][j] = L;
			}
			else
			{
				sparse[i][j] = R;
			}

		}
	}



	for (int i = 0; i <= (int)(log(len)/log(2)); ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			printf("%d ", sparse[i][j]);
		}
		printf("\n");
	}

	int Left,Right;
	while(~scanf("%d %d",&Left,&Right))
	{
		int length = Right - Left + 1;
		int lg = (int)(log(length)/log(2));
		// printf("length%d\n", length);
		// printf("lg%d\n", lg);
		printf("%d\n", min( value[sparse[lg][Left]]  , value[ sparse[lg][Right-(1<<lg)+1] ]));

	}

	
	return 0;

}
