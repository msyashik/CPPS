#include <bits/stdc++.h>

using namespace std;
 
#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

vector<int>v[100005];
int n, c, arr[100005], vis[100005];
int coun = 0;

void dfs(int node, int prev, int cats)
{
	if(arr[node] == 0) cats = 0;
	else cats++;
	if(cats > c) return;
	
	vis[node] = 1;
	int len = v[node].size();
	if(len == 1 && v[node][0] == prev) {coun++;return;}
	for(int i = 0; i < len ; i++)
	{
		int new_node = v[node][i];
		if(!vis[new_node]) dfs(new_node, node, cats);
	}
}

int main()
{   
    cin >> n >> c;
    for(int i = 1;i <= n; i++) cin >> arr[i];
    for(int i = 1;i <= n-1; i++)
    {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}	
	dfs(1,0,0);
	cout << coun << endl;
	return 0;
}
