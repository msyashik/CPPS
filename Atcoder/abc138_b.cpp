#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
 
int main()
{
	int n,a;
	
	cin >> n;
	
	double sum = 0;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a;
		sum += (1/(a*1.0));
	}
	
	double ans = (1/(sum*1.0));
	cout <<setprecision(5)<<fixed<< ans << endl;
	
	return 0;
}
