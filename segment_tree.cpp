#include <bits/stdc++.h>


using namespace std;

//the code of array is index for zero

void construct_tree(int input[],int segement[], int left ,int right , int pos)
{
	if (left == right)
	{
		segement[pos] = input[left];
		return;
	}
	else
	{
		int mid = (left + right) / 2;
		construct_tree(input,segement,left,mid,2*pos+1);// (left + mid / 2)
		construct_tree(input,segement,mid+1,right,2*pos+2);// (mid+1 + right / 2)
		segement[pos] = min(segement[2*pos+1],segement[2*pos+2]);//change,min,max
	}
}

int range_max(int segement[],int range_left,int range_right,int left,int right,int pos)
{
	if (range_left <= left && range_right >= right)//overlaps
	{
		return segement[pos];
	}
	if (range_left > right || range_right < left)//no overlap
	{
		return 1000000;
	}
	else
	{
		int mid = (left + right) / 2;
		return min(range_max(segement , range_left , range_right , left , mid , 2*pos+1), range_max(segement , range_left , range_right ,mid+1 ,right ,2*pos+2));
	}
}




int main()
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int len;
	scanf("%d",&len);
	int input[len];

	for (int i = 0; i < len; ++i)
	{
		scanf("%d",&input[i]);
	}


	int segement[4*len];
	fill(segement,segement+4*len,0);
	int rightmost = 0;

	if (len % 2 != 0)
	{
		rightmost = (int)(log(len)/log(2)) + 1;
	}
	else
	{
		rightmost = (int)(log(len)/log(2)) + 2;
	}

	construct_tree(input,segement,0,(1<<rightmost)-1,0);


	printf("\n");

	int left,right;

	while(scanf("%d %d",&left,&right) != EOF)
		printf("max:%d\n",range_max(segement,left,right,0,(1<<rightmost)-1,0));
	
	return 0;

}