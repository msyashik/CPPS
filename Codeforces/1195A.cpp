#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007
 
int main()
{
    int n, k, arr[1005];
    
    cin >> n >> k;
    
    map<int,int>m;
    
    for(int i = 1; i <= n; i++)
    {
		cin >> arr[i];
		m[arr[i]]++;
	}	
	
	int left = 0, sets , coun = 0;
	
	if(n%2 == 0) sets = n/2;
	else sets = (n/2) + 1;
	
	for(auto it : m)
	{
		int ans = (it.second / 2);
		
		left += (it.second) - (ans*2);
		
		if(sets > 0)
		{
			if(ans <= sets)
			{
				sets -= ans;
				coun += (ans*2);
			}
			else 
			{
				sets = 0;
				coun += (sets*2);
			}
		}
		else break;
	}
	
	if(sets != 0)
	{
	if(left <= sets) coun += left;
	else coun += sets;
    }
	cout << coun << endl;
	
	return 0;
}
