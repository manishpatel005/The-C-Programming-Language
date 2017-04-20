/* Author: Manish Patel */ 
/* Solution to exercise 1.10 of The C Programming Language by K&R*/ 
 
#include <stdio.h> 
/* program to copy input to output and replace each tab by \t, each backspace by \b
   and each backslash by \\.
*/
main() 
{ 
  int c;
  while((c=getchar())!=EOF)
  {
    if(c=='\t')
      putchar('\\t');
    else if(c=='\b')
      putchar('\b');
    else if(c=='\\')
      putchar('\\');
    else
      putchar(c);
  }
}
