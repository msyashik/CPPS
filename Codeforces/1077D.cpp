#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 200005

int f[SIZE];
vector<int>v;
int n,k,a;

int check(int x)
{
	int take = 0;
	for(int i = 1; i <= 2e5; i++)
	{
		take += f[i]/x;
		if(take >= k) return 1;
	}
	return 0;
}

int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo+hi+1)/2;
		if(check(mid))
		{
			lo = mid;
		}
		else hi = mid-1;
	}
	return lo;
} 

void work(int x)
{
	int take = k;
	for(int i =1 ; i <= 2e5; i++)
	{
		int ans = min(take,f[i]/x);
		take-=ans;
		for(int j = 1; j <= ans; j++) v.push_back(i);
	}
}

int main()
{	
	IOS
    
    cin >> n >> k;
    for(int i =1 ;i <= n; i++)
    {
		cin >> a;
		f[a]++;
	}	
	int ans = binsearch(1,n/k);
	work(ans);
	for(auto it : v)
	{
		cout << it << " ";
	}
	cout << endl;
    return 0;
}
