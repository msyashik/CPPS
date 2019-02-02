#include <bits/stdc++.h>

using namespace std;

#define MAX 35

string ch;
vector<char>v;
bool taken[MAX];
int r, len;

void subset(int start)
{
	if(v.size() == r)
	{
		for(int i = 0; i < r; i++)
		{
			cout << v[i];
		}
		cout << "\n";
		return;
	}
	
	for(int i = start; i < len; i++)
	{
		if(taken[i] == false)
		{
			taken[i] = true;
			
			v.push_back(ch[i]);
			
			subset(i+1);
			
			v.pop_back();
			
			taken[i] = false;
		}
		
		while(ch[i] == ch[i+1]) i++;
	}
}

int main()
{
	while(cin >> ch >> r)
	{
		memset(taken, false, sizeof(taken));
		
	    len = ch.size();
	    
	    sort(ch.begin(), ch.end());
	    
	    subset(0);
	}
	
	return 0;
}
