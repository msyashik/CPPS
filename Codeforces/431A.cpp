#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Coming ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define mod 1000000007


int main()
{
    int arr[5];
    string ch;
    
    for(int i = 1; i <= 4; i++) cin >> arr[i];
    
    cin >> ch;
    
    int len = ch.size();
    ll sum = 0;
    
    for(int i = 0; i < len; i++)
    {
		sum += arr[ch[i] - '0'];
	}	
	
	cout << sum << endl;
	
	return 0;
}
