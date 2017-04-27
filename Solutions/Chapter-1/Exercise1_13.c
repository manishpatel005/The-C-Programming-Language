#include<stdio.h>
#define IN 1
#define OUT 0
/* Program to print the histogram of length of words
 * in its input.
 */
int main()
{
  int c,state;
  int i,len;
  state=OUT; //outside the word
  len=0;
  while((c=getchar())!=EOF)
  { 
    if(state==OUT && (c==' '||c=='\t'||c=='\n'))
      ;// do nothing
    else if(state==IN && (c==' '||c=='\t'|| c=='\n'))
    {
      putchar(' ');
      putchar(' ');
      for(i=0;i<len;i++)
      {
	putchar('-');
      }
      putchar('\n');
      state=OUT;
      len=0;
    }
    else
    {
      putchar(c);
      len++;
      state=IN;
    }
  }
  return 0;
}
