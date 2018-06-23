#include <iostream>

class die
{
public:
	virtual void go1()
	{
		std :: cout << "爹走来了" << std :: endl;
	}
	virtual void go2()
	{
		std :: cout << "爹跑来了" << std :: endl;
	}
	virtual void go3()
	{
		std :: cout << "爹飞来了" << std :: endl;
	}
};
class er: public die
{
public:
	void go1()
	{
		std :: cout << "儿走来了" << std :: endl;
	}
	void go2()
	{
		std :: cout << "儿跑来了" << std :: endl;
	}
	void go3()
	{
		std :: cout << "儿飞来了" << std :: endl;
	}
	void go4()
	{
		std :: cout << "儿爬来了" << std :: endl;
	}
};

int main()
{
	std :: cout << sizeof(die) << std :: endl;
	die *p = new er;
	std :: cout << sizeof(*p) << std :: endl; // 内容
	std :: cout << (void *)p << std :: endl; // 对象地址
	std :: cout << *((int *)p) << std :: endl; // 虚函数表的地址，当做整数
	std :: cout << (void *)( *( (int *)p ) ) << std :: endl; // 虚函数表的地址
	std :: cout << (void *)(  *( (int *)*( (int *)p ) + 0)  ) << std :: endl; // 第一个元素地址
	std :: cout << (void *)(  *( (int *)*( (int *)p ) + 1)  ) << std :: endl;
	std :: cout << (void *)(  *( (int *)*( (int *)p ) + 2)  ) << std :: endl;

	typedef void (*pf)();
	pf pfun[3]; // 函数指针数组
	for(int i = 0; i < 3; i ++)
	{
		pfun[i] = (pf)(void *)(  *( (int *)*( (int *)p ) + i)  );
		pfun[i]();
	}

	return 0;
}
