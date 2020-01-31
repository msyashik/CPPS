#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main()
{
	int t, n, arr[1005];
	int kase = 1;
	while(scanf("%d", &t) == 1)
	{
		if(t == 0) return 0;
		for(int i = 1; i <= t; i++)
		{
			arr[i] = 0;
		}
		map<int,int>m;
		queue<int>v[1005];
		queue<int>q;
	    for(int i =1 ;i <= t; i++)
	    {
		    scanf("%d", &n);
		    for(int j = 1; j <= n; j++)
		    {
				int a;
			    cin >> a;
			    m.insert({a,i});
		    }
		}
		string ch;
		printf("Scenario #%d\n", kase);
		kase++;
		while(cin >> ch)
		{
			if(ch == "STOP") break;
			else if(ch == "ENQUEUE")
			{
				int num;
				scanf("%d", &num);
				int dest = m[num];
				v[dest].push(num);
				if(arr[dest] == 0)
				{
					arr[dest] = 1;
					q.push(dest);
				}
			}
			else
			{
				int d = q.front();
				printf("%d\n", v[d].front());
				v[d].pop();
				if(v[d].empty()) 
				{
				    q.pop();
				    arr[d] = 0;
				}
			}
		}
		cout << endl;
	}
	
	return 0;
}
