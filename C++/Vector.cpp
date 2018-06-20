#include <assert.h>
#include <iostream>

using namespace std;

using ull = unsigned long long;
template <typename T>
class Vector
{
private :
    #define Step_Size 64
public :
    // 构造函数
    Vector() : arr(0), cnt(0), alloc(0) {  }
    Vector(ull x, const T& t) : Vector()
    {
        for(int i = 0; i < x; i ++) push_back(t);
    }
    // 拷贝构造
    Vector(const Vector<T>& src) : Vector()
    {
        *this = src;
    }
    // 赋值重载
    Vector<T>& operator = (Vector<T>& src)
    {
        if(this == &src) return *this;
        clear();
        cnt = src.size();
        alloc = src.length();
        arr = new T[alloc];
        for(ull i = 0; i < cnt; i ++)
            arr[i] = src[i];
        return *this;
    }
    // 析构
    ~Vector() { clear(); }
    // 获取元素项
    T& operator[](ull index)
    {
        // 断言
        assert(index < cnt);
        return arr[index];
    }
    // 元素量
    ull size() { return cnt; }
    // 已经分配的长度
    ull length() { return alloc; }
    bool empty() { return cnt == 0; }
    void clear()
    {
        // 回收
        deallocator(arr);
        arr = 0;
        cnt = alloc = 0;
    }
    void push_back(const T& t)
    {
        insert(cnt,t);
    }
    void push_front(const T& t)
    {
        insert(0, t);
    }
    void insert(int x, const T& t)
    {
        if(cnt == alloc)
        {
            T* src = arr;
            alloc += Step_Size;
            arr = allocator(alloc);
            for(ull i = 0; i < cnt; i ++)
                arr[i] = src[i];
            deallocator(src);
        }
        for(int i = (int)cnt ++; i > x; i --)
            arr[i] = arr[i - 1];
        arr[x] = t;
    }
    void erase(ull x)
    {
        if(x < cnt)
        {
            --cnt;
            for(ull i = x; i < cnt; i ++)
                arr[i] = arr[i + 1];
        }
    }
private :
    T* allocator(ull size)
    {
        return new T[size];
    }
    void deallocator(T* arr)
    {
        if(arr) delete[] arr;
    }
private :
    T* arr;
    ull cnt;
    ull alloc;
};
void Traversal(Vector<int>& v)
{
    for(ull i = 0; i < v.size(); i ++)
        cout << v[i] << " ";
    cout << endl << "size = " << v.size() << ", allocator size = " << v.length() << endl;
}
int main()
{
    Vector<int> v1;
    Vector<int> v2(1, 10);
    Traversal(v2);
    v2.push_front(1);
    Traversal(v2);
    v2.erase(0);
    Traversal(v2);
    v1.push_back(2);
    v1.push_front(1);
    Traversal(v1);
    v1.insert(1, 3);
    Traversal(v1);

    v2 = v1;
    v2.insert(0, 0);
    v2.insert(1, -1);
    Traversal(v2);
    return 0;
}
