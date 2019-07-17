#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	string ch;
	
	cin >> ch;
	
	if(ch[0] >= 'a' && ch[0] <= 'z') 
	{
		ch[0] = ch[0] - 32;
	}
	
	cout << ch << endl;
	return 0;
}

