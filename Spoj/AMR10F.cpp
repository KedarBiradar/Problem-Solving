#include <cstdio>

#define gc getchar_unlocked

void scanint(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}

int main()
{
	int n,a,d,t,res;
	scanint(t);
	while(t--)
	{
		scanint(n);
		scanint(a);
		scanint(d);
		res=(n*a)+(((n*(n-1))/2)*d);
		printf("%d\n",res);

	}

	return 0;
}

