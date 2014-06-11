#include <cstdio>
#include <iostream>

using namespace std;

int main()
{

	long int t;
	long long int At,Bt,i;
	int cache[1000001];
	int mens[1000001];
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%lld%lld",&At,&Bt);
	
		for(i=0;i<At;i++)
		{
			scanf("%d",&mens[i]);
		}

		long int maxMen=0,noOfStn=0,maxStn=0;
		if(mens[0]<=Bt)
		{
			cache[0]=mens[0];
			maxMen=mens[0];
			noOfStn=1;
			maxStn=1;
		}
		else
			cache[0]=0;

		for(i=1;i<At;i++)
		{
			if(cache[i-1]+mens[i] <= Bt)
			{
				noOfStn++;
				cache[i]=cache[i-1]+mens[i];
				if( maxStn < noOfStn )
				{
					maxMen=cache[i];
					maxStn=noOfStn;
				}
				else if(maxStn == noOfStn && maxMen > cache[i])
					maxMen=cache[i];
			}
			else if(mens[i]<=Bt)
			{
				int j=i-noOfStn,tmp;
				tmp=cache[i-1];
				while(cache[i-1]+mens[i]>Bt && j<i)
				{
					cache[i-1]-=mens[j++];
					noOfStn--;
				}
				if(j==i)
				{
					cache[i]=mens[i];
					noOfStn=1;
					if(maxStn < noOfStn )
					{
						maxMen=cache[i];
						maxStn=noOfStn;
					}
					else if( maxStn==noOfStn && maxMen>cache[i])
						maxMen=cache[i];
				}
				else
				{
					noOfStn++;
					cache[i]=cache[i-1]+mens[i];
					if( maxStn < noOfStn )
					{
						maxMen=cache[i];
						maxStn=noOfStn;
					}
					else if(maxStn == noOfStn && maxMen>cache[i])
						maxMen=cache[i];
				}
			}
			else
			{
				noOfStn=0;
				cache[i]=0;
			}

		}

		printf("%ld %ld\n",maxMen,maxStn);
	}
	return 0;
}
