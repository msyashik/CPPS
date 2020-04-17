
#include <bits/stdc++.h>
 
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long 
#define endl '\n'

int t,a1,b1,r,c;
string ch[35];
int arr[] = {-1,+1,0,0};
int brr[] = {0,0,-1,+1};
bool vis[35][105];
vector<int>v[35];

void func(int p, int q)
{
		for(int j = 0; j < 4; j++)
		{
			int aa = p + arr[j];
			int bb = q + brr[j];
			if(aa >= 1 && aa <= r && bb >= 0 && bb <= c && vis[aa][bb] == 0 && ch[aa][bb] == ' ')
			{
				vis[aa][bb] = 1;
				ch[aa][bb] = '#';
				func(aa,bb);
			} 
		}
}

int main()
{
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		bool yes = false;
		int mx = 0, coun = 0;
		while(1)
		{
			coun++;
			int i = coun;
			getline(cin,ch[i]);
			int len = ch[i].size();
			v[i].push_back(len-1);
			mx = max(mx,len);
			for(int j = 0; j < len; j++)
			{
				if(ch[i][j] == '*')
				{
					a1 = i;b1 = j;
					break;
				} 
				else if(ch[i][j] == '_') {yes = true;break;}
			}
			if(yes) break;
		}
		--coun;
		r = coun; c = mx-1;
		//cout << coun << endl;
		for(int i = 1; i <= coun; i++)
		{
			int len = ch[i].size();
			if(len < mx)
			{
				for(int j = 1; j <= (mx-len);j++)
				{
					ch[i].push_back('X');
				}
			}
			//cout << ch[i] << endl;
		}
		memset(vis,0,sizeof(vis));
		func(a1,b1);
		ch[a1][b1] = '#';
		for(int i = 1; i <= coun ; i++)
		{
			int len = v[i][0];
			for(int j = 0; j<= len;j++)
			{
				cout << ch[i][j];
			}
			cout << endl;
		}
		cout << ch[coun+1] << endl;
		for(int i = 1; i <= 30; i++) v[i].clear();
	}
	return 0;
}


