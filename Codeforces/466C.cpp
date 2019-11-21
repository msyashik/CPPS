#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100005

ll n,a[500005],b[500005];
ll total = 0,avg;
ll sum3[500005];

int main()
{	
	cin >> n;
	for(int i =1 ; i <= n ;  i++) {cin >> a[i];total += a[i];}
	if(total%3 != 0) 
	{
		cout << 0 << endl;
		return 0;
	}
	else avg = total/3;
	
	ll sum = 0;
	sum3[n+1] = 0;
	
	for(int i = n; i >= 1; i--)
	{
	    sum += a[i];
	    if(sum==avg)
	    {
		    sum3[i] = sum3[i+1] + 1;	
		}
		else
		{
			sum3[i] = sum3[i+1];
		}
	}
	ll summ = 0,coun = 0;
	for(int i =1 ; i <= n-2; i++)
	{
		summ += a[i];
		if(summ==avg)
		{
			coun+= sum3[i+2];
		}
	}
	cout << coun << endl;
	return 0;
}
