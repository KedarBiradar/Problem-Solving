#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{

	int t,i,j,len1,len2;
	scanf("%d",&t);
	char str1[1024],str2[1024];
	while(t--)
	{
		scanf("%s%s",str1,str2);
		len1=strlen(str1);
		len2=strlen(str2);

		int LCS[len1+1][len2+1];

		for(i=0;i<=len1;i++)
			LCS[i][0]=0;
		for(i=0;i<=len2;i++)
			LCS[0][i]=0;

		int res=0;
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(str1[i-1]==str2[j-1])
				{
					LCS[i][j]=LCS[i-1][j-1]+1;
					res=max(res,LCS[i][j]);		
				}
				else
					LCS[i][j]=0;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
