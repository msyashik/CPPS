#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int t;
	string q;
	
	cin >> t;
	
	while(t--)
	{
		cin >> q;
		int len = q.size();
		int coun = 0;
		int open[100005],close[100005];
		
		for(int i = 0; i < len; i++)
		{
			if(q[i] == '(')
			{
				coun++;
				open[i] = coun;
			}
		}
		int goun = 0;
		int mx = 0;
		
		for(int i = len-1; i >= 0; i--)
		{
			if(q[i] == ')')
			{
				goun++;
			}
			else
			{
				close[i] = goun;
				mx = max(mx, 2*min(open[i],close[i]));
			}
		}
		
		cout << mx << endl;
	}
	return 0;
}
