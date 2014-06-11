#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char input[85];
	int len,i,j,length,width;
	scanf("%s",input);

	len=strlen(input);

	length=floor(sqrt(len));
	width=ceil(sqrt(len));
/*
	if(length*length==len)
		width=length;
	else
		width=length+1;
*/

	if(length==width)
	{
		for(i=0;i<length;i++)
		{

			for(j=i;j<len;j+=width)
			{
				//if(j<len)
				printf("%c",input[j]);
				//else
				//continue;
			}		
			printf(" ");
		}
	}
	else
	{
		for(i=0;i<=length;i++)
		{

			for(j=i;j<len;j+=width)
			{
				//if(j<len)
				printf("%c",input[j]);
				//else
				//continue;
			}		
			printf(" ");
		}

	}
	return 0;
}
//ifmanwasmeanttostayonthegroundgodwouldhavegivenusroots
//imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau
//imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau 
