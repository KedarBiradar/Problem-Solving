/*

Calvin is driving his favorite vehicle on the 101 freeway. He notices that the check engine light of his vehicle is on, and he wants to service it immediately to avoid any risks. Luckily, a service lane runs parallel to the highway. The length of the highway and the service lane is N units. The service lane consists of N segments of unit length, where each segment can have different widths.

Calvin can enter into and exit from any segment. Let’s call the entry segment as index i and the exit segment as index j. Assume that the exit segment lies after the entry segment(j>i) and i ≥ 0. Calvin has to pass through all segments from index i to indexj (both inclusive). 

Calvin has three types of vehicles - bike, car and truck, represented by 1, 2 and 3 respectively. These numbers also denote the width of the vehicle. We are given an array width[] of length N, where width[k] represents the width of kth segment of our service lane. It is guaranteed that while servicing he can pass through at most 1000 segments, including entry and exit segments.

    If width[k] is 1, only the bike can pass through kth segment.

    If width[k] is 2, the bike and car can pass through kth segment.

    If width[k] is 3, any of the bike, car or truck can pass through kth segment.

Given the entry and exit point of Calvin’s vehicle in the service lane, output the type of largest vehicle which can pass through the service lane (including the entry & exit segment)
*/


#include <stdio.h>

int main()
{

	int t,n,i,j,index,min;
	int width[100001];
	scanf("%d",&n);
	
	scanf("%d",&t);

	for(i=0;i<n;i++)
		scanf("%d",&width[i]);

	
	while(t>0)
	{
		scanf("%d%d",&i,&j);
		min=3;
		for(index=i;index<=j;index++)
		{
			if(min>width[index])
				min=width[index];

			if(min==1)
			{
				break;
			}
		}
		printf("%d\n",min);

		t--;
	}

	return 0;
}
