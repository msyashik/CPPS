//LCS(recursive dp)
//Shafayets

#include <bits/stdc++.h>

using namespace std;

int dp[3005][3005];
string a, b;
int len_a, len_b;
string ss = "";	

int LCS(int i, int j) // Calculating LCS length
{
	if(i == len_a || j == len_b) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	
	int ans = 0;
	if(a[i] == b[j]) ans = 1 + LCS(i+1, j+1);
	else
	{
		int ans1 = LCS(i, j+1);
		int ans2 = LCS(i+1, j);
		ans = max(ans1, ans2);
	}
	return dp[i][j] = ans;
}

void printLCS(int i, int j) //Searching LCS string
{
	if(i == len_a || j == len_b)
	{
		cout << ss << endl; //LCS string
		return;
	}
	if(a[i] == b[j])
	{
		ss += a[i];
		printLCS(i+1, j+1);
	}
	else
	{
		if(dp[i][j+1] > dp[i+1][j]) printLCS(i,j+1);
		else printLCS(i+1,j);
	}
	return;
}

int main()
{
    memset(dp, -1, sizeof(dp));	
	cin >> a >> b;
	len_a = a.size() , len_b = b.size();	
	int sum = LCS(0,0);
	
	cout << sum << endl; //LCS length
	printLCS(0,0);
	return 0;
}
