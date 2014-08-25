#include <cstdio>
#include <set>
#define gc getchar_unlocked
void scanint(long long int &x)
{
	register long long int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}
using namespace std;
int main()
{
	long long int N=0,i,p,n;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanint(p);
		N^=p;
	}
	printf("%lld\n",N);
}
