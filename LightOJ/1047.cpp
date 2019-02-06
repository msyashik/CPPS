#include <bits/stdc++.h>

using namespace std;

#define ll long long

int t, n, arr[25][25], memo[25][25];

int func(int pos, int clr)
{
	if(pos == n+1)
	{
		return 0;
	}
    
    if(memo[pos][clr] != -1) return memo[pos][clr];
    	
	
	if(clr == 0)
	{
		return memo[pos][clr] = min(func(pos+1, 1), min(func(pos+1, 2), func(pos+1, 3)));
	}
	else if(clr == 1)
	{
		return memo[pos][clr] = (arr[pos][clr] + min(func(pos + 1, 2), func(pos+1, 3)));
	}
	else if(clr == 2)
	{
		return memo[pos][clr] = (arr[pos][clr] +  min(func(pos + 1, 1), func(pos+1, 3)));
	}
	else
	{
		return memo[pos][clr] = (arr[pos][clr] + min(func(pos + 1, 1), func(pos+1, 2)));
	}
}

int main()
{	
	cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		
		memset(memo, -1, sizeof(memo));
		
		for(int j = 1; j <= n; j++)
		{
			scanf("%d %d %d", &arr[j][1], &arr[j][2], &arr[j][3]);
		}
		
		int ans = func(0,0);
		
		printf("Case %d: %d\n", i, ans);
	}
	
	return 0;
}
