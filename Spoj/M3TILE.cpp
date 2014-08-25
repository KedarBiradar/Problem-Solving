#include <cstdio>
#include <stdlib.h>

int main()
{
	long long arr[32];
	arr[0]=1;
	arr[1]=0;
	arr[2]=3;
	arr[3]=0;
	for(int i=4;i<31;i++)
	{
		arr[i]=4*arr[i-2]-arr[i-4];
	}
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		else
			printf("%lld\n",arr[n]);
	}
	return 0;
}
