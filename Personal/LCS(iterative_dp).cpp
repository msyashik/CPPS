//LCS
//Iterative dp
//Learned from Tushar Roy(https://www.youtube.com/watch?v=NnD96abizww)

#include <bits/stdc++.h>

using namespace std;

#define SIZE 3005

int dp[SIZE][SIZE];
string ch, bh, ss = "";
	
int LCS(int len_a, int len_b)
{
	for(int i = 0; i <= len_a; i++)
	{
		for(int j = 0; j <= len_b; j++)
	    {
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(ch[i-1] == bh[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			} 
			else 
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	/*for(int i = 0; i < len_a; i++) // LCS Table
	{
		for(int j = 0; j < len_b; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	return dp[len_a][len_b];
}

void print_LCS(int m, int p, int q)
{
	while(1)
	{
		if(p == 0 || q == 0) break;
		int ans = max(dp[p-1][q], dp[p][q-1]);
		if(ans== m)
		{
			if(ans == dp[p-1][q])
			{
				p -= 1;
			}
			else
			{
				q -= 1;
			}
		}
		else
		{
			m = ans;
			ss.push_back(ch[p-1]);
			p -= 1;
			q -= 1;
		}
	}
	reverse(ss.begin(), ss.end());
	cout << ss << endl; //LCS String
}

int main()
{	
	cin >> ch >> bh;
	
	int len_a = ch.size(), len_b = bh.size();
	
	int ans = LCS(len_a, len_b);
	
	cout << ans << endl; // LCS Length
	
	print_LCS(ans, len_a, len_b);
	
	
	return 0;
}
