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
int main()
{
	int n, q;
	
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	merge(1,1,n);
	return 0;
}
