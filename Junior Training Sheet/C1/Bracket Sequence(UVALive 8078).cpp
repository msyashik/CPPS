#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define endl '\n'
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);

void solve()
{
	string ch;
	
	cin >> ch;
	ll len = ch.size();
	stack<pair<char,int>>s;
	vector<ll>v;
	for(ll i = len-1; i >= 0; i--)
	{
		if(ch[i] == '(' || ch[i] == '{' || ch[i] == '[' || ch[i] == '<')
		{
			if(ch[i] == '(' && s.size() >= 1 && s.top().first == ')')
			{
				s.pop();
				if(s.empty()) v.push_back(len-i);
				else
				{
				    ll val = s.top().second;
				    v.push_back(val-i);
				}
			}
			else if(ch[i] == '[' && s.size() >= 1 && s.top().first == ']')
			{
				s.pop();
				if(s.empty()) v.push_back(len-i);
				else
				{
				    ll val = s.top().second;
				    v.push_back(val-i);
				}
			}
			else if(ch[i] == '{' && s.size() >= 1 && s.top().first == '}')
			{
				s.pop();
				if(s.empty()) v.push_back(len-i);
				else
				{
				    ll val = s.top().second;
				    v.push_back(val-i);
				}
			}
			else if(ch[i] == '<' && s.size() >= 1 && s.top().first == '>')
			{
				s.pop();
				if(s.empty()) v.push_back(len-i);
				else
				{
				    ll val = s.top().second;
				    v.push_back(val-i);
				}
			}
			else
			{
			    s.push({ch[i],i});
			    v.push_back(0);
			}
		}
		else
		{
			s.push({ch[i],i});
			v.push_back(0);
		}
	}
	ll len2 = v.size();
	for(ll i = len2-1; i >= 0; i--)
	{
		cout << v[i] << endl;
	}
}


int main()
{
	ll t;
	
	scanf("%lld", &t);
	for(ll kase = 1; kase <= t; kase++)
	{
		printf("Case %lld:\n", kase);
		solve();
	}
	return 0;
}
