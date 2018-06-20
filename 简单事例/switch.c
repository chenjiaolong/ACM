#include<stdio.h>
void main()
{
    int num;
    printf("请输入1~7\n");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Staurday");
        break;
    case 7:
        printf("Sunday");
        break;
    default :
        printf("你的输入不正确！");
    }
    /*float score;
    printf("请输入同学的分数\n");
    scanf("%f",&score);
     switch(score/10)
                    {
                        case 10:
                        case 9:
                        printf("A");
                        break;
                        case 8:
                        printf("B");
                        break;
                        case 7:
                        printf("C");
                        break;
                        case 6:
                        printf("D");
                        default:
                        printf("E");
                    }*/
    /*float m,n;
    char ch;
    printf("请输入m+(-,*,/)n\n");
    scanf("%f%c%f",&m,&ch,&n);
    switch(ch)
                    {
                        case '+':
                        printf("%.2f+%.2f=%.2f\n",m,n,m+n);
                        break;
                        case '-':
                        printf("%.2f-%.2f=%f\n",m,n,m-n);
                        break;
                        case '*':
                        case 'x':
                        case 'X':
                        printf("%.2f*%.2f=%.2f\n",m,n,m*n);
                        break;
                        case '/':
                        printf("%.2f/%.2f=%.2f\n",m,n,m/n);
                        break;
                    }*/
}

