#include <bits/stdc++.h>



using namespace std;

#define N 5

int value[N] = {5,4,3,2,1};
int cnt[(int)(log(N)/log(2))][N];




int main()
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	printf("%d\n", (int)(log(N)/log(2)));
	for (int i = 0; i < N; ++i)
	{
		cnt[0][i] = i;
	}

	for (int i = 1; (1<<i)<N; ++i)
	{
		for (int j = 0; j+(1<<i)-1 < N ;++j)
		{
			printf("j:%d\n", j);
			int L = cnt[i-1][j];
			int R = cnt[i-1][j+(1<<(i-1))];
			cnt[i][j] = value[L] <= value[R] ? L : R;
		}
	}

	for (int i = 0; i <= (int)(log(N)/log(2)); ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", cnt[i][j]);
		}
		printf("\n");
	}

	
	return 0;

}