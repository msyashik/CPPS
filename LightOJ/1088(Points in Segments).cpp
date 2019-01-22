//1088LOJ

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	int t, n, k, x, y, a[100005];
	
	scanf("%d", &t);
	
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d", &n, &k);
		
		for(int i = 1; i <= n;i++)
		{
			scanf("%d", &a[i]);
		}
		
		cout << "Case " << kase << ":\n";
		
		for(int i = 1; i <= k; i++)
		{
		    scanf("%d %d", &x, &y);
		    
		    int first = 1;
		    int last = n;
		    int mid = (n+1)/2;
		    int index1 = 0;
		    
		    while(first <= last)
		    {
				if(a[mid] >= x && a[mid] <= y)
				{
					index1 = mid;
					
					last = mid - 1;
				}
				else if(a[mid]  < x)
				{
					first = mid + 1;
				}
				else last = mid-1;
				
				mid = (first + last) / 2;
			}
			
			first = index1;
			last = n;
			mid = (index1+last)/2;
			
			int index2 = 0;
			
			while(first <= last)
		    {
				if(a[mid] >= x && a[mid] <= y)
				{
					index2 = mid;
					
					first = mid + 1;
				}
				else if(a[mid]  > y)
				{
					last = mid - 1;
				}
				else first = mid + 1;
				
				mid = (first + last) / 2;
			}
			
			if(index1 == 0 && index2 == 0) cout << 0 << "\n";
			else cout << (index2 - index1) + 1 << "\n";	
		}
	}
	
	return 0;
}
