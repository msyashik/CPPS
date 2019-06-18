//Problem link : https://www.codechef.com/MAY19B/problems/MATCHS

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int main()
{
	ll t, a, b;
	
	cin >> t;
	
	while(t--)
	{
		cin >> a >> b;
		
		ll mx = max(a,b);
		ll mn = min(a,b);
		
		if(a == b) cout << "Ari\n";
		else if(a==1 || b == 1) cout << "Ari\n";
		else if(mx%mn == 0) cout << "Ari\n";
		else if(abs(mx-mn) == 2) cout << "Rich\n";
		else
		{
			
			int f = 0;
			ll coun = 0;
			int g = 0;
		    bool Ari = true;
		    bool Rich = false;
		    	
		while(1)
		{
			if(mx%mn == 0) break;
			
			if(((mx/mn) > 1))
			{
				f = 1;
				break;
			}
			
			ll anss = mx - (mn*(mx/mn));
			ll ansss = mn;
			coun++;
			
			mx = max(anss, ansss);
			mn = min(anss, ansss);
			
			if(Ari)
			{
				Ari = false;
				Rich = true;
			}
			else
			{
				Ari = true;
				Rich = false;
			}
			
			//
			//cout << mx << " " << mn << endl;	
		}
		
		if(f == 1 && Ari) cout << "Ari\n";
		else if(f == 1 && Rich) cout << "Rich\n";
		else if((coun+1)%2 != 0) cout << "Ari\n";
		else cout << "Rich\n";
	    }
	}    	 
	return 0;
}
