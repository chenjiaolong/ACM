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
    static mutex m; // 只会初始化一次
    int sum(0); // 保存结果
    for(int i = 0; i < count; i ++)
        sum += (*arr)[start + i]; // 实现累加
    // 显示结果必须，仅仅计算多余，加锁
    lock_guard<mutex> lckg(m); // 锁定
    cout << "thread = " << this_thread :: get_id()
         << ", count = " << count
         << ", sum = " << sum << endl; // 打印结果
    return sum;
}

int main()
{
    vector<int >data(COUNT); // 数组，100万
    for(int i = 0; i < COUNT; i ++)
        data[i] = i % 1000; // 0-999
    // future<vector<string > >
    vector<future<int > > result; // 结果数组
    int cpus = thread :: hardware_concurrency(); // CPU核心的个数
    for(int i = 0; i < cpus * 2; i ++)
    {
        // 1000 10 = 100
        // 1000 9 = 1000 - 111 * 8
        int batch_each = COUNT / (cpus* 2);
        if(i == cpus* 2 - 1) batch_each = COUNT - COUNT / (cpus * 2) * i; // 最后一个线程承担多点
        // 不断压入结果
        result.push_back(async(add, &data, i * batch_each, batch_each));
        // async 返回结果
    }

    // 汇总
    int lastresult(0);
    for(int i = 0; i < cpus * 2; i ++)
        lastresult += result[i].get(); // 汇总结果
    cout << "lastresult = " << lastresult << endl;
    return 0;
}
