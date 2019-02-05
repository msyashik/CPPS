//all possible subset using bitmask
//learned from forthright48 and BACS camp video from youtube

#include <bits/stdc++.h>

using namespace std;

#define ll long long

string ch;
int len, N;

bool check(int X)
{
	int mask = (1 << X);

	ll answer = (mask & N);
	
	if(answer == 0) return 0;
	else return 1;
}

void sete(int X)
{
	ll mask = (1 << X);
	
	N = (N | mask);
}

void reset(int X)
{
	ll mask = (1 << X);
	
	mask = (~mask);
	
	N = (N & mask);
}

void subset(int i)
{	
	if(i == len)
	{
		for(int j = 0; j< len; j++)
		{
			if(check(j))
			{
				cout << ch[j];
			}
		}
		cout << "\n";
		return;
	}
	
    subset(i+1);
    
    sete(i);
    
    subset(i+1);
    
    reset(i);
    
    return ;	
}

int main()
{	
	cin >> ch;
	
	len = ch.size();
	
	N = 0;
	
	subset(0);
	
	
	return 0;
}
