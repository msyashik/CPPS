#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'

bool comp(pair<int,int>p1, pair<int,int>p2)
{
	return p1.first > p2.first;
}

int main()
{
    int n;
    vector<pair<int,int>>v;
    cin >> n;
    for(int i = 1; i <= n;i++)
    {
		int a,b;
		cin >> a >> b;
		v.push_back({b,a});
	}	
	stable_sort(v.begin(),v.end(),comp);
	
	for(int i = 0; i < (int)v.size();i++)
	{
		cout << v[i].second << " " << v[i].first << endl;
	}
	return 0;
}
