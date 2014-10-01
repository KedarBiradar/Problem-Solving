#include <cstdio>

int main()
{

	int t;
	scanf("%d",&t);
	while(t--)
	{
		int count=0;
		int n,k,d,x,y;
		char type[50002];
		scanf("%d%d",&n,&k);
		for(int i=0;i<=n;i++)
			type[i]=0;

		for(int i=0;i<k;i++)
		{
			scanf("%d%d%d",&d,&x,&y);
			if(x>n||y>n)
			{
				count++;
				continue;
			}
			if(d==1)
			{
				if(type[x]!=0 && type[y]!=0 && type[x]!=type[y])
				{
					count++;
					continue;
				}

				if(type[x]==0 && type[y]==0)
				{
					type[x]=type[y]='A';
				}
				else
				{
					if(type[x]==0 && type[y]!=0)
						type[x]=type[y];
					else
						type[y]=type[x];	
	
				}
				continue;
			}
			if(d==2)
			{
				if(x==y)
				{
					count++;
					continue;
				}
				if(type[x]!=0 && type[y]!=0)
				{
					if(type[x]=='A' && type[y]!='B')
					{
						count++;
						continue;
					}
					else if(type[x]=='B' && type[y]!='C')
					{
						count++;
						continue;
					}
					else if(type[x]=='C' && type[y]!='A')
					{
						count++;
						continue;
					}
				}
				else if(type[x]!=0 && type[y]==0)
				{
					switch(type[x])
					{
						case 'A':
								type[y]='B';
								break;

						case 'B':
								type[y]='C';
								break;

						case 'C':
								type[y]='A';
								break;
					}
				}
				else if(type[x]==0 && type[y]!=0)
				{
					switch(type[y])
					{
						case 'A':
								type[x]='C';
								break;

						case 'B':
								type[x]='A';
								break;

						case 'C':
								type[x]='B';
								break;
					}

				}
				else
				{
					type[x]='A';
					type[y]='B';
				}
			}			
		}
		printf("%d\n",count);
	}
}
