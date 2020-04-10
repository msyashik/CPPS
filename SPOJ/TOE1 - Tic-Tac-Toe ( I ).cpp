#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'

int t;
string ch[5];

bool row(char c)
{
	if(ch[0][0] == c && ch[0][1] == c && ch[0][2] == c) return true;
	if(ch[1][0] == c && ch[1][1] == c && ch[1][2] == c) return true;
	if(ch[2][0] == c && ch[2][1] == c && ch[2][2] == c) return true;
	return false;
}

bool col(char c)
{
	if(ch[0][0] == c && ch[1][0] == c && ch[2][0] == c) return true;
	if(ch[0][1] == c && ch[1][1] == c && ch[2][1] == c) return true;
	if(ch[0][2] == c && ch[1][2] == c && ch[2][2] == c) return true;
	return false;
}

bool diag(char c)
{
	if(ch[0][0] == c && ch[1][1] == c && ch[2][2] == c) return true;
	if(ch[0][2] == c && ch[1][1] == c && ch[2][0] == c) return true;
	
	return false;
}
int main()
{	
	cin >> t;
	for(int kase = 1; kase <= t; kase++)
	{
		int x = 0, o = 0;
		bool possible = true;
		for(int i = 0;i<= 2; i++)
		{
			cin >> ch[i];
		}
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(ch[i][j] == 'X') x++;
				else if(ch[i][j] == 'O') o++;
			}
		}
		if(o > x) possible = false;
		if((x-o) > 1) possible = false;
		bool winx = row('X') || col('X') || diag('X');
		if(winx)
		{
			if((x-o) != 1) possible = false;
		}
		bool wino = row('O') || col('O') || diag('O');
		if(wino)
		{
			if((x-o) != 0) possible = false;
		}
		if(wino && winx) possible = false;
		if(possible) cout << "yes\n";
		else cout << "no\n";
		if(kase != t) cout << "\n";
	}
	return 0;
	
}
