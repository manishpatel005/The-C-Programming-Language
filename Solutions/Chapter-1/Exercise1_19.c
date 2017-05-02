#include<stdio.h>
#define MAXLINE 1000
/*a program that reverses its input a line at a time.
*/
void reverse(char str[],int len)
{
  int i,j;
  char temp;
  i=0;
  j=len-1;
  while(i<j)
  { 
    temp=str[i];
    str[i]=str[j];
    str[j]=temp;
    i++;j--;
  }
}
int mygetline(char line[],int lim)
{
  int c,i;
  for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
  {
    line[i]=c;
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
      reverse(line,len);
      printf("%s\n",line);
  }
  return 0;

}
