#include <stdio.h>
#include <malloc.h>
void main(void) 
{
  int getnum;
  int *primenum;
  scanf("%d", &getnum);
    primenum=(int *)malloc(sizeof(int)*(2+2(getnum/10)));
  divider(getnum, getnum, 2);
}
void divider(int n, int scope, int num, int used) 
{
  int i=used;
  while(i<scope)
  {
    if(num%i==0)
      divider(num/i,num,i);
      primenum[n]=i;
      i++
  }
}
