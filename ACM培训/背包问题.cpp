// 第一类： 01 背包
/**
* 题目表述 :有N件物品和一个容量为V的背包。
* 第i件物品的费用是c[i]，价值是w[i]。
* 求解将哪些物品装入背包可使价值总和最大。*/
// 特点是：每种物品仅有一件，可以选择放或不放
// f[i][v]表示前i件物品恰放入一个容量为v的背包可以获得的最大价值
// 状态方程：f[i][v] = max{f[i-1][v], f[i-1][v-c[i]] + w[i]} （二维）（复杂度：T = O(N*V), S = O(N*V)）
// f[v]保存的是状态f[i-1][v-c[i]]的值
// 保证第i次循环中的状态f[v]是由状态f[v-c]递推而来
// 状态方程：f[v] = max{f[v], f[v-c[i]] + w[i]]}（一维）（复杂度：T = O(N*V), S = O(V)）
// 初始化问题
// (1)要求恰好装满背包，那么在初始化时除了f[0]为0其它f[1..V]均设为-∞;
// (2)背包不一定装满，而是只希望价格尽量大，初始化时应该将f[0..V]全部设为0。
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//using namespace std;
//int Package01(int Weight[], int Value[], int nLen, int nCapacity)
//{
//	int Table[nLen + 1][nCapacity + 1];
//	memset(Table, 0, sizeof(Table));
//	int Path[nLen + 1][nCapacity + 1];
//	for(int i = 1; i <= nLen; i++)
//	{
//		for(int j = 1; j <= nCapacity; j++)
//		{
//			Table[i][j] = Table[i-1][j];
//			Path[i][j] = 0;
//			if(j >= Weight[i-1] && Table[i][j] < Table[i-1][j-Weight[i-1]]+Value[i-1])
//			{
//				Table[i][j] = Table[i-1][j-Weight[i-1]]+Value[i-1];
//				Path[i][j] = 1;
//			}
//		}
//	}
//	for(int i = 1; i <= nLen; i++)
//		for(int j = 1; j <= nCapacity; j++)
//		printf("%2d%c", Table[i][j], j == nCapacity ? '\n' : ' ');
//	int i = nLen, j = nCapacity;
//	while(i > 0 && j > 0)
//	{
//		if(Path[i][j] == 1)
//		{
//			cout << Weight[i-1] << " ";
//			j -= Weight[i-1];
//		}
//		i--;
//	}
//	cout << endl;
//
//	int nRet = Table[nLen][nCapacity];
//	return nRet;
//}
//int Package01_Compress(int Weight[], int Value[], int nLen, int nCapacity)
//{
//	int * Table = new int [nCapacity+1];
//	memset(Table,0,(nCapacity+1)*sizeof(int));
//	for(int i = 0; i < nLen; i++)
//		for(int j = nCapacity; j >= Weight[i]; j--)
//			if(Table[j] < Table[j-Weight[i]]+Value[i])
//				Table[j] = Table[j-Weight[i]]+Value[i];
//	int nRet = Table[nCapacity];
//	delete [] Table;
//	return nRet;
//}
//int main()
//{
//	int Weight[] = {2,3,1,4,6,5};
//	int Value[] =  {5,6,5,1,19,7};
//	int nCapacity = 10;
//	cout << Package01(Weight,Value,sizeof(Weight)/sizeof(int),nCapacity) << endl;
//	cout << Package01_Compress(Weight,Value,sizeof(Weight)/sizeof(int),nCapacity) << endl;
//	return 0;
//}

//#include <stdio.h>
//typedef struct Object
//{
//    int weight;
//    int value; // float rate;
//} Object;
//Object * array; //用来存储物体信息的数组
//int num; //物体的个数
//int container; //背包的容量
//int ** dynamic_table; //存储动态规划表
//bool * used_table; //存储物品的使用情况
////ouput the table of dynamic programming, it's for detection
//void print_dynamic_table()
//{
//    printf("动态规划表如下所示:\n");
//    /* for(int j=0; j<=container; j++) printf("%d ",j); printf("\n");*/
//    for(int i=1; i<=num; i++)
//    {
//        for(int j=0; j<=container; j++)
//            printf("%d ",dynamic_table[i][j]);
//        printf("\n");
//    }
//}//打印动态规划表
//void print_array()
//{
//    for(int i=1; i<=num; i++)
//        printf("第%d个物品的重量和权重:%d %d\n",i,array[i].weight,array[i].value);
//}
////打印输入的物品情况//插入排序，按rate=value/weight由小到大排//动态规划考虑了所有情况，所以可以不用排序
///*void sort_by_rate(){
//for(int i=2; i<=num; i++) {
//Object temp=array[i];
//for(int j=i-1; j>=1; j--)
//if(array[j].rate>temp.rate)
//array[j+1]=array[j];
//else break;
//array[j+1]=temp;
//}}*/
//void print_used_object()
//{
//    printf("所使用的物品如下所示:\n");
//    for(int i=1; i<=num; i++)
//        if(used_table[i]==1)
//            printf("%d-%d\n", array[i].weight, array[i].value);
//}
////打印物品的使用情况
///* 做测试时使用
//void print_used_table(bool * used_table){
//printf("used table as follows:\n");
//for(int i=1; i<=num; i++)
//printf("object %d is %d", i, used_table[i]);
//}*/
//void init_problem()
//{
//    printf("输入背包的容量:\n");
//    scanf("%d", &container);
//    printf("输入物品的个数:\n");
//    scanf("%d", &num);
//    array=new Object[num+1];
//    printf("输入物品的重量和价值, 格式如：4-15\n");
//    for(int i=1; i<=num; i++)
//    {
//        char c;
//        scanf("%d%c%d", &array[i].weight, &c, &array[i].value);
//// array[i].rate=array[i].value/array[i].weight;
//    }
//    print_array();
//}
////对物体的使用情况进行回查
//void trace_back()
//{
//    int weight=container;
//    used_table=new bool[num+1];
//    for(int i=1; i<=num; i++) used_table[i]=0;
////initalize the used_table to be non-used
//    for(int j=1; j<num; j++)
//    {
////说明物品j被使用
//        if(dynamic_table[j][weight]!=dynamic_table[j+1][weight])
//        {
//            weight-=array[j].weight;
//            used_table[j]=1;
//        }
//// print_used_table(used_table);
//    }
////检测第num个物品是否被使用
//    if(weight>=array[num].weight)
//        used_table[num]=1;
//}
//void dynamic_programming()
//{
//    dynamic_table=new int * [num+1];
//    for(int k=1; k<=num; k++)
//        dynamic_table[k]=new int[container+1];
////dynamic_programming table
////为二维动态规划表分配内存
//    for(int m=1; m<num; m++)
//        for(int n=0; n<=container; n++)
//            dynamic_table[m][n]=0;
//    int temp_weight=array[num].weight;
//    for(int i=0; i<=container; i++)
//        dynamic_table[num][i]=i<temp_weight?0:array[num].value;
////初始化动态规划表
//    for(int j=num-1; j>=1; j--)
//    {
//        temp_weight=array[j].weight;
//        int temp_value=array[j].value;
//        for(int k=0; k<=container; k++)
//            if(k>=temp_weight && dynamic_table[j+1][k] < dynamic_table[j+1][k-temp_weight]+temp_value)
//                dynamic_table[j][k]=dynamic_table[j+1][k-temp_weight]+temp_value;
//            else dynamic_table[j][k]=dynamic_table[j+1][k];
//    }//构建动态规划表
//    print_dynamic_table();//打印动态规划表
//}
//
//int main()
//{
//    init_problem();
//    dynamic_programming();
//    trace_back();
//    print_used_object();
//    return 0;
//}

// “01背包”最优方案总数分析及实现
// 最优方案总数这里指物品总价值最大的方案数。
// 设G[i][j]代表F[i][j]的方案总数，那么最总结果应该是G[N][V]
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//using namespace std;
//int Package01Optimal(int Weight[], int Value[], int nLen, int nCapacity)
//{
//	int MaxValueTable[nLen + 1][nCapacity + 1];
//	memset(MaxValueTable, 0, sizeof(MaxValueTable));
//	int OptimalTable[nLen + 1][nCapacity + 1];
//	// memset(OptimalTable, 0, sizeof(OptimalTable));
//
//	//initiallize all OptimalTable[][] with 1
//	for(int i = 0; i <= nLen; i++)
//		for(int j = 0; j <= nCapacity; j++)
//			OptimalTable[i][j] = 1;
//
//	for(int i = 1; i <= nLen; i++)
//		for(int j = 1; j <= nCapacity; j++)
//		{
//
//			MaxValueTable[i][j] = MaxValueTable[i-1][j];
//			OptimalTable[i][j] = OptimalTable[i-1][j];
//			if(j >= Weight[i-1])
//			{
//			   	if(MaxValueTable[i][j] < MaxValueTable[i-1][j-Weight[i-1]]+Value[i-1])
//				{
//					MaxValueTable[i][j] = MaxValueTable[i-1][j-Weight[i-1]]+Value[i-1];
//					OptimalTable[i][j] = OptimalTable[i-1][j-Weight[i-1]];
//				}
//				else if(MaxValueTable[i][j] == (MaxValueTable[i-1][j-Weight[i-1]]+Value[i-1]))
//					OptimalTable[i][j] = OptimalTable[i-1][j]+OptimalTable[i-1][j-Weight[i-1]];
//			}
//		}
//
//	cout << "OptimalCount:" << OptimalTable[nLen][nCapacity] << endl;
//	for(int i = 1; i <= nLen; i++)
//        for(int j = 1; j <= nCapacity; j++)
//        printf("%2d%c", OptimalTable[i][j], j == nCapacity ? '\n' : ' ');
//
//	int nRet = MaxValueTable[nLen][nCapacity];
//	return nRet;
//}
//int Package01Optimal_Compress(int Weight[], int Value[], int nLen, int nCapacity)
//{
//	int * MaxValueTable = new int [nCapacity+1];
//	memset(MaxValueTable,0,(nCapacity+1)*sizeof(int));
//
//	//initiallize all OptimalTable[] with 1
//	int* OptimalTable = new int[nCapacity+1];
//	for(int i = 0; i <= nCapacity; i++)
//		OptimalTable[i] = 1;
//
//	for(int i = 0; i < nLen; i++)
//		for(int j = nCapacity; j >=Weight[i]; j--)
//		{
//			if(MaxValueTable[j] < MaxValueTable[j-Weight[i]]+Value[i])
//			{
//				MaxValueTable[j] = MaxValueTable[j-Weight[i]]+Value[i];
//				OptimalTable[j] = OptimalTable[j-Weight[i]];
//			}
//			else if(MaxValueTable[j] == MaxValueTable[j-Weight[i]]+Value[i])
//				OptimalTable[j] = OptimalTable[j-Weight[i]]+OptimalTable[j];
//		}
//
//	cout << endl << "OptimalCount:" << OptimalTable[nCapacity] << endl;
//        for(int i = 1; i <= nCapacity; i++)
//        printf("%2d%c", OptimalTable[i], i == nCapacity ? '\n' : ' ');
//
//	int nRet = MaxValueTable[nCapacity];
//	delete [] OptimalTable;
//	delete [] MaxValueTable;
//	return nRet;
//}
//int main()
//{
//	int Weight[] = {1,1,1,1,1,1};
//	int Value[] =  {2,2,2,2,2,2};
//	// int Weight[] = {3,2,5,4,5};
//	// int Value[] =  {5,5,10,10,10};
//	int nCapacity = 10;
//	cout << "MaxValue:" << Package01Optimal(Weight,Value,sizeof(Weight)/sizeof(int),nCapacity) << endl;
//	cout << "MaxValue:" << Package01Optimal_Compress(Weight,Value,sizeof(Weight)/sizeof(int),nCapacity) << endl;
//	return 0;
//}

// 饭卡hdu 2546
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int n,m;
//    while(~scanf("%d", &n) && n)
//    {
//        int V[1010] = {0};
//        for(int i = 1; i <= n; i++)
//            scanf("%d", &V[i]);
//        scanf("%d", &m);
//        if(m < 5)
//        {
//            printf("%d\n", m);
//            continue;
//        }
//        sort(V + 1, V + n + 1);
//        int dp[1010] = {0};
//        for(int i = 1; i <= n - 1; i++)
//            for(int j = m - 5; j >= V[i]; j --)
//            if(dp[j] < dp[j - V[i]] + V[i])
//            dp[j] = dp[j - V[i]] + V[i];
//        // printf(">>>>>> %d %d\n", V[n], dp[m - 5]);
//        printf("%d\n", m - V[n] - dp[m- 5]);
//    }
//    return 0;
//}

// 第二类：完全背包
/**
* 题目表述 :有N件物品和一个容量为V的背包，每种物品都有无限件可用。
* 第i件物品的费用是c[i]，价值是w[i]。
* 求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。*/
// 特点：每种物品有无限件
// 状态方程：f[i][v] = max{f[i-1][v-k*c[i]]+k*w[i]|0 <= k*c[i] <= v}（二维）（复杂度： 解状态f[i][v]的时间是O(v/c[i])，总：T >= O(NV∑(v/c[i]))）
// 状态方程：f[i][v] = max{f[i-1][v], f[i][v-c[i]] + w[i]}（复杂度：T = O(NV)）
// 状态方程：f[v] = max{f[v], f[v-cost]+weight}（一维）（复杂度：T = O(NV)）
//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//#include<iostream>
//using namespace std;
//int Package02(int Weight[], int Value[], int nLen, int nCapacity)
//{
//    int Table[nLen + 1][nCapacity + 1];
//    memset(Table, 0, sizeof(Table));
//    int Path[nLen + 1][nCapacity + 1];
//    memset(Path, 0, sizeof(Path));
//
//	for(int i = 1; i <= nLen; i++)
//	{
//		for(int j = 1; j <= nCapacity; j++)
//		{
//			Table[i][j] = Table[i-1][j];
//			if(j >= Weight[i-1] && Table[i][j] < Table[i][j-Weight[i-1]]+Value[i-1])
//			{
//				Table[i][j] = Table[i][j-Weight[i-1]]+Value[i-1];
//				Path[i][j]=1;
//			}
//		}
//	}
//	for(int i = 1; i <= nLen; i++)
//        for(int j = 1; j <= nCapacity; j++)
//        printf("%2d%c", Path[i][j], j == nCapacity ? '\n':' ');
//	int i = nLen, j = nCapacity;
//	while(i > 0 && j > 0)
//	{
//		if(Path[i][j] == 1)
//		{
//			cout << Weight[i-1] << " ";
//			j -= Weight[i-1];
//		}
//		else
//			i--;
//	}
//	cout << endl;
//
//	int nRet = Table[nLen][nCapacity];
//	return nRet;
//}
//int Package02_Compress(int Weight[], int Value[], int nLen, int nCapacity)
//{
//	int * Table = new int [nCapacity+1];
//	memset(Table, 0, (nCapacity+1) * sizeof(int));
//
//	int Path[nLen + 1][nCapacity + 1];
//	memset(Path, 0, sizeof(Path));
//
//	for(int i = 0; i < nLen; i++)
//	{
//		for(int j = Weight[i]; j <=nCapacity; j++)
//		{
//			if(Table[j] < Table[j-Weight[i]]+Value[i])
//			{
//				Table[j] = Table[j-Weight[i]]+Value[i];
//				Path[i+1][j] = 1;
//			}
//		}
//	}
//	int nRet = Table[nCapacity];
//	delete [] Table;
//	return nRet;
//}
//int main()
//{
//	int Weight[] = {3,2,5,1,6,4};
//	int Value[] = {6,5,10,2,16,8};
//	// int Weight[] = {2,3,1,4,6,5};
//	// int Value[] = {5,6,5,1,19,7};
//
//	int nCapacity = 10;
//	cout << Package02(Weight,Value,sizeof(Weight)/sizeof(int),nCapacity) << endl;
//	cout << Package02_Compress(Weight,Value,sizeof(Weight)/sizeof(int),nCapacity) << endl;
//	return 0;
//}

// “完全背包”最优方案总数分析及实现
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//using namespace std;
//int Package02Optimal(int Weight[], int Value[], int nLen, int nCapacity)
//{
//    int MaxValueTable[nLen + 1][nCapacity + 1];
//    memset(MaxValueTable, 0, sizeof(MaxValueTable));
//    int OptimalTable[nLen + 1][nCapacity + 1];
//	// memset(OptimalTable, 0, sizeof(OptimalTable));
//	// initiallize all OptimalTable[][] with 1
//	for(int i = 0; i <= nLen; i++)
//		for(int j = 0; j <= nCapacity; j++)
//			OptimalTable[i][j] = 1;
//
//	for(int i = 1; i <= nLen; i++)
//		for(int j = 1; j <= nCapacity; j++)
//		{
//			MaxValueTable[i][j] = MaxValueTable[i-1][j];
//			OptimalTable[i][j] = OptimalTable[i-1][j];
//			if(j >= Weight[i-1])
//			{
//			   	if(MaxValueTable[i][j] < MaxValueTable[i][j-Weight[i-1]]+Value[i-1])
//				{
//					MaxValueTable[i][j] = MaxValueTable[i][j-Weight[i-1]]+Value[i-1];
//					OptimalTable[i][j] = OptimalTable[i][j-Weight[i-1]];
//				}
//				else if(MaxValueTable[i][j] == (MaxValueTable[i][j-Weight[i-1]]+Value[i-1]))
//					OptimalTable[i][j] = OptimalTable[i-1][j]+OptimalTable[i][j-Weight[i-1]];
//			}
//		}
//
//	cout  << "OptimalCount:" << OptimalTable[nLen][nCapacity] << endl;
//	for(int i = 1; i <= nLen; i++)
//        for(int j = 1; j <= nCapacity; j++)
//        printf("%2d%c", OptimalTable[i][j], j == nCapacity ? '\n' : ' ');
//	int nRet = MaxValueTable[nLen][nCapacity];
//	return nRet;
//}
//int Package02Optimal_Compress(int Weight[], int Value[], int nLen, int nCapacity)
//{
//	int * MaxValueTable = new int [nCapacity+1];
//	memset(MaxValueTable,0,(nCapacity+1)*sizeof(int));
//
//	//initiallize all OptimalTable[] with 1
//	int* OptimalTable = new int[nCapacity+1];
//	for(int i = 0; i <= nCapacity; i++)
//		OptimalTable[i] = 1;
//
//	for(int i = 0; i < nLen; i++)
//		for(int j = Weight[i]; j <= nCapacity; j++)
//		{
//			if(MaxValueTable[j] < MaxValueTable[j-Weight[i]]+Value[i])
//			{
//				MaxValueTable[j] = MaxValueTable[j-Weight[i]]+Value[i];
//				OptimalTable[j] = OptimalTable[j-Weight[i]];
//			}
//			else if(MaxValueTable[j] == MaxValueTable[j-Weight[i]]+Value[i])
//				OptimalTable[j] = OptimalTable[j-Weight[i]]+OptimalTable[j];
//		}
//
//	cout << endl << "OptimalCount:" << OptimalTable[nCapacity] << endl;
//	for(int i = 1; i <= nCapacity; i++)
//        printf("%2d%c", OptimalTable[i], i == nCapacity ? '\n':' ');
//	int nRet = MaxValueTable[nCapacity];
//	delete [] OptimalTable;
//	delete [] MaxValueTable;
//	return nRet;
//}
//int main()
//{
//	// int Weight[] = {3,2,5,1,6,4};
//	// int Value[] =  {6,5,10,2,16,8};
//    int Weight[] = {2,2,2};
//    int Value[] =  {5,5,5};
//	int nCapacity = 10;
//	cout << "MaxValue:" << Package02Optimal(Weight,Value,sizeof(Weight)/sizeof(int),nCapacity) << endl;
//	cout << "MaxValue:" << Package02Optimal_Compress(Weight,Value,sizeof(Weight)/sizeof(int),nCapacity) << endl;
//	return 0;
//}

// “01背包”及“完全背包”装满背包的方案总数分析及实现
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//using namespace std;
//int Package01_FullOfPakage(int Weight[], int nLen, int nCapacity)
//{
//    int MethodTable[nLen + 1][nCapacity + 1];
//    memset(MethodTable, 0, sizeof(MethodTable));
//    MethodTable[0][0] = 1;
//    for(int i = 1; i <= nLen; i++)
//        for(int j = 0; j <=nCapacity; j++)
//            if(j < Weight[i - 1]) MethodTable[i][j] = MethodTable[i - 1][j];
//            else MethodTable[i][j] = MethodTable[i - 1][j] + MethodTable[i - 1][j - Weight[i - 1]];
//    cout << "MethodTable:" << endl;
//    for(int i = 1; i <= nLen; i++)
//        for(int j = 1; j <= nCapacity; j++)
//            printf("%2d%c", MethodTable[i][j], j == nCapacity ? '\n' : ' ');
//
//    int nRet = MethodTable[nLen][nCapacity];
//    return nRet;
//}
//int Package01_FullOfPakage_Compress(int Weight[], int nLen, int nCapacity)
//{
//    int *MethodTable = new int [nCapacity + 1];
//    memset(MethodTable, 0, (nCapacity + 1) * sizeof(int));
//
//    MethodTable[0] = 1;
//    for(int i = 0; i < nLen; i++)
//        for(int j = nCapacity; j >= Weight[i]; j--)
//            if(j >= Weight[i]) MethodTable[j] += MethodTable[j - Weight[i]];
//    for(int i = 1; i <= nCapacity; i++)
//        printf("%2d%c", MethodTable[i], i == nCapacity ? '\n' : ' ');
//
//    int nRet = MethodTable[nCapacity];
//    delete[] MethodTable;
//    return nRet;
//}
//int main()
//{
//     int Weight[] = {1,1,1,1,1,1};
//    int Weight[] = {1,2,3,4,5,6,7,8,9,10};
//    int nCapacity = 20;
//
//    cout << "AllCount:" << Package01_FullOfPakage(Weight,sizeof(Weight)/sizeof(int),nCapacity) << endl;
//    cout << "AllCount:" << Package01_FullOfPakage_Compress(Weight,sizeof(Weight)/sizeof(int),nCapacity) << endl;
//    return 0;
//}

// 第三类：多重背包
/**
* 题目表述 :有N种物品和一个容量为V的背包
* 第i件物品最多有n[i]件可用，每件费用是c[i]，价值是w[i]。
* 求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。*/
// 特点：第i种物品最多有n[i]件可用，每件费用是c[i]，价值是w[i]。
// 状态方程：f[i][v] = max{f[i-1][v-k*c[i]]+k*w[i]|0 <= k <= n[i]}（二维）（复杂度：T >= O(V*Σn[i])）
// 转化为01背包求解：把第i种物品换成n[i]件01背包中的物品，则得到了物品数为Σn[i]的01背包问题，直接求解，复杂度仍然是O(V*Σn[i])。
// 优化方向 ： 二进制 | 单调队列

// 01背包
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//using namespace std;
//const int maxn = 1100;
//
//int main()
//{
//    int n, m, dp[maxn], v[maxn], c[maxn];
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//            scanf("%d %d",&v[i], &c[i]);
//        memset(dp, 0, sizeof(dp)); // 背包不一定装满
//        for(int i = 1; i <= n; i ++)
//            for(int j = m; j >= v[i]; j --)
//                dp[j] = max(dp[j], dp[j - v[i]] + c[i]);
//        int maxi = 0;
//        for(int i = 0; i <= m; i ++)
//        {
//            maxi = max(maxi, dp[i]);
//            printf("sss i = %d , dp[%d] = %d\n", i, i, dp[i]);
//        }
//        printf("%d\n", maxi);
//
//    }
//    return 0;
//}

//3 10
//3 6
//3 6
//5 9

// 完全背包
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
const int maxn = 1100;

int main()
{
    int n, m, dp[maxn], v[maxn], c[maxn];
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i ++)
            scanf("%d %d",&v[i], &c[i]);
        memset(dp, 0, sizeof(dp)); // 背包不一定装满
        for(int i = 1; i <= n; i ++)
            for(int j = v[i]; j <= m; j ++)
                dp[j] = max(dp[j], dp[j - v[i]] + c[i]);
        int maxi = 0;
        for(int i = 0; i <= m; i ++)
        {
            maxi = max(maxi, dp[i]);
            printf("sss i = %d , dp[%d] = %d\n", i, i, dp[i]);
        }
        printf("%d\n", maxi);

    }
    return 0;
}

