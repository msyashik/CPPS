#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

vector<int>v[5005];
bool visited[5005];
int counn = 0;

void dfs(int node)
{
	counn++;
	visited[node] = 1;
	
	int len = v[node].size();
	
	for(int i = 0; i < len; i++)
	{
		int nodd = v[node][i];
		
		if(!visited[nodd])
		{
			dfs(nodd);
		}
	}
}
			

int main()
{
	int n, e, a, b;
	string ch,bh,dh;
	map<string,int>m;
	
	while(scanf("%d %d", &n, &e) == 2)
	{
		if(n == 0 && e == 0) return 0;
		int coun = 1;
		
		
		for(int i = 1; i <= n; i++)
		{
			visited[i] = 0;
			v[i].clear();
		}
		
		for(int i = 1; i <= n; i++)
		{
			cin >> ch;
			if(m.count(ch) == 0)
			{
			    m.insert({ch,coun});
			    coun++;
			}
		}
		
		int ans = 0;
		
		for(int i = 1; i <= e; i++)
		{
			cin >> bh >> dh;
			int a = m[bh];
			int b = m[dh];
			
			v[a].push_back(b);
			v[b].push_back(a);
		}
		
		for(int i = 1; i <= n; i++)
		{
			if(!visited[i])
			{
				counn = 0;
				dfs(i);
				ans = max(ans,counn);
			}
		}
		
		cout << ans << endl;
		
		m.clear();
		
	}
	return 0;
}
