#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll arr[200005];

void solve()
{
    ll n,s,sum = 0;
    
    cin >> n >> s;
    for(ll i = 1;i <= n ;i++)
    {
		cin >> arr[i];
		sum+=arr[i];
	}
	if(n == 1)
	{
		cout << arr[1]-1 << endl;
		return;
	}	
	else
	{
		for(ll i = 1;i <= n; i++)
		{
			ll mn = s - (n-1);
			if(arr[i] >= mn) 
			{
				ll mx = arr[i]-mn;
				ll curr = s - (sum-arr[i]);
				if(curr <= 0)
				{
					cout << mx << " ";
				}
				else
				{
					cout << (curr-1) + mx<< " ";
				}
			}
			else
			{
				ll curr = s - (sum-arr[i]);
				if(curr <= 0)
				{
					cout << 0 << " ";
				}
				else
				{
					cout << curr-1 << " ";
				}
			}
		}
	}
}

int main()
{
	IOS
	solve();
	return 0;
}
