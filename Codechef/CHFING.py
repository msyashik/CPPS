import sys

t = input()

while (t > 0):
    n,k = map(long,sys.stdin.readline().split(' '))
		
	
		
    if(n == 2):
		anss = k-1
		ash = (anss*(anss+1))/2
		man = ash%1000000007
		print man
    else:
		ans = n+k-1
		summ = k-1
		first = k
		sec = ans
		if(2*k <= ans):
			ansss = summ % 1000000007
			print ansss
		else :
			add = ((2*k)-ans-1)
			diff = (sec-first)
			if(add <= diff):
				anssss = (summ+add)%1000000007
				print anssss
			else:
				if((add%diff) == 0):
				    pod = (add/diff)
				    f = (diff)
			            ash = ((((pod)*(((2*f) + ((pod-1)*diff))))) / 2)
			            man = (ash+summ)%1000000007
			            print man 
			        else:
					pod = ((add/diff) + 1)
                                        f =  (add - (diff*(add/diff)))
                                        ash = ((((pod)*(((2*f) + ((pod-1)*diff))))) / 2)
				        man = (ash+summ)%1000000007
			                print man  
					
					    
    t = t-1


