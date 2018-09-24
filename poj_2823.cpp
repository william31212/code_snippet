#include <iostream>
#include <cstdio>

using namespace std;

int N,K;
int arr[1000001];
int indexx[1000001];
int qu[1000001];
int ans[1000001];

void getmin()
{
	int tail = 0,head = 1;
	for (int i = 1; i < K; ++i)
	{
		while(tail >= head && qu[tail] >= arr[i])//check empth & new data is bigger than qu[tail]
			tail--;
		qu[++tail] = arr[i];
		indexx[tail] = i;
	}

	for (int i = K; i <= N; ++i)
	{
		while(tail >= head && qu[tail] >= arr[i])//check empth & new data is bigger than qu[tail]
			tail--;
		qu[++tail] = arr[i];
		indexx[tail] = i;
		while(indexx[head] <= i-K)
			head++;
		ans[i-K] = qu[head];
	}

	for (int i = 0; i <= N-K; ++i)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
}

void getmax()
{
	int tail = 0,head = 1;
	for (int i = 1; i < K; ++i)
	{
		while(tail >= head && qu[tail] <= arr[i])//check empth & new data is bigger than qu[tail]
			tail--;
		qu[++tail] = arr[i];
		indexx[tail] = i;
	}

	for (int i = K; i <= N; ++i)
	{
		while(tail >= head && qu[tail] <= arr[i])//check empth & new data is bigger than qu[tail]
			tail--;
		qu[++tail] = arr[i];
		indexx[tail] = i;

		while(indexx[head] <= i-K)
			head++;

		ans[i-K] = qu[head]; 

	}

	for (int i = 0; i <= N-K; ++i)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
}


int main()
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	while(~scanf("%d %d",&N,&K))
	{
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d ",&arr[i]);
		}
		getmin();
		getmax();
	}

	
	return 0;

}