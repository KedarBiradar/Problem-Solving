#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
#define MAX 100000
#define MAX_VAL 1000000001

int candies[MAX];

/** The code to read from STDIN and output to STDOUT has been provided by us, for convenience. You may or may not use this. **/
 
int main() {
    
    int N,K;
    int i;
    
    scanf("%d %d",&N,&K);
    for(i = 0;i < N;i++)
        scanf("%d",candies + i);
  
	sort(candies,candies+N);
    //int unfairness = // Compute the min unfairness over here, using N,K,candies
        
	int min=candies[K-1]-candies[0];

	for(i=K;i<N;i++)
	{
		if(min>(candies[i]-candies[i-K+1]))
			min=candies[i]-candies[i-K+1];
	}
    printf("%d",min);
    return 0;
}
