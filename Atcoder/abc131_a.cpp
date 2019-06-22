//Problem Link : https://atcoder.jp/contests/abc131/tasks/abc131_a

#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
 
int main()
{
	string ch;
	
	cin >> ch;
	
	if(ch[0] == ch[1] || ch[1] == ch[2] || ch[2] == ch[3]) cout << "Bad\n";
	else cout << "Good\n";
	
	return 0;
}
