#include <bits/stdc++.h>

using namespace std;

int main()
{
    int matrix[1000][1000];
    int n, e, q, dist;
    int coun  = 1;
    while(1)
    {
    cin >> n >> e;
    if(n == 0 && e == 0) break;
    else{
   
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    map<string , int>m;
    string ch, bh;
    int k = 1;
    while(e--)
    {
        cin >> ch >> bh >> dist;
        if(m.count(ch) == 0)
        {
        m.insert(make_pair(ch, k));
        k++;
        }
        if(m.count(bh) == 0)
        {
        m.insert(make_pair(bh, k));
        k++;
        }
        matrix[m[ch]][m[bh]] = dist;
        matrix[m[bh]][m[ch]] = dist;
    }
    for(int i = 1; i <= n; i++) matrix[i][i] = 0;

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
             matrix[i][j] =  max(matrix[i][j], min(matrix[i][k],matrix[k][j]) );
            }
        }
    }
      string jh, pj;
      cin >> jh >> pj;
     cout << "Scenario #" << coun << endl;
    cout << matrix[m[jh]][m[pj]] << " tons" << endl<<endl;
    }
    coun++;
    }
    return 0;
}
