#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define pi acos(-1)
 
vector<int>v[200005]; 
bool vis[200005];
int s[200005],e[200005],start = 1,seq[200005];
 
void dfs(int node)
{
	seq[start] = node;
	s[node] = start;
	vis[node] = 1;
	int len = v[node].size();
	
	for(int i = 0; i < len; i++)
	{
		int nodd = v[node][i];
		if(!vis[nodd])
		{
			start++;
			dfs(nodd);
		}
	}
	e[node] = start;
} 
 
int main()
{
	Fastest
	
	int n,q,a,b,c;
	
	cin >> n >> q;
	for(int i = 2; i <= n; i++)
	{
		cin >> a;
		v[a].push_back(i);
	}
	
	dfs(1);
	
	for(int i = 1; i <= q; i++)
	{
		cin >> b >> c;
		if((c-1+s[b]) > e[b]) cout << -1 << endl;
		else cout << seq[s[b]+c-1] << endl;
	}
	
	return 0;
}
