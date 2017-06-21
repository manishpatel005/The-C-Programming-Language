#include<stdio.h>
#include<string.h> // to include memset
#define MAXSIZE 1000
/* any(s1,s2) return first location in string s1
 * where any character from string s2 occurs else
 * returns -1.
 */
 
/* Unlike previous question, I am going to get an extra 
 * array s3 of size 255 since only 255 characters are 
 * possible in ASCII.
 */ 

int any(char s1[], char s2[])
{
  char s3[256];
  int i;
  // memset initalizes all elements of s3 with 0
  memset(s3,0,sizeof(s3));
  for(i=0;s2[i]!='\0';i++)
     s3[s2[i]-'\0']++;

  for(i=0;s1[i]!='\0';i++)
  {
    if(s3[s1[i]-'\0']) // if match found then return current position
      return i;
  }
  return -1; // if nothing found then return -1
}
int main()
{
  char s1[MAXSIZE],s2[MAXSIZE];
  int i;
  printf("Enter string s1: ");
  scanf("%s",&s1);
  printf("Enter string s2: ");
  scanf("%s",&s2);
  printf("\nFirst location(0-indexed) in s1 of s2 is: %d\n",any(s1,s2));
  return 0;
}
