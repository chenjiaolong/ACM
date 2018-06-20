#include<cstdio>
#include<cstring>
const int maxn=1100;
char S[maxn],T[maxn];
int next[maxn],nextval[maxn];
int len_T,len_S;
// next[]的含义：T[i-next[i]...i-1]=T[0...next[i]-1]
// next[i]为满足T[i-z...i-1]=T[0...z-1]的最大z值（就是x的自身匹配）
void get_next()
{
    int i=0;//后缀
    int j=-1;//前缀
    next[0]=-1;
    while(i<len_T)
    {
        if(j==-1||T[i]==T[j])
        {
            i++,j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
    printf("next为：");
    for(int i=0; i<=len_T; i++)
        printf("%d",next[i]);
    printf("\n");
}
void get_nextval()
{
    int i=0;//后缀
    int j=-1;//前缀
    nextval[0]=-1;
    while(i<len_T)
    {
        if(j==-1||T[i]==T[j])
        {
            i++,j++;
            if(T[i]!=T[j])
                nextval[i]=j;
            else
                nextval[i]=nextval[j];
        }
        else
            j=nextval[j];
    }
    printf("nextval为：");
    for(int i=0; i<=len_T; i++)
        printf("%d",nextval[i]);
    printf("\n");
}
void KMP()
{
    int i=0;
    int j=0;
    while(i<len_S)
    {
        if(j==-1||S[i]==T[j])
        {
            i++;
            j++;
        }
        else j=next[j];//else j=nextval[j];
        if(j==len_T)
        {
            printf("Yes\n");
            return ;
        }
    }
    printf("No\n");

}
int main()
{
    while(~scanf("%s%s",S,T))
    {
        memset(next,0,sizeof(next));
        len_T=strlen(T);
        len_S=strlen(S);
        if(len_T>len_S)
        {
            printf("No\n");
            continue;
        }
        get_next();
        get_nextval();
        KMP();
        if(len_T%(len_T-next[len_T]) == 0 && next[len_T])
            printf("%d\n",len_T/(len_T-next[len_T]));
        else
            printf("1\n");
    }
    return 0;
}

