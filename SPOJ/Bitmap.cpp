#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	int t, n, m;
	
	string arr[200];
	
	cin >> t;
	
	while(t--)
	{
		vector<pair<int,int>>v;
		
	    cin >> n >> m;
	    
	    int coun[n+5][m+5];
	    
	    memset(coun,-1, sizeof(coun));
	    
	    for(int i = 0; i < n; i++)
	    {
			cin >> arr[i];
			
			for(int j = 0; j < m; j++)
			{
				if(arr[i][j] == '1') 
				{
					coun[i+1][j+1] = 0;
					v.push_back(make_pair(i+1,j+1));
				}
			}
		}
		
		int len = v.size();
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(coun[i][j] != 0)
				{
					int ans = INT_MAX;
					
					for(int l = 0; l < len; l++)
					{
						ans = min(ans, abs(i-v[l].first) + abs(j-v[l].second));
					}
					coun[i][j] = ans;
				}
				
				cout << coun[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}
