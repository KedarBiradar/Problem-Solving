#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
int main()
{

	char n1[100001],n2[100001],res[1000001];
	int n,len1,len2,i,t,carry;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%s",n11,n22);
		len1=strlen(n1);
		len2=strlen(n2);
		i=carry=0;
		while(i < len1 || i < len2)
		{

			if(i <len1 && i< len2)
			{
				t=carry+(n1[i]-48)+(n2[i]-48);
				carry=t/10;
				t=t%10;
				res[i]=t+48;
			}
			else if(i<len1)
			{
				res[i]=n1[i];
			}
			else if(i<len2)
			{
				res[i]=n2[i];
			}
			i++;
		}
		printf("%s\n",res);
	}
	return 0;
}
