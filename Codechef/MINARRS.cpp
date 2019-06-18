//Problem link : https://www.codechef.com/problems/MINARRS

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int check(int num, int pos)
{
	ll mux = (1 << pos);
	ll ans = (num & mux);
	
	return ans;
}


int main()
{
	Coming 
	
	vector<int>v;
	
	ll t, n, arr[100005];
	
	cin >> t;
	
	while(t--)
	{
	cin >>n;
	  
	for(ll i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	
	for(int i = 0; i <= 30; i++)
	{
		int zeros = 0;
		int ones = 0;
		
		for(ll j = 1; j <= n; j++)
		{
			if(check(arr[j], i) == 0) zeros++;
			else ones++;
		}
		
		if(zeros > ones) v.push_back(0);
		else v.push_back(1);
	}
	
	int len = v.size();
	
	ll ans = 0;
	
	for(int i = 0; i < len; i++)
	{
		ans += (v[i] * (1 << i));
	}
	
	ll sum = 0;
	
	for(ll i = 1; i <= n; i++)
	{
		sum += (arr[i] ^ ans);
	}
	
	cout << sum << endl;
	
	v.clear();
    }
	return 0;
}
