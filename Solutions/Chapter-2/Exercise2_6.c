#include<stdio.h>
/* setbits(x,p,n,y) function
 * return x with the n bits that begin at position p
 * set to the rightmost n bits of y
 *
 */

/* The idea is very simple. Use ~0 to create all ones.  
 * Then left shift it the length i.e n times. Then 
 * invert it again and left shift till you reach "p"
 * position ie ~(~0<<n) << p+1-n
 * This idea will be  used in all problems using bits.
 */ 
int setbits(int x, int p, int n, int y)
{
   int a,b,c;
   a= ~(~(~0<<n)<< (p+1-n)); // creates all zeroes of length n 
                             // at position p. Eg=(..1110001111)
   b= y & ~(~0<<n);          // extracted the last n bits from y
   b=b<< (p+1-n);            // shift b to position p
   c= (x&a) | b;             // clear x and then set it
   return c;
} 
int main()
{
  int x,p,n,y;
  static const char padder[] = "---------------------------------";
  printf("%s\n setbits(x,p,n,y) program\n\n",padder);
  printf(" Enter the value of x,p,n,y separated by space: ");
  scanf("%d %d %d %d", &x, &p, &n, &y);
  printf("\n\n The changed x=%d\n\n%s\n",setbits(x,p,n,y),padder);
  return 0;
}
