#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'

int main()
{
	int n , m;
	ll coun = 0;
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
	    if(i%5 == 0)
	    {
			coun += (m/5);
		}	
		else
		{
			int ans = (i/5) + 1;
			int man = m - ((5*ans) - i);
			if(man >= 0)
			{
			coun += (man/5);
			coun++;
		    }
		}
		//cout << coun << endl;
	}
	cout << coun << endl;
	
	return 0;
}
