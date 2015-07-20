# reverse in the string
import sys


#data = sys.stdin.readlines()
#str = data[0]
str = "hello world chaoh"
print str
words = str.split(' ')
while words.count(''):
	words.remove('')
words.reverse()
newstr = ' '.join(words)
print newstr

