#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 100005

int main()
{
	int t,n;
	char ch[105];
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t;  kase++)
	{
		scanf("%d", &n);
		getchar();
		for(int i = 1; i <= n; i++) scanf("%c", &ch[i]);
		int ans = 0;
		if(n==1)
		{
			if(ch[1]=='.') ans++;
		}
		else if(n==2)
		{
			if(ch[1]=='.' || ch[2] == '.') ans++;
		}
		else
		{	
		bool pos = false;
		int num = 0, dots = 0;
		for(int i = 1; i <= n; i++)
		{
			if(ch[i] == '.') {dots++; pos = true;}
			if(dots > 0) num++;
		    if(pos == true && num == 3)
		    {
			    	if(dots == 1)
			    	{
						if(ch[i-2] == '.')
						{
							ans++;
							pos = false;
							dots = 0;
							num = 0;
						}
						else continue;
					}
					else if(dots == 2)
					{
						if(ch[i] == '.' && ch[i-1] == '.') continue;
						else
						{
							ans++;
							pos = false;
							dots = 0;
							num = 0;
						}
					}
					else 
					{
						ans++;
						pos = false;
						dots = 0;
						num = 0;
					}
			}
		}
		if(pos==true && dots > 0) ans++;
	    }
	    printf("Case %d: %d\n", kase, ans);
	}
	return 0;
}
