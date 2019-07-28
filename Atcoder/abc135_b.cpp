#include<bits/stdc++.h>

using namespace std;

int main()
{
	int arr[55],n;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	int flag = 0, f = 0,p = 0,q = 0;
	
	for(int i = 1; i < n; i++)
	{
		if(arr[i] <= arr[i+1]) continue;
		else
		{
			flag = 1;
			if(f == 0) 
			{
				f = 1;
				p = i;
			}
			else q = i+1;
		}
	}
	if(flag == 0) cout << "YES\n";
	else
	{
		if(q == 0) q = p+1;
		swap(arr[p],arr[q]);
		for(int i = 1; i < n; i++)
		{
			if(arr[i] > arr[i+1])
			{
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
	}
	
	return 0;
}
