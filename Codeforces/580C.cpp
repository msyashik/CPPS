#include <bits/stdc++.h>

using namespace std;

int n, m, arr[100005];
int coun = 0;
int visited[100005];
vector<int>v[100005];

void dfs(int node, int f, int parent)
{
	visited[node] = 1;
	if(arr[node]) f++;
	if(f > m) return;
	else
	{
		int len = v[node].size();
		
		if(len == 1 && parent == v[node][0])
		{
			coun++;
			return;
		}
		
		for(int i = 0; i < len; i++)
		{
			int nodd = v[node][i];
			if(visited[nodd] == 0)
			{
				if(arr[nodd] == 0) dfs(nodd,0, node);
				else dfs(nodd,f, node);
			}
		}
	}
	return;
}

int main()
{
	int a,b;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = 1; i <= n-1; i++) 
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs(1,0, 0);
	
	cout << coun << endl;
	
	return 0;
}
