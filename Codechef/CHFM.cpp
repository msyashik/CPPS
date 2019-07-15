//Problem Link : https://www.codechef.com/JULY19B/problems/CHFM

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	Fastest
	
	int t, n, arr[100005];
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		ll sum = 0;
		
		for(int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		
		long double mean = sum / (n*1.0);
		long double ans;
		int man = INT_MAX, pos;
		
		for(int i = 1; i <= n; i++)
		{
			ans = (sum-arr[i]) / ((n-1)*1.0);
			if((ans == mean) && (arr[i] < man))
			{
				man = arr[i];
				pos = i;
			}
		}
		
		if(man != INT_MAX)
		{
			cout << pos << endl;
		} 
		else cout << "Impossible\n";
	}
	
	return 0;
}
