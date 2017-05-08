#include<stdio.h>
#define TABSPACE 8
/*  Entab Program: Replaces string of blanks by
 *  the minimum number of tabs and blanks to achieve
 *  same spacing.
 *  To understand how tab works try giving input on command
 *  line itself. You will find that tab positions are fixed
 *  at column length of 8.
 */
int main()
{
  int c,nb,nt,pos;// nb denotes counter of blanks, nt stores
  // number of tabs and pos denotes the position on line
  nb=nt=pos=0;
  while((c=getchar())!=EOF)
  {
    pos++;
    if(c==' ')
    {
      nb++;
      if((pos%TABSPACE)==0) // whenever the position reaches 
      {			    // TAB positon then get a '\t'
	nt++;
	nb=0;
      }
    }
    else if(c=='\n')       // reset everthing at newline
    {
      putchar(c);
      nb=nt=pos=0;
    }
    else                   // whenever receive nonblank or non newline then
    {                      // out tabs, blanks and then the character
      while(nt>0)
      {
	putchar('\t');
	nt--;
      }
      while(nb>0)
      {
	putchar(' ');
	nb--;
      }
      putchar(c);
    }
  }
  // This is same as the else portion because if we get EOF after spaces but before nonblank
  // or non newline then we need to output the tabs and blanks
  while(nt>0)
  {
    putchar('\t');
    nt--;
  }
  while(nb>0)
  {
    putchar(' ');
    nb--;
  }

  return 0;
}
