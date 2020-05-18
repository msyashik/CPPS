#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<pair<ll,ll>>row(5005);
vector<pair<ll,ll>>col(5005);

void solve()
{
	ll n,m,k,task,r,val;
	
	cin >> n >> m >> k;
	for(ll i = 1; i <= k; i++)
	{
		cin >> task >> r >> val;
		if(task == 1)
		{
			row[r].first = val;
			row[r].second = i;
		}
		else
		{
			col[r].first = val;
			col[r].second = i;
		}
	}
	for(ll i = 1;i <= n; i++)
	{
		for(ll j = 1; j <= m;j++)
		{
			if(row[i].second > col[j].second) cout << row[i].first << " ";
			else cout << col[j] .first << " ";
		}
		cout << endl;
	}
}

int main()
{
	solve();
	return 0;
}
