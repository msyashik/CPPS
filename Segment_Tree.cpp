//Segment Tree
//From Shafayets Planet

#include <bits/stdc++.h>

#define ll long long 
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mx 100005

using namespace std;

ll arr[mx];
ll parent[3*mx];

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
		
	    parent[node] = parent[left] + parent[right];
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
	
	return p1+p2;
}

void update(ll node, ll l, ll r, ll i, ll newvalue)
{
	if(r < i || l > i) return;
	if(l >= i && r <= i)
	{
	    parent[node] = newvalue;
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
    IOS
	
    ll n;

    cin >> n;
    
    for(ll i = 1; i <= n; i++) cin >> arr[i];
    
    tree(1,1,n);
    
    cout << query(1,1,n,1,5) << "\n";
    
    update(1,1,n,4,10);
	
    cout << query(1,1,n,1,5) << "\n";
	
    return 0;
}

/*
 Tested Problems:
  
  LightOJ 1082
      
  
 */ 
