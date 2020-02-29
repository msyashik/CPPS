#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define MX 100005

//

int arr[MX];
int tree[4*MX], tree2[4*MX];

void build1(int node, int tl, int tr)
{
	if(tl == tr)
	{
		tree[node] = arr[tl];
		return;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid  = (tl+tr)/2;
	build1(left, tl, mid);
	build1(right, mid+1,tr);
	tree[node] = max(tree[left],tree[right]);
	return;
}

void build2(int node, int tl, int tr)
{
	if(tl == tr)
	{
		tree2[node] = arr[tl];
		return;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid  = (tl+tr)/2;
	build2(left, tl, mid);
	build2(right, mid+1,tr);
	tree2[node] = min(tree2[left],tree2[right]);
	return;
}

int query(int node, int tl, int tr, int i, int j)
{
	if(j < tl ||  i > tr) return 0;
	else if(tl >= i  && j >= tr) return tree[node];
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr) / 2;
	int p1 = query(left, tl, mid, i, j);
	int p2 = query(right, mid+1, tr, i, j);
	return max(p1,p2);
}

int query2(int node, int tl, int tr, int i, int j)
{
	if(j < tl ||  i > tr) return INT_MAX;
	else if(tl >= i  && j >= tr) return tree2[node];
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr) / 2;
	int p1 = query2(left, tl, mid, i, j);
	int p2 = query2(right, mid+1, tr, i, j);
	return min(p1,p2);
}

int main()
{
	int t, n, d;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d", &n, &d);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}
		build1(1,1,n);
		build2(1,1,n);
		int a,b,ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i+(d-1) > n) 
			{
				a = query(1,1,n,i,n);
				b = query2(1,1,n,i,n);
				ans = max(ans,abs(a-b));
			    break;
		    }
			a = query(1,1,n,i,i+(d-1));
			b = query2(1,1,n,i,i+(d-1));
			ans = max(ans,abs(a-b));
		}
		printf("Case %d: %d\n",kase,ans);
	}
	return 0;
}
