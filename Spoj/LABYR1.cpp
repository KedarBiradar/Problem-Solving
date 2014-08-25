#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

char input[1010][1010];
int R,C,I,J,best;


void DFS(int i, int j, int d)
{
	if(i<0 || i>=R || j<0 || j>=C || input[i][j]!='.') return;
	input[i][j] = 'v';
	DFS(i+1, j, d+1);
	DFS(i, j+1, d+1);
	DFS(i, j-1, d+1);
	DFS(i-1, j, d+1);
	input[i][j] = '.';
	if(d > best)
	{
		best = d;
		I = i;
		J = j;
	}
}

int maximum()
{
	int maxLen=0;
	if(input[I][J]!='.')
		return 0;

	while(true)
	{
		best=0;
		DFS(I,J, 0);
		if(best <= maxLen) 
			break;
		else maxLen = best;
	}
	return maxLen;

}
int main()
{
	int i,j,t;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&C,&R);
		for(i=0;i<R;i++)
		{
			scanf("%s",input[i]);
		}

		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
			{
				if(input[i][j]=='.')
				{
					I=i;
					J=j;
					break;
				}
			}
				printf("Maximum rope length is %d.\n",maximum());
	}
	return 0;
}
