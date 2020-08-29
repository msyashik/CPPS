#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t,arr[1005],n,k,mn;

int func(int val)
{
	int coun = 0, sum = 0;
	for(int i = 1; i<= n+1;i++)
	{
		sum += arr[i];
		if(sum > val)
		{
			coun++;
			sum = arr[i];
		}
	}
	return coun;
}

int32_t main()
{
	scanf("%lld",&t);
	for(int kase = 1; kase<= t; kase++)
	{
		scanf("%lld %lld",&n,&k);
		for(int j = 1;j<= n+1;j++)
		{
			scanf("%lld",&arr[j]);
		}
		mn = INT_MAX;
		int lo = 1, hi = 100000;
	    while(lo <= hi)
	    {
		    int mid = (lo+hi)/2;
		    int curr = func(mid);
		    if(curr <= k)
		    {
				mn = min(mn,mid);
				hi = mid - 1;
			}
			else 
			{
				lo = mid + 1;
			}
	    }
	    int sum1 = 0,mx = 0;
	    for(int j = 1;j<= n+1; j++)
	    { 
		   sum1 += arr[j];
		   if(sum1 > mn)
		   {
			   mx = max(mx,sum1-arr[j]);
			   sum1 = arr[j];
		   }
	    }
	    mx = max(sum1,mx);
	    
	    vector<int>v[305],vv[305];
	    int stay = 0, sum2 = 0;
	    for(int j = 1; j<= n+1; j++)
	    {
			sum2 += arr[j];
			if(sum2 > mx)
			{
				stay++;
				sum2 = arr[j];
				v[stay].push_back(arr[j]);
			}
			else v[stay].push_back(arr[j]);
		}
		int rest = stay;
		int last = k;
		vector<int>ans;
		/*for(int i  = 0; i <= stay; i++)
		{
			int len = v[i].size();
			for(int j = 0;j < len;j++) cout << v[i][j] <<" ";
			cout << endl;
		}*/
		for(int i = stay; i >=0;i--)
		{
			int len = v[i].size();
			for(int j = len-1;j >= 0;j--)
			{
				if(rest == k || j == 0)
				{
					vv[last].push_back(v[i][j]);
				}
				else
				{
				    rest++;
				    vv[last].push_back(v[i][j]);
				    last--;
				}
			}
			last--;
		}
		for(int i = 0; i <= k;i++)
		{
			int summ = 0;
			int len = vv[i].size();
			for(int j = 0;j < len; j++)
			{
				summ+=vv[i][j];
			}
			ans.push_back(summ);
		}
		printf("Case %lld: %lld\n",kase,mx);
		for(int i = 0; i <= k;i++)
		{
			printf("%lld\n",ans[i]);
		} 
		ans.clear();
		for(int i = 0;i <=k;i++) {vv[i].clear();v[i].clear();}
	}
	return 0;
}
