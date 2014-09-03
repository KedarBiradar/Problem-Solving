#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

void buildLPS(char pat[],int m,int *lps)
{
	int i=1;
	lps[0]=0;
	int len=0;
	while(i<m)
	{
		while(len>0 && pat[i]!=pat[len])
			len=lps[len-1];

		if(pat[i]==pat[len])
		{
			len++;
		}
		lps[i]=len;

		i++;
	}
}
void KMP(char txt[])
{
	int n=strlen(txt);
	int m=n;
	char pat[200020];
	int *lps=new int[m];

	int i=0;
	int j=m-1;
	while(j>=0)
		pat[i++]=txt[j--];
	pat[i]=0;

	buildLPS(pat,m,lps);
	int index=0;
	i=0;

	for(i=0;txt[i];i++)
	{
		while(index>0 && pat[index]!=txt[i])
			index=lps[index-1];

		if(txt[i]==pat[index])
		{
			index++;
		}
	}
	free(lps);
	int diff=abs(i-index);
	while(diff>0)
	{
		txt[n++]=txt[diff-1];
		diff--;
	}
	txt[n]=0;
	printf("%s\n",txt);
}

int main()
{
	char str[200020];
	while(scanf("%s",str)!=EOF)
	{
		KMP(str);
	}
	return 0;
}
