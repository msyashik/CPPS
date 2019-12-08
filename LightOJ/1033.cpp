#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define mp make_pair
#define pb push_back
#define f first
#define s second

int dp[105][105];
int t;
string ch;
	
int func(int i, int j)
{
	//base
	if(i > j) return 0;
	
	int ans = 0;
	//memoization
	if(dp[i][j] != -1) return dp[i][j];
	
	//rest
	if(ch[i]==ch[j])
	{
		ans = func(i+1, j-1);
	}
	else
	{
		ans = 1 + min(func(i,j-1),func(i+1,j));
	}
	return dp[i][j] = ans;
}

int main()
{
	//IOS
	scanf("%d", &t);
	for(int i = 1;  i <= t; i++)
	{
	    cin >> ch;
	    int n = ch.size();
	    memset(dp,-1,sizeof(dp));
	    int ans = func(0,n-1);
	    printf("Case %d: %d\n",i, ans);
	}
	return 0;
}
