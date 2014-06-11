/*


The Utopian tree goes through 2 cycles of growth every year. The first growth cycle of the tree is during the monsoon season when it doubles in height. The second growth cycle is during the summer when it increases in height by 1 meter. If a new Utopian tree sapling of height 1 meter is planted just before the onset of the monsoon season, can you find the height of the tree after N cycles?
*/


#include <stdio.h>
long long int calHeight(int N)
{

	long long int h=1;
	int i;
	for(i=1;i<=N;i++)
	{
		
		h*=2;
		i++;
		if(i<=N)
			h++;
		/*
		if(i%2==0)
			h++;
		else
			h*=2;
		*/
	}
	return h;
}

int main()
{

	long long int height;
	int t,N;

	scanf("%d",&t); 

	while(t>0)
	{

		scanf("%d",&N);

		if(N==0)
			printf("1\n");
		else
		{

			height=calHeight(N);
			printf("%lld\n",height);
		}	

		t--;
	}

return 0;
}
