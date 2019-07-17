#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	int n;
	string ch;
	
	cin >> n >> ch;
	
	int Anton = 0, Danik = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(ch[i] == 'D') Danik++;
		else Anton++;
	}
	
	if(Anton > Danik) cout << "Anton" << endl;
	else if(Anton < Danik) cout << "Danik" << endl;
	else cout << "Friendship" << endl;
	
	return 0;
}

