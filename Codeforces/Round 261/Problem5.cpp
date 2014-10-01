#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
class tuple
{
	public:
	int s,d,w,t;
	//tuple(int _s,int _d,int _w): s(_s), d(_d),w(_w){}
	void read()
	{
		scanf("%d%d%d",&s,&d,&w);
	}
};
tuple array[350000];
int dp[350000];
int n,m,s,last,ans;

int cmp(const void *a,const void *b)
{
    return ((tuple*)a)->w-((tuple*)b)->w;
}

void cal_path(int i)
{
	while(s<i)
	{
	        if (array[s].t>dp[array[s].d])
	            dp[array[s].d]=array[s].t;
	        s++;
    }
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	//int s,d,w;
	for(i=0;i<m;i++)
	{
		array[i].read();
	}
	qsort(array,m,sizeof(tuple),cmp);
	s=0;
	last=0;
	for(i=0;i<m;i++)
	{
		if(array[i].w!=last)
		{
			cal_path(i);
			last=array[i].w;
		}
		array[i].t=dp[array[i].s]+1;
	}
	cal_path(m);

	ans=1;
	for(i=1;i<=n;i++)
	{
		if(dp[i]>ans)
			ans=dp[i];
	}
	printf("%d\n",ans);
	return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

class Path{
    public:
    int u,v,w,t;
    void read(){
        scanf("%d%d%d",&u,&v,&w);
    }
} path;

Path p[350000];
int f[350000];
int n,m,s,last,ans;

int cmp(const void *a,const void *b){
    return ((Path*)a)->w-((Path*)b)->w;
}
void post(int i){
    while(s<i){
        if (p[s].t>f[p[s].v])
            f[p[s].v]=p[s].t;
        s++;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;++i)
        p[i].read();
    qsort(p,m,sizeof(Path),cmp);
    s=0;
    last=0;
    for (int i=0;i<m;++i){
        if (last!=p[i].w){
            post(i);
            last=p[i].w;
        }
        p[i].t=f[p[i].u]+1;
    }
    post(m);
    ans=1;
    for (int i=1;i<=n;++i)
        if (f[i]>ans)
            ans=f[i];
    printf("%d\n",ans);
    return 0;
}

*/
/*
int solution(vector< vector< tuple > > graph,int start,int maxwt,int count)
{
	int max=count;
	vector< tuple >::iterator it;
	for(it=graph[start].begin();it!=graph[start].end();it++)
	{
		tuple t=*it;
		if(t.w>maxwt)
		{
			int tmp=solution(graph,t.d,t.w,count+1);
			if(tmp>max)
				max=tmp;
		}
	}
	return max;
}*/
/*
int sol(vector< vector< tuple > > graph,vector < vector <tuple> > set)
{
	bool flag=false;
	int len;
	vector< tuple >::iterator it,it1;
	int prev,curr;
	prev=0;
	curr=1;
	for(len=2;len<=e;len++)
	{
		for(it=set[prev].begin();it!=set[prev].end();it++)
		{
			tuple t=*it;
			for(it1=graph[t.d].begin();it1!=graph[t.d].end();it1++)
			{
				tuple t1=*it1;
				if(t1.w>t.w)
				{
					set[curr].push_back(tuple(t1.d,t1.w));
					flag=true;
				}
			}
			//set[prev].erase(set[prev].begin());
		}
		if(flag==false)
			break;
		else
		{
			set[prev]=set[curr];
			set[curr].clear();
			flag=false;
		}
	}
	return len-1;
}
*/

