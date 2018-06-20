#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
double random(double start,double end)
{
    return start+(end-start)*rand()/(RAND_MAX+1.0);
}
int main()
{
    freopen("test0.in","w",stdout);
    srand(unsigned(time(0)));
    for(int i=0;i<1000;i++)
    {
        int n,m;
        n=random(0,1000);
        m=random(0,1000);
        printf("%d %d\n",n,m);
        while(m--)
        {
            int u,v,c;
            u=random(1,n+1);
            v=random(1,n+1);
            c=random(0,1000);
            printf("%d %d %d\n",u,v,c);
        }
    }
    fclose(stdout);
    return 0;
}
