#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef int type;

const int Max_Size = 10;

class Heap
{
private:
    type heap[Max_Size + 10];
    int Size;
public:
    Heap() { Size = 0; }
    void rise(int loc)
    {
        int i = loc, j = loc >> 1;
        type x = heap[loc];
        while(j)
        {
            if(heap[j] > x)
            {
                heap[i] = heap[j];
                i >>= 1;
                j >>= 1;
            }
            else j = 0;
        }
        heap[i] = x;
    }
    void fall(int loc)
    {
        int i = loc, j = loc << 1;
        type x = heap[loc];
        while(j <= Size)
        {
            if(j < Size)
                if(heap[j] > heap[j + 1]) j ++;
            if(x > heap[j])
            {
                heap[i] = heap[j];
                i = j;
                j <<= 1;
            }
            else j = Size + 1;
        }
        heap[i] = x;
    }
    void insert(type data)
    {
        if(Size > Max_Size)
        {
            cout << "No Enough Space!" << endl;
            return ;
        }
        heap[++Size] = data;
        rise(Size);
    }
    void extract()
    {
        if(!Size)
        {
            cout << "No Element Now!" << endl;
            return ;
        }
        heap[1] = heap[Size --];
        if(Size) fall(1);
    }
    void update(int loc, type New)
    {
        if(New < heap[loc])
        {
            heap[loc] = New;
            rise(loc);
        }
        else
        {
            heap[loc] = New;
            fall(loc);
        }
    }
    type minimum() { return heap[1]; }
    bool empty() { return !Size; }
    int size() { return Size; }
};
int main()
{
    Heap T;
    srand(20080427);
    for(int i = 0; i < 10; ++i)
        T.insert(rand() % 9997);
    T.update(5, 1000);
    T.update(1, 10000);
    while(!T.empty())
    {
        cout << setw(8) << T.minimum();
        T.extract();
    }
    cout << endl;
    system("PAUSE");
    return 0;
}
