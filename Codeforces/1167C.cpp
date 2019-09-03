#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

vector<int>v[500005], pos;
bool visited[500005];
int coun = 0;
int arr[500005];

void dfs(int node)
{
	coun++;
	pos.push_back(node);
	visited[node] = 1;
	int len = v[node].size();
	
	for(int i = 0; i < len; i++)
	{
		int nodd = v[node][i];
		if(visited[nodd] == 0)
		{
			dfs(nodd);
		}
	}
	return;
}

int main()
{
    int n, e,b,c,a;
    
    cin >> n >> e;
    
    for(int i = 1; i <= e; i++)
    {
		cin >> a;
		if(a != 0)
		{
			cin >> b;
			for(int j = 2; j <= a; j++)
			{
				cin >> c;
				v[b].push_back(c);
				v[c].push_back(b);
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(visited[i] == 0)
		{
			coun = 0; 
			dfs(i);
			
			int len = pos.size();
			for(int j =0 ;j < len; j++)
			{
			    arr[pos[j]] = coun;	
			}
			pos.clear();
		}
	}
	
	
	for(int i = 1; i <= n; i++) cout << arr[i] << " ";
	cout << endl;
    
    return 0;	
}
