//#include<iostream>
//#include<math.h>
//#include<stdio.h>
//#include<stdlib.h>
//#define PI acos(-1.0)
//using namespace std;
//int main()
//{
//    double L,W,x,y,R,a,v,s;
//    double x1,x2,y1,y2;
//    while(cin>>L>>W>>x>>y>>R>>a>>v>>s&&L+W+x+y+R+a+v+s)
//    {
//        x1=R,x2=L-R,y1=R,y2=W-R;
//        x=x+v*s*cos(a*PI/180.0);
//        y=y+v*s*sin(a*PI/180.0);
//        while(x<x1||x>x2||y<y1||y>y2)
//        {
//            if(x>x2)
//                x=2*x2-x;
//            if(x<x1)
//                x=2*x1-x;
//            if(y>y2)
//                y=2*y2-y;
//            if(y<y1)
//                y=2*y1-y;
//        }
//        printf("%.2f %.2f\n",x,y);
//    }
//    return 0;
//}

//#include<iostream>
//#include<stdio.h>
//#include <math.h>
//using namespace std;
//int main()
//{
//    int t;
//    int l, w, r, a, v, s;
//    double x, y;
//    double pi = acos(-1);
//    double vx, vy;
//    while(cin>>l>>w>>x>>y>>r>>a>>v>>s)
//    {
//        if(l == 0) break;
//        vy = sin( a*pi/180 )*v;
//        vx=cos( a*pi/180 )*v;
//        t=0;
//        while( t!=s )
//        {
//            x+=vx;
//            y+=vy;
//            while( (x-r<0) || (x+r>l) || (y-r<0) || (y+r>w) )
//            {
//                if( x-r<0 ) x=2*r-x, vx=-vx;
//                if( x+r>l ) x=2*l-2*r-x, vx=-vx;
//                if( y-r<0 ) y=2*r-y, vy =-vy;
//                if( y+r>w ) y=2*w-2*r-y, vy =-vy;
//            }
//            t++;
//        }
//        printf( "%.2f %.2f\n", x, y );
//    }
//    return 0;
//}

#include <stdio.h>
#include <string.h>
#include <math.h>

const double PI = acos(-1.0);
int L, W, x, y, R, a, v, s;
double xv, yv, xc, yc;

int main()
{
    // freopen("stdin.txt", "r", stdin);
    while (scanf("%d%d%d%d%d%d%d%d", &L, &W, &x, &y, &R, &a, &v, &s), x)
    {
        L -= R * 2;
        W -= R * 2;
        x -= R;
        y -= R;
        xv = v * cos(a * PI / 180.0);
        yv = v * sin(a * PI / 180.0);
        xc = fmod(fmod(xv * s, L * 2.0) + L * 2.0, L * 2.0);
        yc = fmod(fmod(yv * s, W * 2.0) + W * 2.0, W * 2.0);
        xc += x;
        yc += y;
        if(xc >= 2 * L) xc -= 2 * L;
        else if(xc > L) xc = L - (xc - L);
        if(yc >= 2 * W) yc -= 2 * W;
        else if(yc > W) yc = W - (yc - W);
        printf("%.2lf %.2lf\n", xc + R, yc + R);
    }
    return 0;
}
