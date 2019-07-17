#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	int arr[100005],n;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	int sum = 0, pol = 0;
	
	for(int i = 1 ; i <= n; i++)
	{
		if(arr[i] == -1)
		{
			if(pol > 0)
			{
				pol--;
			}
			else sum++;
		}
		else pol += arr[i];
	}
	
	cout << sum << endl;
	
	return 0;
}
