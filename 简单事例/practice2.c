#include<stdio.h>//��������⺯��
void main()//������
{
    int height;//�û����
    float weight,sweight;//��׼���أ��û����
    printf("�����뱻��ͬѧ����ߣ�����cmΪ��λ��\n");
    scanf("%d",&height);
    do
    {
        printf("�����뱻��ͬѧ�����أ�����kgΪ��λ\n");
        scanf("%f",&weight);
        sweight=(height-100)*0.9;
        if((weight>(sweight*1.1))||(weight<(sweight*0.9)))
            printf("��ͬѧ�������ѳ���򲻴�꣬��ע����ƣ�\n");
        else
            printf("��ϲ��ͬѧ������������������\n");
        printf("�����뱻��ͬѧ����ߣ�����cmΪ��λ��\n");
        scanf("%d",&height);
    }while(height>0);
    /*while(height>0)
    {
        printf("�����뱻��ͬѧ�����أ�����kgΪ��λ\n");
        scanf("%f",&weight);
        sweight=(height-100)*0.9;
        if((weight>(sweight*1.1))||(weight<(sweight*0.9)))
        printf("��ͬѧ�������ѳ���򲻴�꣬��ע����ƣ�\n");
        else
            printf("��ϲ��ͬѧ������������������\n");
        printf("�����뱻��ͬѧ����ߣ�����cmΪ��λ��\n");
        scanf("%d",&height);
    }*/
}
