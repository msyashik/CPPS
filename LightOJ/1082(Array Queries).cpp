#include <bits/stdc++.h>

#define ll long long 
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mx 100005

using namespace std;

ll arr[mx];
ll parent[3*mx];
ll ans;

void tree(ll node, ll l, ll r)
{
	if(l == r) 
	{
	    parent[node] = arr[l];
	    return;
	}
	
	else
	{
		ll left = node *2;
		ll right = (node * 2) + 1;
		
		ll mid = (l+r) / 2;
		
		tree(left, l, mid);
		tree(right, mid+1, r);
		
		parent[node] = min(parent[left] , parent[right]);
	}
}


ll query(ll node, ll l, ll r, ll i, ll j)
{
	if(r < i || l > j) return INT_MAX;
	if(l >= i && r <= j) return parent[node];
	
	ll left = node * 2;
	ll right = (node * 2) + 1;
	ll mid = (l+r)/2;
	
	ll p1 = query(left, l, mid, i, j);
	ll p2 = query(right, mid+1, r, i, j);
	
    return min(p1,p2);
}


int main()
{
	//IOS
	
    ll t, n,m,a,b;

    scanf("%lld", &t);

    for(ll i = 1; i <= t; i++)
    {
		
        scanf("%lld %lld", &n, &m);
    
        for(ll i = 1; i <= n; i++) cin >> arr[i];
    
        tree(1,1,n);
        
        printf("Case %lld:\n", i); 
        
        while(m--)
        {
			      scanf("%lld %lld", &a, &b);
			
			      ll minn = query(1,1,n,a,b);
				
			      printf("%lld\n", minn);
		    }
	}
	
	return 0;
}
