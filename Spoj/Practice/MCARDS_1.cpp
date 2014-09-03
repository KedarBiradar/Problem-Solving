#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct tuple
{
	int col,num;
};

int compare(tuple t1,tuple t2)
{
	if(t1.col==t2.col)
		return t1.num < t2.num;
	else
		return t1.col < t2.col;
}

vector <tuple> cards(410),sortedCards(410);

int new_LIS(int start,int end)
{

	int i,j;
	int LS[410];

	for(i=0;i<410;i++)
		LS[i]=1;

	for(i=start;i<end;i++)
	{

		int index=0;
		while(cards[index].col!=sortedCards[start].col && cards[index].num!=sortedCards[start].num)
			index++;

		LS[i]=1;
		for(j=index+1;j<end;j++)
		{
			if(cards[j].col > sortedCards[i].col && LS[i] <= LS[j])
			{
				LS[i]=LS[j]+1;
			}
			else if( cards[j].col== sortedCards[i].col && cards[j].num > sortedCards[i].num && LS [i] <= LS[j])
			{
				LS[i]=LS[j]+1;
			}
		}
	}

	int max=LS[start];
	for(i=start+1;i<end;i++)
	{
		if(max<LS[i])
			max=LS[i];
	}

	return max;
}

/*
//NLOGN LIS
int LIS(int s,int n,vector <tuple>a,vector <tuple> b)
{
	int i, k, l, r, mid;
	a[s] = b[s], k = 1;  
        for(i = s+1; i <= n; i++)  
        {  
            if(a[k].col < b[i].col || (a[k].col==b[i].col && a[k].num< b[i].num )) a[++k] = b[i];  
            else
		{  
	                l = 1; r = k;  
	                while(l <= r)  
	                {  
	                    mid = ( l + r ) / 2;  
	                    if(a[mid].col < b[i].col || (a[mid].col==b[i].col && a[mid].num< b[i].num ))   
	                        l = mid + 1;  
	                    else    
	                        r = mid - 1;  
	                      
	                }  
                a[l] = b[i];  
            }  
        }  
        return k;  
 }
*/
int main()
{
	int N,C,i;

	scanf("%d%d",&N,&C);

	for(i=1;i<=N*C;i++)
	{
		scanf("%d%d",&cards[i].col,&cards[i].num);
		sortedCards[i].col=cards[i].col;
		sortedCards[i].num=cards[i].num;
	}

	if(C==1)
	{
		printf("0\n");
		return 0;
	}

	sort(sortedCards.begin(),sortedCards.end(),compare);
	
	int tmp,min=N*C;



	for(i=1;i<N*C;i++)
	{

		//vector <tuple>temp(sortedCards.begin()+i);
		tmp=new_LIS(i,N*C);
		printf("LIS from %d to end %d= %d\n",i,N*C,tmp);
		if((N*C)-tmp < min)
			min=(N*C)-tmp;
	}

	printf("%d\n",min);
	return 0;
}
