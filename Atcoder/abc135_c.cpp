#include<bits/stdc++.h>

using namespace std;

#define ll long long 

int main()
{
	int n, a[100005],b[100005];
	
	cin >> n;
	for(int i = 1; i <= n+1; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	ll sum = 0;
	
	for(int i = 1; i <= n; i++)
	{
		if(a[i] >= b[i])
		{
			sum += b[i];
			b[i] = 0;
		}
		else
		{
			sum += a[i];
			b[i] -= a[i];
			
			sum += min(a[i+1],b[i]);
			a[i+1] -= min(a[i+1],b[i]);
		}
	}
	cout << sum << endl;
	return 0;
}
