#include <cstdio>
#include <queue>
#include <limits.h>
#define INTMAX 99999
using namespace std;
char bitmap[200][200];
int n,m;
int dp[200][200];
bool visited[200][200];

struct tuple
{
	int x,y;
	tuple(int _x,int _y): x(_x), y(_y){}
};

bool isValid(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m)
		return true;
	else
		return false;

}
void BFS()
{
	int i,j;
	int dx[4]={1,-1,0,0};
	int dy[4]={0,0,1,-1};

	queue< tuple >q;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(bitmap[i][j]=='1')
			{
				q.push(tuple(i,j));
				visited[i][j]=true;
				dp[i][j]=0;
			}
			else
			{
				visited[i][j]=false;
				dp[i][j]=INTMAX;
			}
		}

	q.push(tuple(-1,-1));
	int x,y,count=0;
	while(!q.empty())
	{
		
		tuple t=q.front();
		q.pop();

		if(t.x==-1 && t.y==-1)
		{
			if(q.empty())
				break;
			else
			{
				count++;
				q.push(tuple(-1,-1));
				continue;
			}
		}

		if(dp[t.x][t.y]>count)
			dp[t.x][t.y]=count;
		for(i=0;i<4;i++)
		{
			x=t.x+dx[i];
			y=t.y+dy[i];
			if(isValid(x,y) && !visited[x][y] && bitmap[x][y]=='0')
			{
				q.push(tuple(x,y));
				visited[x][y]=true;
			}
		}

	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%s",bitmap[i]);	
		BFS();
	}
	return 0;
}
