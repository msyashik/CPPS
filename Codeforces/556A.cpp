#include <bits/stdc++.h>

using namespace std;


#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

int main()
{
	int t,i=0,coun=0,len;
	string ch;
	
	cin >> t >> ch;
	
	len = t;
	
    while(1)
    {
		if((ch.size() == 0) || (i == ch.size())) break;
		
		if((ch[i] == '0' && ch[i+1] == '1') || (ch[i] == '1' && ch[i+1] == '0'))
		{
			coun+=2;
			ch.erase(ch.begin()+i,ch.begin()+i+2);
			if(i == 0) i = 0;
			else i--;
			
			//cout << ch << endl;
		}
		else i++;
	}
	
	cout << len-coun << endl;
        	
	return 0;
}
