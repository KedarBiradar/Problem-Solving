#include <cstdio>
#include <string.h>

using namespace std;
void findFactor(int n,int arr[],int &len)
{
	int tmp=n/2;
	arr[len++]=1;
	for(int i=2;i<=tmp;i++)
	{
		if(n%i==0)
			arr[len++]=i;
	}
	arr[len]=n;
}
bool check(char str[],int len)
{
	int i,j;
	int l=strlen(str);
	for(i=0;i<len;i++)
	{
		for(j=i;j<l;j+=len)
		{
			if(str[j]!=str[i])
				return false;
		}
	}
	return true;
}
int main()
{
	int factor[100001],lenFactor;
	char str[100010];
	while(true)
	{
		lenFactor=0;
		scanf("%s",str);
		if(str[0]=='*')
			break;
		int len=strlen(str);
		findFactor(len,factor,lenFactor);
		int i;
		for(i=0;i<=lenFactor;i++)
		{
			if(check(str,factor[i]))
			{
				printf("%d\n",len/factor[i]);
					break;
			}
		}
		if(i>lenFactor)
			printf("%d\n",len);
	}
	return 0;
}
