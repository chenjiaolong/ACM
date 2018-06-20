// 递归写法
//#include<stdio.h>
//#include<string.h>
//int num[15],cnt[15];
//int N,ans;
//void DFS(int cur)
//{
//    //之前标记已放置皇后的点坐标x（j,num[j]）;
//    if(cur==N)
//    {
//        ans++;
//        return;
//    }
//    int i,j;
//    for(i=0; i<N; i++)//i表示程序运行到现在待放置的皇后应处于的列（横坐标）
//    {
//        int flag=0;
//        for(j=0; j<cur; j++)//j表示遍历已放置皇后的行（纵坐标）以检测是否当前的num[j]列（横坐标）是否能放置皇后
//            if(num[j]==i||i-cur==num[j]-j||i+cur==num[j]+j)//num[j]存的是已放置的皇后的列（横坐标）
//            {
//                flag=1;
//                break;
//            }
//        if(!flag)
//        {
//            num[cur]=i;//cur表示当前要放置的皇后的行（纵坐标）
//            DFS(cur+1);
//        }
//    }
//    return ;
//}
//int main()
//{
//    memset(cnt,-1,sizeof(cnt));
//    while(~scanf("%d",&N)&&N)
//    {
//        memset(num,-1,sizeof(num));
//        if(cnt[N]==-1)
//        {
//            ans=0;
//            DFS(0);
//            printf("%d\n",cnt[N]=ans);
//            continue;
//        }
//        printf("%d\n",cnt[N]);
//
//    }
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//const int N=20;   //最多放皇后的个数
//int q[N];         //各皇后所在的行号
//int cont = 0;     //统计解得个数
////输出一个解
//void print(int n)
//{
//    int i,j;
//    cont++;
//    printf("第%d个解：",cont);
//    for(i=1; i<=n; i++)
//        printf("(%d,%d) ",i,q[i]);
//    printf("\n");
//    for(i=1; i<=n; i++)      //行
//    {
//        for(j=1; j<=n; j++)  //列
//        {
//            if(q[i]!=j)
//                printf("x ");
//            else
//                printf("Q ");
//        }
//        printf("\n");
//    }
//}
////检验第i行的k列上是否可以摆放皇后
//int find(int i,int k)
//{
//    int j=1;
//    while(j<i)  //j=1~i-1是已经放置了皇后的行
//    {
//        //第j行的皇后是否在k列或(j,q[j])与(i,k)是否在斜线上
//        if(q[j]==k || abs(j-i)==abs(q[j]-k))
//            return 0;
//        j++;
//    }
//    return 1;
//}
////放置皇后到棋盘上
//void place(int k,int n)
//{
//    int j;
//    if(k>n)
//        print(n);
//    else
//    {
//        for(j=1; j<=n; j++) //试探第k行的每一个列
//        {
//            if(find(k,j))
//            {
//                q[k] = j;
//                place(k+1,n);  //递归总是在成功完成了上次的任务的时候才做下一个任务
//            }
//        }
//    }
//}
//
//int main(void)
//{
//    int n;
//    printf("请输入皇后的个数(n<=20),n=:");
//    scanf("%d",&n);
//    if(n>20)
//        printf("n值太大，不能求解!\n");
//    else
//    {
//        printf("%d皇后问题求解如下(每列的皇后所在的行数):\n",n);
//        place(1,n);        //问题从最初状态解起
//        printf("\n");
//    }
//    system("pause");
//    return 0;
//}

// 非递归写法
///**
//* 回溯法解八皇后问题
//* 使用一个一维数组表示皇后的位置
//* 其中数组的下标表示皇后所在的行
//* 数组元素的值表示皇后所在的列
//* 这样设计的棋盘，所有皇后必定不在同一行，于是行冲突就不存在了
//**/
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//#define QUEEN 8     //皇后的数目
//#define INITIAL -10000   //棋盘的初始值
//
////int a[QUEEN];    //一维数组表示棋盘
//
//void init()  //对棋盘进行初始化
//{
//    int *p;
//      for (p = a; p < a + QUEEN; ++p)
//        *p = INITIAL;
//}
//
//int valid(int row, int col)    //判断第row行第col列是否可以放置皇后
//{
//    int i;
//    for (i = 0; i < QUEEN; ++i)   //对棋盘进行扫描
//    {
//        if (a[i] == col || abs(i - row) == abs(a[i] - col))   //判断列冲突与斜线上的冲突
//            return 0;
//    }
//    return 1;
//}
//
//void print()    //打印输出N皇后的一组解
//{
//    int i, j;
//    for (i = 0; i < QUEEN; ++i)
//    {
//        for (j = 0; j < QUEEN; ++j)
//        {
//            if (a[i] != j)      //a[i]为初始值
//                printf("%c ", '.');
//            else                //a[i]表示在第i行的第a[i]列可以放置皇后
//                printf("%c ", '#');
//        }
//        printf("\n");
//    }
//    for (i = 0; i < QUEEN; ++i)
//        printf("%d ", a[i]);
//    printf("\n");
//    printf("--------------------------------\n");
//}
//
//void queen()      //N皇后程序
//{
//    int n = 0;
//    int i = 0, j = 0;
//    while (i < QUEEN)
//    {
//        while (j < QUEEN)        //对i行的每一列进行探测，看是否可以放置皇后
//        {
//            if(valid(i, j))      //该位置可以放置皇后
//            {
//                a[i] = j;        //第i行放置皇后
//                j = 0;           //第i行放置皇后以后，需要继续探测下一行的皇后位置，所以此处将j清零，从下一行的第0列开始逐列探测
//                break;
//            }
//            else
//                ++j;             //继续探测下一列
//        }
//        if(a[i] == INITIAL)         //第i行没有找到可以放置皇后的位置
//        {
//            if (i == 0)             //回溯到第一行，仍然无法找到可以放置皇后的位置，则说明已经找到所有的解，程序终止
//                break;
//            else                    //没有找到可以放置皇后的列，此时就应该回溯
//            {
//                --i;
//                j = a[i] + 1;        //把上一行皇后的位置往后移一列
//                a[i] = INITIAL;      //把上一行皇后的位置清除，重新探测
//                continue;
//            }
//        }
//        if (i == QUEEN - 1)          //最后一行找到了一个皇后位置，说明找到一个结果，打印出来
//        {
//            printf("answer %d : \n", ++n);
//            print();
//            //不能在此处结束程序，因为我们要找的是N皇后问题的所有解，此时应该清除该行的皇后，从当前放置皇后列数的下一列继续探测。
//            //_sleep(600);
//            j = a[i] + 1;             //从最后一行放置皇后列数的下一列继续探测
//            a[i] = INITIAL;           //清除最后一行的皇后位置
//            continue;
//        }
//        ++i;              //继续探测下一行的皇后位置
//    }
//}
//
//int main(void)
//{
//    // freopen("test.out", "w", stdout);
//    init();
//    queen();
//    // system("pause");
//    return 0;
//}


// 非递归写法
//#include<math.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include<iostream>
//
//using namespace std;
//#define Max 20      //定义棋盘的最大值
//int a[Max];
//int show(int S)    //定义输出函数
//{
//    int i,p,q;
//    int b[Max][Max]= {0};    //定义并初始化b[][]输出数组
//
//    for(i=1; i<=S; i++)  //按横列i顺序输出a[i]数组坐标
//    {
//        b[i][a[i]]=1;
//        printf("(%d,%d)\t",i,a[i]);
//    }
//    printf("\n");
//    for(p=1; p<=S; p++)   //按棋盘的横列p顺序标明皇后的位置
//    {
//        for(q=1; q<=S; q++)
//        {
//            if(b[p][q]==1)     //在第p行第q列放置一个皇后棋子
//                printf("●");
//            else
//                printf("○");
//        }
//        printf("\n");
//    }
//    return 0;
//}
//
//int check(int k)    //定义check函数
//{
//    int i;
//    for(i=1; i<k; i++)  //将第k行与前面的第1~~k-1行进行判断
//        if((a[i]==a[k]) || (a[i]-a[k]==k-i) || (a[i]-a[k]==i-k))    //检查是否有多个皇后在同一条直线上
//            return 0;
//    return 1;
//}
//
//void check_m(int num)    //定义函数
//{
//    int k=1,count=0;
//    printf("The possible configuration of N queens are:\n");
//    a[k]=1;
//    while(k>0)
//    {
//        if(k<=num && a[k]<=num)    //从第k行第一列的位置开始，为后续棋子选择合适位子
//        {
//            if(check(k)==0)    //第k行的a[k]列不能放置皇后
//                a[k]++;        //继续探测当前行的下一列：a[k]+1
//            else
//            {
//                k++;         //第K行的位置已经确定了，继续寻找第k+1行皇后的位置
//                a[k]=1;      //从第一列开始查找
//            }
//        }
//        else
//        {
//            if(k>num)     //若满足输出数组的要求则输出该数组
//            {
//                count++;
//                printf("[%d]:  ",count);
//                show(num);    //调用输出函数show()
//            }
//            //如果k>num会执行下面两行代码，因为虽然找到了N皇后问题的一个解，但是要找的是所有解，需要回溯，从当前放置皇后的下一列继续探测
//            //如果a[k]>num也会执行下面两行代码，就是说在当前行没有找到可以放置皇后的位置，于是回溯，从上一行皇后位置的下一列继续探测
//            k--;      //棋子位置不符合要求，则退回前一步
//            a[k]++;   //继续试探下一列位置
//        }
//    }
//    printf("The count is: %d \n",count);
//}
//
//int main(void)
//{
//    int N,d;
//    system("color 2a");
//    do
//    {
//        printf("********************N皇后问题系统*********************\n\n");
//        printf("                  1. 四皇后问题                        \n");
//        printf("                  2. 八皇后问题                        \n");
//        printf("                  3. N 皇后问题(N<20)                  \n");
//        printf("                  4. 退出                              \n");
//        printf("******************************************************\n");
//        printf("\n    从数字1-4之间的数选择需要的操作\n\n"); /*提示输入选项*/
//        printf("      请输入你要选择的功能选项:__\n");
//        scanf("%d",&d);
//        switch(d)
//        {
//        case 1:
//            check_m(4);      //4皇后问题
//            break;
//        case 2:
//            check_m(8);     //8皇后问题
//            break;
//        case 3:
//            printf("请输入N的值：_");
//            fflush(stdin);      //清除缓冲
//            scanf("%d",&N);
//            printf("\n");
//            if(N>0&&N<20)
//            {
//                check_m(N);    //N皇后问题
//                break;
//            }
//            else
//            {
//                printf("输入错误，请从新输入：");
//                printf("\n\n");
//                break;
//            }
//        case 4:
//            exit(0);     //程序结束
//        }
//    }
//    while(1);
//    system("pause");
//    return 0;
//}

/**
*目前最快的N皇后递归解决方法
*N Queens Problem
*试探 - 回溯算法，递归实现
*/
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
// sum 用来记录皇后放置成功的不同布局数；upperlim 用来标记所有列都已经放置好的皇后
long sum = 0, upperlim = 1;

// 试探算法从最右边的列开始
// row、ld和rd，分别表示在纵列（行）和两个对角线方向的限制条件下这一行的哪些地方不能放。
// 位于该行上的冲突位置就用row、ld和rd中的1来表示。
// 把它们三个并起来，得到该行所有的禁位，取反后就得到所有可以放的位置（用pos来表示）。
void Test(long row, long ld, long rd)
{
    if(row != upperlim)
    {
        // row, ld, rd 进行 “或” 运算，求得所有可以放置皇后的列，对应位为0
        // 然后再取反后 “与” 运算上全的数， 来求得当前所有可以放置的皇后的位置，对应列改为1
        // 也就是求取当前那些列可以放置皇后
        long pos = upperlim & ~(row | ld | rd);
        while(pos) // 0 -- 皇后没有地方可放，回溯
        {
            // 拷贝 pos 最右边为 1 的 bit，其余 bit 置 0
            // 也就是取得可以放置皇后的最右边的列
            // p就表示该行的某个可以放置的位置，把它从pos中移除并递归调用test过程。
            long p = pos & (~pos + 1);// 其结果是取出最右边的那个1
            // long p = pos & -pos 的意思就是取最右边的 1 再组成二进制数

            // 将 pos 最右边为 1 的 bit 清零
            // 也就是为获取下一次的最右可用列使用做准备
            // 程序将来回溯到这个位置继续试探
            pos -= p;
            // row | p,将当前列置1，表示记录这次皇后放置的列
            // (ld | p) << 1, 标记当前皇后左边相邻的列不允许下一个皇后放置
            // (ld | p) >> 1, 标记当前皇后右边相邻的列不允许下一个皇后放置
            // 此处的移位操作实际上是记录对角线上的限制，只是因为问题都化归到一行网格上来解决， 所以表示为列的限制就可以了。显然，随着移位
            // 在每次选择列之前进行， 原来N X N 网格中某个已放置的皇后针对其对角线上产生的限制都被记录下来了
            Test(row | p, (ld | p) << 1, (rd | p) >> 1);
        }
    }
    else// row 的所有位都为1 ，即找到了一个成功的布局，回溯
        sum ++;
}
int main(int argc, char *argv[])
{
    time_t tm;
    int n = 16;
    if(argc != 1)
        n = atoi(argv[1]);
    tm = time(0);
    // 因为整型数的限制，最大只能32 位
    // 如果想处理N大于32的皇后问题，需要用 bitset数据结构进行存储
    if(n < 1 || n > 32)
    {
        printf("只计算1 ~ 32之间\n");
        exit(-1);
    }
    printf("%d 皇后\n", n);
    upperlim = (upperlim << n) - 1;

    Test(0, 0, 0);
    printf("共有%ld种排列，计算时间是%d秒\n", sum, (int) (time(0) - tm));
    system("pause");

    return 0;
}

