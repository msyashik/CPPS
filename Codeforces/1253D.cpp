#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100005
 
vector<int>v[200005],vv;
bool vis[200005];
int value = 0,mx = 0;
int arr[200005],shesh[200005];

void dfs(int node)
{
	vis[node] = 1;
	mx = max(mx,node);
	arr[node] = value;
	int len = v[node].size();
	for(int i = 0; i < len ; i++)
	{
		int child = v[node][i];
		if(!vis[child]) dfs(child);
	}
}
 
int main()
{
	int n,m,a,b;
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			mx = 0;
			value++;
			dfs(i);
			shesh[value] = mx;
		}
	}
	memset(vis,0,sizeof(vis));
	int coun = 0,ans = 0,pres,pos;
	for(int i = 1; i <= n; i++)
	{
		if(coun == 0) {vv.push_back(arr[i]);coun++;vis[arr[i]] = 1;pres = arr[i];pos = coun-1;}
		else if(vis[arr[i]] == 0)
		{
			vis[arr[i]] = 1;
			vv.push_back(arr[i]);
			coun++;
			ans++;
		}
		if(arr[i] == pres)
		{
			if(shesh[pres] > i) continue;
			int f = 0;
			for(int j = pos; j < coun; j++)
			{
				if(shesh[vv[j]] > i)
				{
					pres = vv[j];
					pos = j;
					f = 1;
					break;
				}
			}
			if(f==0)
			{
				coun = 0;
				vv.clear();
			}
		}
	}
	cout << ans << endl;
	return 0;
}

