#include<stdio.h>
#include<string.h>

int compare(char *num1,char *num2)
{

	int x;
	x=strcmp(num1,num2);
	if(x==0)
		return 0;
	else if(x<0)
		return -1;
	else
		return 1;

}
void odd(char *number,int length)
{

int mid,flag,i,j;
char temp[1000002],temp1[1000003];

mid=length/2;


	strcpy(temp,number);

	for(i=0;i<mid;i++)
	{
		temp[length-1-i]=temp[i];
	}

	flag=compare(temp,number);

	if(flag==1)					//if palindrome of given number greater
	{
		printf("%s\n",temp);
	}
/*	else if(flag==0)
	{

		if(temp[mid]!='9')			//if middle number less than 9
		{
			temp[mid]++;
		}

		else
		{

			j=0;
			while(temp[mid-j]=='9'&&j<=mid)			//if middle element is 9
			{
				temp[mid-j]='0';
				j++;
			}
			if(j<=mid)				// not all digits are 9
			{
				temp[mid-j]++;
				for(i=0;i<mid;i++)
				{
					temp[length-1-i]=temp[i];
				}

			}

			else					//all digits are 9
			{
				for(i=0;i<mid;i++)
				{
					temp[length-1-i]=temp[i];
				}

				strcpy(temp1,"1");
				strcat(temp1,temp);
				strcpy(temp,temp1);
				temp[length]='1';
			}

		}






		printf("already palindrome=%s\n",temp);
	}	

*/
	else
	{


		if(temp[mid]!='9')			//if middle number less than 9
		{
			temp[mid]++;
			
		}

		else
		{

			j=0;
			while(temp[mid-j]=='9'&&j<=mid)			//if middle element is 9
			{
				temp[mid-j]='0';
				j++;
			}
			if(j<=mid)				// not all digits are 9
			{
				temp[mid-j]++;
				for(i=0;i<mid;i++)
				{
					temp[length-1-i]=temp[i];
				}

			}

			else					//all digits are 9
			{
				for(i=0;i<mid;i++)
				{
					temp[length-1-i]=temp[i];
				}

				strcpy(temp1,"1");
				strcat(temp1,temp);
				strcpy(temp,temp1);
				temp[length]='1';
			}

		}



		printf("%s\n",temp);
		
	}





}



void even(char *number,int length)
{
int mid,flag,i,j;
char temp[1000002],temp1[1000003];

mid=(length/2)-1;


	strcpy(temp,number);

	for(i=0;i<=mid;i++)
	{
		temp[length-1-i]=temp[i];
	}

	flag=compare(temp,number);

	if(flag==1)					//if palindrome of given number greater
	{
		printf("%s\n",temp);
	}

	else
	{
			if(temp[mid]!='9')			//if middle number less than 9
			{
				temp[mid]++;
				temp[mid+1]++;
				//printf("%s\n",temp);
			}

			else
			{

				j=0;
				while(temp[mid-j]=='9'&&j<=mid)			//if middle element is 9
				{
					temp[mid-j]='0';
					j++;
				}
				if(j<=mid)				// not all digits are 9
				{
					temp[mid-j]++;
					for(i=0;i<=mid;i++)
					{
						temp[length-1-i]=temp[i];
					}

				}

				else					//all digits are 9
				{
					for(i=0;i<=mid;i++)
					{
						temp[length-1-i]=temp[i];
					}

					strcpy(temp1,"1");
					strcat(temp1,temp);
					strcpy(temp,temp1);
					temp[length]='1';
				}

			}






		printf("%s\n",temp);

	}



}

int main()
{

char array[1000002];
int t,length;
scanf("%d",&t);
while(t>0)
{
scanf("%s",array);

length=strlen(array);

if(length%2==1)
	odd(array,length);
else
	even(array,length);
t--;
}

return 0;
}
