# const的用法
> 在普通的非const成员函数中，this的类型是一个指向类类型的const指针。可以改变this所指向的值，但不能改变this所保存的地址

> 在const成员函数中，this的类型是一个指向const类类型的const指针。既不可以改变this所指向的对象，也不能改变this所保存的地址。

## 1.用const修饰函数的参数
> 如果参数作为输出用，不论它是什么类型，也不论它采用“指针传递”还是“引用传递”，都不能加const修饰，否则该参数将失去输出功能。***const只能修饰输入参数***

a. 如果输入参数采用“指针传递”， 那么加const修饰可以防止意外地改动该指针，起到保护作用。

> 例如Strcpy函数  
> void Strcpy(const char *src, char *des);  
> 其中src是输入参数，des是输出参数。给src加上const修饰后，如果函数体内的语句试图改动src的内容，编译器将指出错误。

b. 如果输入参数采用的是“值传递”，由于函数将自动产生临时变量用于复制该参数，该输入参数本来就无需保护，所以不要加const修饰。

> 例如不要将函数void func(int x) 写成 void func(const int x)。  
> 同理不要将函数void func(A a) 写成 void func(const A a)。其中A为用户自定义的数据类型。

Tips: 对于非内部数据类型的参数而言，像void func(A a)这样声明的函数注定效率比较低。因为函数体内将产生A类型的临时对象用于复制参数a，而临时对象的构造、复制、析构过程都将消耗时间。

c.为了提高效率，可以将函数声明改为void func(A &a)，因为“引用传递”仅借用一下参数的别名而已，不需要产生临时对象。
> 但是函数void func(A &a)存在在一个缺点：“引用传递”有可能改变参数a，这是我们不期望的。  
> 解决这个问题很容易，加const修饰即可，因此函数最终成为void func(const A &a)。  
> 以此类推，是否应将void func(int x) 写成void func(const int &x),以便提高效率？
> 完全没必要，因为内部数据类型的参数不存在构造，析构的过程，而且复制也非常快，“值传递”和“引用传递”的效率相当。

### summary：
> 对于非内部数据类型的输入参数，应该将“值传递”的方式改为“const引用传递”，目的是提高效率。  
> 对于内部数据类型的输入参数，不要将“值传递”的方式改为“const引用传递”，否则既达不到提高效率的目的，又降低了函数的可读性。

## 2.用const修饰函数的返回值
a. 如果给以“指针传递”方式的函数返回值加const修饰，那么函数返回值（即指针）的内容不能被修改，该返回值只能被赋给加const修改的同类型的指针。
> 例如函数：  
> const char \*func();  
> 如下语句将会出现编译错误：  
> char \*str = func();  
> 正确的用法是：  
> const char \*str=fun();  

b. 如果函数返回值采用“值传递方式”，由于函数会把返回值复制到外部临时的存储单元中，加const修饰没有任何价值。
> 例如函数返回值int func(void) 写成const int func(void)。  
> 同理不要将A func(void)写成const A func(void)。其中A为用户自定义的数据类型。

c. 如果返回值不是内部数据类型，将函数A func(void)写成const A &func(void)的确能提高效率。 但此时千万要小心，一定要搞清楚函数究竟是想返回的一个对象的“拷贝”还是仅返回“别名”就可以了，否则程序会出错。  
函数返回值采用“引用传递”的场合并不多，这种方式一般只出现在类的赋值函数中，目的是为了实现链式表达。
> 例如：

	class A
	{
	public:
		A & operator = (const A &other); // 赋值重载
	};
	A a, b, c; // a, b, c为A的对象

	a = b = c; // 正常的链式赋值
	(a = b) = c; // 不正常的链式赋值，但合法
	如果将赋值重载函数的返回值加const修饰，那么返回值得内容不允许被改动。上例中，语句a = b = c仍然正确，但是语句(a = b) = c则是非法的。

## 3. const成员函数
> 任何不会修改数据成员的函数都应该声明为const类型。如果在编写const成员函数时，不慎修改了数据成员，或者调用了其它非const成员函数，编译器将会指出错误，这无疑会提高程序的健壮性。  

> 以下程序中，类Stack的成员函数GetCount仅用于计数，从逻辑上讲GetCount应当为const函数，编译器将会指出GetCount函数中的错误。

	calss Stack
	{
	public:
		void Push(int elem);
		int Pop(void);
		int GetCount(void) const; // const成员函数
	private:
		int m_num;
		int m_data[100]; 
	};
	int Stack :: GetCount(void ) const
	{
		++ m_num; // 编译错误 企图修改数据成员m_num
		Pop(); // 编译错误，企图调用非const函数
		return m_num;
	}

### 关于const函数的规则：
a. const对象只能访问const成员函数，而非const对象可以访问任意的成员函数，包括const成员函数。  
b. const对象的成员是不可修改的，然而const对象通过指针维护的对象却是可以修改的。  
c. const成员函数不可以修改对象的数据，不管对象是否具有const性质。它在编译时，以是否修改成员数据为依据，进行检查。  
d. 然而加上mutable修饰符的数据成员，对于任何情况下，通过任何手段都可以修改，自然此时的const成员函数是可以修改它的。

补充：
标题:const放在后面有什么意思？
--------------------------------------------------------------------------------
> 一个函数AcGePoint3dstartPoint() const;  
> const放在后面跟前面有区别么   
> ==> 准确的说const是修饰this指向的对象的  
> 譬如，我们定义了
	
	class A
	{
	public:
		f(int);
	};
> 这里f函数其实有两个参数，第一个是A\*const this, 另一个才是int类型的参数  
> 如果我们不想f函数改变参数的值，可以把函数原型改为f(const int),但如果我们不允许f改变this指向的对象呢？因为this是隐含参数，const没法直接修饰它，就加在函数的后面了，表示this的类型是const A \*const this。  
> const修饰\*this是本质，至于说“表示该成员函数不会修改类的数据。否则会编译报错”之类的说法只是一个现象，根源就是因为\*this是const类型的