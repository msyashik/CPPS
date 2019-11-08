#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int arr[1005];
int vis[1005];

int main()
{
	int n,m,d,c[1005],space,plat=0,pres;
	
	cin >> n >> m >> d;
	for(int i =1; i <= m; i++) {cin >> c[i];plat += c[i];}
	
	int p = m,end=n+1;
	while(1)
	{
		if(end <= 1 || p < 1) break;
		end-=d;
		end-=(c[p]);
		end++;
		p--;
	}
	end-=d;
	if(end >= 1) cout << "NO\n";
	else
	{
		cout << "YES\n";
		space = n,pres = 0;
		int coun = 1;
		while(1)
		{
			if(coun > m) break;
			else
			{
				int ans1 = space-plat + 1;
				if(ans1 > d)
				{
					space -= (d+c[coun]-1);
					plat -= c[coun];
					pres += (d+c[coun]-1);
					arr[pres-(c[coun]-1)] = coun;
					coun++;
				}
				else
				{
					space -= (ans1+c[coun]-1);
					plat -= c[coun];
					pres+=(ans1+c[coun]-1);;
					arr[pres-(c[coun]-1)] = coun;
					coun++;
				}
			}
		}
		
		for(int i  =1; i <= n;i++)
		{
			if(arr[i] != 0 && vis[i] == 0)
			{
				int man = c[arr[i]];
				int start = i,end = i+man-1,val = arr[i];
				for(int j = start; j <= end; j++) {
					arr[j] = val;vis[j] = 1;}
				
			}
		}
		for(int i = 1; i <= n; i++) cout << arr[i] << " ";
		cout << endl;
	}
	
	return 0;
}
