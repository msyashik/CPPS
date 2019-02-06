//LIS using recursion
//learned from BACS(Youtube)

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define  ON_THE_WAY_TO_SPECIALIST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007

int arr[] = {1,5,3,4,8,-2,9,3};
int memo[100][100];

int lis(int i, int prev)
{	
	if(i == 8) return 0;
    
    if(memo[i][prev] != -1) return memo[i][prev];
    	
	int ans1, ans2;
	
	ans1 = lis(i+1, prev);
    	
	if(arr[i] > prev)
	{
		ans2 = lis(i+1, arr[i]) + 1;
	}
	else ans2 = 0;
	
	return memo[i][prev] = max(ans1, ans2);
}


int main()
{
	//ON_THE_WAY_TO_SPECIALIST
	
	
	memset(memo, -1, sizeof(memo));
	
	cout << lis(0, 0);
	
	
	return 0;
}
/*
*
*
*
*
*/

//LIS using for loop
//Complexity O(n^2)
//learned from Tusher Roy(Youtube)

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int arr[MAX];
int lis[MAX];
int len;

void func()
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
	
	return 0;
}
