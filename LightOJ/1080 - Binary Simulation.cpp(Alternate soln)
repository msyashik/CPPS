#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define MX 100005

//
int tree[4*MX];
int ans = 0;

void update(int node, int tl, int tr, int i, int j)
{
	if(tr < i || tl > j) return;
	else if(tl >= i && tr <= j)
	{
		tree[node]++;
		return;
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr)/2;
	update(left,tl,mid,i,j);
	update(right,mid+1,tr,i,j);
}

void query(int node, int tl, int tr, int indx, int carry)
{
	if(tr < indx || tl > indx) return;
	if(tl == tr)
	{
		 ans = carry+tree[node];
	    // cout << ans  << endl;
	     return;	
	}
	int left = node*2;
	int right = (node*2) + 1;
	int mid = (tl+tr)/2;
	query(left,tl,mid,indx,carry+tree[node]);
	query(right,mid+1,tr,indx,carry+tree[node]);
	
}
int main()
{
	int t, q, n;
	char ch[100005];
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%s",ch);
		n = strlen(ch);
		scanf("%d", &q);
		printf("Case %d:\n", kase);
		for(int i = 1;i <= q; i++)
		{
			char s[2];
			scanf("%s",s);
			if(s[0] == 'I')
			{
				int a,b;
				scanf("%d %d",&a,&b);
				update(1,1,n,a,b);
			}
			else
			{
				int a;
				scanf("%d", &a);
				ans = 0;
				query(1,1,n,a,0);
				if(ans%2)
				{
					if(ch[a-1] == '0') printf("1\n");
					else printf("0\n");
				}
				else printf("%c\n",ch[a-1]);
			}
		}
		for(int i = 1; i <= 4*n; i++)
		{
			tree[i] = 0;
		}
	}
	return 0;
}
