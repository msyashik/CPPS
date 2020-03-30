#include <bits/stdc++.h>

using namespace std;

vector<int>v;
vector<int>vv[105];
int t, n, arr[20];
int total = 0;

void func(int indx, int sum)
{
	if(sum == t)
	{
		total++;
        int len = v.size();
        if(len  == 1) vv[total].push_back(v[0]);
        else
        {
			for(int i = 0; i < len ;i++)
			{
				vv[total].push_back(v[i]);
			}
		}
	    return;	
	}
	if(indx > n) return;
	for(int i = indx; i <= n; i++)
	{
        if(sum + arr[i] <= t) 
        {
			v.push_back(arr[i]);
            func(i+1,sum+arr[i]);
            v.pop_back();
		}
		while((i+1) <= n && arr[i] == arr[i+1]) i++;		
	}
}

int main()
{	
	while(scanf("%d %d", &t, &n) == 2)
	{
		if(t == 0 && n == 0) break;
	    for(int i = 1; i <= n; i++)
	    {
		    cin >> arr[i];
	    }
	    total = 0;
	    func(1,0);
	    printf("Sums of %d:\n",t);
	    if(total == 0) cout << "NONE\n";
	    else
	    {
			for(int i = 1; i <= total ; i++)
			{
				int len = vv[i].size();
				if(len == 1) cout<< vv[i][0] << endl;
				else
				{
					for(int j = 0; j < len-1; j++)
					{
						cout << vv[i][j] << "+";
					}
					cout<< vv[i][len-1] << endl;
				}
			}
		}
		v.clear();
		for(int i = 1; i<= total; i++) vv[i].clear();
	}
	return 0;
}
