#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main()
{
	//IOS
	ll n, m,k, arr[200005], brr[200005];
	map<ll,ll>mp;
	
	scanf("%lld %lld %lld", &n, &m, &k);	
	for(int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
	for(int i = 1; i <= n; i++) brr[i] = arr[i];
	sort(arr+1, arr+n+1, greater<ll>());
	ll sum = 0;
	//for(int i = 1; i <= n; i++) cout<< arr[i] << " ";
	//cout << endl;
	for(int i = 1; i <= k*m; i++) {sum += arr[i];mp[arr[i]]++;}
	printf("%lld\n", sum);
    
   // for(auto it : mp) cout << it.first << " " << it.second << endl;
    
    vector<int>v;
    int coun = 0;
    for(int i = 1; i <= n; i++)
    {
		if((int)v.size() == k-1) break;
		if(coun == m)
		{
			if(mp[brr[i]] <= 0) continue;
			else
			{
				v.push_back(i-1);
				coun = 0;
				i--;
			}
		}
		else if(mp[brr[i]] > 0)
		{
			coun++;
			mp[brr[i]]--;
		}
	}
	int len = v.size();
	for(int i = 0; i < len; i++) printf("%d ", v[i]);
    
	return 0;
}
