#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define endl '\n'

ll arr[100005], n, day, flow, brr[100005], crr[100005];

bool func(ll x)
{
	ll cur = day;
	crr[0] = 0;
	for(int i = 1; i <= n; i++) {brr[i] = arr[i]; crr[i] = 0;}
	for(int i = 1; i <= n; i++)
	{
		crr[i] += crr[i-1];
		brr[i] += crr[i];
		if(brr[i] < x)
		{
		    ll diff = x-brr[i];
		    brr[i]+=diff;
		    cur -= diff; 
		    crr[i] += diff;
		    if(i+flow <= n) crr[i+flow] -= diff;	
		}
		if(cur < 0) return false;
	}
	return true;
}

int main()
{
	IOS
	
	cin >> n >> day >> flow;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	ll low = 1, hi = 1e15, mid;
	ll total = 0;
	while(low <= hi)
	{
		mid = (low+hi)/2;
		bool ans = func(mid);
		if(ans) {total = max(total, mid);low = mid+1;}
		else hi = mid-1;
	}
	cout << total << endl;
	return 0;
}
