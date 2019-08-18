#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
 
int visited[200005];
vector<int>v[200005];
int man[200005];
 
void dfs(int node, int taka)
{
	man[node] += taka;
	visited[node] = 1;
	int len = v[node].size();
	
	for(int i = 0; i < len; i++)
	{
		int nodd = v[node][i];
		if(visited[nodd] == 0)
		{
			dfs(nodd,man[node]);
		}
	}
	return;
}
 
int main()
{
    int n,q,a,b,p,x;
    
    scanf("%d %d", &n, &q);
    
    for(int i = 1; i <= n-1; i++)
    {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= q; i++)
	{
		scanf("%d %d",&p,&x);
		man[p] += x;
	}
    
    for(int i = 1; i <= n; i++)
    {
		if(visited[i] == 0)
		{
			dfs(i,0);
		}
	}
	cout << man[1];
	for(int i = 2; i <= n; i++)
	{
		cout << " " << man[i];
	}	
	cout << endl;
	return 0;
}
