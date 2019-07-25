#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main()
{
	int n,arr[5005];
	vector<pair<int,int>>v1,v2,v3;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if(arr[i] == 1) v1.push_back({1,i});
		else if(arr[i] == 2) v2.push_back({2,i});
		else v3.push_back({3,i});
	}
	
	int ans = min(v1.size(), min(v2.size(), v3.size()));
    
    cout << ans << endl;
   
	for(int i = 0; i < ans; i++)
	{
		cout << v1[i].second << " " << v2[i].second << " " << v3[i].second << endl;
	}
	
	return 0;
}
