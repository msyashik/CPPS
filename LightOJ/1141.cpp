#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 100005

vector<int>prime;
char sieve[SIZE];
vector<int>factors[100005];
bool vis[100005];
int dis[100005];

void isprime(int n)
{
    sieve[0] = 1,sieve[1] = 1;
    sieve[2] = 0;
    for(int i =4; i <= n; i+=2) sieve[i] = 1;
    for(int i = 3; i <= sqrt(n); i+=2)
    {
		if(sieve[i] == 0)
		{
			for(int j = i*i; j <= n; j+= 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(int i = 3; i <= n; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}	
}

void factorize()
{
	for(int j = 4; j <= 1005; j++)
	{
	int n = j; 
	int sqrtn = sqrt(n);
	for(int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	{
		if(sieve[n] == 0) break;
		if(n%prime[i] == 0)
		{
			factors[j].push_back(prime[i]);
			while(n%prime[i] == 0)
			{
				n /= prime[i];
			}
			sqrtn = sqrt(n);
		}
	}
	if(n != 1)
	{
		factors[j].push_back(n);
	}
    }
}

int bfs(int a, int b)
{
	queue<int>q;
	q.push(a);
	vis[a] = 0;
	dis[a] = 0;
	while(!q.empty())
	{
	    int top = q.front();
	    q.pop();
	    if(top == b) return dis[top];
	    for(int i = 0; i < factors[top].size(); i++)
	    {
			int node = factors[top][i] + top;
			if(vis[node] == 0 && node <= b)
			{
				q.push(node);
				dis[node] = dis[top] + 1;
				vis[node] = 1;
			}
		}	
	}
	return -1;
}

int main()
{
	int t,a,b;
	isprime(1005);
	factorize();
	
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++)
	{
		scanf("%d %d", &a, &b);
		printf("Case %d: ", kase);
		if(a > b) printf("-1\n");
		else if(a==b) printf("0\n");
		else  if(a == 1 || sieve[a] == 0) printf("-1\n");
		else
		{
			memset(vis, 0, sizeof(vis));
			memset(dis, 0 , sizeof(dis));
			int ans = bfs(a,b);
			printf("%d\n", ans);
		}
	}
	return 0;
}
