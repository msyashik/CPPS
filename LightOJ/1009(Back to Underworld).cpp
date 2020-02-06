#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

vector<int>v[200005];
bool vis[200005];
int col[200005];
int mxsum = 0;

void bfs(int node)
{
	int zero = 0;
    int one = 0;
	vis[node] = 1;
	col[node] = 1;
	queue<int>q;
	q.push(node);
	while(!q.empty())
    {
		int par = q.front();
		if(col[par] == 1) zero++;
		else one++;
		q.pop();
		int len = v[par].size();
		for(int i = 0; i < len; i++)
		{
			int child = v[par][i];
			if(!vis[child])
			{
				vis[child] = 1;
				q.push(child);
				if(col[par] == 1)  
				{
				    col[child] = 2;
				}
				else col[child] = 1;
			}
		}
	}
	mxsum += max(zero,one);
	 //cout << col[1] << " " << col[2] << " " << col[3] << endl;
}
int main()
{
    int n, m, a, b;
    
    scanf("%d", &n);
    for(int kase = 1; kase <= n; kase++)
    {
		
		scanf("%d", &m);
		map<int,int>mp;
		while(m--)
		{
			scanf("%d %d", &a, &b);
			mp[a]++;mp[b]++;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		printf("Case %d: ", kase);
		mxsum = 0;
		for(auto it : mp)
		{
			if(!vis[it.first]) 
			{
			    bfs(it.first);
			}
		}
		for(auto it : mp)
		{
			vis[it.first] = 0;
			v[it.first].clear();
			col[it.first] = -1;
		}
		mp.clear();
		printf("%d\n", mxsum);
	}
	return 0;
}
