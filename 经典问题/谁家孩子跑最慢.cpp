#include<stdio.h>
int score[4][4];
int main()
{
    int i,j,k,who;
    score[1][1] = 7; /*����֪�������г�ʼ����score[1]:�ż��������ӵĵ÷�*/
    score[2][1] = 8; /*score[2]:�����������ӵĵ÷�*/
    score[3][1] = 9; /*score[3]:����������ӵĵ÷�*/
    for(i = 4; i < 6; i++) /*i:�żҺ�����4��6�ֶο��ܵķ���*/
        for(j = 4; j < 7; j++) /*j:���Һ�����4��6�ֶο��ܵķ���*/
            for(k = 4; i != j && k < 7; k++) /*k:��Һ�����4��6�ֶο��ܵķ���*/
                if(k != i && k != j && 15 - i - score[1][1] != 15 - j - score[2][1] /*�������ܲ���*/
                        && 15 - i -score[1][1] != 15 - k - score[3][1]
                        && 15 - j -score[2][1] != 15 - k - score[3][1])
                {
                    score[1][2] = i;
                    score[1][3] = 15 - i - 7; /*�����������Ľ����������*/
                    score[2][2] = j;
                    score[2][3] = 15 - j - 8;
                    score[3][2] = k;
                    score[3][3] = 15 - k - 9;
                }
    for(who = 0,i = 1; i <= 3; i++,printf("\n"))
        for(j = 1; j <= 3; j++)
        {
            printf("%d ",score[i][j]); /*������Һ��ӵĵ÷����*/
            if(score[i][j] == 1)who = i; /*��¼���һ���ļ�ͥ���*/
        }
    if(who == 1) /*�������жϵĽ��*/
        printf("The last one arrived to end is a child from family Zhang.\n");
    else if(who == 2)
        printf("The last one arrived to end is a child from family Wang.\n");
    else printf("The last one arrived to end is a child from family Li.\n");
    return 0;
}
