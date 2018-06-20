#include <stdio.h>
#include <stdlib.h>

int main()
{
    float d = 5.01f;
    int *p = (int *)(&d);
    int rst = 1889785610;
    printf("f output %%d--(%d)--%f\n", d, 2147483648);
    printf("1----*&d = %f\n", *&d);
    printf("2----*(&d + 1) = %f\n", *(&d + 1));
    printf("3----*(&d + 2) = %f\n",*(&d + 2));
    printf("4----*(&d + 3) = %f\n",*(&d + 3));
    printf("5----*(&d + 4) = %f\n",*(&d + 4));
    printf("first addr-----&d = 0x%x-----p = 0x%x\n", &d, p);
    printf("second addr-----&d + 1 = 0x%x-----p + 1 = 0x%x\n",&d + 1, p + 1);
    printf("1).*p = 0x%x----*(&d) = 0x%x\n", *p, *(&d));
    printf("1.1).*p = %d----*(&d) = %f\n", *p, *(&d));
    printf("2).*(p + 1) = 0x%x----*(&d + 1) = 0x%x\n", *(p + 1), *(&d + 1));
    printf("2.2).*(p + 1) = %d----*(&d + 1) = %f\n", *(p + 1), *(&d + 1));
    printf("3).rst = 0x%x\n",rst);
    printf("4).5.01f = 0x%x\n",5.01f);
    printf("5).0x80000000 = %f\n",0x80000000);
    printf("6).0x4000000080000000 = %f\n",0x4000000080000000);
    printf("--------------\n\n");

    printf("%f %d.\n", d, sizeof(double));
    printf("%d %d %d.\n", d, sizeof(double), sizeof(int));
    printf("%d\n", sizeof(double));
    return 0;
}
