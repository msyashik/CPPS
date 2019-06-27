//Problem Link: https://atcoder.jp/contests/abc116/tasks/abc116_b

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
    Coming
     
    int s;
    
    cin >> s;
    
    map<int,int>m;
    
    m[s]++;
    
    int coun = 1;
    
    while(1)
    {
		if(s%2 == 0)
		{
			s /= 2;
		}
		else 
		{
			s = 3*s + 1;
		}
		
		m[s]++;
		coun++;
		
		if(m[s] == 2) break; 
	}
	
	cout << coun << endl;
    
	return 0;
}
