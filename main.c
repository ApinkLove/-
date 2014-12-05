#include <stdio.h>
#include <malloc.h>
int n=0;
void main(void) 
{
  unsigned int p=0;
  int getnum;
  int *divisor;
  puts("약수를 구하고자 하는 숫자를 입력해주세요.");
  printf(":");
  scanf("%d", &getnum);
    divisor=(int *)malloc(sizeof(int)*(2+2(getnum/10)));
  get_divisor(n, getnum, getnum, 2);
  while(p<n) {
    printf("%d", divisor[p]);
    p++;
  }
  printf("\n");
}
void get_divisor(extern int n, int scope, int num, int used) 
{
  int i=used;
  while(i<=scope)
  {
    if(num%i==0) 
      {
      divisor[n]=i;
      n++;
      get_divisor(n, num/i, num, i);
      }
      i++;
  }
}
