#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll n,arr[60],brr[60],crr[60];
string a,b,c;

void solve()
{	
	cin >> n >> a >> b >> c;
		ll len = a.size();
		ll mx1 = 0, mx2 = 0,mx3 = 0;
		for(ll i = 0;i< len;i++)
		{
			ll curr;
			if(a[i] >= 'a' && a[i] <= 'z')
			{
			    curr = a[i] - 'a';	
			    arr[curr]++;
			}
			else 
			{
			    curr = a[i] - 'A';
			    curr+=26;
			    arr[curr]++;
			}
			mx1 = max(mx1,arr[curr]);
		}
		ll len2 = b.size();
		for(ll i = 0;i< len2;i++)
		{
			ll curr;
			if(b[i] >= 'a' && b[i] <= 'z')
			{
			    curr = b[i] - 'a';
			    brr[curr]++;	
			}
			else 
			{
			    curr = b[i] - 'A';
			    curr += 26;
			    brr[curr]++;
			}
			mx2 = max(mx2,brr[curr]);
		}
		ll len3 = c.size();
		for(ll i = 0;i< len3;i++)
		{
			ll curr;
			if(c[i] >= 'a' && c[i] <= 'z')
			{
			    curr = c[i] - 'a';
			    crr[curr]++;	
			}
			else 
			{
			    curr = c[i] - 'A';
			    curr += 26;
			    crr[curr]++;
			}
			mx3 = max(mx3,crr[curr]);
		}
		
		mx1 += n;mx2+=n;mx3+=n;
		
		if(mx1 > len && n == 1) mx1 = len-1;
		if(mx2 > len2 && n == 1) mx2 = len2-1;
		if(mx3 > len3 &&  n == 1) mx3 = len3-1;
		
		if(mx1 > len) mx1 = len;
		if(mx2 > len2) mx2 = len2;
		if(mx3 > len3) mx3 = len3;
		
		ll ans = max(mx1,max(mx2,mx3));
		ll coun = 0;
		if(mx1 == ans) coun++;
		if(mx2 == ans) coun++;
		if(mx3 == ans) coun++;
		if(coun>= 2) cout << "Draw\n";
		else if(mx1 > mx2 && mx1 > mx3) cout << "Kuro\n";
		else if(mx2 > mx1 && mx2 > mx3) cout << "Shiro\n";
		else cout << "Katie\n";
}

int main()
{
	solve();
	return 0;
}
