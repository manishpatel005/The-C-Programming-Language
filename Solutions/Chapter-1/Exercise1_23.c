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
  int c,stateSin,stateMulti,seenSlash,seenStar,stateQuote;
  stateSin=OUT;//stateSin variable represents whether inside comment or not
  // 0 means out of comment
  stateMulti=OUT;
  stateQuote=OUT;
  seenSlash=seenStar=0;// not seen hash symbol or star yet
  // seenStar tracks the ending star of multiline comment
  while((c=getchar())!=EOF)
  {
    if(stateQuote==OUT && stateMulti==OUT && stateSin==OUT && c=='"') // inside quote
    {
      putchar(c);
      stateQuote=IN;
    }
    else if(stateQuote==IN && stateMulti==OUT && stateSin==OUT && c=='"') // quote ends
    {
      putchar(c);
      stateQuote=OUT;
    }
    else if(stateQuote==IN && stateMulti==OUT && stateSin==OUT)
    {
      putchar(c);
    }
    else if(stateQuote==OUT && seenSlash==0 && c=='/' && stateSin!=IN && stateMulti!=IN)
      seenSlash=1;
    else if(stateQuote==OUT && seenSlash==1 && c=='/')// inside single line comment
    {
      stateSin=IN; 
      seenSlash=0;
    }
    else if(stateQuote==OUT && seenStar==1 && c=='/') // end of multiline comment
    {
      stateMulti=OUT;
      seenStar=0;
    }
    else if(stateQuote==OUT && seenSlash==1 && c=='*') // inside multi line comment
    {
      stateMulti=IN;
      seenSlash=0;	
    }
    else if(stateQuote==OUT && c!='\n' && stateSin==IN)// inside single line comm, hence skip chars
      ;
    else if(stateQuote==OUT && c=='*' && stateMulti==IN) 
    {
      seenStar=1;  // this takes of the case that * should precede / without gap
    }
    else if(stateQuote==OUT && stateMulti==IN)
    {
      seenStar=0;
    } 
    else if(stateQuote==OUT)
    { 
      if(seenSlash==1)
      {
	putchar('/'); // this takes care of case like this-> / /
	seenSlash=0;
      }
      if(c=='\n' && stateSin==IN) // single line comment ends at newline
      {
	stateSin=OUT;
      }
      putchar(c);
    }
  }
  //printf(" /* */"); // Uncomment this to see quoting 
  return 0;
}
