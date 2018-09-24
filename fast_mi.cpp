#include <bits/stdc++.h>

using namespace std;

int power(int x , int n)
{
	if (n == 0)
		return 1;
	else if(n == 1)
		return x;
	else
	{
		if (n % 2 != 0)
		{
			int y = power(x , n / 2);
			return x * y * y;
		}
		else
		{
			int y = power(x , n / 2);
			return y * y;
		}
	}
}



int main()
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	

	int x , n;
	cin >> x >> n;
	cout << power(x,n) << endl;

	return 0;

}