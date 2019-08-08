#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 100005

char sieve[SIZE];
vector<int>prime;
int arr[505];
ll a,b;
 
void primeSieve()
{
	sieve[0] = 1;
	sieve[1] = 1;
	for(int i = 4; i <= 100000; i+=2) sieve[i] = 1;
	int len = sqrt(100000);
	for(int i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(int j = i*i; j <= 100000; j += 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(int i = 3; i <= 100000; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}
}

void segmentSieve(ll a, ll b)
{
	if(a == 1) a++;
	ll len = sqrt(b);
	
	memset(arr, 0, sizeof(arr));
	
	for(int i = 0; i < prime.size() && prime[i] <= len; i++)
	{
		ll p = prime[i];
		ll j = p*p;
		
		if(j < a) j = ((a+p-1)/p) * p;
		for(; j <= b; j+=p)
		{
			arr[j-a] = 1;
		}
	}
	
	for(ll i = b-1; i >= a; i--)
	{
		if(arr[i-a] == 0) 
		{
		    cout << i << endl;
		    break;
		}
	}
}

/*void div(ll n)
{
    ll len = sqrt(n),total = n;
    for(int i = 0; i < prime.size() && prime[i] <= len; i++)
    {
		//if(n > 10000000 && arr[n-a] == 0) break;
		if(n <= 10000000 && sieve[n] == 0) break;
		
		if(n%prime[i] == 0)
		{
			while(n%prime[i] == 0)
			{
				n /= prime[i];
			}
			len = sqrt(n);
			total /= prime[i];
			total *= prime[i]-1;
		}
	}
	if(n != 1)
	{
		total /= n;
		total *= n-1;
	}	
	cout << total << endl;
}*/

int main()
{
	Fastest
	
    primeSieve();
    
    /*cin >> a >> b;
    
    if(a == 1) cout << 1 << endl;
    
    segmentSieve();
    
    for(ll i = a; i <= b; i++)
    {
		if(arr[i-a] == 0) cout << i-1 << endl;
		else div(i);
	}*/
	
	int t;
	ll x;
	
	cin >> t;
	
	while(t--)
	{
		cin >> x;
		if(x-500 < 0) segmentSieve(x-500,x);
		else segmentSieve(x-500,x);
	}
	return 0;
}
