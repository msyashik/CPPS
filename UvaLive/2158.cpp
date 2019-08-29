#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0).cout.tie(0);
#define endl "\n"

ll trailing_zeroes(int n, int num)
{
	int freq = 0;
	while(n)
	{
		freq += (n/num);
		n = (n/num);
	}
	return freq;
}

int main()
{
	int t,n;
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		ll ans = trailing_zeroes(n,2);
		ll ans2 = trailing_zeroes(n,5);
		ll mn = min(ans,ans2);
		cout << mn << endl;
	} 
    		
	return 0;
}
