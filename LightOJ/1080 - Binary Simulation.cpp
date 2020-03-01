#include <bits/stdc++.h>
 #include <string.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define MX 100005


struct info
{
	ll prop,sum;
}tree[MX*4];

void update(ll node, ll tl, ll tr, ll i, ll j)
{
	if(tr < i || tl > j) return;
	else if(i <= tl && j >= tr) 
	{
		tree[node].prop += 1;
		tree[node].sum += ((tr-tl)+1) *1LL* 1;
		return;
	}
	ll left = node*2;
	ll right = (node*2) + 1;
	ll mid = (tl+tr)/2;
	update(left,tl,mid,i,j);
	update(right,mid+1,tr,i,j);
	tree[node].sum = tree[left].sum + tree[right].sum + (tree[node].prop*1LL*((tr-tl) + 1));
	return;
}

ll query(ll node, ll tl, ll tr, ll i ,ll carry)
{
	if(tr<i || tl > i) return 0;
	else if(tl==tr && tl==i)
	{
		return tree[node].sum + (((tr-tl)+1)*1LL*carry);
	}
	ll left = node*2;
	ll right = (node*2) + 1;
	ll mid = (tl+tr)/2;
	ll p1 = query(left,tl,mid,i,carry+tree[node].prop);
	ll p2 = query(right,mid+1,tr,i,carry+tree[node].prop);
	return p1+p2;
}
int main()
{
	ll t, q, n;
	char ch[100005];
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		scanf("%s",ch);
		n = strlen(ch);
		scanf("%lld", &q);
		printf("Case %lld:\n", kase);
		for(int i = 1;i <= q; i++)
		{
			char s[2];
			scanf("%s",s);
			if(s[0] == 'I')
			{
				ll a,b;
				scanf("%lld %lld",&a,&b);
				update(1,1,n,a,b);
			}
			else
			{
				ll a;
				scanf("%lld", &a);
				ll ans = query(1,1,n,a,0);
				if(ans%2)
				{
					if(ch[a-1] == '0') printf("1\n");
					else printf("0\n");
				}
				else printf("%c\n",ch[a-1]);
			}
		}
		for(ll i = 1; i <= 4*n; i++)
		{
			tree[i].sum = 0;
			tree[i].prop = 0;
		}
	}
	return 0;
}
