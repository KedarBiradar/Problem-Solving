#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
bool isPrime[10010];
void sieve()
{
	int i,j;
	for(i=2;i<=100;i++)
	{
		if(!isPrime[i])
		{
			for(j=i*i;j<=10000;j+=i)
				isPrime[j]=true;
		}
	}
}
void toArr(int arr[],int num)
{
	int k=3;
	while(num)
	{
		arr[k]=num%10;
		num/=10;
		k--;
	}
}
int toNumber(int arr[])
{
	int k=0,num=0;
	while(k<4)
	{
		num=num*10+arr[k];
		k++;
	}
	return num;
}

int main()
{
	int t;
	sieve();
	scanf("%d",&t);
	int num_arr[4],a,b,parent[10010],step[10010];
	while(t--)
	{
		queue<int> q;
		scanf("%d%d",&a,&b);
		memset(parent,-1,sizeof(parent));
		memset(step,-1,sizeof(step));
		parent[a]=0;
		step[a]=0;
		q.push(a);
		while(!q.empty())
		{
			int num=q.front();
			for(int i=3;i>=0;i--)
			{
				toArr(num_arr,num);
				for(int k=0;k<=9;k++)
				{
					num_arr[i]=k;
					int tmp=toNumber(num_arr);
					if((!isPrime[tmp]) && step[tmp]==-1 && tmp>=1000)
					{
						step[tmp]=step[num]+1;
						parent[tmp]=num;
						q.push(tmp);
					}
				}
			}
			q.pop();	
		}
		if(step[b]==-1)
			printf("Impossible\n");
		else
			printf("%d\n",step[b]);

	}
	return 0;
}
