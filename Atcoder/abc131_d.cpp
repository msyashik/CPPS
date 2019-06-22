//Problem Link : https://atcoder.jp/contests/abc131/tasks/abc131_d

#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
 
vector<pair<int,int>>v;
 
int main()
{
   int n,a,b;
   
   cin >> n;
   
   for(int i = 1; i <= n; i++)
   {
	   cin >> a >> b;
	   v.push_back(make_pair(b,a));
   }
   
   sort(v.begin(), v.end());
   
   ll sum = 0;
   
   for(int i= 0; i < n; i++)
   {
	   if((sum + v[i].second) > v[i].first)
	   {
		   cout << "No\n";
		   return 0;
	   }
	   else sum += v[i].second;
   }
   
   cout << "Yes\n";
   
   return 0;
}
