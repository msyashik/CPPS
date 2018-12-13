//Segmented Sieve(From forthright48)

#include <bits/stdc++.h> 

using namespace std; 

#define ll long long
#define pb push_back

ll prime[16000];//Give the Half size of the input value
vector<ll>v;

void sieve(ll n)
{
	
	memset(prime, 0, sizeof(prime));
	
	v.pb(2);
	
	ll len = sqrt(n+1);
	
	for(ll i = 3; i <= len; i+=2)
	{
		if(prime[i>>1] == 0)
		{
			for(ll j = i * i; j <= n; j+= i + i)
			{
				prime[j>>1] = 1;
			}
		}
	}
	
	for(ll i = 3; i <= n; i+=2)
	{
		if(prime[i>>1] == 0)
		{
			v.pb(i);
		}
	}
}

void segments(ll m, ll n)
{
	ll len2 = v.size();
    ll len = (n-m) + 1;
    ll seg[len];
    
    for(ll i = 0; i < len; i++) seg[i] = 1;
    
	for(ll i = 0; i < len2; i++)
	{
		
		ll ans = ceil(m/(v[i]*1.0));
	
		if(ans <= v[i]) ans = v[i];
		
		for(ll j = ans*v[i]; j <= n; j += v[i])
		{
			seg[j - m] = 0;
		}
	}
	
	if(m == 1) seg[0] = 0;
	
	for(ll i = 0; i < len; i++)
	{
		 if(seg[i] == 1) printf("%lld\n", i+m);
	} 
	printf("\n");
}

int main() 
{
    ll t, m, n;
    
    scanf("%lld", &t);
    
    for(ll i = 1; i <= t; i++)
    {
		
    scanf("%lld %lld",&m, &n);
    
    ll sqrtn = sqrt(n);
    
    sieve(sqrtn);
    
    segments(m, n);
    
    v.clear();
    
}
    return 0;
}

/*

Tested problems:

SPOJ PRIME1 - Prime Generator

LOJ 1197 - Help Hanzo

*/
