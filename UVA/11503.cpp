#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int par[100005];
int size[100005];

int find(int node)
{
	if(par[node] == node) return node;
	else
	{
		return par[node] = find(par[node]);
	}
}

void union1(int a, int b)
{
	int x = find(a);
	int y = find(b);
	
	if(x!=y)
	{
		if(size[x] < size[y])
		{
			swap(x,y);
		}
		par[y] = x;
		
		size[x]+=size[y];
		
		cout << size[x] << endl;
	}
	else
	{
		cout << size[x] << endl;
	}
}

int main()
{
	int t,n;
	string ch,bh;
	unordered_map<string, int>m;
	
	cin >> t;
	while(t--)
	{
	
	int coun = 1;
	
	for(int i = 1; i <= 100000; i++) 
	{
	    par[i] = i;
	    size[i] = 1;
	}
	
	cin >> n;
	
	while(n--)
	{
		cin >> ch >> bh;
		
		if(m.count(ch) == 0)
		{
			m.insert({ch,coun});
			coun++;
		}
		if(m.count(bh) == 0)
		{
			m.insert({bh,coun});
			coun++;
		}
		
		int a = m[ch];
		int b = m[bh];
		
		union1(a,b);
	}
	m.clear();
    }
    
	return 0;
}
