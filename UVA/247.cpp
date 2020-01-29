#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int parent[105], siz[105], vis[30], flag = 0;
int n, m;
string ch, bh;
map<string,int>mp;
vector<int>v[30];
	
int find_set(int vr)
{
	if(vr == parent[vr]) return vr;
	return parent[vr] = find_set(parent[vr]);
}
void union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b)
	{
		if(siz[a] < siz[b]) swap(a,b);
		parent[b] = a;
		siz[a] += siz[b];
	}
}
void dfs(int a, int b)
{
	vis[a] = 1;
	if(a == b) {flag = 1;return;}
	int len = v[a].size();
	for(int i = 0; i < len; i++)
	{
		int node = v[a][i];
		if(!vis[node]) dfs(node,b);
    }
    return;
}
int main()
{	
	int kase = 1;
	while(scanf("%d %d", &n, &m) == 2)
	{
		map<int,string>mp3;
		if(n == 0 && m == 0) break;
		int man = 1;
	    while(m--)
	    {
		   cin >> ch >> bh;
		   if(mp.count(ch) == 0)
		   {
			   mp.insert({ch,man});
			   mp3.insert({man,ch});
			   man++;
		   }
		   if(mp.count(bh) == 0)
		   {
			   mp.insert({bh,man});
			   mp3.insert({man,bh});
			   man++;
		   }
		   
		   int a = mp[ch];
		   int b = mp[bh];
		   v[a].push_back(b);
	    }
	    for(int i = 1; i <= n; i++)
	    {
			parent[i] = i;
			siz[i] = 1;
		}
	    for(int i = 1; i <= n; i++)
	    {
			for(int j = 1; j <= n; j++)
			{
				int coun = 0;
				if(i != j)
				{
					flag = 0;
					memset(vis,0,sizeof(vis));
				    dfs(i,j);
				    if(flag == 1) coun++;	
				    flag = 0;
				    memset(vis,0,sizeof(vis));
				    dfs(j,i);
				    if(flag == 1) coun++;
				    if(coun == 2) union_sets(i,j);
				}
			}
		}
		map<int,int>mpp;
		vector<int>vec[30];
		for(int i = 1; i <= n; i++)
		{
			int par = find_set(i);
			vec[par].push_back(i);
			mpp[par]++;
		}
		if(kase != 1) printf("\n");
		printf("Calling circles for data set %d:\n", kase);
		kase++;
		for(auto it : mpp)
		{
			int node = it.first;
			int len2 = vec[node].size();
			for(int j = 0; j < len2-1; j++)
			{
				cout << mp3[vec[node][j]] << ", ";
			}
			cout << mp3[vec[node][len2-1]] << endl;
		}
		for(int i = 1; i <= n; i++) {v[i].clear();vec[i].clear();}
		mp.clear();
	}
	return 0;
}
