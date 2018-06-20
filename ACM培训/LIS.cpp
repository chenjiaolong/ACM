//��̬�滮����ʱ�临�Ӷ�O(N^2)��
//#include <iostream>
//using namespace std;
//#define len(array) (sizeof(array) / sizeof(array[0])) //���鳤��
//int LIS(int array[], int len)
//{
//    int longest[len];
//    for (int i=0; i<len; i++)
//        longest[i] = 1;
//
//    for (int j=1; j<len; j++)
//        for (int i=0; i<j; i++)
//            if (array[j]>array[i]&&longest[j]<longest[i]+1)  //ע��longest[j]<longest[i]+1�������������ʡ�ԡ�
//                longest[j] = longest[i] + 1; //������arr[j]��β�����е�����������г���
//
//    int max = 0;
//    for (int j=0; j<len; j++)
//    {
//        cout << "longest[" << j << "]=" << longest[j] << endl;
//        if (longest[j] > max)
//            max = longest[j];  //��longest[j]���ҳ����ֵ
//    }
//    return max;
//}
//int main()
//{
//    int array[] = {1, 4, 5, 6, 2, 3, 8}; //��������
//    int ret = LIS(array, len(array));
//    cout << "max increment substring len=" << ret << endl;
//    return 0;
//}

//��̬�滮DP����ʱ�临�Ӷ�O(N^2)��
//#include<stdio.h>
//#include <iostream>
//
//using namespace std;
// /**����������� LIS
//   * �����鳤�Ȳ����� 30
//   * DP
//   */
//int dp[31];/* dp[i]��¼��[0,i]�����LIS */
//int lis;/* LIS ���� */
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
// /* ���LIS */
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
//    /* ���LIS���ȣ� sizeof �������鳤�� */
//    printf("%d\n",LIS(array,sizeof(array)/sizeof(int)));
//    /* ���LIS */
//    outputLIS(array,sizeof(array)/sizeof(int) - 1);
//    printf("\n");
//    return 0;
//}

//���򣨿��ţ�+LCS(ʱ�临�Ӷ�O(N^2))
//��ΪLIS�ǵ������������ʣ���������һ��LISһ����������������LCS�����Ҿ���LIS����
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//  /** ����������� LIS
//    * �����鳤�Ȳ����� 30
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
//    /* ����LCS����LIS���� */
//    int len = sizeof(array)/sizeof(int);
//    printf("%d\n",LCS(array,arraycopy,len));
//    return 0;
//}

//���ֲ��ҷ�O��NlgN���㷨
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define N 9 //����Ԫ�ظ���
//int array[N] = {2, 1, 6, 3, 5, 4, 8, 7, 9}; //ԭ����
//int B[N]; //�ڶ�̬�滮��ʹ�õ�����,���ڼ�¼�м���,�京����������˵����,��μ����ĵĽ���
//int len; //���ڱ�ʾB�����е�Ԫ�ظ���
//
// //�޸ĵĶ��ֲ����㷨����������Ԫ����Ҫ�����λ�á�
//int BiSearch(int *b, int len, int w)//�����޸ĵĶ��������㷨
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
//        else    //�ҵ��˸�Ԫ�أ���ֱ�ӷ���
//            return mid;
//    }
//    return left;//����b�в����ڸ�Ԫ�أ��򷵻ظ�Ԫ��Ӧ�ò����λ��
//}
//int LIS(int *array, int n) //��������������еĳ���,����B�����Ԫ��,array[]ѭ����һ���,B�ĳ���len��Ϊ����
//{
//    len = 1;
//    B[0] = array[0];
//    int i, pos = 0;
//
//    for(i=1; i<n; ++i)
//    {
//        if(array[i] > B[len-1]) //�������B������Ԫ�أ���ֱ�Ӳ��뵽B����ĩβ
//        {
//            B[len] = array[i];
//            ++len;
//        }
//        else
//        {
//            pos = BiSearch(B, len, array[i]); //���ֲ�����Ҫ�����λ��
//            B[pos] = array[i];
//        }
//    }
//    return len;//LIS�ĳ���
//}
//int main()
//{
//    printf("LIS: %d\n", LIS(array, N));
//
//    int i;
//    for(i=0; i<len; ++i)
//        printf("B[%d]=%d\n", i, B[i]);//����B��ֵֻ�Ǹ�����¼�洢�Ķ�Ӧ����LIS����Сĩβ��
//
//    return 0;
//}

//DP+���ֲ���
//#include <iostream>
//#include<stdio.h>
//using namespace std;
// /**����������� LIS
//   *�����鳤�Ȳ����� 30
//   * DP + BinarySearch
//   */
//int MaxV[30]; /* �洢����i+1��len�������������Ԫ�ص���Сֵ */
//int len;  /* �洢�����е���󳤶� ��MaxV��ǰ���±�*/
// /* ����MaxV[i]�иոմ���x���Ǹ�Ԫ�ص��±� */
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
//    MaxV[0] = array[0]; /* ��ʼ�� */     len = 1;
//    for(int i = 1; i < size; ++i) /* Ѱ��arr[i]�����ĸ�����LIS�����Ԫ�� */
//    {
//        if(array[i] > MaxV[len-1]) /* ����������Ȼ������ң�������ֲ���λ�� */
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
//    /* ����LIS���� */
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
                if(num > b[mid]) l = mid + 1; // ���������� lower_bound����һ���ǵݼ�����[first, last)�еĵ�һ�����ڵ���ֵval��λ�á�
                // if(num >= b[mid]) l = mid + 1;// �ǵݼ������� upper_bound����һ���ǵݼ�����[first, last)�е�һ������val��λ��
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
