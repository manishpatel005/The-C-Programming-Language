#include<stdio.h>
/*
 Program to copy input to output and replacing each string of one or more blanks 
 by a single blank
 */
#define OUT 0
#define IN 1
int main()
{
  int c, state;
  state=OUT; // OUT means no blank seen so far 
             // IN means one blank already seen
  while((c=getchar())!=EOF)
  {
    if(c==' '&& state==OUT) // this is first blank
    { 
      state=IN; 
      putchar(c);
    }
    else if(c==' ' && state ==IN)
       ; // ignore the blanks
    else
    {
      putchar(c);
      state=OUT;
    }
  }
}
