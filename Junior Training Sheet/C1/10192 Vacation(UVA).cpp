#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string ch,bh;
ll len1, len2;
ll dp[105][105];

ll func(ll indx1, ll indx2)
{
	if(indx1 >= len1 || indx2 >= len2)
	{
		return 0;
	}
	if(dp[indx1][indx2] != -1) return dp[indx1][indx2];
	ll ans = 0,ans2 = 0,ans3 = 0;
	if(ch[indx1] == bh[indx2])
	{
		ans = 1 + func(indx1+1,indx2+1);
	}
	else
	{
		ans2 = func(indx1+1,indx2);
		ans3 = func(indx1,indx2+1);
	}
	return dp[indx1][indx2] = max(ans,max(ans2,ans3));
}

int main()
{	
	ll kase = 0;
	while(getline(cin,ch))
	{
		if(ch == "#") break;
		getline(cin,bh);
		len1 = ch.size();len2 = bh.size();
		memset(dp,-1,sizeof(dp));
		ll ans = func(0,0);
		kase++;
		printf("Case #%lld: you can visit at most %lld cities.\n", kase,ans);
	}
	return 0;
}
