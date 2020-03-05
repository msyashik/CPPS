#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define MX 150005
#define endl '\n'

struct info
{
	int sum;
}tree[MX*4];
int arr[MX],coun = 0, total = 0;

void build(int node, int tl , int tr)
{
	if(tl == tr)
	{
		tree[node].sum = 1;
		return;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr) / 2;
	build(left,tl,mid);
	build(right,mid+1,tr);
	tree[node].sum = tree[left].sum + tree[right].sum; 
}

void query(int node, int tl ,int tr, int i)
{
	if(tl == tr)
	{
		
		printf("%d\n", arr[tl]);
		tree[node].sum = 0;
		return;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr) / 2;
	int lans = tree[left].sum;
	if(lans >= i)
	{
		query(left,tl,mid,i);
	}
	else
	{
		query(right,mid+1,tr,i-lans);
	}
	tree[node].sum = tree[left].sum + tree[right].sum;
}

int main()
{
	int t, n, q;
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
	    scanf("%d %d", &n, &q);
	    total = 0, coun = 0;
	    for(int i = 1; i <= n; i++)
	    {
		    scanf("%d", &arr[i]);
		    coun++;
		    total++;
	    }
	    build(1,1,150000);
		getchar();
		char c;
		printf("Case %d:\n", kase);
		for(int i = 1; i <= q; i++)
		{
			int num;
			scanf("%c %d", &c,&num);
			getchar();
			if(c == 'c')
			{
				if(total < num) printf("none\n");
				else
				{
				    total--;
				    query(1,1,150000,num);
				}
			}
			else
			{
				total++;
				coun++;
				arr[coun] = num;
			}
		}
	}
	    return 0;
}
