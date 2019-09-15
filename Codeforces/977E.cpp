#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int coun = 0;
bool vis[200005],g[200005],b[200005];
vector<int>v[200005];
int f = 0,sum = 0,mx=0,cycles = 0,counn=0;
int num[200005];

void dfs(int node,int par,int coun)
{
	counn++;
	num[node] = coun;
	vis[node] =1;
	g[node] = 1;
	
	int len = v[node].size();
	for(int i = 0; i < len; i++)
	{
		int nodd = v[node][i];
		if(!vis[nodd])
		{
			dfs(nodd,node,coun+1);
		}
		else
		{
		if(g[nodd] == 1 && b[nodd] == 0 && f == 0 && par!=nodd)
		{
			f = 1;
			mx = abs(num[nodd]-num[node]) + 1;
		}
		if(g[nodd] == 1 && b[nodd] == 0 && par != nodd)
		{
			cycles++;
 }
 		}
	}
	b[node] = 1;
}

int main()
{
	int n, m,a,b;
	
	cin>>n>>m;
	
	for(int i = 1; i  <= m; i++)
	{
		cin>> a >>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			counn = 0;
			mx=-1;
			f=0;
			cycles=0;
			dfs(i,0,1);
			if(f == 1 && mx == counn && cycles == 1)
			{
				sum++;
			}
		}
	}
	
	cout << sum <<endl;
	
	return 0;
}
