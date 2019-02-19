//disjoint set union

#include <bits/stdc++.h>

using namespace std;

int par[100];
vector<int>vec[100];

int fr(int r)
{
	if(par[r] == r) return r;
	return par[r] = fr(par[r]);
}


void unions(int a, int b)
{
	int u = fr(a);
	int v = fr(b);
	
	if(u != v)
	{
		par[v] = u;
		vec[u].push_back(v);
		int len = vec[v].size();
		for(int i = 0; i < len; i++)
		{
			par[vec[v][i]] = u;
			vec[u].push_back(vec[v][i]);
		}
		
	}
}

int main()
{
    int n, e, a, b;
    
    cin >> n >> e;
    
    for(int i = 1; i <= n; i++) par[i] = i;
    
    for(int i = 1; i <= e; i++)
    {
		 cin >> a >> b;
		 unions(a,b);
	}
	
	for(int i = 1; i <= n; i++) cout << par[i] << "\n";
	
    return 0;	
}
