//Problem Link: https://www.codechef.com/DEC18B/problems/CHFINTRO

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	Fastest
	
	int a, n, r;
	
	cin >> n >> r;
	
	while(n--)
	{
		cin >> a;
		
		if(a < r) cout << "Bad boi\n";
		else cout << "Good boi\n";
	}
	
	return 0;
}
