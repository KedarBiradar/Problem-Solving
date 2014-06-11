#include<stdio.h>
#include<string.h>

int main()
{

char input[5005];
long long int array[5005];
long long int length,i;
while(1)
{
scanf("%s",input);
if(input[0]=='0')
	break;

length=strlen(input);

if(length==1)
{
		printf("1\n");
}
else
{
	array[length]=1;
	if(input[length-1]!='0')
	array[length-1]=1;
	else
	array[length-1]=0;
	i=length-2;
	while(i>=0)
	{
		if(input[i]=='0')
			array[i]=0;
		else 
		{
			if(input[i]=='1')
			{
				array[i]=array[i+1]+array[i+2];
			}
			else if(input[i]=='2')
			{
				if(input[i+1]=='0'||input[i+1]=='1'||input[i+1]=='2'||input[i+1]=='3'||input[i+1]=='4'||input[i+1]=='5'||input[i+1]=='6')
					array[i]=array[i+1]+array[i+2];
				else
					array[i]=array[i+1];
			
			}
			else
			{
				array[i]=array[i+1];
			}	
		}
	i--;	
	
	}

	printf("%lld\n",array[0]);
}
}
return 0;
}
