#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int n, a, b;
int arr[1005];
bool flag = true;
map<int,int>m;
vector<int>v;
vector<int>vec;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n-1; i++)
	{
		scanf("%d %d", &a, &b);
		if(b != n) flag = false;
		m[a]++;
		m[b]++;
	}
	if(!flag || m.count(n-1) == 0) 
	{
	    printf("NO\n");
	    return 0;
	}
	for(int i =1 ; i <= n; i++)
	{
		if(m.count(i) == 0) v.push_back(i);
	}
	for(auto it : m)
	{
		vec.push_back(it.first);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	vec.erase(vec.begin()+0);
	sort(v.begin(), v.end(), greater<int>());
    arr[n] = n;
    int pos = n;
    
    while(1)
    {
		int lenv = vec.size();
		if(lenv <= 0) 
		{
			cout << "NO\n";
			return 0;
		}
		int val = vec[0];
		vec.erase(vec.begin()+0);
	int next = pos;
    pos = pos-m[val];
    
    if(pos < 1)
    {
		cout << "NO\n";
		return 0;
	}
    arr[pos] = val; 
    
    if(pos == 1) break;
    for(int i = pos+1; i < next; i++) 
    {
		int len = v.size();
		if(len <=0 || v[0] > val)
		{
			cout << "NO\n";
		    return 0;
		}
		else
		{
			if(len != 0)
			{
			    arr[i] = v[0];
			    v.erase(v.begin()+0);
			}
			else 
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
    }
    cout << "YES\n";
	for(int i = 1; i <= n-1; i++) cout << arr[i] << " " << arr[i+1] << endl;
	return 0;
}
