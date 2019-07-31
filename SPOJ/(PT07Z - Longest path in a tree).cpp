#include <bits/stdc++.h>

using namespace std;

vector<int>v[10005];

int visited[10005];
queue<int>q;
int dist[100005];
int lenn = 0;
int last;

void bfs(int src)
{
	lenn = 0;
    q.push(src);
    
    visited[src] = 1;
    
    dist[src] = 0;
    
    while(!q.empty())
    {
		int top = q.front();
		//cout << top << " ";
		q.pop();
		
		
		int len = v[top].size();
		
		for(int i = 0; i < len; i++)
		{
			int ans = v[top][i];
			if(visited[ans] == 0)
			{
				q.push(ans);
				visited[ans] = 1;
				dist[ans] = dist[top] + 1;
				lenn = max(lenn, dist[ans]);
			}
		}
		if(q.size() == 0) last = top;
	}
	//cout << lenn << endl;
}

int main()
{
	int n, a, b;
	
	cin >> n;
	
	for(int i = 1; i <= n-1; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(1);
	
	memset(visited, 0, sizeof(visited));
	
	bfs(last);
	cout << lenn << endl;
	
	return 0;
}
