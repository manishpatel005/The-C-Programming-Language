#include<stdio.h>
/* rightrot(x,n) function
 * returns the value of integer x rotated to the
 * right by n bit positions
 */

/* The idea is very simple. Use ~0 to create all ones.  
 * Then left shift it the length i.e n times. Then 
 * invert it again and left shift till you reach "p"
 * position ie ~(~0<<n) << p+1-n
 * This idea will be  used in all problems using bits.
 */ 
int rightrot(int x, int n)
{
   int a,b,c;
   // get the n digits from right in a
   a= x & ~(~0<<n);
   // shift the x to right 
   b=x>>n;
    // shift a left 
   c= a<<(32-n);
   return (b|c);
} 
int main()
{
  int x,n;
  static const char padder[] = "---------------------------------";
  printf("%s\n rightrot(x,n) program\n\n",padder);
  printf(" Enter the value of x,n separated by space: ");
  scanf("%d %d", &x, &n);
  printf("\n\n The right rotated x=%d\n\n%s\n",rightrot(x,n),padder);
  return 0;

}
