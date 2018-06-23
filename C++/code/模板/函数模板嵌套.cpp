#include <list>
#include <vector>
#include <iostream>

using namespace std;

template<typename T1, typename T2>
void showall(vector<T1> v, list<T2> l)
{
    for(auto i : v) cout << i << endl;
    for(auto i : l) cout << i << endl;
}


int main()
{
    vector<int > myint1{1, 2, 3, 4, 5};
    vector<char > mych1{'A', 'B', 'C', 'D', 'E'};

    list<int > myint2{1, 2, 3, 4, 5};
    list<char > mych2{'A', 'B', 'C', 'D', 'E'};
    showall(myint1, mych2);
    cout << "--------" << endl;
    showall(mych1, myint2);
    return 0;
}
