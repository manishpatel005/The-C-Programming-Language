#include<stdio.h>
#define MAXLINE 1000

int mygetline(char line[],int lim)
{
  int c,i;
  for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
  {
    line[i]=c;
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
  int len,max=80;
  char line[MAXLINE];

  while((len=mygetline(line,MAXLINE))>0)
  {
    if(len>max)
    {
      printf("%s\n",line);
    }
  }
  return 0;

}
