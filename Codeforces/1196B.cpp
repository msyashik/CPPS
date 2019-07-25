#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	ll t,n,m,arr[200005];
	cin >> t;
	
	while(t--)
	{
		vector<pair<ll,ll>>v;
		cin >> n >> m;
		ll all = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			all += arr[i];
		}
		
		if(m == 1)
		{
			if(all%2)
			{
				cout << "YES\n";
				cout << n << endl;
			}
			else cout << "NO\n";
		}
		else
		{
		ll sum = 0,coun = 0;
		int f = 0;
		
		for(int i = 1; i <= n; i++)
		{
			sum += arr[i];
			if(sum%2)
			{
				coun++;
				v.push_back({sum,i});
				sum = 0;
				if((coun == (m-1)) && (i!=n))
				{
					coun = m;
					f = 1;
					for(int j = i+1; j <= n; j++)
					{
						sum += arr[j];
					}
					v.push_back({sum,n});
					if(sum%2)
					{
						sum = 0;
					}
				}
			}
			if(f == 1) break;
		}
		if(coun < m) cout << "NO\n";
		else if(coun == m && sum == 0) 
		{
			cout << "YES\n";
		for(int i = 0; i < v.size(); i++) cout << v[i].second << " ";
		cout << endl;
	    }
	    else
	    {
			int len = v.size();
			while(1)
			{
				for(int i = 0; i < len-1; i++)
				{
					v[i].first  = v[i].first + arr[v[i].second + 1];
					v[i+1].first = v[i+1].first - arr[v[i].second + 1];
					v[i].second = v[i].second + 1;
				}
				
				
				int g = 0;
				
				if(v[len-1].first == 0) {cout << "NO\n";break;}
				else
				{
				for(int i = 0;  i < len; i++)
				{
					if(v[i].first % 2 == 0) 
					{
						g = 1;
						break;
					}
				}
				
				if(g == 1) continue;
				cout << "YES\n";
				for(int i = 0; i < v.size(); i++) cout << v[i].second << " ";
				cout << endl;
				break;
			    }
			}
		}
	   } 
	}
	
	return 0;
}
