//求基本数据类型范围
#include<math.h>
#include<float.h>//浮点数限制
#include<stdio.h>
#include<limits.h>//整数限制

int main()
{
    printf("the SHORT_MIN number is : %d\n",SHRT_MIN);
    printf("the SHORT_MAX number is : %d\n",SHRT_MAX);
    printf("the INT_MIN number is : %d\n",INT_MIN);
    printf("the INT_MAX number is : %d\n",INT_MAX);
    printf("the LONG_LONG_MIN number is : %lld\n",LONG_LONG_MIN);
    printf("the LONG_LONG_MAX number is : %lld\n",LONG_LONG_MAX);
    // float 类型数据的最大正有限大值的常量，最大正有限大值为2的128次方;
    // float 类型数据的最小正非零值的常量，最小正非零值为2的-149次方；
    printf("the FLOAT_MIN number is : %.55f\n",FLT_MIN);//float的最小值//%.38f
    printf("the FLOAT_MAX number is : %f\n",FLT_MAX);//float的最大值
    return 0;
}
