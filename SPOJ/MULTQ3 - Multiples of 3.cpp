#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define MX 100005

struct info
{
	int a[5];
	int prop;
}tree[MX*4];

void build(int node, int tl, int tr)
{
	if(tl == tr)
	{
		tree[node].a[0] = 1;
		return;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr) / 2;
	build(left, tl, mid);
	build(right,mid+1,tr);
	tree[node].a[0] = tree[left].a[0] + tree[right].a[0];
}

void update(int node, int tl , int tr, int i, int j)
{
	if(tr < i || j < tl) return;
	else if(i <= tl && j >= tr)
	{
		tree[node].prop++;
		int two = tree[node].a[2];
		int one = tree[node].a[1];
		int zero = tree[node].a[0];
		tree[node].a[0] = two; tree[node].a[1] = zero; tree[node].a[2] = one;
		return;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr) /2;
	update(left,tl,mid,i,j);
	update(right,mid+1,tr,i,j);
	tree[node].a[0] = tree[left].a[0] + tree[right].a[0];
	tree[node].a[1] = tree[left].a[1] + tree[right].a[1];
	tree[node].a[2] = tree[left].a[2] + tree[right].a[2];
	int val = tree[node].prop;
	int two = tree[node].a[2];
	int one = tree[node].a[1];
	int zero = tree[node].a[0];
	
	int flag = 1;
	for(int indx = 0; indx <= 2; indx++)
	{
		int ans = indx;
		ans+=val;
		ans%=3;
		if(flag == 1) 
		{
			tree[node].a[ans] = zero;
			flag++;
		}
		else if(flag == 2) 
		{
			tree[node].a[ans] = one;
			flag++;
		}
		else 
		{
			tree[node].a[ans] = two;
			flag++;
		}
	}
}

int query(int node, int tl , int tr, int i, int j, int carry)
{
	if(tr < i || j < tl) return 0;
	else if(i <= tl && j >= tr)
	{
	    int val = carry;
	    int two = tree[node].a[2];
	    int one = tree[node].a[1];
	    int zero = tree[node].a[0];
	    int a0, a1, a2;
	
	    int flag = 1;
	    for(int indx = 0; indx <= 2; indx++)
	    {
		    int ans = indx;
		    ans+=val;
		    ans%=3;
		    if(flag == 1) 
		    {
			    if(ans == 0) a0 = zero;
			    else if(ans == 1) a1 = zero;
			    else a2 = zero;
			    flag++;
		    }
		    else if(flag == 2) 
		    {
			    if(ans == 0) a0 = one;
			    else if(ans == 1) a1 = one;
			    else a2 = one;
			    flag++;
		    }
		    else 
		    {
			    if(ans == 0) a0 = two;
			    else if(ans == 1) a1 = two;
			    else a2 = two;
			    flag++;
		    }
	    }
	    return a0;	
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr) / 2;
	int p1 = query(left,tl,mid,i,j,carry+tree[node].prop);
	int p2 = query(right,mid+1,tr,i,j,carry+tree[node].prop);
	return p1+p2;
}

int main()
{	
	int n,q;
	scanf("%d %d", &n,&q);
	build(1,1,n);
	for(int j = 1; j <= q; j++)
	{
		int qu;
		scanf("%d", &qu);
		if(qu == 0)
		{
			int x,y;
			scanf("%d %d", &x, &y);
			update(1,1,n,x+1,y+1);
		}
		else
		{
			int x,y;
			scanf("%d %d", &x, &y);
			int ash = query(1,1,n,x+1,y+1,0);
			printf("%d\n", ash);
		}
	}
	return 0;
}
