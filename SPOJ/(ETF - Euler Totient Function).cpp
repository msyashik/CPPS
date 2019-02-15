//Euler Totient function

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void pf(int n)
{
	ll ans  = n;
    	
	if(n%2 == 0)
	{
		while(n%2 == 0)
		{
			n /= 2;
		}
		
		ans /= 2;
		
		ans *= (2-1);
	}
	
	int len = sqrt(n);
	
	
	for(int i = 3; i <= len; i+=2)
	{
		if(n%i == 0)
		{
			while(n%i == 0)
		    {
				n /= i;
			}
			
			ans /= i;
			
			ans *= (i-1);
		}
	}
	
	if(n > 2)
	{
		ans /= n;
		
		ans *= (n-1);
	}
	
	printf("%lld\n", ans);
	
}


int main()
{
	int t, a;
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d", &a);
		
		pf(a);
	}
	
	return 0;
}
