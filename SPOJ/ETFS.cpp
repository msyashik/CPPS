#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 10000005
 
char sieve[SIZE];
vector<int>prime;
ll a,b;
ll v[100005];
ll v2[100005];
 
void primeSieve()
{
	sieve[0] = 1;
	sieve[1] = 1;
	for(int i = 4; i <= 10000000; i+=2) sieve[i] = 1;
	int len = sqrt(10000000);
	for(ll i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(ll j = i*i; j <= 10000000; j += 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(ll i = 3; i <= 10000000; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}
}
 

void sieveAgain()
{
	//if(a == 1) a++;
	int len = prime.size();
	for(int i = 0; i < len; i++)
	{
		ll first = ((a+prime[i]-1)/prime[i]) * prime[i];
		
		for(ll j = first ; j <= b; j += prime[i])
		{
			v[j-a] /= prime[i];
			
			v[j-a] *= (prime[i] - 1);
			
			while((v2[j-a]%prime[i]) == 0)
			{
				v2[j-a] /= prime[i];
			}
		}
	} 
}

 
int main()
{
	//Fastest
	
    primeSieve();
    
    scanf("%lld %lld", &a, &b);
    
   // if(a == 1) cout << 1 << "\n";
    
    for(ll i = a; i <= b; i++) {v[i-a] = i;v2[i-a] = i;}
    
    sieveAgain();
    
    for(ll i =  a; i <= b; i++)
    {
		if(i == 1) cout << 1 << endl;
		else if(v[i-a] == i) cout << i-1 << endl;
		else if(v2[i-a] == 1)cout << v[i-a] << endl;
		else cout << (v[i-a]/v2[i-a])*(v2[i-a]-1) << endl;
	}
	return 0;
}
 
