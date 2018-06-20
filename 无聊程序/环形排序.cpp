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
    char Cycle[9] = {0}; //Cycle[0]��Cycle[7]���ڱ���8������Cycle[8]Ϊ�հ���
    int CurNode = 9, Temp;
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 8; i ++) //�����������
    {
        Cycle[i] = (rand()%8)+1;
        if(CurNode == 9 && Cycle[i] == 1) CurNode = i;//��¼����1��λ��4
        for(int j = 0; j < i; j ++)
        {
            if(Cycle[i] == Cycle[j])
            {
                i--;
                break;
            }
        }
    }
    printf("ԭʼ״̬:\n");
    Graph(Cycle);
    printf("��ʼ�ƶ�:\n");
    for(int i = 2; i<=8; i++) //��һ��Ҫ�ҵ���
    {
        for(int j=0; j<8; j++) //ɨ������
        {
            if(Cycle[j] == i)
            {
                Temp = (CurNode + 1) % 8;
                if(i!=Cycle[Temp])//���λ����ȷ�Ͳ�������
                {
                    Cycle[8] = i;//����������
                    Cycle[j] = 0;
                    Graph(Cycle);
                    if(Temp!=j)
                    {
                        if(Temp>j) j+=8;
                        for(int k=j; k>Temp; k--)
                            Cycle[k%8]=Cycle[(k-1)%8];//˳ʱ����ת
                        Cycle[Temp]=0;
                        Graph(Cycle);
                    }
                    Cycle[Temp]=Cycle[8];//���������Ƴ�
                    Cycle[8]=0;
                    Graph(Cycle);
                }
                CurNode=Temp;//��¼��ǰλ��
                break;
            }
        }
    }
    printf("�ƶ����!\n");
    system("pause");
    return 0;
}
