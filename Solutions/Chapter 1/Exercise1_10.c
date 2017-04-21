#include<stdio.h>
/* Program to replace tabs,backspace and slashes
 * ^H i.e Ctrl+H is the backspace in linux
 * <Tab Key> is the tab in linux
 * <\> is the backslash in linux
 * E.g input= "Hello	there. How ^H are \ you?"
 *     output= Hello\tthere. How \b are \\ you?
 */
int main()
{
  int c;
  while((c=getchar())!=EOF)
  {
    if(c=='\t')
    {
      putchar('\\');
      putchar('t');
    }
    else if(c=='\b')
    {
      putchar('\\');
      putchar('b');
    }
    else if(c=='\\')
    {
      putchar('\\');
      putchar('\\');
    }
    else 
      putchar(c);
  }
  return 0;
}
