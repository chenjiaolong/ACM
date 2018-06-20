// nsu1768: DPË¼Ïë
//#include<bits/stdc++.h>
//int main()
//{
//    int array[35] = {0,1,2,4};
//    for(int i = 4; i <= 30; i++)
//        array[i] = array[i - 1] + array[i -2] + array[i -3];
//    int n;
//    while(scanf("%d",&n) == 1 && n)
//        printf("%d\n",array[n]);
//    return 0;
//}

//nsu1768: µİ¹é
#include<bits/stdc++.h>
int Domino(int n)
{
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    else if(n == 3)
        return 4;
    return Domino(n - 1) + Domino(n - 2) + Domino(n - 3);
}
int main()
{
    int n;
    while(scanf("%d",&n) == 1 &&n)
        printf("%d\n",Domino(n));
    return 0;
}
