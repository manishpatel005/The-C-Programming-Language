#include<stdio.h>
/* Program to determine the ranges of char, short, int, 
 * and long variables, both signed and unsigned
 *
 * Our logic is that 0= 00000000 (min val of unsigned)
 * then ~0=11111111(max val of unsigned). 
 * ~0>>1= 01111111(max val of signed)
 * ~(~0>>1)=10000000(min val of signed)
 */
int main()
{
  unsigned char uc;
  signed char sc;
  unsigned int ui;
  signed int si;
  unsigned short us;
  signed short ss;
  unsigned long ul;
  signed long sl;
  int i;
  uc=0;
  sc=0;
  ui=0;
  si=0;
  ss=0;
  sl=0;
  ul=0;
  printf("The minimum and maximum value of unsigned char= %d %d\n",uc,(unsigned char)~uc );
  printf("The minimum and maximum value of signed char= %d %d\n",~(((unsigned char)~sc)>>1),((unsigned char)~sc)>>1 );
  printf("The minimum and maximum value of unsigned int= %u %u\n",ui,(unsigned int)~ui );
  printf("The minimum and maximum value of signed int= %d %d\n",~(((unsigned int)~si)>>1),((unsigned int)~si)>>1 );
  printf("The minimum and maximum value of unsigned short= %d %d\n",ss,(unsigned short)~ss );
  printf("The minimum and maximum value of signed short= %d %d\n",~(((unsigned short)~ss)>>1),((unsigned short)~ss)>>1 );
  printf("The minimum and maximum value of unsigned long= %lu %lu\n",ul,(unsigned long)~ul );
  printf("The minimum and maximum value of signed long= %ld %ld\n",~(((unsigned long)~sl)>>1),((unsigned long)~sl)>>1 );
  return 0;
}
