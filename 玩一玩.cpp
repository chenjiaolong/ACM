#include<iostream>
#include<string>
#include<algorithm>
#include<list>
using namespace std;
class worker
{
private:
    string name;
    int age;
    double salary;
public:
    worker() {} //����һ���޲εĹ��캯��
    worker(string _name,int _age,double _salary):name(_name),age(_age),salary(_salary) {}//����һ���вεĹ��캯�����ò����ĳ�ʼ��������ݳ�Ա�ĳ�ʼ��
//    worker(string Name,int Age,double wage)//ע�͵��ò����б��ʼ���Ĺ��캯������������
//    {
//        this->name=Name;//�ȼ���name = Name
//        this->age=Age;
//        this->salary=wage;
//    }
    void setData(string Name,int Age,double wage)
    {
        this->name=Name;//�ȼ���name = Name
        this->age=Age;
        this->salary=wage;
    }
    string getName() const
    {
        return name;
    }
    int getAge()const
    {
        return age;
    }
    double getSalary()const
    {
        return salary;
    }
    worker(const worker &w)
    {
        name=w.getName();
        age=w.getAge();
        salary=w.getSalary();
    }
    void display()
    {
        cout<<"������"<<name<<" ���䣺"<<age<<" нˮ��"<<salary<<endl;
    }
    bool operator<(const worker & kk)
    {
        return this->age < kk.getAge();
    }
};
int main()
{
    worker w1("ëë��",25,1500),w2("��ter",24,3000),w3("LPF",30,4500);
    list<worker> L1,L2;
    list<worker> ::iterator p;
    L1.push_back(w1);
    L1.push_back(w2);
    L1.push_back(w3);
    worker wo1("Drizzle",33,3300),wo2("Dijkstra",34,3400),wo3("Bellman_ford",35,3500);
    L2.push_back(wo1);
    L2.push_back(wo2);
    L2.push_back(wo3);
    for(p=L1.begin(); p!=L1.end(); p++)
    {
        worker w(*p);
        w.display();
    }
    cout<<endl;
    L1.sort();
    L2.sort();
    L1.merge(L2);//��L2�ϲ���L1��Ϊʲô���ԣ���ô�ģ�
    for(p=L1.begin(); p!=L1.end(); p++)
    {
        worker w(*p);
        w.display();
    }
}

//#include<stdio.h>
//int fac(int n)
//{
//    int static cow;
//    if(n==1||n==2||n==3)
//        cow=1;
//    else
//        cow=fac(n-1)+fac(n-3);
//    return cow;
//}
//int main()
//{
//    int N;
//    while(~scanf("%d",&N)&&N)
//        printf("%d",fac(N));
//    return 0;
//}


