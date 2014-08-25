/*

After solving "AP - Complete The Series (easy)" very fast, Lucifer decided to make it little more interesting.

He said

He will be give you the 3rd term , 4th last term and the sum of the AP series. You need print length of the series & the series.
Input

First line will contain a number indicating the number of test cases.

Each of the following t lines will have 3 number '3term' ,'4Lastterm' and 'sum'

3term  - is the 3rd term in of the series and

4Lastterm  - is the 4th term in of the series and

sum - is the sum of the series.
Output

For each input of the test case, you need to print 2 lines.

fist line should have 1 value- number of terms in the series.

2nd line of the output should print the series numbers separated by single space.

 
Example

 

Input:

1
3 7 55


Output:
10
1 2 3 4 5 6 7 8 9 10

NOTE - In all the test cases all the series elements are positive integers.
The series will have at least 7 elements.
number of test cases <=100.
All the numbers will fit in 64 bits(long long in C)
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int t;
//	int t,n,diff,i;
	scanf("%d",&t);
//	long long int n3,n3n,sum,start,a,b,c,d,r1,r2;
	long long int a3,a3l,s,i,a,d,len; 
	long double n,sq,diff;
	while(t--)
	{
	      scanf("%lld",&a3);
	      scanf("%lld",&a3l);
	      scanf("%lld",&s);
	     
	      sq=sqrtl(((5.0*a3l+7.0*a3+2.0*s)*(5.0*a3l+7.0*a3+2.0*s))-(48.0*(a3l+a3)*s));
	      n=((5.0*a3l+7.0*a3+2.0*s)+sq)/(2.0*(a3l+a3));
     
	      len=llrintl(n);
	 printf("%lld\n",len);
      diff=(a3l-a3)/(len-6.0);
      d=llrintl(diff);
      a=(a3-(2*d));
      for(i=0;i<len;i++)
       {
                       printf("%lld ",a+i*d);
       }
        printf("\n");
       
/*		scanf("%lld%lld%lld",&n3,&n3n,&sum);
		a=(n3+n3n);
		b=(7*n3+5*n3n+(2*sum));
		c=12*sum;

		d=(b*b)-(4*a*c);
		r1=floorl(abs((-b-sqrtl(d))/(2*a)));
		r2=ceill(abs((-b+sqrtl(d))/(2*a)));

		//printf("%lld and %lld\n",r1,r2);
		n=r1>r2?r1:r2;
		//n++;

		//diff=(sum-(n*n3))/(((n*(n-1))/2)-(2*n));
		diff=(n3n-n3)/(n-6);
		
		//printf("%d-%d\n",n,diff);
		start=n3-(2*diff);
		printf("%d\n",n);
		for(i=0;i<n;i++)
		{
			printf("%lld ",start);
			start+=diff;
		}	
		//printf("\n");	
*/		
	}
	return 0;
}
