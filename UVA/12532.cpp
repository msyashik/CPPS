#include <bits/stdc++.h>

using namespace std;

#define ll int  
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 100005

ll arr[SIZE];
ll tree[3*SIZE];

void init(ll node, ll b, ll e)
{
	//base
	
	if(b == e)
	{
		tree[node] = arr[b];
		return;
	}
	
	ll left = 2*node;
	ll right = (2*node) + 1;
	ll mid = (b+e)/2;
	
	init(left,b,mid);
	init(right,mid+1,e);
	
	tree[node] = (tree[left] * tree[right]);
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
	if(i > e || j < b) return 1;
	if(b >= i && e <= j) return tree[node];
	
	ll left = node*2; 
	ll right = (node*2) + 1;
	ll mid = (b+e)/2;
	
	ll p1 = query(left,b,mid,i,j);
	ll p2 = query(right,mid+1,e,i,j);
	
	return p1*p2;
}


void update(ll node, ll b, ll e, ll i, ll newvalue)
{
	if(i > e || i < b) return;
	if(b == e)
	{
		tree[node] = newvalue;
		return;
	}
	
	ll left = node*2;
	ll right = (node*2) + 1;
	ll mid = (b+e)/2;
	
	update(left, b, mid, i, newvalue);
	update(right, mid+1,e,i,newvalue);
	
	tree[node] = (tree[left] * tree[right]);
}
int main()
{	
	ll n,k,a,b;
	char ch[5];
	
	while(scanf("%d %d", &n, &k) == 2)
	{
		for(int i = 1; i <= n; i++) 
		{
		    scanf("%d", &arr[i]);
		    if(arr[i] < 0) arr[i] = -1;
		    else if(arr[i] > 0) arr[i] = 1;
		}
		
		init(1,1,n);
		
		while(k--)
		{
			scanf("%s", ch);
			scanf("%d %d",&a, &b);
			
			if(ch[0] == 'C')
			{
				if(b > 0) b = 1;
				else if(b < 0) b = -1;
				update(1,1,n,a,b);
			}
			else
			{
				ll ans = query(1,1,n,a,b);
				if(ans == 0) printf("0");
				else if(ans > 0) printf("+");
				else printf("-");
			}
		}
		printf("\n");
	}
	
	return 0;
}
