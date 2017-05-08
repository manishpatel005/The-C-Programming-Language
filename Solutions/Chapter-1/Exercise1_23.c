#include<stdio.h>
#define OUT 0
#define IN 1
/* program to remove all comments from a C program
 * Multiline comments: slash star -star slash
 * Single line comment : slash slash
 * and Comments dont nest i.e inside multiline comment
 * you cant use the multiline comment symbol
 * You can run this program on itself :)
 */
int main()
{
  int c,stateSin,stateMulti,seenSlash,seenStar;
  stateSin=OUT;//stateSin variable represents whether inside comment or not
  // 0 means out of comment
  stateMulti=OUT;
  seenSlash=seenStar=0;// not seen hash symbol or star yet
  // seenStar tracks the ending star of multiline comment
  while((c=getchar())!=EOF)
  {
    if(seenSlash==0 && c=='/' && stateMulti!=IN)
      seenSlash=1;
    else if(seenSlash==1 && c=='/')// inside single line comment
    {
      stateSin=IN; 
      seenSlash=0;
    }
    else if(seenStar==1 && c=='/') // end of multiline comment
    {
      stateMulti=OUT;
      seenStar=0;
    }
    else if(seenSlash==1 && c=='*') // inside multi line comment
    {
      stateMulti=IN;
      seenSlash=0;	
    }
    else if(c!='\n' && stateSin==IN)// inside single line, hence skip chars
      ;
    else if(c=='*' && stateMulti==IN) 
    {
      seenStar=1;  // this takes of the case that * should precede / without gap
    }
    else if(stateMulti==IN)
    {
      seenStar=0;
    } 
    else 
    { 
      if(seenSlash==1)
      {
	putchar('/');
	seenSlash=0;
      }
      if(c=='\n' && stateSin==IN)
      {
	stateSin=OUT;
      }
	putchar(c);
    }
  }
  return 0;
}
