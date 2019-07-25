#include <bits/stdc++.h>

using namespace std;


#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int t;
	string ch;
	map<int,int>mp;
	
	cin >> t >> ch;
	
	transform(ch.begin(), ch.end(), ch.begin(), ::tolower);
	for(int i = 0; i < t; i++)
	{
		mp[ch[i]]++;
	}
	
	if(mp.size() == 26) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}
