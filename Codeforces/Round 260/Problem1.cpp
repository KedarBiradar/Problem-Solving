#include <cstdio>
#include <limits.h>
#include <iostream>
#include <algorithm>

#define si(n) scanf("%d",&n)
#define pin(n) printf("%d\n",n)
#define pi(n) printf("%d",n)
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

struct tuple
{
	int ai,bi;//,index;
};

int compare(tuple t1,tuple t2)
{
	/*if(t1.ai == t2.ai)
		return t1.bi<t2.bi;
	else*/
		return t1.ai<t2.ai;
}


int compare1(tuple t1,tuple t2)
{
	return t1.bi>t2.bi;
}
int main()
{
	int n,i;
	struct tuple array[100001];
	si(n);
	FOR(i,n)
	{
		si(array[i].ai);
		si(array[i].bi);

	}
	sort(array,array+n,compare1);

	/*FOR(i,n)
		array[i].index=i;

	sort(array,array+n,compare1);
*/
	for(i=0;i<n-1;i++)
	{
			if(array[i].ai<array[i+1].ai)
			{
				printf("Happy Alex\n");
				return 0;
			}
	}
	printf("Poor Alex\n");
	return 0;
}
