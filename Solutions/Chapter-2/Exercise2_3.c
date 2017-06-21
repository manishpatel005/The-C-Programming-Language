#include<stdio.h>
#include<string.h> // to include strlen()
#define MAXSIZE 1000

/* htoi= converts hexadecimal to integer value
 * Optional= 0X or Ox 
 * Compulsory=1-9| A-F |a-f 
 */

/*  hexreverse function skips optional 0x or 0X 
 *  and copies characters from hex  to hrev
 *  in reverse order
 *  0x7E1 = 1E7
 */
void hexreverse(char hex[], char hrev[], int len)
{
  int i,j,k;
  i=0; // last index of hex till we copy
  j=len-1; // starting index of hex
  if(len>=2 && (hex[0]=='0' && (hex[1]=='x'||hex[1]=='X')))
  {
    i=2; //last index till we copy
  }
  k=0; // index of hrev
  while(j>=i)
  {
    hrev[k]=hex[j];
    k++;j--;
  }

  return;
}
/* htoi multiples digits with 16 ^ (k)
 *  where k is place number starting from 0.
 *  1E7=1* 1+ 16* E + 16*16*7 =2017
 */ 
int htoi(char hrev[],int len)
{
  int i,ans,st;
  ans=0;
  st=0;

  for(i=st;i<len;i++)
  {
    if(hrev[i]>='0' && hrev[i]<='9')
    {
      ans=16*ans+(hrev[i]-'0');
    }
    else if(hrev[i]>='a' && hrev[i]<='f')
    {
      ans=16*ans+(10+hrev[i]-'a');
    }
    else if(hrev[i]>='A' && hrev[i]<='F')
    {
      ans=16*ans+(10+hrev[i]-'A');
    }
    else 
	return -1;// not valid hexadecimal
  }
  return ans;
}
int main()
{
  int ans;
  char hex[MAXSIZE],hrev[MAXSIZE];

  printf("Enter the hexadecimal number\n");
  scanf("%s",&hex);

  hexreverse(hex,hrev,strlen(hex));

  ans=htoi(hex,strlen(hex));

  if(ans!=-1)
    printf("The integer value=%d\n",ans);
  else
    printf("Invalid hexadecimal number\n");
  return 0;
}
