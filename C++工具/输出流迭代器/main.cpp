#include<vector>
#include<iostream>
#include<iterator>
#include<algorithm>
#include"zyrandom.h"

using namespace std;

const int size = 8;
const int lower_bound = 10;
const int upper_bound = 99;

void Display(vector<int > &v, const char *s)
{
    cout << endl << s << endl;
    vector<int > :: iterator head = v.begin(), tail = v.end();
    ostream_iterator <int > oit(cout, ";");
    copy(head, tail, oit);
    cout << endl;
}

int main()
{
    vector <int > a(size);
    for(int i = 0; i < size; i ++) a[i] = GenerateRandomNumber(10, 99);
    Display(a, "Array generated: ");
    vector<int > :: iterator head = a.begin(), tail = a.end();
    sort(head, tail);
    Display(a, "Array sorted: ");
    reverse(head, tail);
    Display(a, "Array reversed: ");
    return 0;
}
