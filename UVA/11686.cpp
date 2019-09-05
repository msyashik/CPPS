#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1000005

vector<int>v[1000005];
int f = 0;
int grey[1000005], black[1000005], visited[1000005];

void dfs(int node)
{
	visited[node] = 1;
	int len = v[node].size();
	grey[node] = 1;
	
	for(int i = 0; i < len; i++)
	{
		if(f == 1) return;
		int nodd = v[node][i];
		
		if(!visited[nodd])
		{
			dfs(nodd);
		}
		else if(visited[nodd] == 1 && grey[nodd] == 1 && black[nodd] == 0)
		{
			f = 1;
			return;
		}
	}
	black[node] = 1;
}

int main()
{
	int a,b, n, m;
	unordered_map<int,int>mp2;
	
	while(1)
	{
	
	cin >> n >> m;
	
	if(n == 0 && m == 0) return 0;
	
	for(int i = 1; i <= n; i++)
	{
		mp2.insert({i,0});
		v[i].clear();
		visited[i] = 0;
		grey[i] = 0;
		black[i] = 0;
	}
	
    for(int i = 1; i <= m; i++)
    {
		cin >> a >> b;
		v[a].push_back(b);
		
		mp2[b]++;
	}	
	
	f = 0;
	
	for(int i = 1; i <= n; i++)
    {
		if(f == 1) break;
		if(!visited[i])
		{
			dfs(i);
		}
	}
	
	if(f == 1)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
    {
		queue<int>q;
		
		for(auto it : mp2)
		{
			if(it.second == 0) q.push(it.first);
		}
		
		while(!q.empty())
		{
			int top = q.front();
			cout << top << endl;
			
			q.pop();
			
			int len = v[top].size();
			
			for(int i = 0; i < len; i++)
			{
				int node = v[top][i];
				mp2[node] -= 1;
				if(mp2[node] == 0) q.push(node);
			}
		}
	}
	
	mp2.clear();
	
    }
	return 0;
}
