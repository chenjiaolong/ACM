#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int key = 7;
    vector<int >iv(10);
    for(int i = 0; i < 10; i ++) iv[i] = i;
    vector<int > :: iterator it, head = iv.begin(), tail = iv.end();
    it = find(head, tail, key);
    if(it != tail) cout << "Vector contains the value " << key << endl;
    else cout << "Vector does NOT contain the value " << key << endl;
    return 0;
}
