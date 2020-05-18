#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
	ll n,m, pet1 = 0, vas1 = 0,total = 0, prev = -1, pet2 = 0, vas2 = 0;
	
	cin >> n >> m;
	if(n == 0)
	{
		cout << m-1 << " " << 0 << endl;
	}
	else if(m == 0)
	{
		cout << n-1 << " " << 0 << endl;
	}
	else
	{
	    total = n+m;
	    prev = 1;
	    ll nn = n, mm = m;
	    nn--;
	    for(ll i = 2; i <= total; i++)
	    {
		    if(i%2)
		    {
				if(prev == 1)
				{
					if(nn)
					{
						nn--;
						pet1++;
						prev = 1;
					}
					else if(mm)
					{
						mm--;
						vas1++;
						prev = 2;
					}
				}
				else if(prev == 2)
				{
					if(mm)
					{
						mm--;
						pet1++;
						prev = 2;
					}
					else if(nn)
					{
						nn--;
						vas1++;
						prev = 1;
					}
				}
		    }
		    else
		    {
				if(prev == 1)
				{
					if(mm)
					{
						mm--;
						vas1++;
						prev = 2;
					}
					else if(nn)
					{
						nn--;
						pet1++;
						prev = 1;
					}
				}
				else if(prev == 2)
				{
					if(nn)
					{
						nn--;
						vas1++;
						prev = 1;
					}
					else if(mm)
					{
						mm--;
						pet1++;
						prev = 2;
					}
				}
		    }
	    }
	   // cout << pet1 << " "<< vas1 << endl;
	    prev = 2;
	    nn = n, mm = m;
	    mm--;
	    for(ll i = 2; i <= total; i++)
	    {
		    if(i%2)
		    {
				if(prev == 1)
				{
					if(nn)
					{
						nn--;
						pet2++;
						prev = 1;
					}
					else if(mm)
					{
						mm--;
						vas2++;
						prev = 2;
					}
				}
				else if(prev == 2)
				{
					if(mm)
					{
						mm--;
						pet2++;
						prev = 2;
					}
					else if(nn)
					{
						nn--;
						vas2++;
						prev = 1;
					}
				}
		    }
		    else
		    {
				if(prev == 1)
				{
					if(mm)
					{
						mm--;
						vas2++;
						prev = 2;
					}
					else if(nn)
					{
						nn--;
						pet2++;
						prev = 1;
					}
				}
				else if(prev == 2)
				{
					if(nn)
					{
						nn--;
						vas2++;
						prev = 1;
					}
					else if(mm)
					{
						mm--;
						pet2++;
						prev = 2;
					}
				}
		    }
	    } 
	  if(pet1 >= pet2)
	  {
		  cout << pet1 << " "<< vas1 << endl;
	  }
	  else cout<< pet2 << " "<< vas2 << endl;
    }
}
int main()
{	
	solve();
	return 0;
}
