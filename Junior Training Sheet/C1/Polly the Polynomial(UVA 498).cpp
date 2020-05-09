#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll pow(ll a, ll b)
{
    ll anss = 1;
    for(int i = 1; i <= b; i++)
    {
        anss *= a;
    }
    return anss;
}


int main()
{
       string ch, bh;
       while(getline(cin,ch) && getline(cin,bh))
       {
        vector<ll>v2,v3,v4;
        ll ans = 0,sign=0;
        for(int i = 0; i < ch.size(); i++)
        {
            if(ch[i] == '-') {sign = -1;}
            else if(ch[i] == ' ')
            {
                if(sign == -1) ans *= -1;
                v2.push_back(ans);
                ans=0;
                sign=0;
            }
            else
            {
                ans = (ans * 10) + (ch[i] - '0');
            }
        }
        if(sign == -1) ans *= -1;
        v2.push_back(ans);
        ans=0;
        sign=0;
        for(int i = 0; i < bh.size(); i++)
        {
            if(bh[i] == '-') {sign = -1;}
            else if(bh[i] == ' ')
            {
                if(sign == -1) ans *= -1;
                v3.push_back(ans);
                ans=0;
                sign=0;
            }
            else
            {
                ans = (ans * 10) + (bh[i] - '0');
            }
        }
        if(sign == -1) ans *= -1;
        v3.push_back(ans);
        ans=0;
        sign=0;
        for(int i = 0; i < v3.size(); i++)
        {
            ll coun = 0;
            ll ashol = 0;
            for(int j = v2.size()-1; j >= 0; j--)
            {
                if(coun == 0)
                {
                    ashol += v2[j];
                    coun++;
                }
                else
                {
                    ll ash = (v2[j]*pow(v3[i],coun));
                    ashol += ash;
                    coun++;
                }
            }
            v4.push_back(ashol);
        }
        for(int i = 0; i < v4.size()-1; i++) cout << v4[i] << " ";
        cout << v4[v4.size()-1]<< endl;
    }
    return 0;
}
