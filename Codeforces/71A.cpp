#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main()
{
	int n;
	string ch;
	
	cin >> n;
	
	while(n--)
	{
		cin >> ch;
		
		if(ch.size() <= 10) cout << ch << endl;
		else
		{
			int len = ch.size();
			int lenn = len-2;
			cout << ch[0] << lenn << ch[len-1] << endl;
		}
	}

	return 0;
}
