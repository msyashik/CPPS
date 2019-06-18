//Problem link : https://www.codechef.com/JUNE19B/problems/KS2

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int main()
{
	Coming 
	
	int t;
	string n;
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		int len = n.size();
		int sum = 0;
		
		for(int i = 0; i < len; i++)
		{
			sum += n[i] - '0';
		}
		
		if(sum % 10 == 0) cout << n << "0\n";
		else
		{
			int ans = ((sum/10) + 1) * 10;
			
			cout << n << ans-sum << endl;
		}
	}
	
	
	return 0;
}
