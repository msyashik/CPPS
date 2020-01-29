#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int n, m, vis[105];
int languages[105][105];
int total = 0;

void dfs(int curr)
{
	vis[curr] =1;
	for(int i = 1; i <= n; i++)
	{
		if(i!=curr)
		{
		    for(int j = 1; j <= m; j++)
		    {
			    if(languages[curr][j] == 1 && languages[i][j] == 1 && vis[i] == 0) dfs(i);
		    }
		}
	}
	return; 
}
int main()
{	
	int coun = 0;
	cin >> n >> m;
	for(int j = 1; j <= n; j++)
	{
		int a;
		cin >> a;
		if(a == 0) coun++;
		for(int i = 1; i<= a; i++) 
		{
			int lang;
			cin >> lang;
			languages[j][lang] = 1;
		}
	}
	if(n == coun) 
	{
		cout << n << endl;
		return 0;
	}
	for(int i = 1; i<= n; i++)
	{
		if(!vis[i])
		{
			total++;
			dfs(i);
		}
	}
	cout << total-1 << endl;
	return 0;
}
