#include <cstdio>
#include <string.h>

int main()
{
	char str[5001];
	int i,flag,count1,flip,t=0;
	while(1)
	{
		if(scanf("%s",str)==-1)
			break;
		t++;
		flag=count1=i=0;
		while(str[i]!='\0')
		{
			if(str[i]=='1' && flag==0)
			{
				flag=1;
				count1++;
			}
			if(str[i]=='0')
			{
				flag=0;
				//count0++;
			}
			i++;
		}
		if(str[i-1]=='1')
			flip=count1*2-1;
		else
			flip=count1*2;
		printf("Game #%d: %d\n",t,flip);
	}

	return 0;
}
