#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "p5"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)


size_t BKDRHash(const char str[])
{
	size_t seed = 131;
	size_t hash = 0;

	while(*str)
	{
		hash = hash * seed + (*str++);
	}

	return hash & 0x7FFFFFFF;
}



int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	vector <string> str;
	vector <size_t> hash;


	string temp;

	while(cin >> temp)
	{
		str.push_back(temp);
		printf("%s\n",temp.c_str());

		hash.push_back(BKDRHash(temp.c_str()));
		for (int i = 0; i < hash.size(); ++i)
		{
			for (int j = 0; j < hash.size() ; ++j)
			{
					string fuck = str[i] + str[j];
					if (hash[j] == BKDHash(fuck.c_str()))
					 {
					 	cout << fuck << endl;
					 } 
				
			}
		}
	}
	return 0;
}