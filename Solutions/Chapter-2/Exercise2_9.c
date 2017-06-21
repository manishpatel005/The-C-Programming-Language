#include<stdio.h>
/*  bitcount(int x) faster version
 *  counts 1 bits in x
 */ 

int bitcount(int x)
{
  int c=0;
  while(x)
  {
    x=x & (x-1);
    c++;
  }
  return c;
}
int main()
{
  int x;
  static const char padder[] = "---------------------------------";
  printf("%s\n bitcount(x) program\n\n",padder);
  printf(" Enter the value of x: ");
  scanf("%d", &x);
  printf("\n\n The number of 1s in x=%d\n\n%s\n",bitcount(x),padder);
  return 0;
}
