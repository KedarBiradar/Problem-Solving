#include <stdio.h>

int main()
{
	int n,i;
	int maxC[3],maxS[3],maxB[3],maxCi[3],maxSi[3],maxBi[3];	
	scanf("%d",&n);

	for(i=0;i<3;i++)
		maxC[i]=maxS[i]=maxB[i]=maxCi[i]=maxSi[i]=maxBi[i]=0;

	int input[n][3];
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&input[i][0],&input[i][1],&input[i][2]);
	}

	for(i=0;i<n;i++)
	{
		//choc
		if(input[i][0]>maxC[0])
		{
			maxC[2]=maxC[1];
			maxCi[2]=maxCi[1];
			maxC[1]=maxC[0];
			maxCi[1]=maxCi[0];
			maxC[0]=input[i][0];
			maxCi[0]=i;	
		}
		else if(/*input[i][0]<maxC[0] &&*/ input[i][0]>maxC[1])
		{

			maxC[2]=maxC[1];
			maxCi[2]=maxCi[1];
			maxC[1]=input[i][0];
			maxCi[1]=i;
		}
		else if(/*input[i][0]<maxC[1] && */ input[i][0]>maxC[2])
		{
			maxC[2]=input[i][0];
			maxCi[2]=i;
		}
		
		//banana
		if(input[i][2]>maxB[0])
		{
			maxB[2]=maxB[1];
			maxBi[2]=maxBi[1];
			maxB[1]=maxB[0];
			maxBi[1]=maxBi[0];
			maxB[0]=input[i][2];
			maxBi[0]=i;	
		}
		else if(/*input[i][2]<maxB[0] && */ input[i][2]>maxB[1])
		{

			maxB[2]=maxB[1];
			maxBi[2]=maxBi[1];
			maxB[1]=input[i][2];
			maxBi[1]=i;
		}
		else if(/*input[i][2]<maxB[1] && */ input[i][2]>maxB[2])
		{
			maxB[2]=input[i][2];
			maxBi[2]=i;
		}
		
		//strawberry
		if(input[i][1]>maxS[0])
		{
			maxS[2]=maxS[1];
			maxSi[2]=maxSi[1];
			maxS[1]=maxS[0];
			maxSi[1]=maxSi[0];
			maxS[0]=input[i][1];
			maxSi[0]=i;	
		}
		else if(/*input[i][1]<maxS[0] &&*/ input[i][1]>maxS[1])
		{

			maxS[2]=maxS[1];
			maxSi[2]=maxSi[1];
			maxS[1]=input[i][1];
			maxSi[1]=i;
		}
		else if(/*input[i][1]<maxS[1] && */input[i][1]>maxS[2])
		{
			maxS[2]=input[i][1];
			maxSi[2]=i;
		}
		

	}

	for(i=0;i<3;i++)
	{
		printf("[ %d-%d ],[ %d-%d ],[ %d-%d ]\n",maxCi[i],maxC[i],maxSi[i],maxS[i],maxBi[i],maxB[i]);
	}


	int j,k,C,B,S,maxVal=0;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(maxCi[i]!=maxSi[j])
			{
				for(k=0;k<3;k++)
				{
					if(maxCi[i]!=maxBi[k] && maxSi[j] != maxBi[k] )
					{
						if(maxC[i]+maxS[j]+maxB[k] > maxVal )
						{
							maxVal=maxC[i]+maxS[j]+maxB[k];
							C=maxCi[i];
							S=maxSi[j];
							B=maxBi[k];

							printf("%d,%d,%d,%d\n",C,S,B,maxC[i]+maxS[j]+maxB[k]);
						
						}
					}			

				}
			}
		}
	}

	printf("%d\n%d\n%d\n",C,S,B);
	/*
		if(maxCi!=maxSi && maxCi!=maxBi && maxSi!= maxBi)
		{
			printf("%d\n%d\n%d\n",maxCi,maxSi,maxBi);
		}
	*/

	return 0;
}
