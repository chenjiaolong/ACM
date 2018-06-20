#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
int LargestRectangleArea(vector<int> &height)
{
    height.push_back(0);// ȷ��ԭ���� height �����һλ�ܹ��ó�����

    stack<int> s;
    int answer = 0;
    int temp; // ��ʱ����
    for(int i = 0; i < (int)height.size(); )
    {
        if(s.empty() || height[i] > height[s.top()])
        {
            s.push(i);
            i++;
        }
        else
        {
            temp = s.top();
            s.pop();
            answer = max(answer, height[temp] * (s.empty() ? i : i - s.top() - 1 ));
        }
    }
    return answer;
}
int main()
{
    vector<int> height;
    height.push_back(2);
    height.push_back(7);
    height.push_back(5);
    height.push_back(6);
    height.push_back(4);
    int area = LargestRectangleArea(height);
    printf("%d\n", area);
    return 0;
}
//����
// 2, 1, 5, 6, 2, 3
// 10

