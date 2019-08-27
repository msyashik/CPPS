//https://www.mathopenref.com/triangleincircle.html


//largest circle inside a triangle
//The radius of the largest circle in a traingle is (2*a)/p
//where a is the area of the triangle and p is the summation of the 3 sides of the triangle


//https://www.quora.com/How-can-I-find-the-diameter-of-a-circle-with-a-triangle-inside
//triangle inside a circle
//if 3 sides of a triangle are given then the diameter of the circle is (a*b*c) / (2*area of triangle)

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define pi acos(-1)


int main()
{
	ll a[5];
	
	while(scanf("%lld %lld %lld", &a[0], &a[1], &a[2]) == 3)
	{
	
	double x = a[0], y = a[1], z = a[2];
		
	
	double s = (x+y+z) / (2*1.0);
	double area_triangle = sqrt(s*(s-x)*(s-y)*(s-z));
	
	double diameter_circle_outside = (x*y*z) / (2*area_triangle);
	
	double radius_circle_outside = diameter_circle_outside / 2.0;
	
	double area_circle_outside = pi*radius_circle_outside*radius_circle_outside;
	
	cout << setprecision(4) << fixed << area_circle_outside - area_triangle << " ";
	
	double porishima = x+y+z;
	
	double rad = (2*area_triangle) / (porishima*1.0);
	
	cout << area_triangle - (pi*rad*rad) << " ";
	cout << pi*rad*rad << endl;
    }
	return 0;
}
