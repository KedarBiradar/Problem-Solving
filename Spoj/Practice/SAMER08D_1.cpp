#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;

int LCS[1002][1002],dp[1002][1002];
int main()
{

	int i,j,l,len1,len2,k,flag,x,y,m,n;
	while(1)
	{
		scanf("%d",&k);
		if(k==0)
		{
			break;
		}

		char str1[1001],str2[1001];
		scanf("%s%s",str1,str2);
		len1=strlen(str1);
		len2=strlen(str2);

		for(i=0;i<=len1;i++)
			for(j=0;j<=len2;j++)
				LCS[i][j]=0;

		/*for(i=0;i<=len1;i++)
			LCS[i][0]=0;
		for(i=0;i<=len2;i++)
			LCS[0][i]=0;
		*/
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				for(l=0;l<k;l++)
				{
					if(str1[i+l-1]!=str2[j+l-1] || str1[i+l-1]=='\0' || str2[j+l-1]=='\0')
						break;
				}
				if(l==k)
				{
					for(l=0;l<k;l++)
					{
						LCS[i+l][j+l]=LCS[i+l-1][j+l-1]+1;
					}
				
					//m=i+l;
					//n=j+l;
					for(x=i;x<i+k;x++)
					{
						for(y=1;y<=len2;y++)
							LCS[x][y]=max(LCS[x][y],max(LCS[x][y-1],LCS[x-1][y]));
					}
						i+=k-1;
						j=len2+1;
						//j+=k-1;
				}
				else
				{
					//for(l=0;l<k;l++)
					//{
						LCS[i][j]=max(LCS[i][j],max(LCS[i][j-1],LCS[i-1][j]));
					//}
					//i++;j++;
				}
			}
		}

		for(i=0;i<=len1;i++)
		{
			printf("\n");
			for(j=0;j<=len2;j++)
				printf("%d\t",LCS[i][j]);//=0;
		}
			printf("\n");
		printf("%d\n",LCS[len1][len2]);

	}

	return 0;
}
