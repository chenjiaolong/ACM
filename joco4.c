#include <stdio.h>
#include<stdlib.h>
#define MAX 10
int main()
{
    float score[MAX];
    int i;
    float sum=0;
    for(i=0; i<10; i++)
    {
        scanf("%f",&score[i]);
        sum+=score[i];
    }
    printf("%.2f",sum);
    return 0;
}
