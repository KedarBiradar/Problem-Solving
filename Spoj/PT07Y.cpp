#include <cstdio>
#include <vector>
#include <stack>
#define gc getchar_unlocked

void si(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}

using namespace std;

bool visited[10010];
void DFS(vector< vector<int> >graph,int source)
{
	int curr;
	vector<int>::iterator it;
	stack<int> stk;
	
	visited[source]=true;
	stk.push(source);

	while(!stk.empty())
	{
		curr=stk.top();
		stk.pop();
		for(it=graph[curr].begin();it!=graph[curr].end();it++)
		{
			if(!visited[*it])
			{
				visited[*it]=true;
				stk.push(*it);
			}
		}
	}
}

int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

bool isCycle(vector< vector<int> >graph,int v)
{
	int i;
	int *parent=new int[v+1];
	vector<int>::iterator it;
	for(i=0;i<=v;i++)
		parent[i]=-1;

	for(i=1;i<=v;i++)
	{
		for(it=graph[i].begin();it!=graph[i].end();it++)
		{
			int x=find(parent,i);
			int y=find(parent,*it);

			if(x==y)
				return true;
			Union(parent,x,y);
		}
	}
	return false;
}
int main()
{
	int v,e,i,s,d;
	si(v);
	si(e);

	vector<vector<int> >graph(v+1);

	for(i=0;i<e;i++)
	{
		si(s);
		si(d);
		graph[s].push_back(d);
	}

	if(!isCycle(graph,v))
	{
		for(i=0;i<=v;i++)
			visited[i]=false;

		DFS(graph,1);

		int flag=0;
		for(i=1;i<=v;i++)
		{
			if(!visited[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	else
		printf("NO\n");
	return 0;
}
