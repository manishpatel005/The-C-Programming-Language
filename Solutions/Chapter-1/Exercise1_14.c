#include<stdio.h>
#define ASCII_LEN 256
/* Program to print histogram of
 * frequencies of different characters
 */ 

int main()
{
  int c,i,j;
  int arr[ASCII_LEN];
  i=0;
  // Initialize arr 
  for(i=0;i<ASCII_LEN;i++)
  {
    arr[i]=0;
  }
  while((c=getchar())!=EOF)
  {
     arr[c]++;
  }
  // print the histogram
  for(i=0;i<ASCII_LEN;i++)
  {
    if(arr[i])
    {  printf("%c=",i);
       for(j=0;j<arr[i];j++)
        printf("*");
       printf("\n");
    }
  }
  return 0;
}

