#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define mod 100
#define MAXN 100000

int target;
int n, yes[105];
deque<int>q;

void prime()
{
	for(int i = 2; i <= sqrt(31); i++)
	{
		if(yes[i] == 0)
		{
			for(int j = i*i; j <= 31; j+=i)
			{
				yes[j] = 1;
			}
		}
	}
}

int setbit(int mask, int x)
{
	return mask | (1 << x);
}

int checkbit(int mask, int x)
{
	return mask & (1 << x);
}

void func(int num, int curr)
{
	if(num == target)
	{
		if(yes[curr+1] == 1) return;
		deque<int>q2 = q;
		printf("%d",q2.front());
		q2.pop_front();
		while(!q2.empty()) 
		{
			printf(" %d",q2.front());
			q2.pop_front();
		}
		printf("\n");
	}
	for(int i = 1; i <= n ;i++)
	{
		if(!checkbit(num,i-1) && yes[curr+i] == 0)
		{
			q.push_back(i);
			func(setbit(num,i-1),i);
			q.pop_back();
		}
	}
}

int main()
{	
	int kase = 0;
	prime();
	while(scanf("%d",&n) == 1)
	{
		kase++;
		if(kase > 1) printf("\n");
		printf("Case %d:\n",kase);
		if(n == 1)
		{	
		    printf("1\n");
		    continue;
		}
		if(n%2) 
		{
			continue;
		}
	    target = (1 << n) - 1;
	    q.push_back(1);
	    func(setbit(0,0),1);
	    q.pop_front();
	}
	return 0;
}
