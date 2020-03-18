#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI acos(-1.0)

string ch, bh,ash = "";
int len1, len2;
int dp[3005][3005];

int func(int i, int j)
{
	if(i >= len1 || j >= len2) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int ans = 0;
	if(ch[i] == bh[j])
	{
		ans = 1 + func(i+1,j+1);
	}
	else
	{
		ans = max(func(i+1,j), func(i,j+1));
	}
	return dp[i][j] = ans;
}

void path_print(int i, int j)
{
	if(i >= len1 || j >= len2)
	{
		cout << ash << endl;
		return;
	}
	if(ch[i] == bh[j])
	{
		ash += ch[i];
		path_print(i+1,j+1);
	}
	else
	{
		if(dp[i+1][j] > dp[i][j+1]) path_print(i+1,j);
		else path_print(i,j+1);
	}
}

int main()
{	
	cin >> ch >> bh;
	len1 = ch.size(),len2 = bh.size();
	memset(dp,-1,sizeof(dp));
	func(0,0);
	path_print(0,0);
	return 0;
}
