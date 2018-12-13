//memory efficient sieve(from Jane Alom Jan's pdf(Lightoj))

#include <bits/stdc++.h> 

using namespace std; 

#define ll long long
#define pb push_back

ll prime[100];//Give the Half size of the input value
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
	
	ll len2 = v.size();
	
	for(ll i = 0; i < len2; i++)
	{
		printf("%lld\n",v[i]);
	}

}
int main() 
{
    ll n;
    
    scanf("%lld", &n);
    
    sieve(n);
    
    return 0;
}
