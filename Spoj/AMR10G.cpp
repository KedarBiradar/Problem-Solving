# include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n,k,t,i;
	long long int arr[20001],min;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);

		sort(arr,arr+n);

		if(k==1)
			printf("0\n");
		else if(k==n)
			printf("%lld\n",arr[n-1]-arr[0]);
		else
		{
			min=arr[k-1]-arr[0];
			for(i=1;i+k-1<n;i++)
			{
				if(arr[i+k-1]-arr[i] < min)
					min=arr[i+k-1]-arr[i];
			}
			printf("%lld\n",min);

		}
		
	}
	return 0;
}
