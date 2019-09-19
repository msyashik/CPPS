#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

ll n,arr[105];
unordered_map<ll,ll>mp,mp2;
bool visited[105];
vector<ll>v[105];
int n_coun = 0;
int f = 0;

void dfs(int node)
{
	if(f == 1) cout << mp2[node] << " ";
	visited[node] = 1;
	n_coun++;
	
	ll len = v[node].size();
	for(int i =0; i < len; i++)
	{
		ll nodd = v[node][i];
		if(!visited[nodd])
		{
			dfs(nodd);
		}
	}
}

int main()
{
	int coun = 1;
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if(mp.count(arr[i]) == 0)
		{
			mp.insert({arr[i],coun});
			mp2.insert({coun,arr[i]});
			coun++;
		}
	}
	
	/*for(auto it : mp)
	{
		cout << it.first << " " << it.second << endl;
	}*/
	
	for(int i = 1; i <= n; i++)
	{
		if(mp.count(arr[i]*2))
		{
			int u = mp[arr[i]];
			int w = mp[arr[i]*2];
			v[u].push_back(w);
		}
		if(arr[i]%3 == 0 && mp.count(arr[i]/3))
		{
			int u = mp[arr[i]];
			int w = mp[arr[i]/3];
			v[u].push_back(w);
		}
		
	}
	
	/*for(int i = 1; i < coun; i++)
	{
		cout << i << ": ";
		int len = v[i].size();
		for(int j = 0; j < len; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}*/
	
	ll ashol_purush;
	
	for(int i = 1; i <= coun; i++)
	{
		memset(visited,0,sizeof(visited));
		n_coun = 0;
		
		dfs(i);
		if(n_coun == n)
		{
			ashol_purush =  i;
			f = 1;
			break;
		}
	}
	
	memset(visited,0,sizeof(visited));
	dfs(ashol_purush);
	
	return 0;
}
