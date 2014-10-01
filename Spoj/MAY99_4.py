import math

def nCr(n,r):
	f = math.factorial
	return f(n) / f(r) / f(n-r)

n=int(input());
r=int(input());

if n<r:
	print -1
elif n==r or r==1:
	print 1
else:
	print nCr(n-1,r-1)%10000007
