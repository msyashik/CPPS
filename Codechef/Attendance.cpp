#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n";

int main()
{
	map<string, int>m;
	
	int t, n;
	
	cin >> t;
	
	while(t--)
	{
		string ch[105], bh[105];
		
		cin >> n;
		
		for(int i = 1; i <= n; i++)
		{
			cin >> ch[i] >> bh[i];
			
			m[ch[i]]++;
		}
		
		for(int i = 1; i <= n; i++)
		{
			if(m[ch[i]] == 1)
			{
				cout << ch[i] << endl;
			}
			else
			{
				cout << ch[i] << " " << bh[i] << endl;
			}
		}
		
		m.clear();
	}
	
	return 0;
}
