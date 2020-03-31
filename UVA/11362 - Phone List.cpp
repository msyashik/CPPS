#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define LIM 100005

int idx = 0;
int trie[LIM][12];      /// trie[u][d] u theke d hoye zei node e zawa zai
int flag[LIM],coun[LIM];

void add(string s)
{
	int u = 0;
	int len = s.size();
	for(int i = 0; i < len ;i++)
	{
		int d = s[i] - '0';
		if(!trie[u][d])
		{
			trie[u][d] = ++idx;
		}
		u = trie[u][d];
		coun[u]++;
	}
	flag[u] = 1;
}

/*bool query(string s)
{
	int u = 0;
	int len = s.size();
	for(int i = 0; i < len;i++)
	{
		int d = s[i] - '0';
		if(!trie[u][d]) return false;
		u = trie[u][d];
	}
	if(flag[u]) return true;
	return false;
}*/

bool dfs(int u)
{
	if(flag[u] && coun[u] > 1) return false;
	for(int d = 0; d <= 9; d++)
	{
		int v = trie[u][d];
		if(v && !dfs(v)) return false; 
	}
	return true;
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
		bool ans = dfs(0);
		//printf("Case %d: ",kase);
		if(!ans) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

