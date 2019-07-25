#include <bits/stdc++.h>

using namespace std;


#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int t,coun = 0;
	string ch;
	
	cin >> t;
	while(t--)
	{
		cin >> ch;
		if(ch == "++X" || ch == "X++") coun++;
		else coun--;
	}
	cout << coun << endl;
	
    	
	return 0;
}
