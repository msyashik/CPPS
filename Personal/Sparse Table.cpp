//Sparse Table
//Cp-algo
//range sum query

#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define endl '\n'
#define SIZE 105

int main()
{
	int n, k, st[SIZE][SIZE], arr[SIZE];
	
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for(int i = 0; i < n; i++)
	{
		st[i][0] = arr[i];
	}
	for(int j = 1; j <= k;j++)
	{
		for(int i = 0; i+(1<<j) <= n; i++)
		{
			st[i][j] = st[i][j-1] + st[i + (1 << (j-1))][j-1];
		}
	}
	/*for(int i = 0; i< n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			cout << st[i][j] << " ";
		}
		cout << endl;
	}*/
	int L, R, sum = 0;
	
	cin >> L >> R;
	L--; R--; //because of 0 based indexing 
	
	for(int j = k; j >= 0; j--)
	{
		if((1 << j) <= (R-L+1))
		{
			sum += st[L][j];
			L += (1 << j);
		}
	}
	cout << sum << endl;
	return 0;
}
