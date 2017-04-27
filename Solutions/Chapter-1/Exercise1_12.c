#include<stdio.h>
#define OUT 0
#define IN 1
/*
  Program to print its input one word per line
*/
int main()
{
  int c,state;
  state=OUT; // OUT= not seen a word
             // IN= inside the word
  while((c=getchar())!=EOF)
  {
    if(state==OUT&& (c==' '||c=='\t'||c=='\n'))
    {
      //putchar('\n');
      //state=IN;
    }
    else if(state==IN && (c==' '||c=='\t'||c=='\n'))
    {
      putchar('\n');
      state=OUT;
    }
    else
    {
      putchar(c);
      state=IN;
    }
  }
  return 0;
}
