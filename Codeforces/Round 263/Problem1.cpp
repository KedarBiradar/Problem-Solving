#include <cstdio>

char arr[101][101];
int n;

bool isValid(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<n)
		return true;
	else
		return false;
}
bool check(int i,int j)
{
	static int x[4]={-1,1,0,0};
	static int y[4]={0,0,-1,1};
	int count=0;
	for(int m=0;m<4;m++)
	{
		if(isValid(i+x[m],j+y[m]) && arr[i+x[m]][j+y[m]]=='o')
			count++;
	}
	if(count%2==0)
		return true;
	else
		return false;
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(!check(i,j))
			{
				printf("NO\n");
				break;
			}
		}
		if(j!=n)
			break;
	}
	if(i==n)
		printf("YES\n");
	return 0;
}
