/* Author: Manish Patel */
/* Solution to exercise 1.8 of The C Programming Language by K&R*/

#include <stdio.h>
/* program to count blanks,tabs and newlines */
main()
{
    int nb,nt,nn;
    int c;
    nb=nt=nn=0; // initialize the count to zero
    while((c=getchar())!=EOF)
    {
       if(c==' ') // check for blank
           nb++;
       else if(c=='\t') // check for tabs
           nt++;
       else if(c=='\n') // check for newlines
           nn++;
    }
    printf("blanks= %d, tabs= %d, newlines= %d \n",nb,nt,nn);

}
