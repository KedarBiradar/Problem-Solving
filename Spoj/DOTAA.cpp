#include <stdio.h>

using namespace std;
int main()
{
	int t,n,m,D,i;
	int arr[501];
	scanf("%d",&t);
	//printf("%d",t);
	while(t>0)
	{
		t--;
		scanf("%d%d%d",&n,&m,&D);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}

		int count=0,count2;
		while(count<m)
		{
			count2=0;
			for(i=0;i<n;i++)
			{
				/*if(arr[i]==0)
				{
					flag=1;
					break;
				}*/
				if(arr[i]>D)
				{
					arr[i]-=D;
					count++;
					if(count==m)
						break;
				}
				else if(arr[i]<=D)
				{
					count2++;
				}
			}
			if(count2==n)
			{
				printf("NO\n");
				break;
			}
		}
		if(count==m)
		{		
			printf("YES\n");
		}
		

	}
	return 0;
}
