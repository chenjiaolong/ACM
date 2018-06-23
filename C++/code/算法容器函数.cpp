#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std :: placeholders;

struct nodex
{
    int get(int data)
    {
        return data & 1;
    }
};

template<typename T>
bool getT(T data)
{
    return data & 1;
}

int get(int data)
{
    return data & 1;
}
struct node
{
    bool operator()(int num)
    {
        return num & 1;
    }
};


int main()
{
    vector<int >v{1, 2, 3, 4, 5, 6, 7, 8, 9, 11}; // ´´½¨ÈİÆ÷
    // int num = count_if(v.begin(), v.end(), [](int data) -> bool { return !(data & 1); });
    // int num = count_if(v.begin(), v.end(), node());
    // node p;
    // int num = count_if(v.begin(), v.end(), p);
    //! int num = count_if(v.begin(), v.end(), get);

    //! int num = count_if(v.begin(), v.end(), &nodex :: get);
    // nodex px;
    // auto fun = bind(&nodex :: get, &px, _1);
    // int num = count_if(v.begin(), v.end(), fun);
    int num = count_if(v.begin(), v.end(), getT<int>);
    cout << num << endl;

    return 0;
}
