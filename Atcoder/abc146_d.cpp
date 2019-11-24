#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100005
 
vector<int>v[100005]; 
map<pair<int,int>,int>mp; 
int coun = 1;
bool vis[100005];
 
void dfs(int node, int prev)
{
	int baki = 0;
	vis[node] = 1;
	for(int i = 0; i < v[node].size(); i++)
	{
		int nodd = v[node][i];
		if(!vis[nodd]) 
		{
			baki++;
			if(baki==prev) baki++;
			if(baki > coun) baki = 1;
			mp.insert({{node,nodd},baki});
			mp.insert({{nodd,node},baki});
		    dfs(nodd, baki);
		}
	}
}
int main()
{
	int n,a[100005],b[100005],mx=0,node;
	
	cin >> n;
	for(int i =1; i <= n-1; i++)
	{
		cin >> a[i] >> b[i];
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
		if(v[a[i]].size() > mx)
		{
			mx = v[a[i]].size();
			node = a[i];
		}
		if(v[b[i]].size() > mx)
		{
			mx = v[b[i]].size();
			node = b[i];
		}
	}
//	cout << mx << endl;
	int len = v[node].size();
	for(int i = 0; i < len; i++)
	{
		int nodd = v[node][i];
		mp.insert({{node,nodd},coun});
		mp.insert({{nodd,node},coun});
		coun++;
	}
	vis[node] = 1;
	for(int i = 0; i < len; i++)
	{
		int nodd = v[node][i];
		//cout << mp[{node,nodd}] << endl;
		dfs(nodd,mp[{node,nodd}]);
	}
	cout << coun-1 << endl;
	for(int i =1; i < n; i++)
	{
		cout << mp[{a[i],b[i]}] << endl;
	}
	return 0;
}
