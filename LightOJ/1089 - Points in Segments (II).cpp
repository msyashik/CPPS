#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define MX 150005

//
int arr[MX];
int n;
int tree[4*MX];
int ans[4*MX];
int qq[50005], a[50005],b[50005];

void build(int node, int tl, int tr, int i, int j)
{
	if(j < tl ||  i > tr) return;
	else if(tl >= i  && j >= tr)
	{
		ans[node] += 1;
		return;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr) / 2;
	build(left, tl, mid, i, j);
	build(right, mid+1, tr, i, j);
	return;
}

int query(int node, int tl , int tr, int i)
{
	if(i < tl || i > tr) return 0;
	else if(tl==tr)
	{
		return ans[node];
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr)/2;
	int p1 = query(left,tl,mid,i);
	int p2 = query(right,mid+1,tr,i);
	return p1 + p2 + ans[node];
}

int main()
{  
	int t,q;
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d", &n, &q);
		int num = 0;
		map<int,int>mp;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d", &a[i], &b[i]);
			if(mp.count(a[i]) == 0)
			{
				mp[a[i]]++;
			}
			if(mp.count(b[i]) == 0)
			{
				mp[b[i]]++;
			}
		}
		for(int i = 1; i <= q; i++)
		{
			scanf("%d", &qq[i]);
			if(mp.count(qq[i]) == 0)
			{
				mp[qq[i]]++;
			}
		}
		for(auto it : mp)
		{
			num++;
			mp[it.first] = num;
		}
        for(int i = 1; i <= n; i++)
        {
			build(1,1,num,mp[a[i]],mp[b[i]]);
		}
		printf("Case %d:\n", kase);
		for(int i = 1; i <= q; i++)
		{
			int total = query(1,1,num,mp[qq[i]]);
			printf("%d\n",total);
		}
		memset(ans,0,sizeof(ans));
		mp.clear();
	}   
	return 0;
}
