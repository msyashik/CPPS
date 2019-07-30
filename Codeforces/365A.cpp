#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	string ch;
	int arr[10];
	int coun = 0;
	
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
	{
		memset(arr, 0, sizeof(arr));
		cin >> ch;
		for(int j = 0; j < ch.size(); j++)
		{
			arr[ch[j]-'0'] = 1;
		}
		
		int f = 0;
		
		for(int j = 0; j <= k; j++)
		{
			if(arr[j] == 0) 
			{
				f = 1;
				break;
			}
		}
		if(f == 0) coun++;  
		
	}
	cout << coun << endl;
	
	return 0;
}
