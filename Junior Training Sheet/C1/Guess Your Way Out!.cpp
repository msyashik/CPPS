#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll n, h, coun = 0;
bool brk = false;

void recur(ll lev,ll dir)
{
	if(brk) return;
	if(lev == h) return;
	coun++;
	ll total = (1LL << (h-lev));
	if(total <= 2 && n <= 2)
	{
		brk = true;
		if(n == 1 && dir == 1) coun++;
		if(n == 2 && dir == 2) coun++;
		return;
	}
	
	if(n <= (total/2) && dir == 2)
	{
		recur(lev+1,1);
	}
	else if(n <= (total/2) && dir == 1)
	{
		ll rest2 = h-lev;
		ll curr = (1LL << rest2)-1;
		coun+=curr;
		recur(lev+1,1);
		return;
	}
	else if(n > (total/2) && dir == 1)
	{
		n -= (total/2);
		recur(lev+1,2);
	}
	else
	{
		ll rest1 = h - lev;
		ll curr = (1LL << rest1) - 1;
		coun+=curr;
		n -= (1LL << (h-(lev+1)));
		recur(lev+1,2);
		return;
	}
}

void solve()
{
    cin >> h >> n;
    recur(0,2);	
    cout<< coun<<endl;
}

int main()
{
	//IOS
	solve();
	return 0;
}
