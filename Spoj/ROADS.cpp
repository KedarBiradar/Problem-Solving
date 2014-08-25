#include <cstdio>
#include <limits.h>
#include <map>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define gc getchar_unlocked

void scanint(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}

int distanc[10010];
int cost[10010];
bool visited[10010];

struct tuple
{
	int src,dist,cs;
	tuple(int s,int d,int cc): src(s),dist(d),cs(cc){}
};

struct tuple2
{
	int dst,wt,cst;
	tuple2(int d,int w,int c): dst(d),wt(w),cst(c){}
	/*bool operator < (const tuple2 &t2) const
	{
			if(dst == t2.dst)
				return cst < t2.cst;
	}*/
};

class compare{
	public:
	bool operator()(tuple &n1,tuple &n2){

		if(n1.cs > n2.cs) 
			return true;
		else if(n1.cs==n2.cs && n1.dist > n2.dist)
			return true;		
		else
			return false;
	}	
};
int Dijkstra(vector < vector < tuple2 > > graph,int source, int dest,int n,int k)
{
	priority_queue <tuple,vector<tuple>,compare > q;
	int i;
	q.push(tuple(source,0,0));
	
	vector < tuple2 >:: iterator it;
	for(i=0;i<=n;i++)
	{
		distanc[i]=INT_MAX;
		visited[i]=false;
		cost[i]=INT_MAX;
	}

	distanc[source]=0;
	cost[source]=0;

	while(!q.empty())
	{
		tuple t=q.top();
		q.pop();
		if(!visited[t.src])
		{
			visited[t.src]=true;
			for(it=graph[t.src].begin();it!=graph[t.src].end();it++)
			{
				tuple2 t2=*it;
				int d=distanc[t.src]+t2.wt;
				int c=cost[t.src]+t2.cst;

				if(cost[t2.dst]==INT_MAX)
				{
					cost[t2.dst]=c;
					distanc[t2.dst]=d;
					q.push(tuple(t2.dst,d,c));
				}
				else if(cost[t2.dst]>c)
				{
					cost[t2.dst]=c;
					distanc[t2.dst]=d;
					q.push(tuple(t2.dst,d,c));
				}
				else if(cost[t2.dst]==c && distanc[t2.dst] > d)
				{
					distanc[t2.dst]=d;
					q.push(tuple(t2.dst,d,c));
				}
			}
		}
		if(visited[dest]) break;	
	}
	if(cost[dest]==INT_MAX || cost[dest] > k )
		return -1;
	else
		return distanc[dest];
}

int main()
{
	int t;
	scanint(t);
	while(t--)
	{
		int n,k,r,i,s,l,d,c;
		string name;
		scanint(k);
		scanint(n);
		scanint(r);
		vector < vector < tuple2 > > graph(n+1);
		vector < vector < tuple2 > >::iterator it;
		vector < tuple2 >::iterator  it1;

		for(i=0;i<r;i++)
		{
			scanint(s);
			scanint(d);
			scanint(l);
			scanint(c);
			if(d==s)
				continue;

			it1=graph[s].begin();
			int flag=0;
			while(it1!=graph[s].end())
			{
				tuple2 t2=*it1;
				if(t2.dst==d)
				{
					if(t2.cst > c)
						{it1=graph[s].erase(it1); break;}

					else if(t2.cst==c && t2.wt > l)
						{it1=graph[s].erase(it1);break;}

					else if(t2.cst<c)
						{ flag=1; break;}

					else if(t2.cst==c && t2.wt < l)
						{ flag=1; break;}
				}
					else ++it1;
			}
			if(flag==0)
				graph[s].push_back(tuple2(d,l,c));
		}
		/*printf("Given graph is::\n");

		for(it=graph.begin(),i=0;it!=graph.end();it++,i++)
		{
			for(it1=graph[i].begin();it1!=graph[i].end();it1++)
			{
				tuple2 t2=*it1;
				printf("dest=%d path=%d cost=%d\n",t2.dst,t2.wt,t2.cst);
			}
			printf("\n");
		}*/
			printf("%d\n",Dijkstra(graph,1,n,n,k));
	}
	return 0;
}
