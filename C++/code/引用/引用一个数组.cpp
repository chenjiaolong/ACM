#include <iostream>

using namespace std;

int main()
{
    // ջ��
    cout << "---------" <<endl;
    int a[5] {1, 2, 3, 4, 5}; // һά����
    int *pa[5] {a, a + 1, a + 2, a + 3, a + 4}; // ָ������
    int (&ra)[5](a); // ����һ������
    for(auto & i : ra) cout << (i += 1) << endl;
    for(auto i : ra) cout << i << endl;
    int(* (&rpa)[5])(pa); // ����һ��ָ������
    for(auto i : rpa) cout << *i << endl;

    // ����
    cout << "---------" <<endl;
    int *p1(new int[5] {1, 2, 3, 4, 5}); // ����һά����
    // int *(*pp)(nullptr);// ��ʼ��VS2013����һ��ָ��
    int *(*pp)(new int *[5] {p1, p1 + 1, p1 + 2, p1 + 3, p1 + 4});
    int(* (&rp) )(p1);
    int(** (&rpp) )(pp);
    for(int i = 0; i < 5; i ++) cout << rp[i] << endl;
    for(int i = 0; i < 5; i ++) cout << *rpp[i] << endl;

    cout << "---------" <<endl;
    int b[2][3] {1, 2, 3, 4, 5, 6}; // ��ά����
    // ��ά���飬ÿһ��Ԫ����һ��ָ��
    int *pb[2][3] {&b[0][0], &b[0][0] + 1,
                   &b[0][0] + 2, &b[0][0] + 3,
                   &b[0][0] + 4, &b[0][0] + 5
                  };
    int (&rb)[2][3](b); // ���ö�ά����
    int *( (&rpb)[2][3] )(pb); // ���ö�άָ������
    for(int i = 0; i < 2; i ++)
    {
        for(int j = 0; j < 3; j ++)
            cout << rb[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < 2; i ++)
    {
        for(int j = 0; j < 3; j ++)
            cout << *(rpb[i][j]) << " ";
        cout << endl;
    }

    // ָ�������ָ�룬{}����
    cout << "---------" << endl;
    int (*p2)[4] {new int[3][4] {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}}; // ���϶�ά����

    int (* (&rp2) )[4](p2); // ����һ����ָ��
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 4; j ++)
            cout << rp2[i][j] << " ";
        cout << endl;
    }

    cout << "---------"<< endl;
    // ���Ͽ��ٶ�άָ������
    int *(*pp2)[3] { new int *[2][3]{
            { &b[0][0], &b[0][0] + 1, &b[0][0] + 2},
            { &b[0][0] + 3, &b[0][0] + 4, &b[0][0] + 5}
        }
    };
    int (* (*&rpp2)[3])(pp2); // ���ö�ά��ָ������
    for(int i = 0; i < 2; i ++)
    {
        for(int j = 0; j < 3; j ++)
            cout << *rpp2[i][j] << " ";
        cout << endl;
    }
    return 0;
}
