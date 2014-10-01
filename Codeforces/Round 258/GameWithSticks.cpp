#include <cstdio>
#include <iostream>

using namespace std;

int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int tmp=min(n,m);
	if(tmp%2==0)
		printf("Malvika\n");
	else
		printf("Akshat\n");
	return 0;
}
