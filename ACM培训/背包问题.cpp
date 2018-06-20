// ��һ�ࣺ 01 ����
/**
* ��Ŀ���� :��N����Ʒ��һ������ΪV�ı�����
* ��i����Ʒ�ķ�����c[i]����ֵ��w[i]��
* ��⽫��Щ��Ʒװ�뱳����ʹ��ֵ�ܺ����*/
// �ص��ǣ�ÿ����Ʒ����һ��������ѡ��Ż򲻷�
// f[i][v]��ʾǰi����Ʒǡ����һ������Ϊv�ı������Ի�õ�����ֵ
// ״̬���̣�f[i][v] = max{f[i-1][v], f[i-1][v-c[i]] + w[i]} ����ά�������Ӷȣ�T = O(N*V), S = O(N*V)��
// f[v]�������״̬f[i-1][v-c[i]]��ֵ
// ��֤��i��ѭ���е�״̬f[v]����״̬f[v-c]���ƶ���
// ״̬���̣�f[v] = max{f[v], f[v-c[i]] + w[i]]}��һά�������Ӷȣ�T = O(N*V), S = O(V)��
// ��ʼ������
// (1)Ҫ��ǡ��װ����������ô�ڳ�ʼ��ʱ����f[0]Ϊ0����f[1..V]����Ϊ-��;
// (2)������һ��װ��������ֻϣ���۸����󣬳�ʼ��ʱӦ�ý�f[0..V]ȫ����Ϊ0��
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
//Object * array; //�����洢������Ϣ������
//int num; //����ĸ���
//int container; //����������
//int ** dynamic_table; //�洢��̬�滮��
//bool * used_table; //�洢��Ʒ��ʹ�����
////ouput the table of dynamic programming, it's for detection
//void print_dynamic_table()
//{
//    printf("��̬�滮��������ʾ:\n");
//    /* for(int j=0; j<=container; j++) printf("%d ",j); printf("\n");*/
//    for(int i=1; i<=num; i++)
//    {
//        for(int j=0; j<=container; j++)
//            printf("%d ",dynamic_table[i][j]);
//        printf("\n");
//    }
//}//��ӡ��̬�滮��
//void print_array()
//{
//    for(int i=1; i<=num; i++)
//        printf("��%d����Ʒ��������Ȩ��:%d %d\n",i,array[i].weight,array[i].value);
//}
////��ӡ�������Ʒ���//�������򣬰�rate=value/weight��С������//��̬�滮������������������Կ��Բ�������
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
//    printf("��ʹ�õ���Ʒ������ʾ:\n");
//    for(int i=1; i<=num; i++)
//        if(used_table[i]==1)
//            printf("%d-%d\n", array[i].weight, array[i].value);
//}
////��ӡ��Ʒ��ʹ�����
///* ������ʱʹ��
//void print_used_table(bool * used_table){
//printf("used table as follows:\n");
//for(int i=1; i<=num; i++)
//printf("object %d is %d", i, used_table[i]);
//}*/
//void init_problem()
//{
//    printf("���뱳��������:\n");
//    scanf("%d", &container);
//    printf("������Ʒ�ĸ���:\n");
//    scanf("%d", &num);
//    array=new Object[num+1];
//    printf("������Ʒ�������ͼ�ֵ, ��ʽ�磺4-15\n");
//    for(int i=1; i<=num; i++)
//    {
//        char c;
//        scanf("%d%c%d", &array[i].weight, &c, &array[i].value);
//// array[i].rate=array[i].value/array[i].weight;
//    }
//    print_array();
//}
////�������ʹ��������лز�
//void trace_back()
//{
//    int weight=container;
//    used_table=new bool[num+1];
//    for(int i=1; i<=num; i++) used_table[i]=0;
////initalize the used_table to be non-used
//    for(int j=1; j<num; j++)
//    {
////˵����Ʒj��ʹ��
//        if(dynamic_table[j][weight]!=dynamic_table[j+1][weight])
//        {
//            weight-=array[j].weight;
//            used_table[j]=1;
//        }
//// print_used_table(used_table);
//    }
////����num����Ʒ�Ƿ�ʹ��
//    if(weight>=array[num].weight)
//        used_table[num]=1;
//}
//void dynamic_programming()
//{
//    dynamic_table=new int * [num+1];
//    for(int k=1; k<=num; k++)
//        dynamic_table[k]=new int[container+1];
////dynamic_programming table
////Ϊ��ά��̬�滮������ڴ�
//    for(int m=1; m<num; m++)
//        for(int n=0; n<=container; n++)
//            dynamic_table[m][n]=0;
//    int temp_weight=array[num].weight;
//    for(int i=0; i<=container; i++)
//        dynamic_table[num][i]=i<temp_weight?0:array[num].value;
////��ʼ����̬�滮��
//    for(int j=num-1; j>=1; j--)
//    {
//        temp_weight=array[j].weight;
//        int temp_value=array[j].value;
//        for(int k=0; k<=container; k++)
//            if(k>=temp_weight && dynamic_table[j+1][k] < dynamic_table[j+1][k-temp_weight]+temp_value)
//                dynamic_table[j][k]=dynamic_table[j+1][k-temp_weight]+temp_value;
//            else dynamic_table[j][k]=dynamic_table[j+1][k];
//    }//������̬�滮��
//    print_dynamic_table();//��ӡ��̬�滮��
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

// ��01���������ŷ�������������ʵ��
// ���ŷ�����������ָ��Ʒ�ܼ�ֵ���ķ�������
// ��G[i][j]����F[i][j]�ķ�����������ô���ܽ��Ӧ����G[N][V]
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

// ����hdu 2546
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

// �ڶ��ࣺ��ȫ����
/**
* ��Ŀ���� :��N����Ʒ��һ������ΪV�ı�����ÿ����Ʒ�������޼����á�
* ��i����Ʒ�ķ�����c[i]����ֵ��w[i]��
* ��⽫��Щ��Ʒװ�뱳����ʹ��Щ��Ʒ�ķ����ܺͲ����������������Ҽ�ֵ�ܺ����*/
// �ص㣺ÿ����Ʒ�����޼�
// ״̬���̣�f[i][v] = max{f[i-1][v-k*c[i]]+k*w[i]|0 <= k*c[i] <= v}����ά�������Ӷȣ� ��״̬f[i][v]��ʱ����O(v/c[i])���ܣ�T >= O(NV��(v/c[i]))��
// ״̬���̣�f[i][v] = max{f[i-1][v], f[i][v-c[i]] + w[i]}�����Ӷȣ�T = O(NV)��
// ״̬���̣�f[v] = max{f[v], f[v-cost]+weight}��һά�������Ӷȣ�T = O(NV)��
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

// ����ȫ���������ŷ�������������ʵ��
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

// ��01������������ȫ������װ�������ķ�������������ʵ��
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

// �����ࣺ���ر���
/**
* ��Ŀ���� :��N����Ʒ��һ������ΪV�ı���
* ��i����Ʒ�����n[i]�����ã�ÿ��������c[i]����ֵ��w[i]��
* ��⽫��Щ��Ʒװ�뱳����ʹ��Щ��Ʒ�ķ����ܺͲ����������������Ҽ�ֵ�ܺ����*/
// �ص㣺��i����Ʒ�����n[i]�����ã�ÿ��������c[i]����ֵ��w[i]��
// ״̬���̣�f[i][v] = max{f[i-1][v-k*c[i]]+k*w[i]|0 <= k <= n[i]}����ά�������Ӷȣ�T >= O(V*��n[i])��
// ת��Ϊ01������⣺�ѵ�i����Ʒ����n[i]��01�����е���Ʒ����õ�����Ʒ��Ϊ��n[i]��01�������⣬ֱ����⣬���Ӷ���Ȼ��O(V*��n[i])��
// �Ż����� �� ������ | ��������

// 01����
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
//        memset(dp, 0, sizeof(dp)); // ������һ��װ��
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

// ��ȫ����
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
        memset(dp, 0, sizeof(dp)); // ������һ��װ��
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

