#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
	string ch,name1,extra,action,name2,work;
	int t;
	
	cin >> ch >> t;
	map<string,int>mp;
	for(int i = 1;i <= t; i++)
	{
		cin >> name1 >> action;
		if(action == "commented" || action == "posted")
		{
			cin>> extra;
		}
		cin >> name2 >> work;
		name2 = name2.substr(0,name2.length()-2);
		int val;
		if(action == "commented") val = 10;
		else if(action == "posted")val = 15;
		else val = 5;
		if(name1 == ch)
		{
			mp[name2]+=val;
		}
		else if(name2 == ch) mp[name1]+=val;
		else 
		{
			mp[name1];mp[name2];
		}
	}
	vector<pair<int,string>>vec;
	for(auto it : mp)
	{
		//cout << it.first << " " << it.second<< endl;
		vec.push_back({-it.second,it.first});
	}
	sort(vec.begin(),vec.end());
	for(int i = 0;i <(int)vec.size(); i++) cout << vec[i].second << endl;
}

int32_t main()
{
	//IOS
	solve();
	return 0;
}
