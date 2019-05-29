#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int a[5];

bool yes = false;

void rec(int indx, int total)
{
	if(indx >= 5)
	{
		if(total == 23) yes = true;
		return;
	}
	
	rec(indx+1, total+a[indx]);
	
	rec(indx+1, total*a[indx]);
	
	rec(indx+1, total-a[indx]);
	
	return;
}

int main()
{   
    while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]) == 5)
    {
		if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0) return 0;
		
		sort(a, a+5);
		
		yes = false;
		
		int f = 0;
		
		do
		{
			rec(1,a[0]);
			
			if(yes) {cout << "Possible\n"; f  = 1;break;}
		}
		while(next_permutation(a, a+5));
		
		if(f == 0) cout << "Impossible\n";
	}
    	
	return 0;
}
