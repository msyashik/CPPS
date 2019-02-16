#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define eps 1e-6

double precal[1000006];

void calc()
{
	for(int i = 1; i <= 1000000; i++)
	{
		precal[i] = precal[i-1] + log10(i);
	}
}

int main()
{
	calc();
	
	int t, n, b;
	
	scanf("%d", &t);
	
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d", &n, &b);
	
		int sum = (precal[n] / log10(b)) + 1 + eps;
		
		printf("Case %d: %d\n", kase, sum);
	}
	
	return 0;
}
