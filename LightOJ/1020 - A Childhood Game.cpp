#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1005
#define eps 1e-9

int main()
{
	ll t, a;
	string ch;
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%lld", &a);
		cin >> ch;
		printf("Case %lld: ", kase);
		if(ch == "Alice")
		{
			if(a%3 == 1) printf("Bob\n");
			else printf("Alice\n");
		}
		else
		{
			if(a%3 == 0) printf("Alice\n");
			else printf("Bob\n");
		}
	}
	return 0;
}
