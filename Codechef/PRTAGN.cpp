//Problem Link: https://www.codechef.com/JULY19B/problems/PRTAGN

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int func(int x)
{
	int coun = 0;
	
	while(x)
	{
		if(x%2 == 1) coun++;
		x /= 2;
	}
	return coun;
}

int main()
{
	Fastest
	
	//func2();
	int t, q;
	
	cin >> t;
	
	while(t--)
	{
		cin >> q;
		
		int a;
		
		map<int,int>m;
		
		int odd = 0, even = 0;
		
		for(int i = 1; i <= q; i++)
		{
			cin >> a;
		   	
		   	    if(m.count(a) != 0)
		   	    {
					cout << even << " " << odd << endl;
					continue;
				}
		   	
				vector<int>v;
		
				for(auto it : m)
				{
					if((a != it.first) && (m.count(it.first ^ a) == 0)) v.push_back(it.first ^ a);
				}
				
				if(m.count(a) == 0)
				{
					v.push_back(a);
			    }
				int len = v.size();
				
				for(int j = 0; j < len; j++)
				{		
					m.insert({v[j], 1});
					
					int asho = func(v[j]);
					
					if(asho%2) odd++;
					else even++;
				}
				//v.clear();
			
			    cout << even << " " << odd << endl;
			
		}
	}
	
	
	return 0;
}
