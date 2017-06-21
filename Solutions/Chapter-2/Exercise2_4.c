#include<stdio.h>
#define MAXSIZE 1000

/* squeeze(s1,s2) that deletes each character in s1 that
 * matches any character in s2
 */ 
void squeeze(char s1[],char s2[])
{
  int i,j,k,found;
  for(i=j=k=0;s1[i]!='\0';i++)
  {  found=0;
    // For every character in s1
    // search for every character in s2
    for(k=0;s2[k]!='\0';k++)
    {
      if(s2[k]==s1[i])
      {
        found=1;
        // if match found then skip
        break;
      }
    }
    // if no match found then copy in original char in s1
    if(found==0)
    { 
      s1[j++]=s1[i];   
    }
  }
  s1[j]='\0'; 
}
int main()
{
  char s1[MAXSIZE],s2[MAXSIZE];

  printf("Enter the first string: ");
  scanf("%s",&s1);
  printf("Enter the second string: ");
  scanf("%s",&s2);
  
  squeeze(s1,s2);
  printf("The squeezed string is: %s\n",s1);
  return 0;
}
