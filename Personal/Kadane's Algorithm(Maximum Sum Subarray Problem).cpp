//Kadane's Algorithm(Maximum Sum Subarray Problem)
// learned from (https://www.youtube.com/watch?v=86CQq3pKSUw)

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int arr[100], n;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) cin >> arr[i];
	
	int max_curr = 0, max_global;
    	
	for(int i = 1; i <= n; i++) // Just simulate with an input array(very easy algo)
	{
		max_curr = max(arr[i], max_curr + arr[i]);
		
		if(max_curr > max_global)
		{
			max_global = max_curr;
		}
	}
	
	cout << max_global << endl;
    	
	return 0;
}
