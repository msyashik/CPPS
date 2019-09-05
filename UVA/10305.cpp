#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

vector<int>v[105];

int main()
{
	while(1)
	{
	
    int a,b,n,m;
    queue<int>q;
    unordered_map<int,int>mp;
    
    cin >> n >> m;
    
    if(n == 0 && m == 0) return 0;
    
    for(int i = 1; i <= n; i++) 
    {
		mp.insert({i,0});
		v[i].clear();
	}
    
    for(int i = 1; i <= m; i++)
    {
		cin >> a >> b;
		v[a].push_back(b);
		mp[b]++;
	} 
    
    
    for(int i = 1; i <= n; i++)
    {
		if(mp[i] == 0) q.push(i);
	}
         
   vector<int>vec;     
         
    while(!q.empty())
    {
		int top = q.front();
		vec.push_back(top);
		q.pop();
		
		int len = v[top].size();
		
		for(int i = 0; i < len; i++)
		{
			int ans = v[top][i];
			
			mp[ans] -= 1;
			
			if(mp[ans] == 0) q.push(ans);
		}
		
	}  
	
	int len = vec.size();
	
	if(len > 0)
	{
		cout << vec[0];
		for(int i = 1;i < len; i++)
		{
			cout  << " " << vec[i];
		}
		cout << endl;
	}
	mp.clear();
	vec.clear();
 }
	return 0;
}
