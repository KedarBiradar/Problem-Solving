/*

The aliens have arrived to Earth and everything is in harmony, the two races can live together. However, one specific Female Alien does not want to see humans on her way to the university, the alien must use the train as every human does. But she can choose any train station such she doesn’t see more than B humans, however, the Alien wants to go as far as possible with the train. Please, help her in this task

                        INPUT:
You will receive one integer T denoting the number of test cases, then, the next line will contain two integers At Bt where At and Bt is the number of stations in the train (1<=At<=100,000) and the number of people that the alien wants to see as maximum (1<=Bt<=10,000,000), after that, one line containing At integers separated by a single space will denote the number of people the Alien can find in the At-i-th station. (For each station there will be as much 100 people)
                        OUTPUT:
Your output should consist on T pair of numbers denoting the number of people the alien will see and the number of stations she will pass respectively.

SAMPLE:


INPUT:
1
5 100
20 15 30 80 100


OUTPUT
65 3

 

Output note:
The alien takes the train at station 1 (with 20 people) and goes to station 2, then the 3rd station, at this point, she have seen 65 people, if she decides to go to station 4 she will see 145 people… Then she exits the station.

The alien, however, can start at station 2 with 15 people, then continue up to the 4th station, then, she would have seen 125 people, but, as she wants to see the minimum people possible and this number of people exceeds what she wants to see, she decides to choose the way from the 1st to the 3rd station.

Clarification: The alien will be moving always forward (remember, she can choose any station as a start), NEVER backwards, and you should choose the best path that satisfies the output specification.
*/

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{

	long int t;
	long long int At,Bt,i;
	int cache[1000001];
	int mens[1000001];
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%lld%lld",&At,&Bt);
	
		for(i=0;i<At;i++)
		{
			scanf("%d",&mens[i]);
		}

		long int maxMen=0,noOfStn=0,maxStn=0;
		if(mens[0]<=Bt)
		{
			cache[0]=mens[0];
			maxMen=mens[0];
			noOfStn=1;
			maxStn=1;
		}
		else
			cache[0]=0;

		for(i=1;i<At;i++)
		{
			if(cache[i-1]+mens[i] <= Bt)
			{
				noOfStn++;
				cache[i]=cache[i-1]+mens[i];
				if( maxStn < noOfStn )
				{
					maxMen=cache[i];
					maxStn=noOfStn;
				}
				else if(maxStn == noOfStn && maxMen > cache[i])
					maxMen=cache[i];
			}
			else if(mens[i]<=Bt)
			{
				int j=i-noOfStn,tmp;
				tmp=cache[i-1];
				while(cache[i-1]+mens[i]>Bt && j<i)
				{
					cache[i-1]-=mens[j++];
					noOfStn--;
				}
				if(j==i)
				{
					cache[i]=mens[i];
					noOfStn=1;
					if(maxStn < noOfStn )
					{
						maxMen=cache[i];
						maxStn=noOfStn;
					}
					else if( maxStn==noOfStn && maxMen>cache[i])
						maxMen=cache[i];
				}
				else
				{
					noOfStn++;
					cache[i]=cache[i-1]+mens[i];
					if( maxStn < noOfStn )
					{
						maxMen=cache[i];
						maxStn=noOfStn;
					}
					else if(maxStn == noOfStn && maxMen>cache[i])
						maxMen=cache[i];
				}
			}
			else
			{
				noOfStn=0;
				cache[i]=0;
			}

		}

		printf("%ld %ld\n",maxMen,maxStn);
	}
	return 0;
}
