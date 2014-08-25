#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;



int LCSLength(char *str1,char *str2,int len1,int len2)
{

		int *x=new int[len2+1];
		int *y=new int[len2+1];
		int i,j;

		for(i=0;i<=len2;i++)
			y[i]=x[i]=0;
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(str1[i-1]==str2[j-1])
					y[j]=x[j-1]+1;
				else
					y[j] = y[j-1] > x[j] ? y[j-1] : x[j];
			}
				int * t;
				t = x;
				x = y;
				y = t;
		}

			return x[len2];
}

int main()
{

	int t,i,j,len1,len2;
	scanf("%d",&t);
	char str1[1024],str2[1024];
	while(1)
	{
		scanf("%s",str1);
		if(str1[0]=='#')
			break;
		scanf("%s",str2);
		int len1=strlen(str1);
		int len2=strlen(str2);
		int len=LCSLength(str1,str2,len1,len2);
		//printf("%d\n",len);
		long long res=(len1-len)*15+(len2-len)*30;
		printf("%lld\n",res);
	}

	return 0;
}
