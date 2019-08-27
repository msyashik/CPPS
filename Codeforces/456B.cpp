
#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define pi acos(-1)


int main()
{
	string n;
	
	cin >> n;
	
	if(n == "0") cout << 4 << endl;
	else
	{
		int len = n.size();
		int res = 0;
		
		for(int i = 0; i < len; i++)
		{
			res = ((res*10) + (n[i]-'0') ) % 4;
		}
		int ans = 1;
		if(res == 0) ans = ((ans%5) + (2%5))%5;
		else if(res == 1) ans = ((ans%5) + (5%5))%5;
		else if(res == 2) ans = ((ans%5) + (8%5))%5;
		else
		{
			ans = ((ans%5) + (5%5))%5;
		}
		
		if(n[len-1] == '0' || n[len-1] == '2' || n[len-1] == '4' || n[len-1] == '6'|| n[len-1] == '8')
		{
			ans  = ((ans%5) + (1%5))%5;
		}
		else
		{
			ans  = ((ans%5) + (4%5))%5;
		}
		cout << ans << endl;
	}
	return 0;
}
