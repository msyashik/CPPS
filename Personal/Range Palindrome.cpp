//The algorithm is helpful solving the LightOJ-1044 problem.
//Learned from Shajib vhai(Devskill ACP)

#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define MX 100005
#define SIZE 1005

char ch[SIZE];
int dp[SIZE][SIZE];

int func(int l, int r)
{
	if(l >= r) return 1;
	if(dp[l][r] != -1) return dp[l][r];
	if(ch[l] == ch[r] && func(l+1,r-1))
	{
	    return dp[l][r] = 1;    	
	}
	return dp[l][r] = 0;
}

int main()
{
	int t, l, r, q;
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t;kase++)
	{
	    scanf("%s %d", ch, &q); //Given a string and a query.
	    memset(dp,-1,sizeof(dp)); // we have to memset only for once for a string, as the string remains same for all the time
	                              // during query for a particular string so it works perfectly. Think about coin change problem 
	                              // when the coins are same we have to memset only for once.
	    while(q--)
	    {	    
			scanf("%d %d", &l, &r); // Given a range. Check the range is a palindrome or not.
	        int ans = func(l,r); // we are saving the vaues into a dp table.Say if we call 2, 8. And then we call 3,6. In the last
	                             //call it would give the answer in O(1) time.Because during the call 2,8 we saved the value of 3,6 also.        
	        if(ans) printf("Yes\n");
	        else printf("No\n");
		}	
	}
	
	return 0;
}
