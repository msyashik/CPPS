#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int prime[1005];
vector<int>v;

void func()
{
	prime[0] = 1;
	prime[1] = 1;
	
	for(int i = 4; i <= 1000; i+=2) prime[i] = 1;
	
	int len = sqrt(1000);
	
	for(int i = 3; i <= len; i+=2)
	{
		if(prime[i] == 0)
		{
			for(int j = i*i; j <= 1000; j += 2*i)
			{
				prime[j] = 1;
			}
		}
	}
	
	for(int i = 1; i <= 1000; i++)
	{
		if(prime[i] == 0)
		{
			v.push_back(i);
		}
	}
	 
}

int main()
{
	func();
	
	int n, k,coun = 0;
	
	cin >> n >> k;
	
	int len = v.size();
	
	for(int i = 6; i <= n; i++)
	{
		if(prime[i] == 0)
		{
		int ans = i-1;
		for(int j = 0; j < len-1; j++)
		{
			int a = v[j];
			int b = v[j+1];
			if((a+b) > ans) break;
			if(ans == (a+b))
			{
				coun++;
				break;
			}
		}
	    }
		if(coun >= k) break;
	}
	
	if(coun >= k) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}
