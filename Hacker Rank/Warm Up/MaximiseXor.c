#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r) 
{

	int a,b,max=l;
	a=l;
	b=r;
	for(a=l;a<b;a++)
	{
		for(b=r;b>a;b--)
		{
			if((a^b)>max)
				max=a^b;
		}
	}

	return max;
}
int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}
