#include <bits/stdc++.h>

using namespace std;


#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int t,a[1010],b[1010],f=0,g = 0,prev =0;
	
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> a[i] >> b[i];
		if((a[i] < b[i]) || (a[i] > b[i])) f = 1;
	}
	if(f == 1) cout << "rated" << endl;
	else
	{
		prev = a[1];
		for(int i = 2; i <= t; i++)
		{
			if(a[i] > prev) g =1;
			prev = a[i];
		}
		if(g == 1) cout << "unrated\n";
		else cout << "maybe\n";
	}
		
	return 0;
}
