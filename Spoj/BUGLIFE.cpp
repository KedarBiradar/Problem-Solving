#include <cstdio>
#include <queue>
#include <string.h>

int V;
using namespace std;

bool isBipartite(int **G, int src)
{
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;
    colorArr[src] = 1;
    queue <int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; ++v)
        {
            if (G[u][v] && colorArr[v] == -1)
            {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
             else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
    return true;
}

int main()
{
	int t,k=0,v,s,d,**G;
	long long int i,j,e;
	scanf("%d",&t);
	while(t--)
	{
		k++;
		s=0;
		d=0;
		scanf("%d%lld",&v,&e);
		v++;
		G = new int*[v];
		for(i = 0; i < v; ++i) 
		{
		    G[i] = new int[v];
		}
		V=v;
		for(i=0;i<v;i++)
			for(j=0;j<v;j++)
				G[i][j]=0;
		for(i=0;i<e;i++)
		{
			scanf("%d%d",&s,&d);
			G[s][d]=1;
			G[d][s]=1;
		}
		printf("Scenario #%d:\n",k);
		if(isBipartite(G,s))
			 printf("No suspicious bugs found!\n");	
		else
			printf("Suspicious bugs found!\n");

		for(i = 0; i < v; ++i)
		 {
    			delete [] G[i];
		 }	
		delete [] G;
	}
	return 0;	
}
