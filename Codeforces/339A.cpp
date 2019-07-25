#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main()
{
	string ch;
	vector<int>v;
	
	cin >> ch;
	int len = ch.size();
	for(int i = 0; i < len; i++)
	{
		if(ch[i] != '+')
		{
			v.push_back(ch[i]-'0');
		}
	}
	sort(v.begin(), v.end());
	
	int lenn = v.size();
	
	cout << v[0];
	
	for(int i = 1; i < lenn; i++)
	{
		cout << '+' << v[i];
	}
	return 0;
}
