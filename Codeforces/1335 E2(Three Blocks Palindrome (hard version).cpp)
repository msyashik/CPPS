#include <bits/stdc++.h>
 
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long 
#define endl '\n'

int t, n, arr[200005], pref[205][200005];
vector<int>v[205];

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		//memset(pref,0,sizeof(pref));
		for(int i = 1; i <= n ;i++)
		{
			cin >> arr[i];
			for(int j = 1; j <= 200; j++)
			{
				pref[j][i] = pref[j][i-1];
				if(j == arr[i]) pref[j][i]++;
			}
			v[arr[i]].push_back(i); 
		}
		int ash = 0;
		for(int i = 1; i <= 200; i++)
		{
			if(pref[i][n] != 0)
			{
				int len = v[i].size();
				int f = 0, l = len-1;
				int coun = 0;
				while(f < l)
				{
					int pos = v[i][f], pos2 = v[i][l];
					coun+=2;
					int mx = 0;
					for(int occ = 1 ; occ <= 200; occ++)
					{
						if(pref[occ][n] != 0)
						{
						    int ase = pref[occ][pos2-1] - pref[occ][pos];
						    mx = max(mx,ase);
						}
					}
					ash = max(ash,mx+coun);
					f++;
					l--;
				}
			}
		}
		cout << max(ash,1) << endl;
		for(int i = 1; i <= n; i++) v[arr[i]].clear();
	}
	return 0;
}
