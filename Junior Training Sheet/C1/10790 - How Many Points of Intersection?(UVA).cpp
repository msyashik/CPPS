#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define double long double 
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

/* To make a cross point i have to select 2 points from the upper row and 2 points from the down row.
                                           .     .
                                            \   /
                                             \ /
                                              \
                                             / \       
                                            /   \
                                           .     .

Now i can select 2 points from row a in (aC2) ways and 2 points from row b in (bC2) ways.So the answer is aC2*bC2.
If we iterate further we will get (a*(a-1))/2 * (b*(b-1))/2.

*/
int32_t main()
{
	int a,b;
	int kase = 1;
    while(scanf("%lld %lld",&a,&b) == 2)
    {
		if(a == 0 && b == 0) return 0;
		else printf("Case %lld: %lld\n",kase,((a*(a-1))/2)*((b*(b-1))/2));
		kase++;
	}
	return 0;
}
