#include <cstdio>

int main()
{
	int arr[27];
	int t,i;
	char str1[32],str2[32];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<27;i++)
			arr[i]=0;

		scanf("%s%s",str1,str2);
		i=0;
		while(str1[i]!=0)
		{
			arr[str1[i]-97]++;
			i++;
		}
		i=0;
		while(str2[i]!=0)
		{
			arr[str2[i]-97]--;
			i++;
		}
		
		for(i=0;i<27;i++)
			if(arr[i]!=0)
				break;

		if(i==27)
			printf("YES\n");
		else
			printf("NO\n");

	}	

	return 0;
}
