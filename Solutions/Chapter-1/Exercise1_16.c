#include<stdio.h>
#define MAXLEN 1001
/* Program to print length of arbitrary long input lines
 * and as much possible of the text
 */
int mygetline(char line[],int size);
void copy(char to[],char from[]);

int main()
{
  int c;
  int len,maxlen;
  char line[MAXLEN]; /* Current length*/
  char maxline[MAXLEN]; /* Maximum length seen so far*/
  maxlen=0; 
  while((len=mygetline(line,MAXLEN))>0)
  {
    if(len>maxlen)
    {
      maxlen=len;
      copy(maxline,line);
    }

  }
  if(maxlen>0)
  {  
    printf("Original length= %d\n",maxlen);
    printf("Printed length=%d \n",(maxlen<MAXLEN?maxlen:MAXLEN));
    printf("Longest line=%s\n",maxline);
  } 
  return 0;
}
int mygetline(char line[],int size)
{
  int i,c,j; // variable j keeps track of maximum length 
             // inside maxline array
  for(i=0;(c=getchar())!=EOF && c!='\n' ;i++)
  {
    if(i<(size-1))
    {	
      line[i]=c;
      j=i;
    }
  }
  if(c=='\n')
  {  
    line[j]='\n';
    j++;
  }
  line[j]='\0';
  return i;
}
void copy(char to[],char from[])
{
  int i=0;
  while((to[i]=from[i])!='\0')
    i++;
}
