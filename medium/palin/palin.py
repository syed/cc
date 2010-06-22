#!/usr/bin/python

cases = int(raw_input())
def is_palin(num) :
		if num<10 :
			return 0
		else :
			num_str = str(num)
			l = len(num_str)
			for i in range ( 0 , l/2 ) :
				if num_str[i] != num_str[-1-i] :
					return 0
		return 1 

while cases :
	num = int(raw_input())
	if is_palin(num) : 
		num+=1
	num_str = str(num)
	#check if alreay palindrome in that case increment 
	l = len(num_str)
	if l == 1 : #single string 
		if num == 9 :
			print "11" 
		else :
		  	print num+1 

		continue	

	if l %2 == 0 : #even
		left = num_str[:l/2]
		right = num_str[l/2:]
		r_num = int(right)
		l_num = int(left)
		lr_num = int(left[::-1])
		if lr_num > r_num :
			ans = left + left[::-1] 
		elif lr_num < r_num :
			l_num+=1;
			left = str(l_num)
			ans = left + left[::-1]

	else : 
		center  = int(num_str[l/2])
		left = num_str[:l/2]
		right = num_str[l/2+1:]
		l_num= int(left)
		r_num = int(right)
		lr_num = int(left[::-1])
		if lr_num > r_num :
			ans = left + str(center) + left[::-1]
		elif lr_num < r_num :
			carry = 0 
			center+=1
			if center == 10 : 
				center = 0 
				carry = 1 
			left = str( l_num+carry )
			ans = left + str(center) + left[::-1]

	
	print ans 
	cases-=1
