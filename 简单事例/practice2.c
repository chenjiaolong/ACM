#include<stdio.h>//输入输出库函数
void main()//主函数
{
    int height;//用户身高
    float weight,sweight;//标准体重，用户身高
    printf("请输入被测同学的身高，并以cm为单位：\n");
    scanf("%d",&height);
    do
    {
        printf("请输入被测同学的体重，并以kg为单位\n");
        scanf("%f",&weight);
        sweight=(height-100)*0.9;
        if((weight>(sweight*1.1))||(weight<(sweight*0.9)))
            printf("该同学的体重已超标或不达标，请注意改善！\n");
        else
            printf("恭喜该同学体重正常（完美）！\n");
        printf("请输入被测同学的身高，并以cm为单位：\n");
        scanf("%d",&height);
    }while(height>0);
    /*while(height>0)
    {
        printf("请输入被测同学的体重，并以kg为单位\n");
        scanf("%f",&weight);
        sweight=(height-100)*0.9;
        if((weight>(sweight*1.1))||(weight<(sweight*0.9)))
        printf("该同学的体重已超标或不达标，请注意改善！\n");
        else
            printf("恭喜该同学体重正常（完美）！\n");
        printf("请输入被测同学的身高，并以cm为单位：\n");
        scanf("%d",&height);
    }*/
}
