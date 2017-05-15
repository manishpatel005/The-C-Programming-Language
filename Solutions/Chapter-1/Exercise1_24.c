#include<stdio.h>
/* Program to rudimentary syntax errors like unmatched parentheses,
 * brackets and braces. Don't forget about quotes, both single and 
 * double, escape sequences, and comments.
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
  int ar[100]; // array that saves starting of paranthesises, 
               //braces and brackets
  int count=0; // count keeps track of count of paranthese, 
               //braces and brackets
  int err=0;// no syntax error
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
    else if(c=='('|| c=='{' || c=='[')
    {
      // push on stack
      putchar(c);
      ar[count++]=c;
      
    }
    else if(c==')'||c=='}'||c==']')
    {
       
       if(c==')' && count>0 && ar[count-1]=='(')
       {
         ar[count-1]=0;
	 count--; //correct
       }
       else if(c=='}' && count> 0 && ar[count-1]=='{')
       {
         ar[count-1]=0;
         count--;//correct
       }
       else if(c==']' && count>0 && ar[count-1]=='[')
       {
         ar[count-1]=0;
         count--;//correct
       }
       else
       {
          err=1;
          break;
       }
       putchar(c); 
    }
    else
      putchar(c);

    if(c=='\n')
      prev=' ';
    else
      prev=c;
  }
  if(err==1 || count!=0)
    printf("Syntax error\n"); 
  else
    printf("No Syntax error\n"); 
  return 0;
}
