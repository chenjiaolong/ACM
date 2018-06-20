#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void Graph(char rect[9])
{
    char buffer[9];
    for(int i = 0; i < 9; i ++)
    {
        if(rect[i]) buffer[i] = rect[i] + '0';
        else buffer[i] = ' ';
    }
    printf("%c-%c-%c\n", buffer[0], buffer[1], buffer[2]);
    printf("|\\|/|\n");
    printf("%c-%c-%c\n", buffer[7], buffer[8], buffer[3]);
    printf("|/|\\|\n");
    printf("%c-%c-%c\n\n", buffer[6], buffer[5], buffer[4]);
}
int main()
{
    char Cycle[9] = {0}; //Cycle[0]到Cycle[7]用于保存8个数，Cycle[8]为空白区
    int CurNode = 9, Temp;
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 8; i ++) //随机产生序列
    {
        Cycle[i] = (rand()%8)+1;
        if(CurNode == 9 && Cycle[i] == 1) CurNode = i;//记录数字1的位置4
        for(int j = 0; j < i; j ++)
        {
            if(Cycle[i] == Cycle[j])
            {
                i--;
                break;
            }
        }
    }
    printf("原始状态:\n");
    Graph(Cycle);
    printf("开始移动:\n");
    for(int i = 2; i<=8; i++) //下一个要找的数
    {
        for(int j=0; j<8; j++) //扫描找数
        {
            if(Cycle[j] == i)
            {
                Temp = (CurNode + 1) % 8;
                if(i!=Cycle[Temp])//如果位置正确就不用再移
                {
                    Cycle[8] = i;//移入中心区
                    Cycle[j] = 0;
                    Graph(Cycle);
                    if(Temp!=j)
                    {
                        if(Temp>j) j+=8;
                        for(int k=j; k>Temp; k--)
                            Cycle[k%8]=Cycle[(k-1)%8];//顺时针轮转
                        Cycle[Temp]=0;
                        Graph(Cycle);
                    }
                    Cycle[Temp]=Cycle[8];//从中心区移出
                    Cycle[8]=0;
                    Graph(Cycle);
                }
                CurNode=Temp;//记录当前位置
                break;
            }
        }
    }
    printf("移动完成!\n");
    system("pause");
    return 0;
}
