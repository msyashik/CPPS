//KMP
//Tushar Roy
//Just implemented the algotithm.Modify it as you want.

#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main()
{
	int arr[105];
	string text, pattern;
	
	cin >> text >> pattern;
	int i = 1, j = 0, len = pattern.size();
	
	arr[0]=0;
	while(i < len) //Building Prefix Array 
	{
		if(pattern[i] == pattern[j])
		{
			arr[i] = j+1;
			i++;
			j++;
		}
		else
		{
			if(j == 0) 
			{
			    arr[i] = 0;
			    i++;
			}
			else
			{
				j = arr[j-1];
			}
		}
	}
	for(int i = 0; i < len; i++) cout << arr[i] <<" ";
	cout << endl;
	
	//Matching Starts
	
	int x = 0, y = 0, coun = 0, len2 = text.size();
	while(x < len2)
	{
		if(text[x] == pattern[y]) 
		{
		    coun++;
		    x++;
		    y++;
		}
		else
		{
			if(y == 0)
			{
			    x++;
			    coun = 0;
			}
			else
			{
			    y = arr[y-1];
			    coun = y;
			}
		}
		if(coun == len) 
		{
			cout << "YES\n";
			break;
		}
	}
	
	return 0;
}
