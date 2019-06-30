//Problem Link : https://www.codechef.com/LTIME73B/problems/SILLYPRS

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
    Coming 
    
    int t, n,a,b,c, arr[100005],brr[100005];
    int crr[100005],drr[100005];
     
    cin >> t;
    
    while(t--)
    {
		cin >> n;
		
		int coun1 = 0, coun2 = 0;
		
		for(int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		
		for(int i = 1; i <= n; i++)
		{
			cin >> brr[i];
			
			if(brr[i]%2)
			{
				coun1++;
				crr[coun1] = brr[i];
			}
			else
			{
				coun2++;
				drr[coun2] = brr[i];
			}
		}
		
		ll sum = 0, even = 0, odd = 0;
		
		for(int i = 1; i <= n; i++)
		{
			if(arr[i]%2 == 0)
			{
				even++;
				if(even <= coun2)
				{
					sum += (arr[i]+drr[even]) / 2;
				}
				else
				{
					odd++;
					sum += (arr[i]+crr[odd]) / 2;
				}
			}
			else
			{
				odd++;
				if(odd <= coun1)
				{
					sum += (arr[i]+crr[odd]) / 2;
				}
				else
				{
					even++;
					sum += (arr[i]+drr[even]) / 2;
				}
			}
		}
		
		cout << sum << endl;
	} 
     
	return 0;
}
