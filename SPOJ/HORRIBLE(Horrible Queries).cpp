#include <bits/stdc++.h>


#define ll long long int
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mx  4000001 


using namespace std;

ll arr[mx];
struct info {
    ll prop, sum;
} tree[mx * 4];

void abc(ll node, ll l, ll r)
{
	if(l == r) 
	{
	    tree[node].sum = arr[l];
	    tree[node].prop = 0;
	    return;
	}
	
	else
	{
		ll left = node *2;
		ll right = (node * 2) + 1;
		
		ll mid = (l+r) / 2;
		
		abc(left, l, mid);
		abc(right, mid+1, r);
		
		tree[node].sum = tree[left].sum + tree[right].sum;
	}
}

ll query(ll node, ll b, ll e, ll i, ll j, ll carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return (tree[node].sum) + (carry * (e - b + 1)); 

    ll Left = node << 1;
    ll Right = (node << 1) + 1;
    ll mid = (b + e) >> 1;

    ll p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}


void update(ll node, ll b, ll e, ll i, ll j, ll x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) 
    {
        tree[node].sum += ((e - b + 1) * x); 
        tree[node].prop += x; 
        return;
    }
    ll Left = node * 2;
    ll Right = (node * 2) + 1;
    ll mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = (tree[Left].sum + tree[Right].sum + ((e - b + 1) * tree[node].prop));
}


int main()
{
	
	//freopen("milk2.in", "r", stdin);
	//freopen("milk2.out", "w", stdout);
	
	
	ll t, n, m, a, b, c, d, e,f;
	
	scanf("%lld", &t);
	
	for(ll i = 1; i <= t; i++) 
	
	{	
		scanf("%lld %lld", &n, &m);
		
		for(ll p = 1; p <= n; p++)arr[p] = 0;
		
		for(ll q = 1; q <= 4*n; q++)
		{
			tree[q].sum = 0;
			tree[q].prop = 0;
		}
		
		abc(1,1,n);
		
		for(ll j = 1; j <= m; j++)
		{
			scanf("%lld", &a);
			
			if(a == 0) 
			{
				scanf("%lld %lld %lld", &b, &c, &d);
				update(1,1,n,b,c,d);
			}
			else if(a == 1)
			{
				scanf("%lld %lld", &e, &f);
				
				ll ans = query(1,1,n,e,f);
				
				printf("%lld\n", ans);
			}
		}
	}
	
	return 0;
}
