#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	long int n,i;
	scanf("%ld",&n);
	
	long long int array[n],total=0,sum=0,prod=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&array[i]);
		sum+=array[i];
		prod+=(i+1)*array[i];
	}
	//sort(array,array+n);

	total=prod;
	for(i=0;i<n;i++)
	{
		prod+=sum;
		prod-=array[n-i-1]*n;
		if(prod>total)
			total=prod;
	}
/*
	for(i=0;i<n;i++)
		total+=(i+1)*array[i];
*/
	printf("%lld\n",total);
	return 0;
}
