//动态规划法（时间复杂度O(N^2)）
//#include <iostream>
//using namespace std;
//#define len(array) (sizeof(array) / sizeof(array[0])) //数组长度
//int LIS(int array[], int len)
//{
//    int longest[len];
//    for (int i=0; i<len; i++)
//        longest[i] = 1;
//
//    for (int j=1; j<len; j++)
//        for (int i=0; i<j; i++)
//            if (array[j]>array[i]&&longest[j]<longest[i]+1)  //注意longest[j]<longest[i]+1这个条件，不能省略。
//                longest[j] = longest[i] + 1; //计算以arr[j]结尾的序列的最长递增子序列长度
//
//    int max = 0;
//    for (int j=0; j<len; j++)
//    {
//        cout << "longest[" << j << "]=" << longest[j] << endl;
//        if (longest[j] > max)
//            max = longest[j];  //从longest[j]中找出最大值
//    }
//    return max;
//}
//int main()
//{
//    int array[] = {1, 4, 5, 6, 2, 3, 8}; //测试数组
//    int ret = LIS(array, len(array));
//    cout << "max increment substring len=" << ret << endl;
//    return 0;
//}

//动态规划DP法（时间复杂度O(N^2)）
//#include<stdio.h>
//#include <iostream>
//
//using namespace std;
// /**最长递增子序列 LIS
//   * 设数组长度不超过 30
//   * DP
//   */
//int dp[31];/* dp[i]记录到[0,i]数组的LIS */
//int lis;/* LIS 长度 */
//int LIS(int * array, int size)
//{
//    for(int i = 0; i < size; ++i)
//    {
//        dp[i] = 1;
//        for(int j = 0; j < i; ++j)
//            if(array[i] > array[j] && dp[i] < dp[j] + 1)
//            {
//                dp[i] = dp[j] + 1;
//                if(dp[i] > lis)
//                    lis = dp[i];
//            }
//    }
//    return lis;
//}
// /* 输出LIS */
//void outputLIS(int * array, int index)
//{
//    bool isLIS = 0;
//    if(index < 0 || lis == 0)
//        return;
//    if(dp[index] == lis)
//    {
//        --lis;
//        isLIS = 1;
//    }
//    outputLIS(array,--index);
//    if(isLIS)
//        printf("%d ",array[index+1]);
//}
//int main()
//{
//    int array[] = {1,-1,2,-3,4,-5,6,-7};
//    /* 输出LIS长度； sizeof 计算数组长度 */
//    printf("%d\n",LIS(array,sizeof(array)/sizeof(int)));
//    /* 输出LIS */
//    outputLIS(array,sizeof(array)/sizeof(int) - 1);
//    printf("\n");
//    return 0;
//}

//排序（快排）+LCS(时间复杂度O(N^2))
//因为LIS是单调递增的性质，所以任意一个LIS一定跟排序后的序列有LCS，并且就是LIS本身。
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//  /** 最长递增子序列 LIS
//    * 设数组长度不超过 30
//    * quicksort + LCS
//    */
//void Swap(int * array, int i, int j)
//{
//    int temp = array[i];
//    array[i] = array[j];
//    array[j] = temp;
//}
//void QuickSort(int * array, int left, int right)
//{
//    if(left >= right)
//        return ;
//    int index = left;
//    for(int i =left+1; i <= right; ++i)
//        if(array[i] < array[left])
//            Swap(array,++index,i);
//    Swap(array,index,left);
//    QuickSort(array,left,index-1);
//    QuickSort(array,index+1,right);
//}
//int dp[31][31];
//int LCS(int * array, int * arraycopy, int len)
//{
//    for(int i = 1; i <= len; ++i)
//        for(int j = 1; j <= len; ++j)
//        {
//            if(array[i-1] == arraycopy[j-1])
//                dp[i][j] = dp[i-1][j-1] + 1;
//            else
//                dp[i][j] =max(dp[i][j-1],dp[i-1][j]);
//        }
//    return dp[len][len];
//}
//int main()
//{
//    int array[] = {1,-1,2,-3,4,-5,6,-7};
//    int arraycopy [sizeof(array)/sizeof(int)];
//
//    memcpy(arraycopy,array,sizeof(array));
//    QuickSort(arraycopy,0,sizeof(array)/sizeof(int)-1);
//
//    /* 计算LCS，即LIS长度 */
//    int len = sizeof(array)/sizeof(int);
//    printf("%d\n",LCS(array,arraycopy,len));
//    return 0;
//}

//二分查找法O（NlgN）算法
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define N 9 //数组元素个数
//int array[N] = {2, 1, 6, 3, 5, 4, 8, 7, 9}; //原数组
//int B[N]; //在动态规划中使用的数组,用于记录中间结果,其含义三言两语说不清,请参见博文的解释
//int len; //用于标示B数组中的元素个数
//
// //修改的二分查找算法，返回数组元素需要插入的位置。
//int BiSearch(int *b, int len, int w)//做了修改的二分搜索算法
//{
//    int left = 0, right = len - 1;
//    int mid;
//    while (left <= right)
//    {
//        mid = left + (right-left)/2;
//        if (b[mid] > w)
//            right = mid - 1;
//        else if (b[mid] < w)
//            left = mid + 1;
//        else    //找到了该元素，则直接返回
//            return mid;
//    }
//    return left;//数组b中不存在该元素，则返回该元素应该插入的位置
//}
//int LIS(int *array, int n) //计算最长递增子序列的长度,计算B数组的元素,array[]循环完一遍后,B的长度len即为所求
//{
//    len = 1;
//    B[0] = array[0];
//    int i, pos = 0;
//
//    for(i=1; i<n; ++i)
//    {
//        if(array[i] > B[len-1]) //如果大于B中最大的元素，则直接插入到B数组末尾
//        {
//            B[len] = array[i];
//            ++len;
//        }
//        else
//        {
//            pos = BiSearch(B, len, array[i]); //二分查找需要插入的位置
//            B[pos] = array[i];
//        }
//    }
//    return len;//LIS的长度
//}
//int main()
//{
//    printf("LIS: %d\n", LIS(array, N));
//
//    int i;
//    for(i=0; i<len; ++i)
//        printf("B[%d]=%d\n", i, B[i]);//数组B的值只是辅助记录存储的对应长度LIS的最小末尾。
//
//    return 0;
//}

//DP+二分查找
//#include <iostream>
//#include<stdio.h>
//using namespace std;
// /**最长递增子序列 LIS
//   *设数组长度不超过 30
//   * DP + BinarySearch
//   */
//int MaxV[30]; /* 存储长度i+1（len）的子序列最大元素的最小值 */
//int len;  /* 存储子序列的最大长度 即MaxV当前的下标*/
// /* 返回MaxV[i]中刚刚大于x的那个元素的下标 */
//int BinSearch(int * MaxV, int size, int x)
//{
//    int left = 0, right = size-1;
//    while(left <= right)
//    {
//        int mid = (left + right) / 2;
//        if(MaxV[mid] <= x)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    return left;
//}
//int LIS(int *array, int size)
//{
//    MaxV[0] = array[0]; /* 初始化 */     len = 1;
//    for(int i = 1; i < size; ++i) /* 寻找arr[i]属于哪个长度LIS的最大元素 */
//    {
//        if(array[i] > MaxV[len-1]) /* 大于最大的自然无需查找，否则二分查其位置 */
//            MaxV[len++] = array[i];
//        else
//        {
//            int pos = BinSearch(MaxV,len,array[i]);
//            MaxV[pos] = array[i];
//        }
//    }
//    return len;
//}
//int main()
//{
//    int array[] = {1,-1,2,-3,4,-5,6,-7};
//    /* 计算LIS长度 */
//    printf("%d\n",LIS(array,sizeof(array)/sizeof(int)));
//    return 0;
//}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
const int maxn = 1e5 + 10;
int n;
int a[maxn],b[maxn], dp[maxn];
int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
            dp[i] = 1;
        }
        int l, r, mid, maxi = 0, len = 0;
        for(int i = 1; i <= n; i ++)
        {
            int num = a[i];
            l = 1;
            r = len;
            while(l <= r)
            {
                mid = (l + r) >> 1;
                if(num > b[mid]) l = mid + 1; // 递增子序列 lower_bound返回一个非递减序列[first, last)中的第一个大于等于值val的位置。
                // if(num >= b[mid]) l = mid + 1;// 非递减子序列 upper_bound返回一个非递减序列[first, last)中第一个大于val的位置
                else r = mid - 1;
            }
            b[l] = num;
            dp[i] = l;
            if(len < l) len = l;
            if(maxi < dp[i]) maxi = dp[i];
        }
        for(int i = 1; i <= n; i ++)
            printf("sss i = %d , dp[%d] = %d\n", i, i, dp[i]);
        printf("%d\n", maxi);
    }
    return 0;
}
