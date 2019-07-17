#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007


int main()
{
	int a, b,c;
	
	cin >> a >> b;
	
	int coun = 1;
     c = a;
	
	while(1)
	{
		int sum = c%10;
		if(sum == b || sum == 0) 
		{
		    break;
		}
		else c+=a;
		
		coun++;
		
		//cout << c << endl;
	}
	
	cout << coun << endl;
	
	return 0;
}
