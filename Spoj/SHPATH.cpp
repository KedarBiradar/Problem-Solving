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


map <string,int> nameMap;

int distanc[10010];
bool visited[10010];

struct tuple
{
	int src,dist;
	tuple(int s,int d): src(s),dist(d){}
};

struct tuple2
{
	int dst,wt;
	tuple2(int d,int w): dst(d),wt(w){}
};

class compare{
	public:
	bool operator()(tuple &n1,tuple &n2){
		if(n1.dist > n2.dist) return true;
		else return false;
	}	
};
int Dijkstra(vector < vector < tuple2 > > graph,int source, int dest,int n)
{
	priority_queue <tuple,vector<tuple>,compare > q;
	int i;
	q.push(tuple(source,0));
	
	vector < tuple2 >:: iterator it;
	for(i=0;i<=n;i++)
	{
		distanc[i]=INT_MAX;
		visited[i]=false;
	}

	distanc[source]=0;

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

				if(distanc[t2.dst]==INT_MAX)
				{
					distanc[t2.dst]=d;
					q.push(tuple(t2.dst,d));
				}
				else if(distanc[t2.dst]>d)
				{
					distanc[t2.dst]=d;
					q.push(tuple(t2.dst,d));
				}
			}
		}
		if(visited[dest]) break;	
	}
	return distanc[dest];
}

int main()
{
	int t;
	//scanf("%d",&t);
	scanint(t);
	while(t--)
	{
		int n,s,d,wt,i,r,p;
		string name;
		//scanf("%d",&n);
		scanint(n);
		vector < vector < tuple2 > > graph(n+1);
		for(i=1;i<=n;i++)
		{
			cin>>name;
			nameMap[name] = i;
			//scanf("%d",&p);
			scanint(p);
			for(int j=0;j<p;j++)
			{
				//scanf("%d%d",&d,&wt);
				scanint(d);
				scanint(wt);
				graph[i].push_back(tuple2(d,wt));
			}

		}
		//scanf("%d",&r);
		scanint(r);
		string source,dest;
		for(i=0;i<r;i++)
		{
			cin>>source>>dest;
			s=nameMap.at(source);
			d=nameMap.at(dest);
			printf("%d\n",Dijkstra(graph,s,d,n));
		}
		//printf("\n");
	}
	return 0;
}
