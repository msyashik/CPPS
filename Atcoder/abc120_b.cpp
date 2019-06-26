//Problem Link : https://atcoder.jp/contests/abc120/tasks/abc120_b

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
    int a, b, c;
    
    cin >> a>> b >> c;
    
    int coun = 0;
    
    for(int i = 100; i >= 1; i--)
    {
		if((a%i == 0) && (b%i == 0))
		{
			coun++;
		}
		if(coun == c) 
		{
			cout << i << endl;
			return 0;
		}
	}
    
    
    return 0;	
}
