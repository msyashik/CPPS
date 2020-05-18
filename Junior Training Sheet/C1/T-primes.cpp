#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

char sieve[1000005];

void isprime(ll n)
{
    sieve[0] = 1,sieve[1] = 1;
    sieve[2] = 0;
    for(ll i =4; i <= n; i+=2) sieve[i] = 1;
    for(ll i = 3; i <= sqrt(n); i+=2)
    {
		if(sieve[i] == 0)
		{
			for(ll j = i*i; j <= n; j+= 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
}


void solve()
{
	ll n, arr[100005];
	
	cin >> n;
	for(ll i = 1; i<= n; i++)
	{
		cin >> arr[i];
		if(arr[i] == 4) cout << "YES\n";
		else if(arr[i]%2)
		{
			ll sq = sqrt(arr[i]);
			if(sieve[sq] == 0 && sq*sq == arr[i]) cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "NO\n";
	}
}

int main()
{
	isprime(1000000); 
	solve();
	return 0;
}
