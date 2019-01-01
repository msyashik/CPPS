//longest common subsequence
//shafayets planet

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define maxx 1000

int dp[maxx][maxx];
int visited[maxx][maxx];
string a, b, sum;

int lcs(int i, int j)
{
    if(a[i] == '\0' || b[j] == '\0') return 0;
    else if(visited[i][j]) return dp[i][j];
    
    visited[i][j] = 1;
    
    int ans = 0;
    
    if(a[i] == b[j]) ans = 1 + lcs(i+1, j+1);
    
    else
    {
		int div1 = lcs(i, j+1);
		int div2 = lcs(i+1, j);
		
		ans = max(div1, div2);
	}    	
	
	return dp[i][j] = ans;
}


void printlcs(int i, int j)
{
	if(a[i] == '\0' || b[j] == '\0')
	{
		cout << sum << "\n";
		return;
	}
	
	if(a[i] == b[j])
	{
		sum+=a[i];
		printlcs(i+1, j+1);
	}
	else
	{
		if(dp[i][j+1] > dp[i+1][j]) printlcs(i, j+1);
		else printlcs(i+1, j);
	}
}

void printall(int i, int j)
{
	if(a[i] == '\0' || b[j] == '\0')
	{
		cout << sum << "\n";
		sum.clear();
		return;
	}
	
	if(a[i] == b[j])
	{
		sum+=a[i];
		printall(i+1, j+1);
	}
	else
	{
		if(dp[i][j+1] > dp[i+1][j]) printall(i, j+1);
		else if(dp[i][j+1] < dp[i+1][j]) printall(i+1, j);
		else
		{
			printall(i, j+1);
			printall(i+1, j);
		}
	}
}

int main()
{
	IOS;
	
	cin >> a >> b;
	
	cout << lcs(0, 0) << "\n";
    printall(0,0);
	
	
	return 0;
}
