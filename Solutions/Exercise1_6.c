#include<stdio.h>
/* To verify getchar()!=EOF returns 0 or 1
 */
int main()
{
  int c;
  while(c=getchar()!=EOF)
  {
    printf("%d\n",c);
   //  putchar(c); 
  }
  printf("%d\n",c);
  return 0;
}
