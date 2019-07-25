#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main()
{
	string ch;
	map<char,int>m;
	
	getline(cin ,ch);

	int len = ch.size();
	for(int i = 0; i < len; i++)
	{
		if(ch[i] >= 'a' && ch[i] <= 'z') m[ch[i]]++;
	}
    
    cout << m.size() << endl;
	return 0;
}
