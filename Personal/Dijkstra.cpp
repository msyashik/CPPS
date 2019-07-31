//Dijkstra
//Learned from Shafayets Planet

#include <bits/stdc++.h>

using namespace std;

#define SIZE 100 // Give your required value

vector<int>v[SIZE];
int cost[SIZE][SIZE];
int distt[SIZE];
priority_queue<pair<int,int>>pq;


void dijkstra(int node)
{
	distt[node] = 0;
	pq.push({0,node});
	
	while(!pq.empty())
	{
		int u = pq.top().second;
		int len = v[u].size();
		pq.pop();
		
		for(int i = 0; i < len; i++)
		{
			int new_node = v[u][i];
			
			if((distt[u] + cost[u][new_node]) < distt[new_node])
			{
				distt[new_node] = distt[u] + cost[u][new_node];
				pq.push({distt[new_node], new_node});
				
			}
		}
		
	}
}

int main()
{
	int n, e, a, b;
	
	cin >> n >> e;
	
	for(int i = 1; i <= e; i++)
	{
		cin >> a >> b >> cost[a][b];
		v[a].push_back(b);
	}
	
	for(int i = 1; i <= n; i++) distt[i] = INT_MAX;
	
	dijkstra(1);
	
	for(int i = 1; i <= n; i++)
	{
		cout << distt[i] << endl;
	}
	return 0;
}
