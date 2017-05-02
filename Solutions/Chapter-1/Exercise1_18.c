#include<stdio.h>
#define MAXLINE 1000

/* program to remove trailing blanks and tabs from each line of input, 
 * and to delete entirely blank lines.
 */ 
int mygetline(char line[],int lim)
{
  int c,i,j;
  for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
  {
    line[i]=c;
  }
 // This loop removes trailing blanks and tabs.
  for(j=i-1;j>=0 && (line[j]=='\t' ||line[j]==' ');j--)
     ;
  i=j+1;
  if(i!=0 && c=='\n') // if empty line then skip
  {
    line[i]=c;
    i++;
  }
  if(i==0 && c==EOF) 
   return EOF;
  
  line[i]='\0';
  return i;
}
int main()
{
  int len;
  char line[MAXLINE];

  while((len=mygetline(line,MAXLINE))>=0)
  {
      printf("%s",line);
  }
  return 0;

}
