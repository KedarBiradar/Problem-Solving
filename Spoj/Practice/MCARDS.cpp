#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct tuple
{
    int clr,num;
    tuple(int cl,int cr) : clr(cl), num(cr) {}
/*
bool operator < (const tuple& t2) const
    {
	if(senior==t2.senior)
		return (prod > t2.prod);
	else
		return (senior > t2.senior);
    }*/
};

struct sorted_tuple
{
    int clr,num;
    tuple(int cl,int cr) : clr(cl), num(cr) {}

bool operator < (const tuple& t2) const
    {
	if(clr==t2.clr)
		return (num < t2.num);
	else
		return 0;
    }
};

/*
int compare(tuple t1,tuple t2)
{

	if(t1.clr==t2.clr)
	{
		return t1.num < t2.num;
	}
	else
		return 0;
}
*/

vector <tuple> cards(410);
vector <tuple> sortedCards(410);
vector <tuple> :: iterator it;

int min(int a,int b)
{
	return a<b?a:b;
}

int cost(int start,int end)
{
	int i;
	printf("cost of %d to %d=",start,end);

	it=lower_bound(sortedCards.begin()+start,sortedOrder.begin()+end-1,cards[end]);
/*
	if(color[end-1]==color[end] && cards[end-1]<cards[end] )
	{
			return 0;
	}
	for(i=start;i<end;i++)
	{
		if(color[i]==color[end])
		{
			printf("1\n");
			printf("position %d change required= %d %d\n",i,color[i],cards[i]);
			return 1;
		}
	}
	printf("0\n");
*/	return 0;
}

int main()
{

	int clr,crds,i,len;
	scanf("%d%d",&clr,&crds);
	for(i=1;i<=clr*crds;i++)
	{
		scanf("%d%d",&cards[i].clr,&cards[i].num);
	}

	if(crds==1)
		printf("00\n");
	else
	{

		crds*=clr;
		for(i=1;i<=crds;i++)
			m[i][i]=0;

		int c=crds;
		for(len=2;len<=c;len++)
		{
			for(i=1;i<crds;i++)
			{
				int tmp=calculateCost(i,i+len-1);
				int mn=min(m[i][i+len-2],m[i+1][i+len-1]);
				printf("cost= %d min=%d\n",tmp,mn);
				m[i][i+len-1]=tmp+mn;
			}
			crds--;
		}

		for(i=1;i<=c;i++)
		{		
			for(int j=1;j<=c;j++)
			{
				printf("%d\t",m[i][j]);
			}
			printf("\n");
		}


	}

	return 0;
}
