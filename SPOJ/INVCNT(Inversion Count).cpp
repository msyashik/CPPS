#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

//merge sort

int arr[200005], n, brr[200005];
ll val = 0;

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
				val += (fe-p1)+1;
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
	
	
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		scanf("%d",&n);
	    for(int j = 1; j <= n; j++) scanf("%d", &arr[j]);
	    val = 0;
	    divide(1,n);
	    printf("%lld\n", val);
	}
	return 0;
}
