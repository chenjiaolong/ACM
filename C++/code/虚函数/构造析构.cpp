#include <iostream>

// 虚函数表，调试，断电，指针的自动变量
// 任何一个类，如果有一个或者多个虚函数，内部隐藏一个指针，指向虚函数表
// 构造函数不可以是虚函数，如果是虚函数，子类对象中的父类拷贝无法初始化。
// 继承的本质就是子类中包含父类对象
// 使用多态，析构函数必须为虚函数，造成内存泄漏
// 构造，父类 -> 子类，构造为虚，父类无法构造
// 析构，子类 -> 父类，父类指针，析构为虚，调用子类的析构，自动调用父类的析构
// 父类指针，析构不为虚，父类的内存，子类的内存无法释放
class myclass
{
public:
	char *p;
    myclass()
    {
    	p = new char[1024 * 1024 * 100];
    }
    virtual ~myclass()
    {
    	delete []p;
    }
	virtual void go()
	{
		std :: cout << "myclass" << std :: endl;
	}
};
class classX : public myclass
{
public:
	int *p;
	classX()
	{
		p = new int[1024 * 1024 * 100];
	}
	~classX()
	{
		delete []p;
	}
	void go()
	{
		std :: cout << "classX" << std :: endl;
	}
};
class classY : public myclass
{
	void go()
	{
		std :: cout << "classY" << std :: endl;
	}
};

int main()
{
    std :: cout << sizeof(myclass) << std :: endl;
	myclass *p;
	p = new classX;
	p -> go();

	p = new classY;
	p -> go();

    p = new classX;

    std :: cin.get();

    delete p;

    std :: cout << "sss" << std :: endl;

	return 0;
}
