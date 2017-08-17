#include<stdio.h>
#include<time.h>
/*  binsearch() with one test inside loop
 */ 
clock_t startt, endt;

int binsearch(int x, int v[], int n)
{
  int low,high,mid;
  low=0;
  high=n-1;
  mid=(low+high)/2;
  while(low<=high && v[mid]!=x)
  {
    mid=(low+high)/2;
    if(v[mid]<x)
      low=mid+1;
    else
      high=mid-1;
  }
  if(v[mid]==x)
    return mid;
  else
    return -1;
}
int main()
{
  int i,n,x;
  static const char padder[] = "----------------------------------------------";
  printf("%s\n binsearch(int x, int v[], int n) program\n\n",padder);
  printf("Enter the value of n: ");
  scanf("%d",&n);
  int v[n];
  printf("Enter the values of sorted array separated by space: ");
  for(i=0;i<n;i++)
    scanf("%d",&v[i]);
  printf("Enter the value of element to be found i.e x: ");
  scanf("%d",&x);

 // startt=clock();
  printf("The element is found at position: %d\n",binsearch(x,v,n));
 // endt=clock();
 // printf("The time taken is: %.50lf\n",(double)(endt-startt)/CLOCKS_PER_SEC);
  
  printf("%s\n",padder);
  return 0;
}
