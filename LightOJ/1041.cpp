#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

vector<pair<int,pair<int,int>>>v;
vector<int>vec[105];
int par[105];
int sum = 0;
bool visitedd[105];
int total = 0;

int find(int r)
{
	if(par[r] == r) return r;
	else return par[r] = find(par[r]);
} 

void unions2(int a, int b, int take)
{
	int u = find(a);
	int v = find(b);
	
	if(u != v)
	{
		par[v] = u;
		sum += take;
	}
}

void dfs(int node)
{
	visitedd[node] = 1;
	total++;
	
	int len = vec[node].size();
	
	for(int i = 0; i < len; i++)
	{
		int nodd = vec[node][i];
		if(!visitedd[nodd])
		{
			dfs(nodd);
		}
	}
}

int main()
{  
	unordered_map<string,int>mp;
	int t, a, b,e, cost;
	string ch,bh;
	
	scanf("%d", &t);
	
	for(int kase = 1; kase <= t; kase++)
	{
		
	scanf("%d", &e);
	
	for(int i = 1;  i <= 100; i++) 
	{
		visitedd[i] = 0;
	    par[i] = i;
	    vec[i].clear();
	}
	
	int coun = 1;
	sum = 0;
	total = 0;
	
	for(int i = 1; i <= e; i++)
	{
		cin >> ch >> bh >> cost;
		
		if(mp.count(ch) == 0)
		{
			mp.insert({ch,coun});
			coun++;
		}
		if(mp.count(bh) == 0)
		{
			mp.insert({bh,coun});
			coun++;
		}
		
		a = mp[ch];
		b = mp[bh];
		
		v.push_back(make_pair(cost, make_pair(a,b)));
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
	//
	
	/*for(int i = 0; i < v.size(); i++)
	{
		cout << v[i].second.first << " " << v[i].second.second << " " << v[i].first << endl;
	}
	*/
	//
	
	
	
	dfs(1);
	
	
	if(total != (coun-1))
	{
		printf("Case %d: Impossible\n", kase);
	}
	else
	{
	sort(v.begin(), v.end());
	
	int len = v.size();
	
	for(int i = 0; i < len; i++)
	{
		int a1 = v[i].second.first;
		int b1 = v[i].second.second;
		int k = v[i].first;
		
		unions2(a1,b1,k);
	}
	
	printf("Case %d: %d\n",kase,sum);
    }
	
	mp.clear();
	v.clear();
    }
	return 0;
}
