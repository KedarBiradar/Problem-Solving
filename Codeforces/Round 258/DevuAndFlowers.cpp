/*
E. Devu and Flowers
time limit per test
4 seconds
memory limit per test
256 megabytes
input
standard input
output
standard output

Devu wants to decorate his garden with flowers. He has purchased n boxes, where the i-th box contains fi flowers. All flowers in a single box are of the same color (hence they are indistinguishable). Also, no two boxes have flowers of the same color.

Now Devu wants to select exactly s flowers from the boxes to decorate his garden. Devu would like to know, in how many different ways can he select the flowers from each box? Since this number may be very large, he asks you to find the number modulo (109 + 7).

Devu considers two ways different if there is at least one box from which different number of flowers are selected in these two ways.
Input

The first line of input contains two space-separated integers n and s (1 ≤ n ≤ 20, 0 ≤ s ≤ 1014).

The second line contains n space-separated integers f1, f2, ... fn (0 ≤ fi ≤ 1012).
Output

Output a single integer — the number of ways in which Devu can select the flowers modulo (109 + 7).
*/

#include <cstdio>

long long array[22],total;
int n;

void recursion(int index,long long remain)
{
	if(index>n-1)
		return;
	if(index==n-1)
	for(int j=0;j<=remain && j<=array[index];j++)
		if(remain-j==0)
		total++;

	for(int i=0;i<=array[index];i++)
		recursion(index+1,remain-i);
}

void iterate(int index,int remain)
{
	while(index<n)
	{
		for(int i=0;i<=array[index];i++)
		{
		
		}
	}
}
int main()
{
	//int n;
	long long s;
	scanf("%d%lld",&n,&s);
	total=0;
	for(int i=0;i<n;i++)
		scanf("%lld",&array[i]);

	recursion(0,s);
	printf("%lld\n",total);	
	return 0;
}
