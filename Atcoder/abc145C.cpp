#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 100005
 
 
int main()
{
	int n,a,b,coun;
	int arr[10];
	double ashol = 0;
	vector<pair<int,int>>v[10];
	
	cin >> n;
	for(int i = 0; i < n; i++) arr[i] = i+1;
	for(int i  =1; i <= n; i++)
	{
		cin >> a >> b;
		v[i].push_back({a,b});
	}
	do
	{
		for(int i = 0; i < n-1; i++)
		{
			double ans1 = v[arr[i]][0].first;
			double ans2 = v[arr[i]][0].second;
			double ans3 = v[arr[i+1]][0].first;
			double ans4 = v[arr[i+1]][0].second;
			ashol += sqrt(((ans1-ans3)*(ans1-ans3)) + ((ans2-ans4)*(ans2-ans4)));
		}
		coun++;
	}
	
	while(next_permutation(arr,arr+n));
	cout <<fixed << setprecision(10)<< ashol/(coun*1.0) << endl;
	
	return 0;
}
