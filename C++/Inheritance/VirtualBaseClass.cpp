#include<string>
#include<iostream>
using namespace std;
class Person
{
public :
    Person(string name, char sex, int age)
    {
        this -> name = name;
        this -> sex = sex;
        this -> age = age;
    }
protected :
    string name;
    char sex;
    int age;
};
class Teacher : virtual public Person
{
public :
    Teacher(string name, char sex, int age, string title) : Person(name, sex, age)
    {
        this -> title = title;
    }
protected :
    string title;
};
class Student : virtual public Person
{
public :
    Student(string name, char sex, int age, float score) : Person(name, sex, age), score(score) { }
protected :
    float score;
};
class Graduate : public Teacher, Student
{
public :
    Graduate(string name, char sex, int age, string title, float score, float wage) :
        Person(name, sex, age), Teacher(name, sex, age, title), Student(name, sex, age, score),wage(wage) { }
    void show()
    {
        cout << "name : " << Teacher :: name << endl;
        cout << "age : " << age << endl;
        cout << "sex : " << sex << endl;
        cout << "score : " << score << endl;
        cout << "title : " << title << endl;
        cout << "wages : " << wage << endl;
    }
protected :
    float wage;
};
int main()
{
    Graduate graduate("Wang - Li", 'f', 24, "assistant", 89.5, 1234.5);
    graduate.show();
    return 0;
}

