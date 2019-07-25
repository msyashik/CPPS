#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int func(int m)
{
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 1;
	else return 0;
}

int main()
{
    int t, a[1005], b[1005], c[1005], d[1005];
    
    while(1)
    {
        cin >> t;
        if(t == 0) return 0;
        for(int i = 1; i <= t; i++)
        {
		    cin >> a[i] >> b[i] >> c[i] >> d[i];	
		}
		
		ll sum = 0,coun = 0;
		
		for(int i = 2; i <= t; i++)
		{
			int month = func(b[i-1]);
			int feb = -1;
			
			if(((c[i]%4 == 0) && (c[i]%100 != 0)) || (c[i]%400 == 0))
			{
				feb = 1;
			}
			else feb = 0;
			
			if((a[i-1]+1 == a[i]) && (b[i-1] == b[i]) && (c[i-1] == c[i]))//same month diff dates
			{
				coun++;
				sum += (d[i]-d[i-1]);
			}
			else if((a[i-1] == 31) && (a[i] == 1) && (b[i-1]+1 == b[i]) && (c[i-1] == c[i]))//different month first date 31
			{
				coun++;
				sum += (d[i]-d[i-1]);
			}
			else if(a[i-1] == 30 && a[i] == 1 && month == 0 && (b[i-1]+1 == b[i]) && (c[i-1] == c[i])) // different month first date 30
			{
				coun++;
				sum += (d[i]-d[i-1]);
			}
			else if((a[i-1] == 31) && (a[i] == 1) && (b[i-1] == 12) && (b[i] == 1) && (c[i-1]+1 == c[i] ))//different year dec-jan
			{
				coun++;
				sum += (d[i]-d[i-1]);
			}
			else if((a[i-1] == 29 && a[i] == 1) && (b[i-1]== 2 && b[i] == 3) && (c[i-1] == c[i])) // february 29
			{
				coun++;
				sum += (d[i]-d[i-1]);
			}
			else if((a[i-1] == 28 && a[i] == 1) && (b[i-1] == 2 &&  b[i] == 3) && (c[i-1] == c[i]) && (feb == 0)) //february 28
			{
				coun++;
				sum += (d[i]-d[i-1]);
			}
		}
		cout << coun << " " << sum << endl;
	}
    
    	
	return 0;
}
