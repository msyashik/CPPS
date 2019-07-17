#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007

int main()
{
	string ch,bh;
	
	cin >> ch >> bh;
	
	int lenn = bh.size();
	
	int j = 0;
	
	for(int i = 0; i < lenn; i++)
	{
		if(bh[i] == ch[j])
		{
			j++;
		} 
	}
	
	cout << j+1 << endl;
	
	return 0;
}
