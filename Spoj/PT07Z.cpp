#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

int dist[10000];
bool visited[100000];
int indegree[100000];
int BFS(vector< vector<int> >graph,int source,int v)
{
	int curr,i;
	for(i=0;i<=v;i++)
	{
		dist[i]=0;
		visited[i]=false;
	}
	queue<int> q;
	q.push(source);
	visited[source]=true;
	q.push(-1);
	int count=0;
	while(!q.empty())
	{

		curr=q.front();
		q.pop();
		if(curr==-1)
		{
			if(!q.empty())
			{
				count++;
				q.push(-1);
				continue;
			}
			else
				break;
		}
		dist[curr]=count;
		vector<int>::iterator it;
		for(it=graph[curr].begin();it!=graph[curr].end();it++)
		{
			if(!visited[*it])
			{
				visited[*it]=true;
				q.push(*it);
			}
		}
	}

	int max=dist[1];
	int index=1;
	for(i=2;i<=v;i++)
	{
		if(max<dist[i])
		{
			max=dist[i];
			index=i;
		}
	}
	return index;
}
int main()
{
	int n,e,i,s,d;
	scanf("%d",&n);
	e=n-1;
	vector< vector<int> >graph(n+1);
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&s,&d);
		graph[s].push_back(d);
		graph[d].push_back(s);
	}
	int node=BFS(graph,s,n);
	int ind=BFS(graph,node,n);
	printf("%d\n",dist[ind]);
	return 0;
}
