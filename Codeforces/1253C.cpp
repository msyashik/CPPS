#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100005
 
ll n,k,a[200005],pre[200005]; 
 
int main()
{	
	cin >> n >> k;
	for(int i = 1; i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1; i <= k;i++) pre[i] = a[i];
	for(int i =k+1; i <= n; i++)
	{
		pre[i] = a[i] + pre[i-k];
	} 
	ll sum = 0;
	int coun = 0,gun = 1;
	for(int i = n; i >= 1; i--)
	{
		if(coun == k)
		{
			coun = 1;
			gun++;
			sum += a[i]*gun;
		}
		else {sum += (a[i]*gun);coun++;}
	}
	vector<ll>v;
	v.push_back(sum);
	sum -= a[n];
	for(ll i = n-1; i >= 1; i--)
	{
		if((i-(k-1)) > 0) sum -= pre[i-k+1];
		v.push_back(sum);
		sum-=a[i];
	}
	reverse(v.begin(),v.end());
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
    return 0;
}
