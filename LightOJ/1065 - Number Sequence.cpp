#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define MAXROW 17
#define MAXCOL 17

ll matRow = 2;
ll matCol = 2;
ll mod;

struct matrix
{
	ll mat[MAXROW][MAXCOL];
	
	matrix(ll TYPE)
	{
		memset(mat,0,sizeof(mat));
		if(TYPE == 1) ///Identity Matrix
		{
			for(ll i = 0, j = 0; i < matRow && j < matCol; i++,j++)
			{
				mat[i][j] = 1;
			}
		}
		else if(TYPE == 2) ///Fibonacci
		{
			mat[0][0] = mat[0][1] = mat[1][0] = 1;
		}
		else if(TYPE == 3) ///nth order fib:  f(n) = f(n-1) + f(n-2) + f(n-3) + ...
		{
			for(ll i = 0; i < matCol; i++) mat[0][i] = 1;
			for(ll i = 1; i < matRow; i++) mat[i][i-1] = 1;
		}
	}
};

matrix matMul(matrix a, matrix b)
{
	matrix ans = matrix(0);
	
	for(ll row = 0; row < matRow; row++)
	{
		for(ll col = 0; col < matCol; col++)
		{
			for(ll p = 0; p < matCol; p++)
			{
				ans.mat[row][col] = (ans.mat[row][col] + a.mat[row][p] * b.mat[p][col])%mod;
			}
		}
	}
	return ans;
}

matrix matBigMod(matrix n, ll r)
{
	if(!r) return matrix(1);
	if(r%2) return matMul(matBigMod(n,r-1),n);
	matrix ans = matBigMod(n,r/2);
	return matMul(ans,ans);
}

int main()
{
	ll t, n, d;
	
	scanf("%lld",&t);
	for(ll kase = 1; kase <= t; kase++)
	{
		ll a[17], f[17];
		a[0] =  a[1] = 1;
		scanf("%lld %lld %lld %lld", &f[0],&f[1],&n,&d);
		matRow = matCol = 2;
		mod = 1;
		while(d--) mod *= 10;
		
		matrix co = matrix(0);
		for(ll i = 0; i < 2; i++) co.mat[0][i] = a[i];
		for(ll i = 1; i < 2; i++) co.mat[i][i-1] = 1;
		
		if(n < d)
		{
			printf("Case %lld: %lld\n",kase,f[n-1]%mod);
			continue;
		}
		
		co = matBigMod(co,n-1);
		
		ll ans =  0;
		ans = (co.mat[0][0]*f[1] + co.mat[0][1]*f[0])%mod;
		printf("Case %lld: %lld\n",kase,ans);
	}
	return 0;
}
