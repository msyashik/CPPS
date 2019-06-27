//Problem Link : https://atcoder.jp/contests/abc118/tasks/abc118_b

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	Coming 
	
	int a, n, m, b;
	
	cin >> n >> m;
	
	map<int,int>mapp;
	
	for(int i = 1; i <= n; i++)
	{
	    cin >> a;
	    
	    for(int i = 1; i <= a; i++)
	    {
			cin >> b;
			
			mapp[b]++;
		}
	}
	
	int coun = 0;
	
	for(auto it : mapp)
	{
		if(it.second == n) coun++;
	}
	
	cout << coun << endl;
	
	mapp.clear();
	
	return 0;
}
