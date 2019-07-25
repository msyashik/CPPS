#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	
	cin >> n >> k;
	
	char ch[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	string s = "";
	
	for(int i = 0; i < k; i++) s += ch[i];
	
	int ans = n/k;
	int mod = n%k;
	
	string ash = "";
	
	for(int i = 1; i <= ans; i++)
	{
		ash += s;
	}
	
	for(int i = 0; i < mod; i++)
	{
		ash += ch[i];
	}
	
	cout << ash << endl;
	
	return 0;
}
