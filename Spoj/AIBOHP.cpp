#include <cstdio>
#include <string.h>
#include <stdlib.h>


int max(int a,int b)
{
	return a>b?a:b;
}


int LCSLength(char *str1,char *str2,int n,int *x,int *y)
{

		int len1,len2,i,j;
		len1=n;
		len2=n;

		for(i=0;i<=len1;i++)
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

		return x[n];
}

int main()
{
	int n,tst;
	int x[5005],y[5005];
	char str[5002],strR[5002];

	scanf("%d",&tst);
	
	while(tst--)
	{
		scanf("%s",str);
		int i=0;
		n=strlen(str);
		while(i<n)
		{
			strR[i]=str[n-1-i];
			i++;
		}
		strR[n]=0;
		printf("%d\n",n-LCSLength(str,strR,n,x,y));
	}
	return 0;
}
