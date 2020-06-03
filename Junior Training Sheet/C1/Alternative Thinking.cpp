#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define double long double 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int32_t main()
{
	int n,coun = 1;
	string ch;
	
	cin >> n >> ch;
	for(int i = 1; i < n ;i++)
	{
		if(ch[i] != ch[i-1]) coun++;
	}
	cout << min(coun+2,n) << endl;
	
	return 0;
}

