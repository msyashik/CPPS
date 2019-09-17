#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

ll n,m,arr[200005],a,b;
vector<ll>v[200005];
map<ll,ll>mp1,mp2;

int main()
{
	Fastest
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) 
    {
        cin >> arr[i];
        mp1[arr[i]]++;
	}
    for(int i = 1; i<= m; i++)
    {
		cin >> a >> b;
		
		if(arr[a]==arr[b]) continue;
		
		if(arr[a] > arr[b])
		{
			v[a].push_back(b);
		}
		else v[b].push_back(a);
	}
    
    ll sum = 0;
    
    for(auto it : mp1)
    {
		sum += it.second;
		mp2[it.first] = sum;
	}
    
    for(int i = 1; i <= n; i++)
    {
		ll ans = mp2[arr[i]]-mp1[arr[i]];
		if(ans == 0) cout << 0 << " ";
		else
		{
		    ans -= v[i].size();
		    cout << ans << " ";	 
		}
	}
    cout << endl;	
	return 0;
}
