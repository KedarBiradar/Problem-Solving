#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;

int LCS[1002][1002],dp[1002][1002];
int main()
{

	int i,j,l,len1,len2,k;
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
			{
				LCS[i][j]=0;
				dp[i][j]=0;
			}
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{

				LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);

				if(str1[i-1]==str2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=0;

			if(dp[i][j]>=k)
				for(l=k;l<=dp[i][j];++l)
					LCS[i][j]=max(LCS[i][j],LCS[i-l][j-l]+l);
			}
		}
		printf("%d\n",LCS[len1][len2]);

	}

	return 0;
}
