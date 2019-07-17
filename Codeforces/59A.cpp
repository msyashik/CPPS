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
	
	int len = ch.size();
	
	int upper = 0, lower = 0;
	
	for(int i = 0; i < len; i++)
	{
		if(ch[i] >= 'A' && ch[i] <= 'Z') upper++;
		else lower++;
	}
	
	if(upper > lower)
	{
		transform(ch.begin(), ch.end(), ch.begin(), ::toupper);
	}
	else if(lower < upper)
	{
		transform(ch.begin(), ch.end(), ch.begin(), ::tolower);
	}
	else 
	{
		transform(ch.begin(), ch.end(), ch.begin(), ::tolower);
	}

	cout << ch << endl;

	return 0;
}
