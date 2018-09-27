#include <bits/stdc++.h>


using namespace std;

//the code of array is index for one


void construct_tree(int input[],int segment[], int left ,int right , int pos)
{
	if (left == right)
	{
		segment[pos] = input[left];
		return;
	}
	else
	{
		int mid = (left + right) / 2;
		
		construct_tree(input,segment,left,mid,2*pos);// (left + mid / 2)
		construct_tree(input,segment,mid+1,right,2*pos+1);// (mid+1 + right / 2)
		segment[pos] = max(segment[2*pos],segment[2*pos+1]);//change,min,max
	}
}

int range_max(int segment[],int range_left,int range_right,int left,int right,int pos)
{
	if (range_left <= left && range_right >= right)//overlaps
	{
		return segment[pos];
	}
	if (range_left > right || range_right < left)//no overlap
	{
		return INT_MIN;
	}
	else
	{
		int mid = (left + right) / 2;
		return max(range_max(segment , range_left , range_right , left , mid , 2*pos), range_max(segment , range_left , range_right ,mid+1 ,right ,2*pos+1));
	}
}




int main()
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int len;
	scanf("%d",&len);//scan the length
	int input[len];

	for (int i = 1; i <= len; ++i)
	{
		scanf("%d",&input[i]);
	}


	int segment[4*len];//4 length is definetly enough
	fill(segment,segment+4*len,0);
	int rightmost = 0;
	if ((int)(log(len)/log(2)) < log(len)/log(2) )
	{
		rightmost = (int)(log(len)/log(2)) + 1;
	}
	else
	{
		rightmost = (int)(log(len)/log(2));
	}

	construct_tree(input,segment,0,(1<<rightmost),1);


	int left,right;

	while(scanf("%d %d",&left,&right) != EOF)
		printf("max:%d\n",range_max(segment,left,right,0,(1<<rightmost),1));
	
	return 0;

}
