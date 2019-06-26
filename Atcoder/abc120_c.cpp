//Problem Link : https://atcoder.jp/contests/abc120/tasks/abc120_c

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
    int coun = 0;
    
    string ch;
    
    stack<char>s;
    
    cin >> ch;
    
    int len = ch.size();
    
    if(len == 1) {cout << 0 << endl;return 0;}
    else
    {
		s.push(ch[0]);
		
		for(int i = 1; i < len; i++)
		{
			if(s.size() == 0)
			{
				s.push(ch[i]);
				continue;
			}
			
			if((s.top() == '0' && ch[i] == '1') || (s.top() == '1' && ch[i] == '0'))
			{
				s.pop();
				coun++;
			}
			else s.push(ch[i]);
		}
	}
    
    
    cout << coun*2 << endl;
    
    return 0;	
}
