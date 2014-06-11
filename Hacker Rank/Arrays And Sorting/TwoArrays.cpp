#include <stdio.h>
#include <algorithm>


using namespace std;
int main()
{
	int t,n,i;
	long long int k,ai[1001],bi[1001];

	scanf("%d",&t);

	while(t>0)
	{
		scanf("%d%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&ai[i]);
				//if(ai<min1)
				//	min1=ai;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&bi[i]);
				//if(bi<min2)
				//	min2=bi;
		}

/*
		if(min1+min2>=k)
			printf("YES\n");
		else
			printf("NO\n");
*/

		sort(ai,ai+n);
		sort(bi,bi+n);

		for(i=0;i<n;i++)
		{
			if(ai[i]+bi[n-i-1]<k)
				break;
		}
		

		if(i==n)
			printf("YES\n");
		else
			printf("NO\n");


		t--;
	}
	return 0;
}
