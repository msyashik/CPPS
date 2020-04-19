#include <bits/stdc++.h>

using namespace std;

#define ll long long 

string ch[1000005],bh;
int coun = 0;
int arr[1000005];
bool t[1000005];
	

int main()
{
	while(cin >> bh)
	{
		if(bh == "()")
		{
			int mx = 0;
			bool yes = false;
			for(int i = 1; i <= coun;i++)
			{
				int num = 0, pos;
				int len = ch[i].size();
				for(int j = 0; j < len;j++)
				{
					if(ch[i][j] == '(') continue;
					else if(ch[i][j] == ',')
					{
						pos = j;
						break;
					}
					else
					{
						num = (num*10) + (ch[i][j] - '0');
					}
				}
				if(ch[i][pos+1] == ')')
				{
					if(t[1]) yes = true;
					arr[1] = num;
					mx = max(mx,1);
					t[1] = true;
				}
				else
				{
					int p = 1;
					for(int j = pos+1; j < len-1;j++)
					{
						if(ch[i][j] == 'L') p = p*2;
						else
						{
							p = p*2;
							p++;
						}
					}
					if(t[p]) yes = true;
					arr[p] = num;
					t[p] = true;
					mx = max(mx,p);
				}
			}
			if(mx > 1 && t[1] == false) yes = true; 
			for(int i = mx; i >= 1; i--)
			{
				if(t[i] == false) continue;
				int lvl = i;
				while(lvl > 1)
				{
					lvl = lvl/2;
					if(t[lvl] == false)
					{
						yes = true;
						break;
					}
				}
			}
			if(yes) cout << "not complete\n";
			else 
			{
				vector<int>v;
				for(int i = 1; i  <= mx; i++)
				{
					if(t[i]) v.push_back(arr[i]);
				} 
				cout << v[0];
				for(int i = 1; i < (int)v.size();i++)
				{
					cout << " "<< v[i];
				}
				cout << endl;
				v.clear();
			}
			for(int i = 1; i <= mx; i++)
			{
				t[i] = false;
				arr[i] = 0;
			}
			coun = 0;
		}
		else
		{
			coun++;
		    ch[coun] = bh;
		}
	}
	return 0;
} 
