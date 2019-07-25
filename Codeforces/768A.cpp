#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int t,a,mn = INT_MAX,mx = INT_MIN, coun = 0;
	map<int,int>m;
	
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> a;
		m[a]++;
		if(a < mn) mn = a;
		if(a > mx) mx = a; 
	}
	
	for(auto it : m)
	{
		if((mn < it.first) && (mx > it.first)) coun+=it.second;
	}
	
	cout << coun << endl;
	
	return 0;
}
