#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
int smallest(int x, int y, int z)
{
    int smallest = min(x,y);
    return min(smallest,z);
    }
int cost[3003][3003];
int main()
{
	int i,j,len1,len2,diff,t;
	char str1[3002],str2[3002];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",str1,str2);
		len1=strlen(str1);
		len2=strlen(str2);
		//int cost[len1+1][len2+1];

		for(i=0;i<len1+1;i++)
			cost[i][0]=i;

		for(j=0;j<len2+1;j++)
			cost[0][j]=j;

		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(str1[i-1]==str2[j-1])
					diff=0;
				else
					diff=1;

				cost[i][j]=smallest(cost[i-1][j]+1,cost[i][j-1]+1,diff+cost[i-1][j-1]);
			}

		}
		printf("%d\n",cost[len1][len2]);
	}
	return 0;
}
