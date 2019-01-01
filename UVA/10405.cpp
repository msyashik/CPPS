#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define maxx 1005

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

int main()
{
	while(getline(cin, a))
	
	{
		getline(cin, b);
		memset(visited, 0, sizeof(visited));
		
 	    cout << lcs(0, 0) << "\n";
    }
    
	return 0;
}
