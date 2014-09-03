
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define gc getchar_unlocked

void SS(int &x)
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

struct node{
    int pos,len,cost;
    
    node(){}
    
    node(int _pos, int _len, int _cost){
        pos = _pos; len = _len; cost = _cost;
    }
    
    bool operator < (node X)const{
        if(len != X.len) return len > X.len;
        return cost > X.cost;
    }
}aux;

bool visited[100][10001];
vector<int> to[100],P[100],L[100];

void dijkstra(int N,int K)
{
	priority_queue<node> Q;
	Q.push(node(0,0,0));
	memset(visited,false,sizeof(visited));    
	int ans = -1;     
	while(!Q.empty())
	{
		aux = Q.top();
		Q.pop();          
		if(visited[aux.pos][aux.cost]) continue;
		visited[aux.pos][aux.cost] = true;           
		if(aux.pos == N-1)
		{
			ans = aux.len;
			break;
		}         
		for(int i = to[aux.pos].size()-1;i >= 0;--i)
		{
			int pos2 = to[aux.pos][i];
			int l2 = aux.len + L[aux.pos][i];
			int cost2 = aux.cost + P[aux.pos][i];
			if(cost2 <= K) Q.push(node(pos2,l2,cost2));
		}
	}
	printf("%d\n",ans);
}


int main()
{
	int T,K,N,R;   
	//scanf("%d",&T);    
	SS(T);
	while(T--)
	{
		//scanf("%d %d %d",&K,&N,&R);    
		SS(K);
		SS(N);
		SS(R);
		for(int i = 0;i < N;++i)
		{
			to[i].clear();
			P[i].clear();
			L[i].clear();
		}      
		for(int i = 0,u,v,l,p;i < R;++i)
		{
			//scanf("%d %d %d %d",&u,&v,&l,&p);
			SS(u);
			SS(v);
			SS(l);
			SS(p);
			--u; --v;
			to[u].push_back(v);
			L[u].push_back(l);
			P[u].push_back(p);
		}
		dijkstra(N,K);	
	}
	return 0;
}
