
//UVA  Best Friend

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

vector<ll>vv;

ll euler_phi(ll n)
{
	ll ans = n;
	vector<ll>v;
	
	if(n%2 == 0) v.push_back(2);
	
	while(n%2 == 0)
	{
		n /= 2;
	}
	
	ll len = sqrt(n);
	
	for(ll i = 3; i <= len; i+=2)
	{
		if(n%i == 0) v.push_back(i);
		
		while(n%i == 0)
		{
			n /= i;
		}
	}
	
	if(n > 2)
	{
		v.push_back(n);
	}
	
	ll lenn = v.size();
	
	for(ll i = 0; i < lenn; i++)
	{
		ans /=  v[i];
		ans *= (v[i]-1);
		
	}
	
	return ans;
}

void divisors(ll n)
{	
	ll len = sqrt(n);
	
	for(ll i = 1; i <= len; i++)
	{
		if(n%i == 0)
		{
			if(n/i == i) vv.push_back(i);
			else
			{
				vv.push_back(i);
				vv.push_back(n/i);
			}
		}
	}
	
	sort(vv.begin(), vv.end());
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("outp.txt", "w", stdout);
	
	ll t, p, k;
	
	cin >> t;
	
	for(ll kase = 1; kase <= t; kase++)
	{
	    cin >> p >> k;	
		
		divisors(p);
		
		vector<ll>phi;
		
		ll lenn = vv.size();
		
		for(int i = 0; i < lenn; i++)
		{
		    phi.push_back(euler_phi(p/vv[i]));
		    if(i) phi[i] += phi[i-1];	
		}
		
		cout << "Case " << kase << endl;
		
		while(k--)
		{
			ll a;
			cin >> a;
			
			if(a >= p) cout << p << endl;
			else if(a <= 0) cout << 0 << endl;
			else
			{
				ll pos = upper_bound(vv.begin(), vv.end(), a) - vv.begin();
				pos--;
				
				cout << phi[pos] << endl;
			}
		}
		
		vv.clear();
	}
	
	return 0;
}
