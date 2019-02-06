#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define  IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1000

int memo[MAX][MAX];
int arr[MAX];
int lis[MAX];
int len;

int rec_lis(int i, int prev) //LIS using recursive dp
{	
	if(i == len) return 0;
    
    if(memo[i][prev] != -1) return memo[i][prev];
    	
	int ans1, ans2;
	
	ans1 = rec_lis(i+1, prev);
    	
	if(arr[i] > prev)
	{
		ans2 = rec_lis(i+1, arr[i]) + 1;
	}
	else ans2 = 0;
	
	return memo[i][prev] = max(ans1, ans2);
}
void func()   //LIS using for loop
{
    for(int i = 0; i < len; i++)
    {
		lis[i] = 1;
	}	
	
	for(int i = 1; i < len; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[i] > arr[j])
			{
				if((lis[j] + 1) > lis[i])
				{
					lis[i] = lis[j] + 1;
				}
			}
		}
	}
	
	for(int i = 0; i < len; i++)
	{
		cout << lis[i] << " ";// the highest value is the length of the lis
	}
	cout << "\n";
	
	return;
}


int main()
{
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	len = n;
	
	func();
	
	memset(memo, -1, sizeof(memo));
	
	cout << rec_lis(0,0);
	
	return 0;
}
