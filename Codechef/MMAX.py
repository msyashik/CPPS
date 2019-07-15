#Problem Link : https://www.codechef.com/JULY19B/problems/MMAX

import sys

t = input()

while (t > 0):
    n = input()
    k = input()
    
    if(n <= k):
		if(n == k):
		    print 0
		elif((k%n) == 0):
		    print 0
		else:
			ans = k%n
			anss = min(ans, abs(n-ans))
			if(n > (2*anss)):
				print 2*anss
			else:
				print (2*anss)-1
    elif((n > k) and (n <= 2*k)):
	    if(2*k == n):
		print (2*k)-1
	    else:
		print (n%k)*2
    else:
	print 2*k					
    
    t = t-1



	
	  
