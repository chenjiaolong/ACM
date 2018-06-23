#include <mutex>
#include <vector>
#include <thread>
#include <future>
#include <cstdlib>
#include <iostream>

#define COUNT 4

using namespace std;

int add( vector <int > *arr, int start, int count)
{
    static mutex m; // ֻ���ʼ��һ��
    int sum(0); // ������
    for(int i = 0; i < count; i ++)
        sum += (*arr)[start + i]; // ʵ���ۼ�
    // ��ʾ������룬����������࣬����
    lock_guard<mutex> lckg(m); // ����
    cout << "thread = " << this_thread :: get_id()
         << ", count = " << count
         << ", sum = " << sum << endl; // ��ӡ���
    return sum;
}

int main()
{
    vector<int >data(COUNT); // ���飬100��
    for(int i = 0; i < COUNT; i ++)
        data[i] = i % 1000; // 0-999
    // future<vector<string > >
    vector<future<int > > result; // �������
    int cpus = thread :: hardware_concurrency(); // CPU���ĵĸ���
    for(int i = 0; i < cpus * 2; i ++)
    {
        // 1000 10 = 100
        // 1000 9 = 1000 - 111 * 8
        int batch_each = COUNT / (cpus* 2);
        if(i == cpus* 2 - 1) batch_each = COUNT - COUNT / (cpus * 2) * i; // ���һ���̳߳е����
        // ����ѹ����
        result.push_back(async(add, &data, i * batch_each, batch_each));
        // async ���ؽ��
    }

    // ����
    int lastresult(0);
    for(int i = 0; i < cpus * 2; i ++)
        lastresult += result[i].get(); // ���ܽ��
    cout << "lastresult = " << lastresult << endl;
    return 0;
}
