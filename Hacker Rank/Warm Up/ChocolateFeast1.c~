#include <stdio.h>

int main()
{

	int t;
	long int n,c,m;
	scanf("%d",&t);
	long int chocGet,chocOnDesc,chocRem,total;
	while(t>0)
	{
		scanf("%ld%ld%ld",&n,&c,&m);

		chocGet=n/c;
		chocOnDesc=chocGet/m;
		chocRem=chocGet%m;
		total=chocGet;
		if(chocOnDesc+chocRem>=m)
		{
			total+=chocOnDesc;
			while(chocOnDesc+chocRem>=m)
			{
				chocGet=chocOnDesc+chocRem;
				chocOnDesc=chocGet/m;
				chocRem=chocGet%m;
				total+=chocOnDesc;
			}
		}
		else
			total+=chocOnDesc;

		printf("%ld\n",total);
		t--;
	}
	return 0;
}
