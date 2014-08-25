#include <cstdio>
#include <algorithm>

typedef unsigned int lli;

using namespace std;

#define gc getchar_unlocked

void scanint(lli &x)
{
	register lli c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}

int binaryReverse(int toReverse) 
{
 
         int reversed = 0;
         while(toReverse > 0) {
                 reversed *= 2;
                 reversed += toReverse % 2;
                 toReverse /= 2;
         }
 
         return reversed;
}
int main()
{

	lli n,i,num;
	scanint(n);
	for(i=0;i<n;i++)
	{
		scanint(num);
		if(num%2==0)
		{
			printf("%d\n",binaryReverse(num));		
		}		
		else
			printf("%d\n",num);
	}
	return 0;
}
