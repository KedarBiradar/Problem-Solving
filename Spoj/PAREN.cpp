#include<iostream>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
using namespace std;

int countParenth(char symb[], char oper[], int n)
{
    int F[n][n], T[n][n];
 
    for (int i = 0; i < n; i++)
    {
        F[i][i] = (symb[i] == 'F')? 1: 0;
        T[i][i] = (symb[i] == 'T')? 1: 0;
    }
 
    for (int gap=1; gap<n; ++gap)
    {
        for (int i=0, j=gap; j<n; ++i, ++j)
        {
            T[i][j] = F[i][j] = 0;
            for (int g=0; g<gap; g++)
            {
                int k = i + g;
 
                int tik = T[i][k] + F[i][k];
                int tkj = T[k+1][j] + F[k+1][j];
 
                if (oper[k] == '&')
                {
                    T[i][j] += T[i][k]*T[k+1][j];
                    F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]);
                }
                if (oper[k] == '|')
                {
                    F[i][j] += F[i][k]*F[k+1][j];
                    T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]);
                }
                if (oper[k] == '^')
                {
                    T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j];
                    F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
                }
            }
        }
    }
    return T[0][n-1];
}
 
int main()
{
	    char symbols[100];
	    char operators[100];
 
	char str[512];
	char *pch;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char ch=getchar();
		gets(str);
		//printf("%s",str);
		pch = strtok (str," \n");
		int i=0,j=0;
		while (pch != NULL)
		{
			if(pch[0]=='T' || pch[0]=='F')
			symbols[i++]=pch[0];
			else
			{
				if(strcmp(pch,"and")==0)
					operators[j++]='&';

				else if(strcmp(pch,"or")==0)
					operators[j++]='|';

				if(strcmp(pch,"xor")==0)
					operators[j++]='^';
			}
	
			pch = strtok (NULL, " \n");
		}
		symbols[i]=0;
		operators[j]=0;
		//printf("%s %s %d\n",symbols,operators,i);
	    printf("%d\n", countParenth(symbols, operators, i));
	}
    return 0;
}
