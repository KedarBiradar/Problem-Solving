/*
B. Sort the Array
time limit per test
1 second
memory limit per test
256 megabytes
input
standard input
output
standard output

Being a programmer, you like arrays a lot. For your birthday, your friends have given you an array a consisting of n distinct integers.

Unfortunately, the size of a is too small. You want a bigger array! Your friends agree to give you a bigger array, but only if you are able to answer the following question correctly: is it possible to sort the array a (in increasing order) by reversing exactly one segment of a? See definitions of segment and reversing in the notes.
Input

The first line of the input contains an integer n (1 ≤ n ≤ 105) — the size of array a.

The second line contains n distinct space-separated integers: a[1], a[2], ..., a[n] (1 ≤ a[i] ≤ 109).
Output

Print "yes" or "no" (without quotes), depending on the answer.

If your answer is "yes", then also print two space-separated integers denoting start and end (start must not be greater than end) indices of the segment to be reversed. If there are multiple ways of selecting these indices, print any of them.
*/

#include <cstdio>

long long array[100010];

void reverse(int i,int j)
{
	int temp;
	while(i<j)
	{
		temp=array[i];
		array[i]=array[j];
		array[j]=temp;
		i++;
		j--;
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&array[i]);
	}
	int start=-1,end=-1;
	//bool desc=false;
	for(i=0;i<n-1;i++)
	{
		if(array[i]>array[i+1])
		{
			//desc=true;
			start=i;
			break;
		}
	}
	for(i=n-1;i>0;i--)
	{
		if(array[i] < array[i-1])
		{
			end=i;
			break;
		}
	}
	reverse(start,end);
	for(i=0;i<n-1;i++)
	{
		if(array[i]>array[i+1])
			break;
	}
	if(start==-1)
		printf("yes\n1 1\n");
	else if(end==-1)
		printf("yes\n1 %d\n",n);
	else if(i==n-1)
		printf("yes\n%d %d\n",start+1,end+1);
	else
		printf("no\n");
	return 0;
}
