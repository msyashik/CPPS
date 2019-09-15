#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1000005
 
vector<int>v[200005];
int visited[200005];
int rong[200005];
int f = 0;
map<pair<int,int>,int>mp;
 
 
void dfs(int node, int clr, int sign, int par)
{
	visited[node] = 1;
	
	rong[node] = clr;
	
	int len = v[node].size();
	for(int i = 0; i < len; i++)
	{
		if(f == 1) return;
		int nodd = v[node][i];
		if(!visited[nodd])
		{
			if(sign == 0)
			{
			   mp[{node,nodd}] = 0;
			   mp[{nodd,node}] = 1;
     		}
		    else
		    {
			   mp[{node,nodd}] = 1;
			   mp[{nodd,node}] = 0;
			}
			if(clr == 1) 
			{
			    if(sign == 0) dfs(nodd,2,1,node);
			    else dfs(nodd,2,0,node);
			}
			else 
			{
			    if(sign == 0) dfs(nodd,1,1,node);
			    else dfs(nodd,1,0,node);
			}
		}
		else if(rong[nodd] == clr)
		{
			f = 1;
			return;
		}
		else if(par != nodd)
		{
			if(sign == 0)
			{
			   mp[{node,nodd}] = 0;
			   mp[{nodd,node}] = 1;
     		}
		    else
		    {
			   mp[{node,nodd}] = 1;
			   mp[{nodd,node}] = 0;
			}
		}
	}
}
 
int main()
{	
	int n,m,a[200005],b[200005];
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i];
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
	}
	
    dfs(1,1,0, 0);	
	
	if(f == 1) cout << "NO\n";
	else
	{
		cout << "YES\n";
		
		/*for(auto it : mp)
		{
			cout << it.first.first << " " << it.first.second << " " << it.second << endl;
		}*/
		
		for(int i  = 1; i <= m; i++)
		{
			if(mp[{a[i],b[i]}] == 0) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
	
	return 0;
}
