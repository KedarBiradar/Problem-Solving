/*

 Byteman has a collection of N squares with side 1. How many different rectangles can he form using these squares?

Two rectangles are considered different if none of them can be rotated and moved to obtain the second one. During rectangle construction, Byteman can neither deform the squares nor put any squares upon any other ones.
Input

The first and only line of the standard input contains one integer N (1 ≤ N ≤ 10000).
Output

The first and only line of the standard output should contain a single integer equal to the number of different rectangles that Byteman can form using his squares.
Example

For the input data:

6

the correct result is:

8


*/


#include <cstdio>
#include <cmath>
int main()
{
	int n,sqr,i,j,count;
	scanf("%d",&n);
	count=0;
	sqr=sqrt(n);
	for(i=1;i<=sqr;i++)
		for(j=i+1;i*j<=n;j++)
			count++;

	printf("%d\n",sqr+count);
	return 0;
}
