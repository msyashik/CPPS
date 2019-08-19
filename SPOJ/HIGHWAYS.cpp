#include <bits/stdc++.h>
 
using namespace std;
 
int distt[100005];
 
struct edge
{
	int v;
	int w;
};

bool operator <(struct edge a, struct edge b) {
	return a.w < b.w;
}
 
int main()
{
	int t,start,end;
	
	scanf("%d", &t);
	while(t--)
	{
			
	int d, n, e, a,b;
	
	scanf("%d %d %d %d", &n , &e, &start, &end);
	
	vector<edge>v[n+1];
	priority_queue<edge>pq; 
	
	for(int i = 1; i <= e; i++)
	{
		scanf("%d %d %d", &a, &b, &d);
		
		v[a].push_back({b,d});
		v[b].push_back({a,d});
	}
	
	for(int i = 1; i <= n; i++)
	{
		distt[i] = 100000000;
		//v[i].clear();
	}
	
	distt[start] = 0;
	pq.push({start,0});
    
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
			}
		}
	}	
	
	if(distt[end] == 100000000) printf("NONE\n");
	else printf("%d\n",distt[end]);
	
    }
	return 0;
}
