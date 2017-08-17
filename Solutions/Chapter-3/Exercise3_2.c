#include<stdio.h>
#define MAXLEN 10
int getstring(char s[], int lim)
{
  int c,i;
  i=0;
  while((c=getchar())!=EOF && i<lim)
  {
    s[i++]=c;
  }
  s[i]='\0';
  return i;
}
void escape(char s[], char t[])
{
  int i=0,j=0;
  while(t[i]!='\0')
  {
    switch(t[i])
    {
      case '\n':
	         s[j++]='\\';
		 s[j++]='n';
		 break;
      case '\t': 
		 s[j++]='\\';
		 s[j++]='t';
      case '\b': 
		 s[j++]='\\';
		 s[j++]='b';
      case '\r': 
		 s[j++]='\\';
		 s[j++]='r';
      default:
		 s[j++]=t[i];
    }
    i++;
  }
}
int main()
{
  int c;
  char s[MAXLEN],t[MAXLEN];
  printf("Enter the string: ");
  getstring(t,MAXLEN);
  escape(s,t);
  printf("Escaped string=%s\n",s);
 
  return 0;
}

