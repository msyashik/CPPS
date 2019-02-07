//LIS using binary search
//Complexity : O(nlogn)
//learned from Tushar Roy(https://www.youtube.com/watch?v=S9oUiVYEq7E&t=273s)

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define MAX 1000

vector<int>v;
int arr1[MAX];
int arr2[MAX];
int n, mxlen = 0;
int coun = 0;

int up_bound(int ans)     //returns upper_bound of an element
{
	int lo = 0;
	int hi = coun;
	int mid = (lo + hi) / 2;
	int ind;
	
	while(lo <= hi)
	{
		if(v[arr1[mid]] <= ans)
		{
			lo = mid + 1;
		}
		else
		{
			ind = mid;
			hi = mid - 1;
		}
		
		mid = (lo + hi) / 2;
	}
	
	return ind;
}

void lis()
{	
	for(int i = 1; i < n; i++)
	{
		if(v[i] > v[arr1[coun]])
		{
			mxlen++;
			coun++;
			arr1[coun] = i;
			arr2[i] = arr1[coun-1];
		}
		else if(v[i] < v[arr1[0]])
		{
			arr1[0] = i;
		}
		else
		{
			int indx = up_bound(v[i]);
			
			arr1[indx] = i;
			
			arr2[i] = arr1[indx - 1];
		}
	}
}


int main()
{
    
    int a; 
    
    cin >> n; // number of elements
    
    for(int i = 0; i < n; i++)
    {
		cin >> a;
		
		v.pb(a);
	}
    
    memset(arr2, -1, sizeof(arr2));
 
    arr1[0] = 0;

    
    lis();
    
    cout << mxlen + 1 << "\n";
    
    int beg = arr1[coun];
    
    vector<int>path;
    
    while(beg != -1)
    {
		path.push_back(v[beg]);
		
		beg = arr2[beg];
	}
    
    reverse(path.begin(), path.end());
    
    int len = path.size();
    
    for(int i = 0; i < len; i++)
    {
		cout << path[i] << " ";
	}
    
	cout << "\n";
 
	return 0;
}
