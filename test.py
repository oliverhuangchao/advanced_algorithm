#kmp algorithm

import pdb
def getPatten(str):
	#key point: how to use splice in python
	a = 0
	size = len(str)
	b = len(str)-1
	res = [0]*size
	#pdb.set_trace()
	for i in range(1,size):
		j = res[i-1]
		#print str[:j+1]
		#print str[i-j:i+1]
		if str[:j+1] == str[i-j:i+1]:
			res[i] = j+1
		else:
			while j != 0 and str[:j] != str[i-j+1:i+1]:
				j -= 1
			res[i] = j
	return res
	#print res

# return the match pattern lengh of two string
def compare(str,pattern,pos):
	i = 0
	while i<len(pattern):
		if str[pos] != pattern[i]:
			return i
		else:
			pos += 1
			i += 1 
	return i


def kmp(str, pattern):
	print(str);
	patten_list = getPatten(pattern)
	#print patten_list
	i = 0
	#db.set_trace()
	while i < len(str):
		res  = compare(str,pattern,i)
		#print res
		if res == len(pattern):
			print '*'*i + pattern
			return
		else:
			if res == 0: # KEY POINT : here is the case that I alwasy forget
				i += 1
			else:
				i += res - patten_list[res-1]

	print "no mattching"



str =     "BBC ABCDAB ABCDABD"
pattern = "ABCDABD"
kmp(str,pattern)
