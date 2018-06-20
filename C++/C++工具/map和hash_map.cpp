//#include<map>
//#include<string>
//#include<iostream>
//
//using namespace std;
//
//struct person
//{
//    string name;
//    int age;
//
//    person(string name, int age)
//    {
//        this->name =  name;
//        this->age = age;
//    }
//
//    bool operator < (const person& p) const
//    {
//        return this->age < p.age;
//    }
//};
//
//map<person,int> m;
//int main()
//{
//    person p1("Tom1",20);
//    person p2("Tom2",22);
//    person p3("Tom3",22);
//    person p4("Tom4",23);
//    person p5("Tom5",24);
//    m.insert(make_pair(p3, 100));
//    m.insert(make_pair(p4, 100));
//    m.insert(make_pair(p5, 100));
//    m.insert(make_pair(p1, 100));
//    m.insert(make_pair(p2, 100));
//
//    for(map<person, int>::iterator iter = m.begin(); iter != m.end(); iter++)
//    {
//        cout<<iter->first.name<<"\t"<<iter->first.age<<endl;
//    }
//
//    return 0;
//}

/**
  *\author peakflys
  *\brief ��ʾhash_map��ֵ������ɵ�����
 */
#include <iostream>
#include<string.h>
#include <ext/hash_map>
struct Unit
{
    char name[32];
    unsigned int score;
    Unit(const char *_name,const unsigned int _score) : score(_score)
    {
        strncpy(name,_name,32);
    }
};
int main()
{
    typedef __gnu_cxx::hash_map<char*,Unit*> uHMap;
    typedef uHMap::value_type hmType;
    typedef uHMap::iterator hmIter;
    uHMap hMap;
    Unit *unit1 = new Unit("peak",100);
    Unit *unit2 = new Unit("Joey",20);
    Unit *unit3 = new Unit("Rachel",40);
    Unit *unit4 = new Unit("Monica",90);
    hMap[unit1->name] = unit1;
    hMap[unit2->name] = unit2;
    hMap.insert(hmType(unit3->name,unit3));
    hMap.insert(hmType(unit4->name,unit4));
    for(hmIter it=hMap.begin(); it!=hMap.end(); ++it)
    {
        std::cout<<it->first<<"\t"<<it->second->score<<std::endl;//��������
    }
    for(hmIter it=hMap.begin(); it!=hMap.end(); ++it)
    {
        Unit *unit = it->second;
        // hMap.erase(it++);
        delete unit; //delete�ͷŽڵ��ڴ棬����hMapû�г�ȥ,���hMap�ڲ����ң��п���崻�
    }
    hmIter it = hMap.begin();
    strncpy(it->first,"cc",32);//ǿ�и���
    for(hmIter it=hMap.begin(); it!=hMap.end(); ++it)
    {
        std::cout<<it->first<<"\t"<<it->second->score<<std::endl;//��ѭ����ԭ��μ�����++����˵��

        /*operator++ �����Ǵ�_M_cur��ʼ������_M_cur->_M_next��Ϊ��ʱ����vectorֱ���ҵ�һ��_M_cur��Ϊ�յĽڵ㣬����vector ʱ��Ҫȡ����Ӧ��Ͱλ��(�ο�����hash_mapȡֵ����)��_M_bkt_num_key(key)��key��ֵ���޸ĺ��ֵ��������ĵļ�ֵ��ͨ�� �˺����õ���Ͱλ�����㵱ǰԪ��֮ǰ���������������ѭ��.

        */
    }
    return 0;
}
