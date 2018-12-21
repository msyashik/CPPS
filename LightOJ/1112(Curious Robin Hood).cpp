#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mx 100005
 
using namespace std;
 
ll arr[mx];
ll parent[3*mx];
ll ans, f;
 
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
       
        parent[node] = (parent[left] + parent[right]);
    }
}
 
 
ll query(ll node, ll l, ll r, ll i, ll j)
{
    if(r < i || l > j) return 0;
    if(l >= i && r <= j) return parent[node];
   
    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (l+r)/2;
   
    ll p1 = query(left, l, mid, i, j);
    ll p2 = query(right, mid+1, r, i, j);
   
    return (p1+p2);
}

void update(ll node, ll l, ll r, ll i, ll newvalue)
{
	if(r < i || l > i) return;
	if(l >= i && r <= i)
	{
		if(f == 1)
		{
		    printf("%lld\n", parent[node]);
		    parent[node] = newvalue;
		}
		else parent[node] += newvalue;
		return;
	}
	
	ll left = node * 2;
	ll right = (node*2) + 1;
	ll mid = (l+r)/2;
	
	update(left, l, mid, i, newvalue);
	update(right, mid+1, r, i, newvalue);
	
	parent[node] = parent[left] + parent[right];
} 
 
int main()
{
    ll t, n, m,a,b,c;
    
    scanf("%lld", &t);
    
    for(ll i = 1; i <= t; i++)
    {
		scanf("%lld %lld", &n, &m);
		
		for(ll i = 1; i <= n; i++) scanf("%lld", &arr[i]);
		
		tree(1,1,n);
		
		printf("Case %lld:\n", i);
		
		while(m--)
		{
			scanf("%lld", &a);
			if(a == 1)
			{
				f = 1;
				scanf("%lld", &b);
				update(1,1,n,b+1,0); 
			}
			else if(a == 2)
			{
				scanf("%lld %lld", &b, &c);
				f = 0;
				update(1,1,n,b+1,c);
			}
			else if(a == 3)
			{
				scanf("%lld %lld", &b, &c);
				
				ll ans = query(1,1,n,b+1,c+1);
				
				printf("%lld\n", ans);
			}
		}
	}
    
    return 0;
}
