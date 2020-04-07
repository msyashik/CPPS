#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);

int main()
{
	int t, n;
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<int>v;
		int val = 0;
		while(1)
		{
			bool yes = false;
			for(int i = 0; i < (int)v.size(); i++)
			{
				int curr = v[i] + (val+1);
				int sq = sqrt(curr);
				if(sq*sq == curr)
				{
					yes = true;
					val++;
					if(i == 0) v.erase(v.begin(),v.begin()+1);
					else v.erase(v.begin()+i,v.begin()+i+1);
					v.push_back(val);
					break;
				}
			}
			if(!yes && v.size() >= n)
			{
				break;
			}
			else if(!yes && v.size() < n)
			{
				val++;
				v.push_back(val);
			}
		}
		cout<<val << endl;
		v.clear();
	}
	return 0;
}
