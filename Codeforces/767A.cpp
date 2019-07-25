#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int brr[100005];

int main()
{
	int t,arr[100005];
	
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
	    cin >> arr[i];	
	}
    
    int ans = t; 
     
    for(int i = 1; i <= t; i++)
    {
		brr[arr[i]] = 1;
		if(arr[i] == ans)
		{
			for(int j = arr[i]; j >= 1; j--)
			{
				if(brr[j] == 0) 
				{
					ans = j;
				    break;
				}
				else
				{
					cout << j << " ";
				}
			}
			cout << endl;
		}
		else cout << endl;
	}
    
    	
	return 0;
}
