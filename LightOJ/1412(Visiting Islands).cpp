#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int t, n, m, query;
vector<int>v[100005];
vector<pair<int,int>>vv;
bool vis[100005], vism[100005];
int coun = 0, dist[100005], mx = 0, start, second[100005];

void bfs(int node)
{
	vector<int>tlekomaw;
	queue<int>q;
	vis[node] = 1;
	vism[node] = 1;
	q.push(node);
	dist[node] = 0, coun = 0, mx = 0;
	while(!q.empty())
	{
		int top = q.front();
		tlekomaw.push_back(top);
		coun++;
		if(dist[top] >= mx)
		{
			mx = dist[top];
			start = top;
		}
		q.pop();
		int len = v[top].size();
		for(int i = 0; i < len; i++)
		{
			int child = v[top][i];
			if(!vis[child])
			{
				vism[child] = 1;
				vis[child] = 1;
				q.push(child);
				dist[child] = dist[top] + 1;
			}
		}
	}
	int leno = tlekomaw.size();
	for(int i = 0; i < leno; i++)
	{
		vis[tlekomaw[i]] = 0;
		dist[tlekomaw[i]] = 0;
	}
}

int main()
{	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++)
		{
			v[i].clear();
			vis[i] = 0;
			vism[i] = 0;
			second[i] = -1;
		}
		for(int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d %d",&a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int ash = 0, mxcoun = 0;
		for(int i = 1;i <= n; i++)
		{
			if(!vism[i])
			{
				if(v[i].size() != 0) bfs(i);
				else {mx = 0; coun = 1;};
				if(mx+1 != coun) bfs(start);
				vv.push_back({coun,mx+1});
				ash = max(mx,ash);
				mxcoun = max(mxcoun,coun);
			}
		}
		sort(vv.begin(), vv.end());
		int lenvv = vv.size();
		int mxnodes = 0;
		for(int i = lenvv-1; i >= 0; i--)
		{
			mxnodes = max(mxnodes, vv[i].second);
			vv[i].second = mxnodes;
			second[vv[i].first] = mxnodes;
		}
		int num = second[mxcoun];
		for(int i = mxcoun; i >= 1; i--)
		{
			if(second[i] == -1) second[i] = num;
			else 
			{
			    num = second[i];
			}
		}
		int mxlen = ash + 1;
		scanf("%d", &query);
		printf("Case %d:\n", kase);
		for(int i = 1; i <= query; i++)
		{
			int k;
			scanf("%d", &k);
			if(k > mxcoun) printf("impossible\n");
			else if(k <= mxlen) printf("%d\n",k-1);
			else
			{
				int rest = k - (second[k]);
				int total = (rest*2) + (second[k]-1);
				printf("%d\n",total);
			}
		}
		vv.clear();
	}
	return 0;
}
