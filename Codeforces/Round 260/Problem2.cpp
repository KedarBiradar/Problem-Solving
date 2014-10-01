#include <cstdio>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define si(n) scanf("%d",&n)
#define pfn(n) printf("%d\n",n)
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

char array[1000010];
int main()
{

	int digit=0;
	scanf("%s",array);
	int len=strlen(array);
	if(len==1)
		digit+=array[0]-48;
	else
	{
		digit+=(array[len-2]-48)*10;
		digit+=array[len-1]-48;
	}
	if(digit%4==0)
		printf("4\n");
	else
		printf("0\n");
	return 0;
}

