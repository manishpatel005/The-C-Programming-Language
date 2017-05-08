#include<stdio.h>
#define FOLDAT 50
/* Program to fold long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th 
 * column of input.
 */
int main()
{
  int c,pos,nb;
  pos=nb=0;
  while((c=getchar())!=EOF)
  { 
    pos++;
    if(c==' ') // print if it comes before any nonblank character
    {           // and also before  FOLDAT
      nb++;
      if(pos==FOLDAT)
      {
	putchar('\n');
	pos=nb=0;
      }
    }
    else if(c=='\n')
    {
	putchar('\n');
        pos=nb=0;
    }
    else
    {
      while(nb>0)
      {
	putchar(' ');
       	nb--;
      }

      if(pos==FOLDAT)
      {
	putchar(c);
	putchar('\n');
	pos=nb=0;
      }
      else
	putchar(c);
    }
  }
  return 0;
}

