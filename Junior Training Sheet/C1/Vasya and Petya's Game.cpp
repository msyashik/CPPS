#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int prime[1010];

void isprime()
{
	int len = sqrt(1000);
	
	prime[1] = 1;
	
	for(int i = 2; i <= len; i++)
	{
		if(prime[i] == 0)
		{
			for(int j = 2*i; j <= 1000; j+=i)
			{
				prime[j] = 1;
			}
		}
	} 
}


int main()
{
    isprime();	
    	
	int n;
	
	cin >> n;
	
	set<int>s;
	
	for(int i = 1; i <= n; i++)
	{
		if(prime[i] == 0)
		{
			int p = 1;
			
			while(p*i <= n)
			{
				p  = p*i;
			    s.insert(p);
			}
		}
	}
	
	
	cout << s.size() << "\n";
	
	for(auto q : s)
	{
		cout << q << " ";
	}
	cout << "\n";
	
	return 0;
}
