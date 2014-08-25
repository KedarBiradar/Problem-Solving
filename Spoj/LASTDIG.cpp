#include<cstdio>
#define f(a) printf(a)
#define y else if
#define m case 
#define b break
typedef int i;i z(i q){return q%4+1;}i main(){i p,t;unsigned long long q;scanf("%d",&t);while(t--){scanf("%d%lld",&p,&q);if(q==0){if(p==0)f("0\n");else f("1\n");continue;}p%=10;i l=z(q-1);q--;switch(p){m 0:f("0");b;m 1:printf("%d",p);b;m 2:if(l==1)f("2");y(l==2)f("4");y(l==3)f("8");y(l==4)f("6");b;m 3:if(l==1)f("3");y(l==2)f("9");y(l==3)f("7");y(l==4)f("1");b;m 4:if(q%2+1==1)f("4");else f("6");b;m 5:f("5");b;m 6:f("6");b;m 7:if(l==1)f("7");y(l==2)f("9");y(l==3)f("3");y(l==4)f("1");b;m 8:if(l==1)f("8");y(l==2)f("4");y(l==3)f("2");y(l==4)f("6");b;m 9:if(q%2+1==1)f("9");else f("1");b;}f("\n");}return 0;}
/*
//LASTDIG2
#include <stdio.h>
#include <cstring>
int main()
{
 int B[10][5]={0,0,0,0,0,
      0,0,0,0,0,
      6,2,4,8,4,
      1,3,9,7,4,
      6,4,0,0,2,
      0,0,0,0,0,
      0,0,0,0,0,
      1,7,9,3,4,
      6,8,4,2,4,
      1,9,0,0,2,};
 int t;
 scanf("%d",&t);
 while(t--)
 {
  char A[1005];
  unsigned long long p;
  scanf("%s",A);
  scanf("%llu",&p);
  int len=strlen(A),temp,k;
  if(p==0)
   printf("1\n");
  else{
   temp=A[len-1]-48;
   if(temp==0)
    printf("0\n");
   else if(temp==1)
    printf("1\n");
   else if(temp==5)
    printf("5\n");
   else if(temp==6)
    printf("6\n");
   else{
    k=p%B[temp][4];
    printf("%d\n",B[temp][k]);
   }
  }
 }
}*/
