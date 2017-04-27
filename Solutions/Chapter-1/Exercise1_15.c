#include<stdio.h>
/*Program to convert Fahrenheit to Celsius
 * using function
 */
float FahrToCelsius(int);
int main()
{
  float i;
  for(i=0;i<=300;i+=20)
  {
    printf("%3.0f %6.1f\n",i,FahrToCelsius(i));
  }
  return 0;
}
float FahrToCelsius(int fahr)
{
  return (5.0/9.0)*(fahr-32.0);
}
