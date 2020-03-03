#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define MX 10000005

struct info
{
    int num;
}tree[MX*4];

set<int>s;

void update(int node, int tl, int tr, int i, int j, int val)
{
	if(tr < i || tl > j) return;
	else if(i <= tl && j >= tr)
	{
		tree[node].num = val;
		return;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr)/2;
	update(left,tl,mid,i,j,val);
	update(right,mid+1,tr,i,j,val);
}

void query(int node, int tl, int tr, int mx)
{
	if(tl==tr)
	{
		mx = max(mx,tree[node].num);
		if(mx > 0) s.insert(mx);
		return;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr)/2;
	query(left,tl,mid,max(mx,tree[node].num));
	query(right,mid+1,tr,max(mx,tree[node].num));
}
int main()
{
	int t, n, a[100005], b[100005];
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int val = 1;
		int rindx = 0;
		for(int i =1; i<= n; i++)
		{
			scanf("%d %d", &a[i], &b[i]);
			rindx = max(rindx,b[i]);		
		}
		for(int i = 1; i <= n; i++)
		{
			update(1,1,rindx,a[i],b[i],val);
			val++;
			//for(int i = 1; i <=31; i++) cout << tree[i].num << " ";
		}	
		query(1,1,rindx,-1);
		int ans = s.size();
		printf("%d\n",ans);
		s.clear();
		for(int i = 1; i <= 4*1e7;i++)
		{
			tree[i].num = 0;
		}
	}
	return 0;
}
