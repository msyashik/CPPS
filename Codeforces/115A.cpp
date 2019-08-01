#include <bits/stdc++.h>

using namespace std;

int n, arr[2005],par[2005];
int coun = 0;

void dfs(int p)
{
	//cout << p << " ";
	coun++;
	if(par[p] != -1)
	{
		dfs(par[p]);
	}
	return;
}
int main()
{	int goun = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		par[i] = arr[i];
		if(par[i] == -1) goun++;
	}
	
	int ans = 0;
	
	if(n == 1 || goun == n) 
	{
		cout << 1 << endl;
		return 0;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(par[i] != -1)
		{
			coun = 0;
			dfs(i);
			ans = max(ans,coun);
			//cout << endl;
		}
	}
	cout << ans << endl;
	
	return 0;
}
