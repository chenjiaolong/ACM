#include<stdio.h>
int main()
{
  float fnum=38.52099;
  printf("*%f*\n",fnum);
  printf("*%e*\n",fnum);
  printf("*%4.2f*\n",fnum);
  printf("*%3.1f*\n",fnum);
  printf("*%10.3f*\n",fnum);
  printf("*%10.3e*\n",fnum);
  printf("*%+4.2f*\n",fnum);
  printf("*%010.2f*\n",fnum);
  getchar();
  return 0;
}
