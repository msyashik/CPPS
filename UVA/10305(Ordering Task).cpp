//finishing and discovery time

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int visited[100];
int a, b, n, e;
vector <int> v[105];
vector< pair<int, int> > m;

int dis[105];
int fin[105];
int tim = 0;

void dfs(int p)
{
	dis[p] = tim;
	
	int len = v[p].size();
	
	visited[p] = 1;
	
	for(int i = 0; i < len; i++)
	{
		int ans = v[p][i];
		
		if(visited[ans] == 0)
		{
			tim++;
			dfs(ans);
		}
		
	}
	
	tim++;
	
	fin[p] = tim;
}


int main()
{
	//IOS
	
    
    while(1)
    {
        cin >> n >> e;
    
        if(n == 0 && e == 0) return 0;
         
         
        memset(visited, 0, sizeof(visited)); 
         
        for(int i = 1; i <= e; i++)
        {
		    cin >> a >> b;
		    v[a].push_back(b);
	    }
	
        tim = 0;
        	
        for(int i = 1; i <= n; i++)
        {
		    if(visited[i] == 0 && v[i].size() >= 1)
		    {
			    tim++;
			    dfs(i);
			    v[i].clear();
		    }
		    else v[i].clear();
	    }
	   
	   for(int j = 1; j <= n; j++)
	    {
			m.push_back(make_pair(fin[j], j));
		}
		
		sort(m.begin(), m.end());
	    
	    int lenn = m.size();
	   
	    for(int l = lenn - 1; l >= 0; l--) 
	    {
			cout << m[l].second << " ";
		}
	    
	    cout << "\n";
	    
	    m.clear();
    
    }
	return 0;
}
