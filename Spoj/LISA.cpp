#include <cstdio>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include<limits.h>

using namespace std;

void calmax(int * expr,char * sign,int n)
{
	int i,j,k,q,l,q1;
	long long cost[n+1][n+1],min_cost[n+1][n+1];
	for(i=0;i<=n;i++)
		min_cost[i][i]=cost[i][i]=expr[i];

	for(l=2;l<n+1;l++)
	{
		for(i=0;i<n-l+1;i++)
		{
			j=i+l-1;
			cost[i][j]=INT_MIN;
			min_cost[i][j]=INT_MAX;
			for(k=i;k<j;k++)
			{
				switch(sign[k])
				{
					case '+':		
							q=cost[i][k]+cost[k+1][j];
							q1=min_cost[i][k]+min_cost[k+1][j];
							break;
					case '*':		
							q=cost[i][k]*cost[k+1][j];
							q1=min_cost[i][k]*min_cost[k+1][j];
							break;
				}

				if(q>cost[i][j])
					cost[i][j]=q;

				if(q1<min_cost[i][j])
					min_cost[i][j]=q1;
											
			}
		}
	}

	printf("%lld %lld\n",cost[0][n-1],min_cost[0][n-1]);
}

int main()
{
	int t,l,k,i;
	scanf("%d",&t);
	char expr1[200],sign[200];
	int expr[200];
	while(t--)
	{
		scanf("%s",expr1);
		l=i=k=0;
		while(expr1[i]!='\0')
		{
			if(expr1[i]=='*' || expr1[i]== '+')
				sign[k++]=expr1[i];
			else
				expr[l++]=expr1[i]-48;
			i++;
		}
		sign[k]='\0';
		calmax(expr,sign,l);
	}
	return 0;
}
