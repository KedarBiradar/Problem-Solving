#include <cstdio>
#include <algorithm>
#define gc getchar_unlocked

using namespace std;

void SI(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}

int LCA(int * parent,int x,int y,int n)
{
	bool *visited=new bool[n+1];
	for(int i=0;i<=n;i++)
		visited[i]=false;
	while(x!=-1)
	{
		visited[x]=true;
		x=parent[x];
	}
	while(visited[y]!=true)
	{
		y=parent[y];
	}
	delete visited;
	return y;
}
int main()
{
	int t,n,m,tst,tmp,i,j,x,y;
	SI(t);
	for(int c=1;c<=t;c++)
	{
		SI(n);
		int *parent=new int[n+1];
		for(i=0;i<=n;i++)
			parent[i]=-1;
		for(int i=1;i<=n;i++)
		{
			SI(m);
			for(j=0;j<m;j++)
			{
				SI(tmp);
				parent[tmp]=i;
			}
		}

		printf("Case %d:\n",c);
		SI(tst);
		while(tst--)
		{
			SI(x);
			SI(y);
			printf("%d\n",LCA(parent,x,y,n));
		}
		delete parent;
	}
	return  0;
}
