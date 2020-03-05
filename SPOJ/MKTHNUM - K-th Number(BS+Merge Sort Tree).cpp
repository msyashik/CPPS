#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define MX 100005

int arr[MX];
struct  info
{
	vector<int>v;
}tree[4*MX];

void func(int node, int fl, int fr, int sl, int sr)
{
	int pos = 1, left = fl;
	int brr[MX];
	while(1)
	{
		if(fl > fr) 
		{
			for(int i = sl; i <= sr; i++)
			{
				brr[pos] = arr[i];
				pos++;
				sl++;
			}
		}
		else if(sl > sr)
		{
			for(int i = fl; i <= fr; i++)
			{
				brr[pos] = arr[i];
				pos++;
				fl++; 
			}
		}
		else
		{
			if(arr[fl] < arr[sl])
			{
				brr[pos] = arr[fl];
				pos++;
				fl++;
			}
			else 
			{
				brr[pos] = arr[sl];
				pos++;
				sl++;
			}
		}
		if(fl > fr && sl > sr) break;
	}
	for(int i = 1; i < pos; i++)
	{
		arr[left] = brr[i];
		left++;
		tree[node].v.push_back(brr[i]);
	}
}
void merge(int node, int tl, int tr)
{
	if(tl == tr)
	{
		tree[node].v.push_back(arr[tl]);
		return;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr) / 2;
	merge(left,tl,mid);
	merge(right,mid+1,tr);
	func(node,tl,mid,mid+1,tr);
}

int query(int node, int tl, int tr, int i, int j, int x)
{
	if(tr < i || tl > j) return 0;
	else if(tl >= i && j >= tr)
	{
		int ans = upper_bound(tree[node].v.begin(), tree[node].v.end(), x) - tree[node].v.begin();
		return ans;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr) / 2;
	int ans1 = query(left,tl,mid,i,j,x);
	int ans2 = query(right,mid+1,tr,i,j,x);
	return ans1+ans2;
}
int main()
{
	int n, q;
	
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	merge(1,1,n);
	
	for(int i = 1; i <= q; i++)
	{
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);
		int lo = 1, hi = n;
		int x;
		while(lo < hi)
		{
			x = (lo+hi) / 2;
			int total = query(1,1,n,a,b,arr[x]);
			//cout << x << " " << total << endl;
			if(total >= k) hi = x;
			else lo = x + 1;
		}
		printf("%d\n",arr[hi]);
	}
	
	
	
	
	/*for(int i = 1; i <= 13; i++)
	{
		int len = tree[i].v.size();
		cout << "Node " << i << ": ";
		for(int j = 0;j < len ;j++)
		{
			cout << tree[i].v[j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}
