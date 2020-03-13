#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define MX 100005
#define SIZE 1005
//
char ch[SIZE];
int dp[SIZE][SIZE], dp2[SIZE][SIZE];

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

int split(int left, int right)
{
	if(left == right) return 1;
	if(left > right) return 0;
	if(dp2[left][right] != -1) return dp2[left][right];
	int ans = 100000;
	for(int i = left; i <= right; i++)
	{
		if(func(left,i)) // Checking if the range (left,i) is palindrome or not
                         // if the range (left,i) is palindrome then we are calling
                         // the range (i+1,right) 		
		{
			ans = min(ans,1 + split(i+1,right));
		}
	} 
	return dp2[left][right] = ans;
}

int main()
{
	int t;
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t;kase++)
	{
	    scanf("%s", ch);
	    int len = strlen(ch);
	    memset(dp,-1,sizeof(dp)); 
	    int ans = func(0,len-1); //at first we are calling the entire range so that
	                             // if we call any range latter then we will get it
	                             // in O(1) time. 
	    memset(dp2,-1,sizeof(dp2));
	    int total = split(0,len-1);
	    printf("Case %d: %d\n",kase,total);         
	}
	
	return 0;
}
