//Used bitwise sieve

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int num = 32000, status[1005];
vector<int>v, v1 ,v3[1000];

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
	int a, b;
	
	sieve();
	
    int len = v.size();
    
    for(int i = 1; i < len; i++)
    {
		v1.push_back(v[i] - v[i-1]);
	}
	
	
	int lenn = v1.size(), coun = 0;
	
    for(int i = 0; i < lenn-1; i++)
    {
		if(v1[i] == v1[i+1])
		{
			int beg = i;
			int end = i+1;
			
			while(end < lenn)
			{
				if(v1[end+1] == v1[end])
				{
					end++;
				}
				else break;	
			}
			
			i = end;
			
			for(int j = beg; j <= end+1; j++)
			{
				v3[coun].push_back(v[j]);			
		    }
		    coun++;
		}
	}	
	
	
	while(scanf("%d %d", &a, &b) == 2)
	{
		if(a == 0 && b == 0) return 0;
		
		if(a > b) swap(a,b);
		
		for(int i = 0; i < coun; i++)
		{
			if(v3[i].size() == 3)
			{
				if(v3[i][0] >= a && v3[i][2] <= b)
				{
					cout << v3[i][0] << " " << v3[i][1] << " " << v3[i][2] << "\n";
				}
			}
			else if(v3[i].size() == 4)
			{
				if(v3[i][0] >= a && v3[i][3] <= b)
				{
					cout << v3[i][0] << " " << v3[i][1] << " " << v3[i][2]  << " " << v3[i][3] << "\n";
				}
			}
		}
	}
    return 0;	
}
