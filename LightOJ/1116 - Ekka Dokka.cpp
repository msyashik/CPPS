#include <stdio.h>
#include <math.h>
int main()
{
    long long int m, n, w;
    long long int tst, i, j, odd, Valid, limit;
    scanf("%lld", &tst);
    for(i=1; i<=tst; i++)
    {
        scanf("%lld", &w);
        limit = w/2;
        Valid = 0;
        odd = 0;
        for(j=2; j <= limit;  j *= 2)
        {
            if(w%j == 0)
                odd = w/j;
            if(odd%2 == 1)
            {
                Valid = 1;
                break;
            }
        }
        if(Valid==1)
            printf("Case %lld: %lld %lld\n", i, odd, j);
        else
            printf("Case %lld: Impossible\n", i);
    }
    return 0;
}
