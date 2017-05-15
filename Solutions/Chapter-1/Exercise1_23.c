#include<stdio.h>
/* Program to remove all comments from a C program. Don't forget to handle quoted strings
 * and character constants properly
 */
// Run this program on itself :) 
void skipSingleQuote(int prev)
{
   putchar(prev);
   int c;
   while((c=getchar())!=EOF)
   {
     if(prev=='\\' && c=='\'')
       putchar(c);
     else if(c=='\'')
       break;
     else 
       putchar(c);
     prev=c;
   }
   putchar(c);
}
void skipDoubleQuote(int c)
{
   putchar(c);
   while((c=getchar())!=EOF && c!='"')
   {
     putchar(c);
   }
   putchar(c);
}
void skipComments(int isSingleLine)
{
  int c, prev=' ';
  if(isSingleLine==1)
  {  
    while((c=getchar())!=EOF && c!='\n')
    {
      ; 
    }
    putchar(c); 
  }
  else // multiline
  {
     while((c=getchar())!=EOF)
    {
      if(prev=='*' && c=='/')
         break;
      prev=c;
    }
  }
}
int main()
{
 
  int c,prev=' ';
  while((c=getchar())!=EOF)
  {
   
    if(prev=='/' && c=='/') // inside single line comment
    {
      skipComments(1);
    }
    else if(prev=='/' && c=='*') // inside multiline comment
    {
      skipComments(0);
    }
    else if(prev==' ' && c=='/')
    {
      ;
    }
    else if(c=='\'') // single quote
    {
       skipSingleQuote(c);
    }
    else if(c=='"')// inside quotes
    { 
      skipDoubleQuote(c);
    }
    else
      putchar(c);

    if(c=='\n')
      prev=' ';
    else
      prev=c;
  }
  printf("/* */");
  return 0;
}
