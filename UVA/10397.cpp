#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int parent[100005], siz[100005];

//DSU
double sum = 0;

void make_set(int v)
{
	parent[v] = v;
	siz[v] = 1;
}

int find_set(int v)
{
	if(v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b, double cost)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
		sum += cost;
		if(siz[a] < siz[b]) swap(a,b);
		parent[b] = a;
		siz[a] += siz[b];
	}
}
//DSU

int main()
{	
	int n, a[1000], b[1000], m;
	
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			parent[i] = i;
			siz[i] = 1;
			scanf("%d %d", &a[i], &b[i]);
		}
		scanf("%d", &m);
		int p, q;
		for(int i = 1; i <= m;i++)
		{
			scanf("%d %d", &p, &q);
			union_sets(p,q, 0);
		}
		vector<pair<double, pair<int,int>>>v;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i != j)
				{
					double dis = sqrt(abs(a[i]-a[j])*abs(a[i]-a[j])*1.0  + abs(b[i]-b[j])*abs(b[i]-b[j])*1.0);
					v.push_back({dis,{i,j}});
				}
			}
		}
		sort(v.begin(), v.end());
		int len = v. size();
		sum = 0;
		for(int i = 0; i < len; i++)
		{
			int n1 = v[i].second.first;
			int n2 = v[i].second.second;
			union_sets(n1,n2, v[i].first);
		}
		printf("%.2lf\n", sum);
		v.clear();
	}
}

