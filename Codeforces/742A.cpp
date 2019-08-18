#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl '\n'
 
int main()
{
	int a;
	
	scanf("%d", &a);
	
	if(a == 0) printf("1\n");
	else
	{
		if(a%4 == 1) printf("8\n");
		else if(a%4 == 2) printf("4\n");
		else if(a%4 == 3) printf("2\n");
		else if(a%4 == 0) printf("6\n");
	}
	
	return 0;
}
