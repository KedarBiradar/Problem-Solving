#include <iostream>
#include <cstdio>
#include <string.h>

typedef unsigned long long ull;

ull nCr[251][251];

void compute()
{
	int i,j;

	nCr[0][0]=1;
	for(i=1;i<=200;i++)
	{
		nCr[i][0]=1;
		for(j=1;j<=i;j++)
		{
			nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
		}
	}
}

int main()
{
	char str[255];
	int arr[26],coef[26],num[26];
	int i,len,t;
	ull ans;
	compute();
	while(gets(str))
	{
		len=0;
		for(i=0;i<26;i++)
			arr[i]=0;

		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]>64 && str[i]<91)
			{
				arr[str[i]-'A']++;
				len++;
			}
			else if(str[i]>96 && str[i]<123)
			{
				arr[str[i]-'a']++;
				len++;
			}
		}

		if(len==0)
		{
			printf("1\n");
			continue;
		}

/*		for(i=0;i<26;i++)
			if(arr[i]!=0)
			printf("%d\t",arr[i]);

*/
		int count=0;
		for(i=0;i<26;i++)
			count+=(arr[i]&1)?1:0;
//		printf("\n");

		if(count>1)
		{
			printf("0\n");
			continue;
		}
		else if((len&1)==0 && count==1)
		{
				printf("0\n");
				continue;
		}
		else
		{
			t=0;
			for(i=0;i<26;i++)
				coef[i]=num[i]=0;

			for(i=0;i<26;i++)
			{
				if(arr[i])
				{
					coef[t++]=arr[i]/2;
					num[t-1]=coef[t-1]+((t==1)?0:num[t-2]);	
				}

			}
			ans=1;
			for(i=0;i<t;i++)
				ans*=nCr[num[i]][coef[i]];
			printf("%lld\n",ans);
		}
	}



	return 0;
}
