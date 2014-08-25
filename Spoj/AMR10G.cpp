/*

My kid's kindergarten class is putting up a Christmas play.  (I hope he gets the lead role.)  The kids are all excited, but the teacher has a lot of work.  She has to produce costumes for a scene with K soldiers.  She wants to buy all the costumes in the same size, allowing for some small amount of length alteration to be done by the kids' parents later.  So she has taken all the kids' height measurements.  Can you help her select K kids from her class of N to play the soldier role, such that the height difference between the tallest and shortest in the group is minimized, and alternations will be easiest?  Tell her what this minimum difference is.
 
 
INPUT
The first line contains the number of test cases T. T test cases follow each containing 2 lines.
 
The first line of each test case contains 2 integers N and K.
The second line contains N integers denoting the height of the N kids.
 
OUTPUT
Output T lines, each line containing the required answer for the corresponding test case.
 
CONSTTRAINTS
T <= 30
1 <= K <= N <= 20000
1 <= height <= 1000000000
 
SAMPLE INPUT
3
3 1
2 5 4  
3 2
5 2 4  
3 3
2 5 4  
 
 
SAMPLE OUTPUT
0
1
3
 
EXPLANATION
In the first test case, the teacher needs to only select 1 kid and hence she can choose any kid since the height difference is going to be 0.
In the second test case, the teacher can choose kids with height 4 and 5.
In the third test case, the teacher is forced to choose all 3 kids and hence the answer = 5-2 = 3
*/

# include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n,k,t,i;
	long long int arr[20001],min;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);

		sort(arr,arr+n);

		if(k==1)
			printf("0\n");
		else if(k==n)
			printf("%lld\n",arr[n-1]-arr[0]);
		else
		{
			min=arr[k-1]-arr[0];
			for(i=1;i+k-1<n;i++)
			{
				if(arr[i+k-1]-arr[i] < min)
					min=arr[i+k-1]-arr[i];
			}
			printf("%lld\n",min);

		}
		
	}
	return 0;
}
