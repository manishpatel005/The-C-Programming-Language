#include<stdio.h>
/* invert(x,p,n) function
 * return x with the n bits that begin at position p
 * inverted, leaving others unchanged
 *
 */

/* The idea is very simple. Use ~0 to create all ones.  
 * Then left shift it the length i.e n times. Then 
 * invert it again and left shift till you reach "p"
 * position ie ~(~0<<n) << p+1-n
 * This idea will be  used in all problems using bits.
 */ 
int invert(int x, int p, int n)
{
   int a,b,c;
   a= ~(~0<<n)<< (p+1-n); // creates all ones of length n 
                          // at position p. Eg=(..000111000)
   c= x ^a;               // Xoring inverts the bits
   return c;
} 
int main()
{
  int x,p,n;
  static const char padder[] = "---------------------------------";
  printf("%s\n invert(x,p,n) program\n\n",padder);
  printf(" Enter the value of x,p,n separated by space: ");
  scanf("%d %d %d", &x, &p, &n);
  printf("\n\n The inverted x=%d\n\n%s\n",invert(x,p,n),padder);
  return 0;

}
