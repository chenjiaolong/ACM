// USACO 2.2.2 Subset Sums
#include<fstream>
#include<iostream>

using namespace std;
const unsigned int MAX_SUM=1024;
int n;
unsigned long long int dyn[MAX_SUM];
int main()
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    fin>>n;
    fin.close();
    int s=n*(n+1);
    if(s%4)
    {
        fout<<0<<endl;
        fout.close();
        return 0;
    }
    s/=4;
    int i,j;
    dyn[0]=1;
    for(i=1; i<=n; i++)
        for(j=s; j>=i; j--)
            if(j-i>=0)
                dyn[j]+=dyn[j-i];
    fout<<dyn[s]/2<<endl;
    fout.close();
    return 0;
}
