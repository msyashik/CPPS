#include <bits/stdc++.h>

using namespace std;


#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	string ch,gh = "";
	
	cin >> ch;
	
	int len = ch.size();
	transform(ch.begin(), ch.end(), ch.begin(), ::tolower);
	
	for(int i = 0; i < len; i++)
	{
		if(ch[i] == 'y' || ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
		{
			continue;
		}
		else gh.push_back(ch[i]);
	}
	
	int lenn = gh.size();
	
	for(int i = 0; i < lenn; i++)
	{
		cout << "." << gh[i] ;
	}
	cout << endl;
	
	return 0;
}
