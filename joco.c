#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main ()
{
    int a,b,i;
    for (a=200;a<=300;a++)
    {
         b = (int)sqrt(a);
         for(i=2;i<=b;i++)
              if(a%i==0)
                break;
          if(i>b)
              printf("%d\n",a);
     }
    system("pause");
    return 0;
}

