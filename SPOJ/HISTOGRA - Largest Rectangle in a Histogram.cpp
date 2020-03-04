#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define MX 100005
#define endl '\n'

struct info
{
	int val,indx;
}tree[4*MX];
ll n, arr[MX], mn = INT_MAX, num;

void build(ll node, ll tl, ll tr)
{
	if(tl == tr)
	{
		tree[node].val = arr[tl];
		tree[node].indx = tl;
		return;
	}
	ll left = node*2;
	ll right = (node*2) + 1;
	ll mid = (tl+tr) / 2;
	build(left,tl,mid);
	build(right,mid+1,tr);
	if(tree[left].val < tree[right].val)
	{
		tree[node].val = tree[left].val;
		tree[node].indx = tree[left].indx;
	}
	else
	{
		tree[node].val = tree[right].val;
		tree[node].indx = tree[right].indx;
	}
}

void query(ll node, ll tl , ll tr, ll i, ll j)
{
	if(tr < i || tl > j) return;
	else if(tl >= i && j >= tr)
	{
	    if(tree[node].val < mn)
	    {
			mn = tree[node].val;
			num = tree[node].indx;
		}	
		return;
	}
	ll left = node*2;
	ll right = (node*2) + 1;
	ll mid = (tl+tr) / 2;
	query(left,tl,mid,i,j);
	query(right,mid+1,tr,i,j);
}

ll func(ll tl, ll tr)
{
	if(tl > tr) return 0;
	else if(tl == tr) return arr[tl];
	else
	{
		mn = INT_MAX;
		query(1,1,n,tl,tr);
		ll ans1 = (tr-tl + 1) * mn;
		ll ans2 = func(tl,num-1);
		ll ans3 = func(num+1,tr);
		return max(ans1,max(ans2,ans3));
	}
}
int main()
{
    while(scanf("%lld", &n) == 1)
    {
    if(n == 0) return 0;
    else
    {
		for(ll i = 1; i <= n; i++)
		{
			scanf("%lld", &arr[i]);
		}
		build(1,1,n);
	    ll ans = func(1,n);
	    printf("%lld\n", ans);
	}	
}
	return 0;
}
