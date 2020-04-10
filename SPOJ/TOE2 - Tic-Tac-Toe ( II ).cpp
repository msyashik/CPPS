#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'

string bh,ch[5];

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
	while(1)
	{
		int x = 0, o = 0, coun = 0;
		bool possible = true;
			
		cin >> bh;
	    if(bh == "end") break;
		else
		{
			ch[0][0] = bh[0]; ch[0][1] = bh[1]; ch[0][2] = bh[2]; 
			ch[1][0] = bh[3]; ch[1][1] = bh[4]; ch[1][2] = bh[5];
			ch[2][0] = bh[6]; ch[2][1] = bh[7]; ch[2][2] = bh[8];
	    }
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(ch[i][j] == 'X') x++;
				else if(ch[i][j] == 'O') o++;
				else coun++;
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
		if(wino == false && winx == false && coun > 0) possible = false;
		if(possible) cout << "valid\n";
		else cout << "invalid\n";
	}
	return 0;
	
}
