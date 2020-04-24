#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100005

vector<int>prime;
char sieve[SIZE];
bool arr[100005];//used for segmented sieve
vector<int>factors;//used for prime factorization

//checking prime or not
void isprime(int n)
{
    sieve[0] = 1,sieve[1] = 1;
    sieve[2] = 0;
    for(int i =4; i <= n; i+=2) sieve[i] = 1;
    for(int i = 3; i <= sqrt(n); i+=2)
    {
		if(sieve[i] == 0)
		{
			for(int j = i*i; j <= n; j+= 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(int i = 3; i <= n; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}	
}

//prime factorization
void factorize(int n)
{
	int sqrtn = sqrt(n);
	for(int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	{
		if(sieve[n] == 0) break; //if n is prime we can't factorize it anymore
		if(n%prime[i] == 0)
		{
			while(n%prime[i] == 0)
			{
				n /= prime[i];
				factors.push_back(prime[i]);
			}
			sqrtn = sqrt(n);
		}
	}
	if(n != 1)
	{
		factors.push_back(n);
	}
}

//Number of Divisors(NOD)
void NOD(int n)
{
	int sqrtn = sqrt(n);
	int res = 1;
	for(int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	{
		if(sieve[n] == 0) break; //if n is prime we can't factorize it anymore
		if(n%prime[i] == 0)
		{
			int p = 0;
			while(n%prime[i] == 0)
			{
				n /= prime[i];
				factors.push_back(prime[i]);
				p++;
			}
			sqrtn = sqrt(n);
			p++;
			res *= p;
		}
	}
	if(n != 1)
	{
		factors.push_back(n);
		res *= 2;
	}
	cout << res << endl;
}

//Sum of Divisors(SOD)
void SOD(int n)
{
	int sqrtn = sqrt(n);
	int res = 1;
	for(int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	{
		if(sieve[n] == 0) break; //if n is prime we can't factorize it anymore
		if(n%prime[i] == 0)
		{
			int p = 1,po = 1;
			while(n%prime[i] == 0)
			{
				n /= prime[i];
				factors.push_back(prime[i]);
				po*=prime[i];
				p += po;
			}
			sqrtn = sqrt(n);
			res *= p;
		}
	}
	if(n != 1)
	{
		factors.push_back(n);
		res *= (n+1);
	}
	cout << res << endl;
}



//segmented sieve
void segmented_sieve(int a,int b)
{
	if(a==1) a++;
	int sqrtn = sqrt(b);
	memset(arr,0,sizeof(arr));
	
	for(int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	{
		int p = prime[i];
		int j = p*p;
		if(j < a) j = ((a+p-1)/p)*p;
		
		for(; j <= b; j+=p)
		{
			arr[j-a] = 1;
		} 
	}
	for(int i = a; i <= b; i++)
	{
		if(arr[i-a] == 0) cout<< i << endl;
	}
}

int main()
{
	isprime(100000);	
	SOD(100);
	return 0;
}
