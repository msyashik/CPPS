// Problem link : https://www.codechef.com/JUNE19B/problems/PROXYC

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int main()
{
	Coming 
	
	int t, n;
	string ch;
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> ch;
		
		int coun = 0;
		
		for(int i = 0; i < n; i++)
		{
			if(ch[i] == 'P') coun++;
		}
		
		double pres = coun / (n*1.0);
		
		//cout << pres << endl;
		
		if(pres >= 0.75) cout << 0 << endl;
		else 
		{
			int len = n- 2;
			int f = 0;
			
			if(len >= 3)
			{
				int ans = 0;
				
				for(int i = 2; i < len; i++)
				{
					if((ch[i] == 'A') && (ch[i-1] == 'P' || ch[i-2] == 'P') && (ch[i+1] == 'P' || ch[i+2] == 'P'))
					{
						ans++;
						coun++;
					}
					
					pres = coun / (n*1.0);
					
					//cout << pres << endl;
					if(pres >= 0.75) {f = 1;cout << ans << endl;break;}
				}
				if(f == 0) cout << -1 << endl;
			}
			else cout << -1 << endl;
		}
		
		
	}
	
	return 0;
}
