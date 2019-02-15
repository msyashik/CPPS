//Used bitwise sieve

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int num = 100000000, status[10000000];
vector<int>v;

bool check(int N, int pos)
{
	return bool (N & (1 << pos));
}

int SET(int N, int pos)
{
	return N = (N | (1 << pos));
}

void sieve()
{
	v.pb(2);
	
	int len = sqrt(num);
	
	for(int i = 3; i <= len; i+=2)
	{
		if(check(status[i>>5], i&31) == 0)
		{
			for(int j = i*i; j <= num; j+=2*i)
			{
				status[j>>5] = SET(status[j>>5], j&31);
			}
		}
	}
	
	for(int i = 3; i <= num; i+=2)
	{
		if(check(status[i>>5], i&31) == 0) v.pb(i);
	}
}

int main()
{
	sieve();
	
    int len = v.size();
    
    //cout << len << endl;
    
    int ans = 0;
    
    while(1)
    {
	    if(ans > len) break;
	    else
	    {
			cout << (v[ans]) << "\n";
			
			ans += 100;
		}
	}
    	
    
    return 0;	
}
