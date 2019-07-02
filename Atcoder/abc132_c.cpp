// Problem Link : https://atcoder.jp/contests/abc132/tasks/abc132_c

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int a[100005], n; 
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	if(n%2)
	{
		cout << 0 << endl;
		return 0;
	}
	
	sort(a+1, a+n+1);
	
	int mid = n/2;
	
	int f = a[mid];
	int l = a[mid+1];
	
	if(f == l) cout << 0 << endl;
	else
	{
		cout << l-f << endl;
	}
	
	return 0;
}
