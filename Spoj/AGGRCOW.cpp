/*

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input

t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output

For each test case output one integer: the largest minimum distance.
Example

Input:

1
5 3
1
2
8
4
9

Output:

3

Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/

#include <iostream>
#include <algorithm>
#include <stdio.h>

int main()
{
	int t;
	long long int i,min,n,c,step;
	scanf("%d",&t);
	long long int stall[100002];
	while(t--)
	{
		scanf("%lld%lld",&n,&c);

		for(i=0;i<n;i++)
			scanf("%lld",&stall[i]);

		std::sort(stall,stall+n);

		step=((n-c)/(c-1))+1;
		min=stall[step]-stall[0];
		for(i=1;i<n-step;i++)
		{
			if(stall[i+step]-stall[i] < min )
				min=stall[i+step]-stall[i];
		}

		printf("%lld\n",min);

	}

}
