#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define LIM 1000005

int idx = 0;
int trie[LIM][30];     
int flag[LIM],coun[LIM];

void add(string s)
{
	int u = 0;
	int len = s.size();
	for(int i = 0; i < len ;i++)
	{
		int d = s[i] - 'a';
		if(!trie[u][d])
		{
			trie[u][d] = ++idx;
		}
		u = trie[u][d];
		coun[u]++;
	}
	flag[u] = 1;
}

int dfs(int u,  int c)
{
	if(coun[u]  == 1) return c;
	int ans = 0;
	for(int d = 0; d <= 26; d++)
	{
		int v = trie[u][d];
		if(v)
		{
			ans += dfs(v,c+1);
		} 
	}
	return ans;
}

int main()
{
	int t, n;
	string ch;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
	    idx = 0;
	    memset(trie,0,sizeof(trie));
	    memset(flag,0,sizeof(flag));
	    memset(coun,0,sizeof(coun));
	    scanf("%d",&n);
	    for(int i = 1; i  <= n; i++)
	    {
			cin >> ch;
			add(ch);
		}	
		int ans = dfs(0,0);
		cout << ans << endl;
		
	}
	return 0;
}
