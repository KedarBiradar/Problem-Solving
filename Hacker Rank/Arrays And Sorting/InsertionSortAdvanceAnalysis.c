#include <stdio.h>

long int tmp[1000001];
long int merge(long int arr[],long int min,long int mid,long int max)
{
  long int count=0;
  long int i,j,k,m; 
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
	count=count+(mid-j+1);

     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];

	return count;
}



long int part(long int arr[],long int min,long int max)
{
	 long int mid,total=0,result=0,leftResult=0,rightResult=0;
	 if(min<max)
	 {
	   mid=(min+max)/2;
	   leftResult=part(arr,min,mid);
	   rightResult=part(arr,mid+1,max);
	   result=merge(arr,min,mid,max);
	   total=result+leftResult+rightResult;
	 }
		return total;
}


int main()
{
	int t;
	long int n,i,result;
	long int a[1000001];
	scanf("%d",&t);

	while(t>0)
	{
		scanf("%ld",&n);
			for(i=0;i<n;i++)
				scanf("%ld",&a[i]);

		//printf("before calling");
		result=part(a,0,n-1);
		//printf("after calling");
		printf("%ld\n",result);

		t--;
	}	
	return 0;
}
