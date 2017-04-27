#include<stdio.h>
#define OUT 0
#define IN 1
/*
  Program to print its input one word per line
*/
int main()
{
  int c,state;
  state=OUT; // OUT= no blank seen so far
	     //  IN= one balnk already seen 
  while((c=getchar())!=EOF)
  {
    if(state==OUT&& (c==' '||c=='\t'||c=='\n'))
    {
      putchar('\n');
      state=IN;
    }
    else if(state==IN && (c==' '||c=='\t'||c=='\n'))
    {	;// do nothing
    }
    else 
    {
      putchar(c);
      state=OUT;
    }
  }
  return 0;
}

