#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define MX 100005
//
pair <int,string>dp[105][105];
string ch,bh;
int len1,len2,len;
string str = "", ash = "";

pair<int,string> func(int i,int j)
{
	if(i >= len1 || j >= len2) {return {0,""};}
	if(dp[i][j].first != -1)
	{
		return dp[i][j];
	}
	pair<int,string>ans;
	if(ch[i] == bh[j])
	{
		pair<int,string>curr = func(i+1,j+1);
		ans.first = 1 + curr.first;
		string c = ch[i] + curr.second;
		
		return dp[i][j] = {ans.first,c};
	
	}
	else
	{
		pair<int,string> curr1 = func(i+1,j);
		pair<int,string> curr2 = func(i,j+1);
		
		if(curr1.first > curr2.first)  {return dp[i][j] = {curr1.first,curr1.second};}
		else if(curr1.first < curr2.first)  {return dp[i][j] = {curr2.first,curr2.second};}
		else 
		{
			return dp[i][j] = {curr2.first,min(curr2.second,curr1.second)};
		}
	}
}

void path_print(int i,int j)
{
	if(i >= len1 || j >= len2)
	{
		ash = min(ash,str);
		return;
	}
	if(ch[i] == bh[j])
	{
		str += ch[i];
		path_print(i+1,j+1);
		str.erase(str.end()-1);
	}
	else
	{
		if(dp[i+1][j].first < dp[i][j+1].first) path_print(i,j+1);
		else if(dp[i+1][j].first > dp[i][j+1].first) path_print(i+1,j);
		else
		{
		    string c1 = dp[i+1][j].second;
		    string c2 = dp[i][j+1].second;
		  
		    if(c1 < c2) path_print(i+1,j);
	        else path_print(i,j+1);
		}
	}
}

int main()
{
	char chh[105],bhh[105],ashh[105];
	int t;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
	    scanf("%s %s", chh, bhh);
	    len1 = strlen(chh), len2 = strlen(bhh);
	    ch = "",bh = "";
	    for(int i = 0; i < len1; i++) ch += chh[i];
	    for(int i = 0; i < len2; i++) bh += bhh[i];
	    for(int i = 0; i < 105; i++)
	    {
			for(int j = 0; j < 105; j++)
			{
				dp[i][j] = {-1,""};
			}
		}
        pair<int,string>curr = func(0,0);
        len = curr.first; 
        str = "";
	    ash = "";
	    for(int i = 1; i <= 105; i++) ash += "z";
	    path_print(0,0);
	    printf("Case %d: ",kase);
	    if(len == 0) printf(":(\n");
	    else
	    {
			int ashs = ash.size();
			for(int i = 0; i < ashs; i++) 
			{
				ashh[i] = ash[i];
			}
			for(int i = 0; i < ashs; i++) printf("%c",ashh[i]);
			printf("\n");
		}
	}
	return 0;
}

