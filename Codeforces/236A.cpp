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
	
	set<char>s;
	
	for(int i = 0; i < len; i++)
	{
		s.insert(ch[i]);
	}
	
	if(s.size()%2) cout << "IGNORE HIM!\n";
	else cout << "CHAT WITH HER!\n";
	
	return 0;
}
