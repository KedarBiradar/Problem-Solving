#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <vector>
using namespace std;

void BFS(std::vector< int > *vlist,int* vert,int vertex)
{
	std::list<int> q;
	
	vert[vertex]=1;
	q.push_back(vertex);
	
	while(!q.empty())
	{
		int curr=q.front();
		q.pop_front();
		
		int nebor=vlist[curr].size();
		for(int i=0;i<nebor;i++)
		{
			if(vert[vlist[curr].at(i)]==1)
				continue;
			q.push_back(vlist[curr].at(i));
			vert[vlist[curr].at(i)]=1;
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-- > 0)
	{
		int* vert;
		int edge,v,count=0;
		scanf("%d%d",&v,&edge);
		vert=(int*)calloc(v,sizeof(int));
		
		std::vector< int > *vlist=new std::vector<int>[v];
				
		for(int i=0;i<edge;i++)
		{
			int v1,v2;
			scanf("%d%d",&v1,&v2);
			if(v1>=v || v2>=v)
				continue;
			if(v1==v2)
				continue;
				
			vlist[v1].push_back(v2);
			vlist[v2].push_back(v1);
		}
	
		for(int i=0;i<v;i++)
		{
			if(vert[i]==1)
				continue;
			count++;
			BFS(vlist,vert,i);
		}
		
		printf("%d\n",count);
		//cout<<count<<endl;
	}

	return 0;
}
