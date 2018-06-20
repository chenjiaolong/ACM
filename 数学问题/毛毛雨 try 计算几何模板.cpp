// Circle Through Three Points
//#include<math.h>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<iostream>
//#define signals(pos) (fabs(pos) < 1e-6 || pos > 0 ? '+' : '-')
//using namespace std;
//
//int main()
//{
//    double Ax, Ay, Bx, By, Cx, Cy;
//    while(scanf("%lf%lf%lf%lf%lf%lf", &Ax, &Ay, &Bx, &By, &Cx, &Cy) == 6)
//    {
//        double da = - (Ax * Ax + Ay * Ay);
//        double db = - (Bx * Bx + By * By);
//        double dc = - (Cx * Cx + Cy * Cy);
//        double D = (- 1) * Ax * By + (- 1) * Bx * Cy + (- 1) * Cx * Ay - (- 1) * Ax * Cy - (-1) * Bx * Ay - (-1) * Cx * By;
//        double c = ((- 1) * da * By + (- 1) * db * Cy + (- 1) * dc * Ay - (- 1) * da * Cy - (- 1) * db * Ay - (- 1) * dc * By) / D;
//        double d = ((- 1) * Ax * db + (- 1) * Bx * dc + (- 1) * Cx * da - (- 1) * Ax * dc - (- 1) * Bx * da - (- 1) * Cx * db) / D;
//        double e = (Ax * By * dc + Bx * Cy * da + Cx * Ay * db - Ax * Cy * db - Bx * Ay * dc - Cx * By * da) / D;
//        // cout << c << d << e << endl;
//        double h = c / 2;
//        double k = d / 2;
//        double r = sqrtf((c * c + d * d + 4 * e)) / 2;
//        // cout << h << k << r << endl;
//        printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n", signals(h), fabs(h), signals(k), fabs(k), r);
//        printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n\n",signals(c), fabs(c), signals(d), fabs(d), signals(-e), fabs(e));
//    }
//
//    return 0;
//}

// Text Reverse
//#include<stdio.h>
//#include<string.h>
//using namespace std;
//void reverse(char *temp)
//{
//    if(*temp != '\0')
//        reverse(temp + 1);
//    if(*temp != '\0')
//        printf("%c", *temp);
//}
//int main()
//{
//    int T;
//    while(~scanf("%d", &T))
//    {
//        char buffer[10];
//        gets(buffer);
//        char str[1005];
//        while(T--)
//        {
//            gets(str);
//            int len = strlen(str);
//            char temp[1005] = {'\0'};
//            int cur = 0;
//            for(int i = 0; i <= len; i++)
//            {
//                if(str[i] == ' ' || str[i] == '\0')
//                {
//                    temp[cur++] = '\0';
//                    // puts(temp);
//                    reverse(temp);
//                    printf("%c", str[i] == '\0' ? '\n' : ' ');
//                    memset(temp, '\0', sizeof(temp));
//                    cur = 0;
//                }
//                else
//                    temp[cur++] = str[i];
//            }
//        }
//    }
//    return 0;
//}

// ��Ŀ���⣺��֪n�������꣬�������㣬�������㵽���������֮�ͣ���ȷ����λ����������
// �㷨��1.ģ���˻�
//#include <stdio.h>
//#include <time.h>
//#include <math.h>
//#include <stdlib.h>
//#define RANGE 10000
//#define MAXN 110
//#define eps 1e-3
//const double pi=acos(-1.0);
//
//struct Point
//{
//    double x,y;
//} p[MAXN];
//int n;
//
//int SA(int cnt = 3) 		//cntΪִ��ģ���˻�Ĵ�����Ĭ��Ϊ3
//{
//    double step,tmp,ans,theta;
//    double delta=pi/4,ret=1e40,rate=0.83;	//��������
//    int i;
//    Point pt,cur;
//    srand(time(NULL));
//    while (cnt--)
//    {
//        step = rate*RANGE;	//��ʼ�¶�
//        cur.x = (rand()%RANGE+1.0)/RANGE;
//        cur.y = (rand()%RANGE+1.0)/RANGE;
//        for (ans = i = 0; i < n; ++i)
//            ans += sqrt( (cur.x-p[i].x)*(cur.x-p[i].x) + (cur.y-p[i].y)*(cur.y-p[i].y) );
//
//        while ( step>eps )
//        {
//            for (theta=0; theta<2*pi+eps; theta+=delta)  	//�ڸõ㸽������8����
//            {
//                pt.x = cur.x + step*cos(theta);
//                pt.y = cur.y + step*sin(theta);
//                for (tmp=i=0; i<n; ++i)
//                    tmp += sqrt( (pt.x-p[i].x)*(pt.x-p[i].x) + (pt.y-p[i].y)*(pt.y-p[i].y) );
//                if (tmp < ans)
//                {
//                    ans = tmp;
//                    cur = pt;
//                }
//            }
//            step *= rate;
//        }
//        if (ans < ret)	ret = ans;
//    }
//    return ret + 0.5;
//}
//
//int main()
//{
//    scanf("%d", &n);
//    for (int i=0; i<n; ++i)
//        scanf("%lf%lf", &p[i].x, &p[i].y);
//    printf("%d\n", SA());
//    return 0;
//}

// �㷨��2.ţ�ٵ�����
#include <stdio.h>
#include <math.h>
#define MAXN 110
#define eps 1e-3

struct Point
{
    double x,y;
} p[MAXN];
int n;
double dist[MAXN];

//��f(x,y)=Sigma( sqrt((x-xi)^2 + (y-yi)^2) ),����Ҫ��f(x,y)����Сֵ��
//�˺�����͹�ġ�����֤��СֵΨһ���ҵ�p0,p1..pn-1����һ������ʱ����Сֵ��Ψһ��
//����ֻ�����f'x=f'y=0�ĵ㼴�ɡ���ţ�ٵ�������˶�Ԫ�����顣

//���disti=sqrt( (x-xi)^2 + (y-yi)^2 ),�󵼵ã�
//fx=Sigma( (x-xi)/disti) );			fy=Sigma( (y-yi)/disti );
//fxx=Sigma( (y-yi)^2/(dist^3) );		fyy=Sigma( (x-xi)^2/(dist^3) );
//fxy = -Sigma( (x-xi)*(y-yi)/(disti^3) );

//������ʽΪ��
//x_k+1 = x_k + (fx*fyy-fy*fxy)/(fxy*fxy-fxx*fyy)|(x_k,y_k);
//y_k+1 = y_k + (fy*fxx-fx*fxy)/(fxy*fxy-fxx*fyy)|(x_k,y_k);

int Newton()
{
    double ret=1e40,ans=1e40,tmp=0;
    double fx,fxx,fy,fyy,fxy;	//����ƫ������ֵ
    double tx,ty,d3;			//�����򻯼������ʱ����
    int i;
    Point cur,pt;
    cur.x = cur.y = 0;
    for (i=0; i<n; ++i)
    {
        cur.x += p[i].x;
        cur.y += p[i].y;
    }
    cur.x = cur.x/n + 0.5;		//ȡƽ������Ϊ������ֵ(+0.5��Ϊ�˱����ֵ����ĳ������)
    cur.y = cur.y/n + 0.5;
    for (ans=i=0; i<n; ++i)
        ans += dist[i] = sqrt( (cur.x-p[i].x)*(cur.x-p[i].x) + (cur.y-p[i].y)*(cur.y-p[i].y) );

    while (1)
    {
        fx=fy=fxx=fyy=fxy=0;		//�������ƫ����
        for (i=0; i<n; ++i)
        {
            tx = cur.x - p[i].x;
            ty = cur.y - p[i].y;
            d3 = dist[i]*dist[i]*dist[i];

            fx  += tx/dist[i];
            fy  += ty/dist[i];
            fxx += ty*ty/d3;
            fyy += tx*tx/d3;
            fxy -= tx*ty/d3;		//ע�������Ǽ��ţ���(��Ȼ����̫���Ӻ�Ҳ��AC����=��=)
        }

        tmp = fxy*fxy-fxx*fyy;		//�������½�
        pt.x = cur.x + (fx*fyy-fy*fxy)/tmp;
        pt.y = cur.y + (fy*fxx-fx*fxy)/tmp;

        for (tmp=i=0; i<n; ++i)
            tmp += dist[i] = sqrt( (pt.x-p[i].x)*(pt.x-p[i].x) + (pt.y-p[i].y)*(pt.y-p[i].y) );

        if (fabs(tmp-ans)<eps) break;
        else
        {
            cur=pt;
            ans=tmp;
        }
    }

    return ans+0.5;
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
        scanf("%lf %lf", &p[i].x , &p[i].y);
    printf("%d\n", Newton());
    return 0;
}
