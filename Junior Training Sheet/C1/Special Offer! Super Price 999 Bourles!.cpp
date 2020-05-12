#include <bits/stdc++.h>

using namespace std;
 
#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	string ch,bh;
	
	cin >> ch >> bh;
	ll len1 = ch.size(),len2 = bh.size();
	if(len1 == 1)
	{
		cout << ch << endl;
		return 0;
	}
	ll coun9 = 0;
	for(ll i = len1-1;i >= 0; i--)
	{
		if(ch[i] == '9') coun9++;
		else break;
	}
	ll sum = 0;
	for(ll i = 0;i < len1; i++) 
	{
		sum = sum*10 + (ch[i]-'0');
	}
	ll sum2 = 0;
	for(ll i = 0;i < len2; i++) 
	{
		sum2 = sum2*10 + (bh[i]-'0');
	}
	ll rest = len1-len2;
	ll currr = 0;
	for(ll i = rest; i <len1; i++)
	{
		currr = currr*10 + (ch[i]-'0');
	}
	if(sum2 > currr)
	{
		string chh = ch;
		char c = ((chh[rest-1] - '0') - 1) + '0';
		if(chh[rest-1] == '0') 
		{
		    for(ll i = rest-1; i >= 1;i--)
		    {
				if(chh[i] == '0') chh[i] = '9';
				else
				{
					chh[i] = ((chh[i]-'0')-1)+'0';
					break;
				}
			} 
		}
		else chh[rest-1] = c;
		for(ll i = rest; i < len1; i++)
		{
			chh[i] = '9';
		}
		ll coun99 = 0;
		for(ll i = chh.size()-1;i>=0;i--)
		{
			if(chh[i] =='9') coun99++;
			else break;
		}
		if(coun9 >= coun99) 
		{
			cout << ch << endl;
			return 0;
		}
		bool yes = false;
		for(ll i = 0;i < (ll)chh.size(); i++)
		{
			if(!yes && chh[i] == '0')
			{
				continue;
			}
			else if(!yes && chh[i] != '0')
			{
				yes = true;
				cout << chh[i];
			}
			else
			{
				cout << chh[i];
			}
		}
	}
	else
	{
		string chh = ch;
		char c = ((chh[rest] - '0') - 1) + '0';
		if(chh[rest] == '0') 
		{
		    for(ll i = rest-1; i >= 1;i--)
		    {
				if(chh[i] == '0') chh[i] = '9';
				else
				{
					chh[i] = ((chh[i]-'0')-1)+'0';
					break;
				}
			} 
		}
		else chh[rest] = c; 
		for(ll i = rest+1; i < len1;i++)
		{
			chh[i] = '9';
		}
		ll coun99 = 0;
		for(ll i = chh.size()-1;i>=0;i--)
		{
			if(chh[i] =='9') coun99++;
			else break;
		}
		if(coun9 >= coun99) 
		{
			cout << ch << endl;
			return 0;
		}
		bool yes = false;
		for(ll i = 0;i < (ll)chh.size(); i++)
		{
			if(!yes && chh[i] == '0')
			{
				continue;
			}
			else if(!yes && chh[i] != '0')
			{
				yes = true;
				cout << chh[i];
			}
			else
			{
				cout << chh[i];
			}
		}
	}
	return 0;
}


