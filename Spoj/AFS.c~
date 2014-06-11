#include <stdio.h>

long long int arr[1000001];
long long int sieve[1000001];


void preCompute()
{
	long long int i,m,res;
	for(i=0;i<1000001;i++)
	{
		arr[i]=0;
		sieve[i]=1;
	}

	for(i=2;i<1000001;i++)
	{
		//if(sieve[i]==0)
		//{
		//	sieve[i]=i;
			m=i;
			res=m+m;
			while(res<1000001)
			{	
				//if(sieve[res]==0)
					sieve[res]+=i;
				res+=m;
			}
		//}

/*		if(i<=12)
			printf("%lld - %lld\n",i,sieve[i]);
*/	}

	arr[0]=arr[1]=0;

	for(i=2;i<1000001;i++)
	{
		arr[i]=arr[i-1]+sieve[i];
/*		if(i<=12)
			printf("%lld - %lld\n",i,arr[i]);
*/
	}
}

int main()
{	
	long int n,t;
//	calArr();
	preCompute();
	scanf("%ld",&t);
	while(t>0)
	{
		scanf("%ld",&n);
		printf("%lld\n",arr[n]);
		t--;
	}
	return 0;
}
