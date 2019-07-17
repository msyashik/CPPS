#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	int arr[10][10];
	
	int pos1,pos2;
	
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= 5; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == 1) 
			{
				pos1 = i;
				pos2 = j;
			}
		}
	}
	
	cout << abs(pos1-3) + abs(pos2 - 3) << endl;
	return 0;
}
