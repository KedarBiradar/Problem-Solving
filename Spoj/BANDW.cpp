#include <cstdio>
#include <string.h>

int main()
{
	char str1[1001],str2[1001];
	int count,flag,i;
	while(1)
	{
		flag=count=i=0;
		scanf("%s%s",str1,str2);
//		printf("%s\n%s",str1,str2);
		if(str1[0]=='*' || str2[0]=='*')
			break;
		while(str1[i]!='\0')
		{
			if(str1[i]==str2[i])
			{
				if(flag==1)
				{
					flag=0;
					count++;
				}
			}
			else
				flag=1;
			i++;
		}
		if(flag==1)
			count++;

		printf("%d\n",count);
		
	}

	return 0;
}
