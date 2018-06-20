// CSU 1007
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    int Px, Py;
    int Ax, Ay, Bx, By;
    while(T--)
    {
        scanf("%d%d", &Px, &Py);
        scanf("%d%d%d%d", &Ax, &Ay, &Bx, &By);
        if(Py > By || Px < Ax || Py < Ay || Px > Bx) puts("Outside");
        else if(Px > Ax && Px < Bx && Py < By && Py > Ay) puts("Inside");
        else puts("On");
    }
    return 0;
}
