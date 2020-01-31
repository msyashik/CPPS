#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

vector<int>v[105];
bool vis[105];

void dfs(int node)
{
	vis[node] = 1;
	int len = v[node].size();
	for(int i = 0; i < len; i++)
	{
		int child = v[node][i];
		if(!vis[child]) dfs(child);
	}
}

int main()
{
	int test;
	string ch,bh;
	
	cin >> test;
	int f = 1;
	while(test--)
	{
	    cin>>ch;
	    getchar();
	    int t = (int)(ch[0] - 'A') + 1;
	    while(1)
	    {
			getline(cin,bh);
			if(bh.size() == 0) break;
			int a = (int)(bh[0] - 'A') + 1;
			int b = (int)(bh[1] - 'A') + 1;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int coun = 0;
		for(int i = 1; i <= t; i++)
		{
			if(!vis[i])
			{
				coun++;
				dfs(i);
			}
		}
		if(f != 1) cout << endl;
		cout << coun << endl;
		f++;
		for(int i = 1; i <= t; i++)
		{
			vis[i] = 0;
			v[i].clear();
		}
	}
	return 0;
}
