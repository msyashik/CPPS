#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define SIZE 100005
#define inf 100000000

int dist[SIZE]; // change the value of inf SIZE as you want
int path[SIZE];

struct edges
{
	int v;
	int w;
};

bool operator < (struct edges a, struct edges b)
{
	return a.w < b.w;
}

void dij(int node, priority_queue<edges>pq, vector<edges>v[])
{
	pq.push({node, 0});
	
	while(!pq.empty())
	{
		edges top = pq.top();
		pq.pop();
		
		int len = v[top.v].size();
		for(int i = 0; i < len; i++)
		{
			edges nodd = v[top.v][i];
			
			if((dist[top.v] +  nodd.w) < dist[nodd.v])
			{
				dist[nodd.v] = dist[top.v] + nodd.w;
				pq.push(nodd);
				path[nodd.v] = top.v;
			}
		}
	}
}

int main()
{
	int n, e, a, b, cost;
	
	scanf("%d %d", &n,&e);
	
	vector<edges>v[n+1];
	priority_queue<edges>pq;
	
	for(int i = 1; i <= e; i++)
	{
		scanf("%d %d %d", &a, &b, &cost);
		v[a].push_back({b,cost});
		v[b].push_back({a,cost}); //if the graph is undirected
	}
	
	for(int i = 1; i <= n; i++) dist[i] = inf; // change the value of inf as you want
	
	dist[1] = 0; // if 1 is the starting point
	
	dij(1, pq, v); //if 1 is the starting point
	
	printf("%d\n", dist[n]); //distance of n from the starting point
	
	//path_printing
	
    vector<int>pathprint;	
	
	pathprint.push_back(n);
	int m = n;
	
	while(1)
	{
	    if(m == 1) break;
	    else
	    {
			pathprint.push_back(path[m]);
			m = path[m];
		}	
	}
	reverse(pathprint.begin(), pathprint.end());
	
	int lenn = pathprint.size();
	for(int i = 0; i < lenn; i++)
	{
		printf("%d ", pathprint[i]);
	}
	printf("\n");
	
	return 0;
}

