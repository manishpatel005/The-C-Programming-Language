#include<stdio.h>
/*  lower(int c) without if-else
 *  converts c to lower case
 */ 

int lower(int c)
{
  return ((c>='A' && c <='Z')?(c-'A'+'a'):c); 
}
int main()
{
  int c;
  static const char padder[] = "---------------------------------";
  printf("%s\n lower(c) program\n\n",padder);
  printf("Input (Ctrl+D to exit): \n");
  while((c=getchar())!=EOF)
    putchar(lower(c));
  printf("%s\n",padder);
  return 0;
}
