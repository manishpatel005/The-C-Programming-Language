#include<stdio.h>
#define MAXLINE 1000

int mygetline(char line[],int lim)
{
  int c,i;
  for(i=0;i<lim-1;i++)
  {
   if((c=getchar())!=EOF)
   {
     if( c!='\n')
   	line[i]=c;
     else
         break;
   }
   else
      break;
  }
  if(c=='\n')
  {
    line[i]=c;
    i++;
  }
  line[i]='\0';
  return i;
}
int main()
{
  int len;
  char line[MAXLINE];

  while((len=mygetline(line,MAXLINE))>0)
  {
      printf("%s",line);
  }
  return 0;

}
