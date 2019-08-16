#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 100000005
 
char sieve[SIZE];
vector<ll>v;
 
void isprime()
{
	sieve[0] = 1;
	sieve[1] = 1;
	sieve[2] = 0;
	for(ll i = 4; i <= 100000000; i+=2)
	{
		sieve[i] = 1;
	}
	ll len = sqrt(100000000);
	for(ll i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(ll j = i*i; j <= 100000000; j+= 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	v.push_back(2);
	for(ll i = 3; i <= 100000000; i+=2)
	{
		if(sieve[i] == 0) v.push_back(i);
	}
}
 
void divisors(ll n)
{
	ll m = n;
	ll sum = 1;
	ll len = sqrt(n);
	
	for(int i = 0; i < v.size() && v[i] <= len; i++)
	{
		if(n%v[i] == 0)
		{
			ll ans = 1, po = 1;
			while(n%v[i] == 0)
			{
				n /= v[i];
				po *= v[i];
				ans += po;
			}
			len = sqrt(n);
			sum *= ans;
		}
	}
	if(n != 1)
	{
		sum *= (1+n);
	}
	sum -= m;
	printf("%lld\n",sum);
}
int main()
{	
	isprime();
    //cout << v.size() << endl;
    ll t, n;
    
    scanf("%lld",&t);
    while(t--)
    {
		scanf("%lld", &n);
		divisors(n);
	}
    
    return 0;
    	
}
