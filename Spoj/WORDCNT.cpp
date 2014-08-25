#include <cstdio>
#include <string.h>

int main()
{
	int t,count,maxCount,prevLen,len;
	char ch;
	scanf("%d",&t);
	ch=getchar();
	while(t--)
	{
		prevLen=-1;
		len=0;
		maxCount=0;
		count=1;

		while(true)
		{
			ch=getchar();
				if(ch=='\n')
				{
					if(len==prevLen)
						count++;
					else
						count=1;
					if(maxCount<count)
						maxCount=count;
					break;
				}
				if(ch==32)
				{
					if(len==prevLen)
						count++;
					else
						count=1;
					if(maxCount<count)
						maxCount=count;
					prevLen=len;

					len=0;
				}
				else
				{
					len++;
				}
		
		}

		printf("%d\n",maxCount);
	}
	return 0;
}
