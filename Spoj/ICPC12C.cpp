#include <cstdio>

int main()
{

	int t,i,j,len2,flag;
	scanf("%d",&t);
	char str[100001],str2[100001],arr[26],arr2[26];
	while(t--)
	{
		scanf("%s",str);
		scanf("%s",str2);
		for(i=0;i<26;i++)
			arr[i]=arr2[i]=0;
		i=0;
		while(str2[i]!='\0')
		{
			arr2[str2[i++]-97]++;
		}
		len2=i;
		i=0;
		while(i<len2)
		{
			arr[str[i++]-97]++;
		}
		for(j=0;j<26;j++)
		{
			if(arr[j]!=arr2[j])
				break;
		}
		if(j==26)
		{
			printf("YES\n");
			continue;
		}

		flag=0;
		while(str[i-1]!='\0')
		{
			for(j=0;j<26;j++)
			{
				if(arr[j]!=arr2[j])
					break;
			}
			if(j==26)
			{
				printf("YES\n");
				flag=1;
				break;
			}

			arr[str[i-len2]-97]--;
			arr[str[i++]-97]++;
		}
		if(flag==0)
			printf("NO\n");

	}
	return 0;
}
