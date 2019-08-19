#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
 
struct edge
{
	int v;
	ll w;
};

bool operator <(struct edge a, struct edge b) {
	return a.w < b.w;
}
 
 
ll distt[100005];
int path[100005];
  
void dijk(priority_queue<edge>pq, vector<edge>v[])
{	
	distt[1] = 0;
	pq.push({1,0});
    
    while(!pq.empty())
    {
		edge top = pq.top();
		int len = v[top.v].size();
		pq.pop();
		
		for(int i = 0; i < len; i++)
		{
			edge nodd = v[top.v][i];
			if((distt[top.v]+ nodd.w) < distt[nodd.v])
			{
				distt[nodd.v] = distt[top.v] + nodd.w;
				pq.push(nodd);
				path[nodd.v] = top.v;
			}
		}
	}
} 
 
int main()
{	
	int n, e, a,b;
	ll d;
	scanf("%d %d", &n , &e); 
	
	priority_queue<edge>pq;
    vector<edge>v[n+1];
	
	for(int i = 1; i <= e; i++)
	{
		scanf("%d %d %lld", &a, &b, &d);
		
		v[a].push_back({b,d});
		v[b].push_back({a,d});
	}
	for(int i = 1; i <= n; i++)
	{
		distt[i] = 1000000000000000000;
		//v[i].clear();
	}		
	
	dijk(pq, v);
	
	//cout << distt[n] << endl;
	
	if(distt[n] == 1000000000000000000)
	{
		printf("-1\n");
	}
	else
	{
	vector<int>f;
	
	f.push_back(n);
	
	int m = n;
	while(1)
	{
		if(m == 1) 
		{	
			break;
		}
		else
		{
			f.push_back(path[m]);
			m = path[m];
		}
	}
	reverse(f.begin(),f.end());
	
	for(auto it : f)
	{
		cout << it << " ";
	}
	
    }
    cout << endl;
	return 0;
}
