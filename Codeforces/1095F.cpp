#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Fastest ios_base:: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

ll arr[200005], par[200005];
vector<pair<ll, pair<ll,ll>>>v;
ll sum = 0;

ll func(ll r)
{
	if(par[r] == r) return r;
	return par[r] = func(par[r]);
}

void uniono(ll a, ll b, ll take)
{
	a = func(a);
	b = func(b);
	
	if(a != b)
	{
		par[b] = a;
		sum += take;
	}
}

int main()
{
    ll n, m,a,b,cost;
    
    cin >> n >> m;
    
    ll mn = 1000000000000000000;
    ll pos;
    
    for(ll i = 1; i <= n; i++)
    {
		cin >> arr[i];
		if(arr[i] < mn)
		{
			mn = arr[i];
			pos = i;
		}
	}
    
    for(ll i = 1; i <= n; i++)
    {
		par[i] = i;
		if(i != pos)
		{
			v.push_back(make_pair(arr[i]+arr[pos], make_pair(i,pos)));
		}
	}     
     
    for(ll i = 1; i <= m; i++)
    {
		cin >> a >> b >> cost;
		v.push_back(make_pair(cost, make_pair(a,b)));
	}
     
    sort(v.begin(), v.end()); 
    
    for(auto it : v)
    {
		ll node1 = it.second.first;
		ll node2 =  it.second.second;
		ll take = it.first;
		
		uniono(node1,node2,take);
	}    
    
    
    cout << sum << endl;    
    return 0;	
}
