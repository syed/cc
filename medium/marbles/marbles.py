#!/usr/bin/python 


def factorial(n):
	if n == 1 or n == 0 :
		return 1
	else :
		x=1
		for i in range ( 2 , n+1 ) :
			x=x*i
		return x 


cases = int( raw_input() )

while cases :
	nums = raw_input().split() 
	
	n = int(nums[0])
	k = int(nums[1])

	n=n-1
	k=k-1
	ans = factorial( n ) / ( factorial(n-k) * factorial(k) )

	print ans 
	cases = cases-1





