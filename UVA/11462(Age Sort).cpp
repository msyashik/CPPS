#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

//merge sort

int arr[2000005], n, brr[2000005];

void merge(int fs, int fe, int ss, int se)
{
	int indx = 1;
	int p1 = fs, p2 = ss;
	while(1)
	{
		if(p1 > fe && p2 > se) break;
		if(p1 > fe)
		{
			for(int i = p2; i <= se; i++) 
			{
				brr[indx] = arr[i];
				indx++;
				p2++;
			}
		}
		else if(p2 > se)
		{
			for(int i = p1; i <= fe; i++) 
			{
				brr[indx] = arr[i];
				indx++;
				p1++;
			}
		}
		else
		{
			if(arr[p1] < arr[p2])
			{
				brr[indx] = arr[p1];
				indx++;p1++;
			}
			else
			{
				brr[indx] = arr[p2];
				indx++;p2++;
			}
		}
	}
	indx = 1;
	for(int i = fs; i <= se; i++)
	{
		arr[i] = brr[indx];
		indx++;
	}
}

void divide(int lo, int hi)
{
	if(lo==hi) return;
	int mid = (lo+hi)/2;
	divide(lo,mid);
	divide(mid+1,hi);
	merge(lo,mid, mid+1,hi);
}

int main()
{
	
	while(scanf("%d", &n) == 1)
	{
		if(n == 0) return 0;
	    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	    divide(1,n);
	    for(int i = 1; i<n; i++) printf("%d ", arr[i]);
	    printf("%d\n", arr[n]);
	}
	return 0;
}
