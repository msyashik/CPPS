#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
 
int main()
{
	ll pos1,pos2,n,arr[100005],minus=  0, plus = 0, mn = -1 * INT_MAX, mx = INT_MAX;
	
	scanf("%lld",&n);
	for(int  i = 1;i <= n; i++)
	{
		scanf("%lld",&arr[i]);
		if(arr[i] < 0)
		{
			if(mn < arr[i]) pos1 = i;
			mn = max(mn,arr[i]);
		}
		else {if(mx>arr[i]) pos2 = i;mx = min(mx,arr[i]);}
		
		if(arr[i] < 0) minus++;
		else plus++;
	}
	//cout << minus << " " << plus << " " << mn << " " << mx << endl;
	ll coun = 0;
	if(minus%2 == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			if(arr[i] < 0)
			{
				coun += (abs(arr[i]) - 1);
			}
			else if(arr[i] > 0)
			{
				coun += (arr[i]-1);
			}
			else coun++;
		}
		cout << coun << endl;
	}
	else
	{
		if(plus == 0)
		{
			for(int i = 1; i <= n; i++)
		    {
			if(i != pos1 && arr[i] < 0)
			{
				coun += (abs(arr[i]) - 1);
			}
		    }
		    coun += (abs(mn)-1 + 2);
		    cout << coun << endl;
		}
		else
		{
			//cout << pos1 << " " << pos2 << endl;
			for(int i = 1; i <= n; i++)
			{
				if(i == pos1)
				{
					continue;
				}
				else if(i == pos2) continue;
				else
				{
					if(arr[i] < 0)
					{
						if(arr[i] != -1)
						{ 
						    coun += (abs(arr[i]) -1);
						}
					}
					else if(arr[i] > 0)
					{
						coun += (arr[i]-1);
					}
					else
					{
						coun++;
					}
				}
			}
			ll mn1 = (abs(arr[pos1]) - 1 + 2) + (arr[pos2]-1);
			coun += mn1;
			cout << coun << endl;
		}
	}  
	return 0;
}
