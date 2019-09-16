#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	ll n,m,a[200005],b[200005];
	
	cin >> n >> m;
	for(int i = 1; i <= n;i++)
	{
		cin>>a[i];
	}
	
	ll man = a[1],j=1,coun = 1,prev = 0;
	
	for(int i = 1;i<= m; i++)
	{
		cin >> b[i];
	}
	
	for(int i = 1;i<= m; i++)
	{
	    if(man >= b[i])
		{
			cout << coun << " " << b[i]-prev << endl;
		}
		else
		{
			coun++;
			prev = man;
			j++;
			man+=a[j];
			i--;
		}
	}
	return 0;
}
