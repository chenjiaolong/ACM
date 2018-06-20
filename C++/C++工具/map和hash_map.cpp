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
  *\brief 演示hash_map键值更改造成的问题
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
        std::cout<<it->first<<"\t"<<it->second->score<<std::endl;//正常操作
    }
    for(hmIter it=hMap.begin(); it!=hMap.end(); ++it)
    {
        Unit *unit = it->second;
        // hMap.erase(it++);
        delete unit; //delete释放节点内存，但是hMap没有除去,造成hMap内部错乱，有可能宕机
    }
    hmIter it = hMap.begin();
    strncpy(it->first,"cc",32);//强行更改
    for(hmIter it=hMap.begin(); it!=hMap.end(); ++it)
    {
        std::cout<<it->first<<"\t"<<it->second->score<<std::endl;//死循环，原因参加上面++操作说明

        /*operator++ 操作是从_M_cur开始，优先_M_cur->_M_next，为空时遍历vector直至找到一个_M_cur不为空的节点，遍历vector 时需要取它对应的桶位置(参砍上面hash_map取值过程)，_M_bkt_num_key(key)中key的值是修改后的值，假如你改的键值，通过 此函数得到的桶位置在你当前元素之前，这样就造成了死循环.

        */
    }
    return 0;
}
