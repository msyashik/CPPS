#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

bool prime[1000000];//Give the Half size of the input value
vector<ll>v;
vector<ll>v2;

void sieve(ll n)
{ 
 v.pb(2);
 
 ll len = sqrt(n+1);
 
 for(ll i = 3; i <= len; i+=2)
 {
  if(prime[i>>1] == false)
  {
   for(ll j = i * i; j <= n; j+= i + i)
   {
    prime[j>>1] = true;
   }
  }
 }
 
 for(ll i = 3; i <= n; i+=2)
 {
  if(prime[i>>1] == false)
  {
   v.pb(i);
  }
 }

}

void segments(ll m, ll n)
{
 
 ll len2 = v.size();
    ll len = (n-m) + 1;
    ll seg[len];
   
    for(ll i = 0; i < len; i++) seg[i] = 1;
   
    ll sqrtn = sqrt(n+1);
   
 for(ll i = 0; i < len2; i++)
 {
  if(v[i] > sqrtn) break;
  
  ll ans = ceil(m/(v[i]*1.0));
 
  if(ans <= v[i]) ans = v[i];
  
  for(ll j = ans*v[i]; j <= n; j += v[i])
  {
   seg[j - m] = 0;
  }
 }
 
 if(m == 1) seg[0] = 0;
 
 for(ll i = 0; i < len; i++)
 {
   if(seg[i] == 1) v2.pb(i+m);
 }
}

int main()
{
    sieve(1000000);
   
    ll a, b;
   
    while(scanf("%lld %lld", &a, &b) == 2)
    {
   
    ll len = v.size();
   
    if(a <= 1000000 && b <= 1000000)
    {
  ll maxx = max(a, b);
  ll minn = min(a,b);
  
  for(ll i = 0; i < len; i++)
  {
   if((v[i] <= maxx) && (v[i] >= minn)) v2.pb(v[i]);
   if(v[i] > maxx) break;
  }
 }
 else{
  ll minn = min(a, b);
  ll maxx = max(a,b);
  
  segments(minn, maxx);
 }
 
 ll len2 = v2.size();
 
 //for(ll i = 0; i < len2; i++) cout << v2[i] << "\n";
 
 
 if(len2 <= 1) cout << "There are no adjacent primes.\n";
 else{
  ll maxx2 = INT_MAX;
  ll minn2 = 0;
  ll a, b, c, d;
  
  for(ll i = 1; i < len2; i++)
  {
   ll ans = v2[i] - v2[i-1];
   if(ans < maxx2)
      {
    a = v2[i - 1];
    b = v2[i];
    
    maxx2 = ans;
   }
   if(ans > minn2)
   {
    c = v2[i-1];
    d = v2[i];
    
    minn2 = ans;
   }
  }
    
  cout << a  << "," << b << " are closest, ";
  cout << c  << "," << d << " are most distant.\n";
    }
    v2.clear();
   
}
    return 0;
}
