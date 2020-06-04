#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define double long double 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 1000005

vector<int>prime;
char sieve[SIZE];
vector<pair<int,int>>factors;

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

void factorize(int n)
{
	int sqrtn = sqrt(n);
	for(int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	{
		//if(sieve[n] == 0) break;
		int coun = 0;
		if(n%prime[i] == 0)
		{
			while(n%prime[i] == 0)
			{
				coun++;
				n /= prime[i];
			}
			factors.push_back({prime[i],coun});
			sqrtn = sqrt(n);
		}
	}
	if(n != 1)
	{
		factors.push_back({n,1});
	}
	sort(factors.begin(),factors.end());
	reverse(factors.begin(),factors.end());
	
	cout << factors[0].first << " " << factors[0].second;
	for(int i = 1; i < (int)factors.size(); i++)
	{
		cout << " "<< factors[i].first << " " << factors[i].second;
	}
	cout << endl;
	factors.clear();
}

int32_t main()
{
	string ch;
	vector<int>v;
	isprime(1000000);
	
	while(1)
	{
		getline(cin,ch);
		if(ch == "0") break;
		int len = ch.size();
		int ans = 0, mul = 10;
		for(int i = 0; i < len; i++)
		{
			if(ch[i] == ' ')
			{
				v.push_back(ans);
				ans =0;
			}
			else
			{
				ans = (ans*mul) + (ch[i] - '0');
			}
		}
		v.push_back(ans);
		int total = 1;
		for(int i = 0; i < (int)v.size()-1; i+=2)
		{
			int curr = 1, val = v[i], po = v[i+1];
			for(int j = 1 ; j<= po; j++)
			{
				curr *= val;
			}
			total *= curr;
		}
		total--;
		factorize(total);
		v.clear();
	}
	
	return 0;
}

