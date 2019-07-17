#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	int t;
	string ch;
	
	cin >> t >> ch;
	
	int coun = 0, pos = 0;
	
	for(int i = 1; i < t; i++)
	{
	    if(ch[pos] != ch[i])
	    {
			coun +=  i-pos-1;
			pos = i;
		}	
	}
	
	cout << coun+(t-pos - 1) << endl;
	
	return 0;
}
