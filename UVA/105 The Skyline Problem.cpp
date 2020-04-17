
#include <bits/stdc++.h>
 
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long 
#define endl '\n'

int main()
{
	int a,h,b,arr[10005];
	int mx = 0;
	while(scanf("%d %d %d", &a, &h,&b) == 3)
	{
		for(int i = a; i < b; i++)
		{
			arr[i] = max(arr[i],h);
		}
		mx = max(mx,b);
	}
	int prev = 0;
	for(int i = 0; i < mx; i++)
	{
	    if(arr[i] != prev)
	    {
			cout << i << " " << arr[i] << " ";
			prev = arr[i];
		}	
	}
	cout << mx << " " << " 0\n";
	
	return 0;
}
