#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100005

int main()
{
	ll ans, a,b,lo = 1,hi = 1e9,mid;
	
	cin >> a >> b ;
	while(1)
	{
		mid = (lo+hi) / 2;
		ans = mid*(mid+1);
		ans /= 2;
		if((mid+(ans-b)) == a) break;
		else if(mid+(ans-b) > a)  hi = mid-1;
		else lo = mid+1;
	}
	cout << ans-b << endl;
	return 0;
}
