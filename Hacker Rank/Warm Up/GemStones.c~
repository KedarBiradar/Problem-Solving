#include <stdio.h>
#include <string.h>
int main()
{

	int matrix[101][26];
	int n,l,i,j;
	char inputString[500];

	for(i=0;i<101;i++)
		for(j=0;j<26;j++)
			matrix[i][j]=0;

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%s",inputString);
		l=0;
		while(inputString[l]!='\0')
		{
			j=inputString[l]-97;
			matrix[i][j]++;
			l++;
		}
	}
	int count=0,flag;

	for(i=0;i<26;i++)
	{
		for(j=0;j<n;j++)
		{
			if(matrix[j][i]!=0)
				flag=1;
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			count++;
	}

	printf("%d\n",count);
	return 0;
}
