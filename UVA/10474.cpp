#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main()
{
	int n,q;
	int test = 1;
	while(scanf("%d %d", &n, &q) == 2)
	{
		if(n == 0 && q == 0) return 0;
		int arr[100005];
		map<int,int>m;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&arr[i]);
			m[arr[i]]++;
		}
		int coun = 1;
		for(auto it : m)
		{
			int per = coun;
			coun += m[it.first];
		    m[it.first] = per;	
		}
		printf("CASE# %d:\n", test);
		test++;
		int aa;
		while(q--)
		{
			scanf("%d", &aa);
			if(m.count(aa))
			{
				printf("%d found at %d\n", aa, m[aa]);
			} 
			else
			{
				printf("%d not found\n", aa);
			}
		}
	}
	
	return 0;
}
