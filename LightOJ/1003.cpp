#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

map<string,int>mp;

vector<int>v[10005];
int f = 0;
int visited[10005], grey[10005],black[10005];

void dfs(int node)
{
    visited[node] = 1;
    grey[node] = 1;
    
    int len = v[node].size();
    
    for(int i =0;i < len; i++)
    {
		if(f == 1) return;
		int nodd = v[node][i];
		
		if(!visited[nodd])
		{
			dfs(nodd);
		}
		else if(visited[nodd] == 1 && grey[nodd] == 1 && black[nodd] == 0)
		{
			//cout << node << " " << nodd << endl;
			f = 1;
			return;
		}
	}
	black[node] = 1;		
}

int main()
{
	int t,m;
	string a,b;
	
	scanf("%d", &t);
	
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d", &m);
	    
	    f = 0;
		int coun = 1;
		
		while(m--)
		{
			cin >> a >> b;
			int ans1,ans2;
	        
	        if(mp.count(a) == 0)
	        {
				mp.insert({a,coun});
				ans1 = coun;
				coun++;
			}
			else ans1 = mp[a];
					
			if(mp.count(b) == 0)
			{
				mp.insert({b,coun});
				ans2 = coun;
				coun++;
			}
			else ans2 = mp[b];
			
			v[ans1].push_back(ans2);
		}
		
		for(int i = 1; i < coun; i++)
		{
			if(f == 1) break;
			if(!visited[i])
			{
				dfs(i);
			}
		}
		
		if(f == 1)
		{
			printf("Case %d: No\n",kase);	
		}
		else printf("Case %d: Yes\n",kase);	
	    
	    for(int i = 1; i < coun; i++)
		{
			visited[i] = 0;
			v[i].clear();
			grey[i] = 0;
			black[i] = 0;
		}
		
	    mp.clear();
	}
	return 0;
}
