#include <cstdio>
#include <stack>
#include <queue>

bool visited[20005];


using namespace std;
struct tuple
{
	int parent;
	char digit;
};

tuple array[20005];
void printNum(int i)
{
	if(i==-1)
		return;
	printNum(array[i].parent);
	putchar(array[i].digit);
}
void BFS(int num)
{
	queue<int> q;

	for(int i=0;i<num;i++)
		visited[i]=false;

	q.push(1);
	visited[1]=true;
	array[1].parent=-1;
	array[1].digit='1';
	while(true)
	{
		int curr=q.front();
		q.pop();
		int num1=(curr*(10%num))%num;
		int num2=(num1+1)%num;
		if(!visited[num1])
		{
			array[num1].parent=curr;
			array[num1].digit='0';
			if(num1==0)
				break;
			visited[num1]=true;
			q.push(num1);
		}
		if(!visited[num2])
		{
			array[num2].parent=curr;
			array[num2].digit='1';
			if(num2==0)
				break;
			visited[num2]=true;
			q.push(num2);
		}
	}
	printNum(0);
	printf("\n");
}

int main()
{
	int n,k;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&n);
		if(n==1)
			printf("1\n");
		else
			BFS(n);
	}
	return 0;
}
