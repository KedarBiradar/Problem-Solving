#include <cstdio>

#define gc getchar_unlocked

void ssi(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}

void ssl(long long int &x)
{
	register long long int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}
int main()
{
	int t;
	long long int k;		
	ssi(t);
	while(t--)
	{
		ssl(k);
		printf("%lld\n",(k-1)*250+192);
	}
	return 0;
}
