#include <bits/stdc++.h>
 
using namespace std;

#define endl "\n"
 
int main()
{
	
	int n, arr[100005], sum[100005];
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		
		if(i == 0) sum[i] = arr[i];
		else sum[i] = sum[i-1] + arr[i];
	}
	
	int a, b, q;
	
	cin >> q;
	
	while(q--)
	{
		cin >> a >> b;
		
		if(a == 0) cout << sum[b] << endl;
		
		else cout << sum[b] - sum[a-1] << endl;
	}
	
	  	 
	return 0;
}
 
