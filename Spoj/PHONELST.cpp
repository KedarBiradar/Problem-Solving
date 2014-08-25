#include <cstdio>
#include <stdlib.h>
#include <string.h>

struct node
{
	bool endNode;
	node * child[10];
};

node * newNode()
{
	node * n=(node *)malloc(sizeof(node));
	n->endNode=false;
	for(int i=0;i<10;i++)
		n->child[i]=NULL;
	return n;
}

bool insert(node *root,char number[])
{
	int len=strlen(number);
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		if(curr->endNode)
			return true;
		if(curr->child[number[i]-48])
			curr=curr->child[number[i]-48];
		else
		{
			curr->child[number[i]-48]=newNode();
			curr=curr->child[number[i]-48];
		}
	}
	curr->endNode=true;
	for(int i=0;i<10;i++)
	{
		if(curr->child[i])
			return true;
	}
	return false;
}

void deleteTree(node * root)
{
	for(int i=0;i<10;i++)
	{
		if(root->child[i])
			deleteTree(root->child[i]);
	}
	delete root;
}
int main()
{
	int n,t,i;
	scanf("%d",&t);
	char number[11];
	bool flag;
	while(t--)
	{
		node *root=newNode();
		scanf("%d",&n);
		flag=false;
		for(i=0;i<n;i++)
		{
			scanf("%s",number);
			if(!flag)
			{
				if(insert(root,number))
					flag=true;
			}
		}
		if(!flag)
			printf("YES\n");
		else
			printf("NO\n");
		deleteTree(root);
	}
	return 0;
}
