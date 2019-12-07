#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 100005

int arr[SIZE];
pair<int,int>tree[3*SIZE];
int n,k;
string ch;

void init(int node, int b, int e)
{
	//base
	
	if(b == e)
	{
		tree[node].first = arr[b];
		tree[node].second = 0;
		return;
	}
	
	int left = 2*node;
	int right = (2*node) + 1;
	int mid = (b+e)/2;
	
	init(left,b,mid);
	init(right,mid+1,e);
	
	int mx1 = max(tree[left].first, tree[right].first);
	int mx2;
	if(tree[left].first == mx1)
	{
		mx2 = max(tree[left].second, max(tree[right].first,tree[right].second));
	}
	else mx2 = max(tree[right].second, max(tree[left].first,tree[left].second));
	tree[node].first = mx1;
	tree[node].second = mx2;
}

pair<int,int> query(int node, int b, int e, int i, int j)
{
	if(i > e || j < b)
	{
		pair<int,int>p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	if(b >= i && e <= j) return tree[node];
	
	int left = node*2; 
	int right = (node*2) + 1;
	int mid = (b+e)/2;
	
	pair<int,int> p1 = query(left,b,mid,i,j);
	pair<int,int> p2 = query(right,mid+1,e,i,j);
	
	int mx1 = max(p1.first, p2.first);
	int mx2;
	if(mx1==p1.first)
	{
		mx2 = max(p1.second, max(p2.first, p2.second));
	}
	else mx2 = max(p2.second,max(p1.first, p1.second));
	
	pair<int,int>ans;
	ans.first = mx1;
	ans.second = mx2;
	return ans;
	
}

void update(ll node, ll b, ll e, ll i, ll newvalue)
{
	if(i > e || i < b) return;
	if(b == e)
	{
		tree[node].first = newvalue;
		tree[node].second = 0;
		return;
	}
	
	ll left = node*2;
	ll right = (node*2) + 1;
	ll mid = (b+e)/2;
	
	update(left, b, mid, i, newvalue);
	update(right, mid+1,e,i,newvalue);
	
	int mx1 = max(tree[left].first, tree[right].first);
	int mx2;
	if(tree[left].first == mx1)
	{
		mx2 = max(tree[left].second, max(tree[right].first,tree[right].second));
	}
	else mx2 = max(tree[right].second, max(tree[left].first,tree[left].second));
	tree[node].first = mx1;
	tree[node].second = mx2;
}


int main()
{
	scanf("%d", &n);
	for(int i =1 ; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	init(1,1,n);
	scanf("%d", &k);
	/*for(int i = 1; i <= 9; i++)
	{
		cout << tree[i].first <<" " << tree[i].second << endl;
	}*/
	int a, b;
	string ch;
	while(k--)
	{
		cin >> ch;
		scanf("%d %d",&a, &b);
		if(ch == "Q")
		{
			pair<int,int> ashol = query(1,1,n,a,b);
			printf("%d\n",ashol.first+ashol.second);
		}
		else
		{
			update(1,1,n,a,b);
		}
	}
}
