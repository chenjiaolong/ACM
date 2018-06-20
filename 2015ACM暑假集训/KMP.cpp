// Number Sequence
//#include<cstdio>
//#include<cstring>
//int a[1000100],b[10010];
//int nextval[10010];
//int M,N;
//void get_nextval()
//{
//    int i=0;
//    int j=-1;
//    nextval[0]=-1;
//    while(i<M)
//    {
//        if(j==-1||b[i]==b[j])
//        {
//            i++;
//            j++;
//            if(b[i]!=b[j])
//                nextval[i]=j;
//            else
//                nextval[i]=nextval[j];
//        }
//        else
//            j=nextval[j];
//    }
//}
//int KMP()
//{
//    int i=0;
//    int j=0;
//    while(i<N)
//    {
//        if(j==-1||a[i]==b[j])
//        {
//            i++;
//            j++;
//        }
//        else
//            j=nextval[j];
//        if(j==M)
//            return i-M+1;
//    }
//    return -1;
//}
//int main()
//{
//    int T;
//    while(~scanf("%d",&T))
//    {
//        while(T--)
//        {
//            scanf("%d%d",&N,&M);
//            for(int i=0; i<N; i++)
//                scanf("%d",&a[i]);
//            for(int i=0; i<M; i++)
//                scanf("%d",&b[i]);
//            memset(nextval,0,sizeof(nextval));
//            get_nextval();
//            printf("%d\n",KMP());
//        }
//    }
//    return 0;
//}

// Oulipo
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//char W[10010],T[1000010];
//int nextval[10010];
//int len_W,len_T;
//void get_nextval()
//{
//    int i=0,j=-1;
//    nextval[0]=-1;
//    while(i<len_W)
//    {
//        if(j==-1||W[i]==W[j])
//        {
//            ++i,++j;
//            if(W[i]!=W[j])
//                nextval[i]=j;
//            else
//                nextval[i]=nextval[j];
//        }
//        else j=nextval[j];
//    }
//}
//void Index_KMP()
//{
//    int cnt=0;
//    int i=0,j=0;
//    while (i <len_T)
//    {
//
//        if (j==-1||T[i] == W[j])
//        {
//            i++;
//            j++;
//        }
//        else
//            j = nextval[j];
//        if(j==len_W)
//            cnt++;
//    }
//    printf("%d\n",cnt);
//}
//int main()
//{
//    int cas;
//    while(~scanf("%d",&cas))
//    {
//        while(cas--)
//        {
//            scanf("%s%s",W,T);
//            memset(next,0,sizeof(next));
//            len_W=strlen(W);
//            len_T=strlen(T);
//            get_nexval();
//            Index_KMP();
//        }
//    }
//    return 0;
//}

// ¼ô»¨²¼Ìõ
//#include<cstdio>
//#include<cstring>
//char S[1010],T[1010];
//int nextval[1010];
//int len_T,len_S;
//void get_nextval()
//{
//    int j=-1,i=0;
//    nextval[0]=-1;
//    while(i<len_T)
//    {
//        if(j==-1||S[i]==T[j])
//        {
//            i++;
//            j++;
//            if(T[i]!=T[j])
//                nextval[i]=j;
//            else
//                nextval[i]=nextval[j];
//        }
//        else
//            j=nextval[j];
//    }
//}
//void index_KMP()
//{
//    int i=0,j=0,cnt=0;
//    while(i<len_S)
//    {
//        if(j==-1||S[i]==T[j])
//        {
//            i++;
//            j++;
//        }
//        else
//            j=nextval[j];
//        if(j==len_T)
//        {
//            j=0;
//            cnt++;
//        }
//
//    }
//    printf("%d\n",cnt);
//}
//int main()
//{
//    while(~scanf("%s",S)&&S[0]!='#')
//    {
//        scanf("%s",T);
//        len_T=strlen(T);
//        len_S=strlen(S);
//        if(len_T>len_S)
//        {
//            printf("0\n");
//            continue;
//        }
//        memset(nextval,0,sizeof(nextval));
//        get_nextval();
//        index_KMP();
//    }
//    return 0;
//}

// Period
//#include<cstdio>
//#include<cstring>
//char T[1000010];
//int next[1000010];
//int N;
//void get_next()
//{
//    int i=0,j=-1;
//    next[0]=-1;
//    while(i<N)
//    {
//        if(j==-1||T[i]==T[j])
//        {
//            i++;
//            j++;
//            next[i]=j;
//        }
//        else
//            j=next[j];
//    }
//}
//int main()
//{
//    int cnt=0;
//    while(~scanf("%d",&N)&&N)
//    {
//        /*getchar();
//        for(int i=0; i<N; i++)
//            scanf("%c",&T[i]);*/
//        scanf("%s",T);
//        get_next();
//        printf("Test case #%d\n",++cnt);
//        for(int i=1; i<=N; i++)
//            if(i%(i-next[i])==0&&next[i])
//                printf("%d %d\n",i,i/(i-next[i]));
//        printf("\n");
//
//    }
//    return 0;
//}

// Power Strings
//#include<cstdio>
//#include<cstring>
//char T[1000010];
//int next[1000010];
//int len_T;
//void get_next()
//{
//    int i=0,j=-1;
//    next[0]=-1;
//    while(i<len_T)
//    {
//        if(j==-1||T[i]==T[j])
//        {
//            i++;
//            j++;
//            next[i]=j;
//        }
//        else
//            j=next[j];
//    }
//}
//int main()
//{
//    while(~scanf("%s",T)&&T[0]!='.')
//    {
//        len_T=strlen(T);
//        get_next();
//        if(len_T%(len_T-next[len_T])==0&&next[len_T])
//        printf("%d\n",len_T/(len_T-next[len_T]));
//        else
//            printf("1\n");
//    }
//    return 0;
//}

// The Minimum Length
//#include<cstdio>
//#include<cstring>
//char T[1000010];
//int next[1000010];
//int len_T;
//void get_next()
//{
//    int i=0,j=-1;
//    next[0]=-1;
//    while(i<len_T)
//    {
//        if(j==-1||T[i]==T[j])
//        {
//            i++;
//            j++;
//            next[i]=j;
//        }
//        else
//            j=next[j];
//    }
//}
//int main()
//{
//    while(~scanf("%s",T))
//    {
//        len_T=strlen(T);
//        memset(next,0,sizeof(next));
//        get_next();
//        printf("%d\n",len_T-next[len_T]);
//    }
//    return 0;
//}

// Seek the Name, Seek the Fame
//#include<cstdio>
//#include<cstring>
//char S[400010];
//int next[400010];
//int len_S;
//int array[400010];
//void get_next()
//{
//    int i=0,j=-1;
//    next[0]=-1;
//    while(i<len_S)
//    {
//        if(j==-1||S[i]==S[j])
//        {
//            i++;
//            j++;
//            next[i]=j;
//        }
//        else
//            j=next[j];
//    }
//}
//int main()
//{
//    int cnt;
//    while(~scanf("%s",S))
//    {
//        len_S=strlen(S);
//        get_next();
//        int cur=len_S;
//        cnt=0;
//        while(next[cur]!=0)
//        {
//            array[cnt++]=cur;
//            cur=next[cur];
//        }
//        array[cnt++]=cur;
//        for(int i=cnt-1; i>=0; i--)
//                printf("%d%c",array[i],i==0?'\n':' ');
//    }
//    return 0;
//}

// Period II
//#include<cstdio>
//#include<cstring>
//char S[1000001];
//int next[1000001];
//int ans[1000001];
//int len_S;
//void get_next()
//{
//    int i=0,j=-1;
//    next[0]=-1;
//    while(i<len_S)
//    {
//        if(j==-1||S[i]==S[j])
//        {
//            i++;
//            j++;
//            next[i]=j;
//        }
//        else
//            j=next[j];
//    }
//}
//int main()
//{
//    int T,cnt;
//    while(~scanf("%d",&T))
//    {
//        for(int t=1; t<=T; t++)
//        {
//            scanf("%s",S);
//            len_S=strlen(S);
//            get_next();
//            cnt=0;
//            int cur=len_S;
//            while(next[cur])
//            {
//                ans[cnt++]=len_S-next[cur];
//                cur=next[cur];
//            }
//            ans[cnt++]=len_S;
//            printf("Case #%d: %d\n",t,cnt);
//            for(int i=0; i<cnt; i++)
//                printf("%d%c",ans[i],i==cnt-1?'\n':' ');
//        }
//    }
//    return 0;
//}

// Count the string
//#include<cstdio>
//#include<cstring>
//char S[200010];
//int next[200010];
//int len_T,sum,n;
//void get_next()
//{
//    int i=0,j=-1;
//    next[0]=-1;
//    while(i<n)
//    {
//        if(j==-1||S[i]==S[j])
//        {
//            i++;
//            j++;
//            next[i]=j;
//        }
//        else
//            j=next[j];
//    }
//}
//int main()
//{
//    int cas;
//    while(~scanf("%d",&cas))
//    {
//        while(cas--)
//        {
//            sum=0;
//            scanf("%d",&n);
//            getchar();
//            for(int i=0; i<n; i++)
//                scanf("%c",&S[i]);
//            get_next();
//            int a[200010];
//            for(int i=1; i<=n; i++)
//            {
//                a[i]=(a[next[i]]+1)%10007;
//                sum=(sum+a[i])%10007;
//            }
//            printf("%d\n",sum%10007);
//        }
//    }
//    return 0;
//}

// Censor
//#include<cstdio>
//#include<cstring>
//char W[5000001],P[5000001];
//int top=-1;
//int next[5000001];
//int len_W,len_P;
//struct stack
//{
//    char ch;
//    int J;
//} stack[5000001];
//void get_next()
//{
//    int i=0,j=-1;
//    next[0]=-1;
//    while(i<len_W)
//    {
//        if(j==-1||W[i]==W[j])
//        {
//            i++;
//            j++;
//            next[i]=j;
//        }
//        else
//            j=next[j];
//    }
//}
//void KMP()
//{
//    int i=0,j=0;
//    top=-1;
//    while(i<len_P)
//    {
//        if(j==-1||P[i]==W[j])
//        {
//            top++;
//            stack[top].J=j+1;
//            stack[top].ch=P[i];
//            i++;
//            j++;
//        }
//        else
//            j=next[j];
//        if(j==len_W)
//        {
//            top=top-len_W;
//            j=stack[top].J;
//        }
//
//    }
//}
//int main()
//{
//    while(~scanf("%s%s",W,P))
//    {
//        len_W=strlen(W);
//        len_P=strlen(P);
//        if(len_W>len_P)
//        {
//            printf("%s\n",P);
//            continue;
//        }
//        get_next();
//        KMP();
//        for(int k=0; k<=top; k++)
//            printf("%c",stack[k].ch);
//        printf("\n");
//    }
//    return 0;
//}

// Blue Jeans
//#include<cstdio>
//#include<cstring>
//char str[11][65];
//char T[65],S[65];
//char ans[65];
//int next[65];
//int len_T;
//void get_next()
//{
//    int i=0,j=-1;
//    next[0]=-1;
//    while(i<len_T)
//    {
//        if(j==-1||T[i]==T[j])
//        {
//            i++;
//            j++;
//            next[i]=j;
//        }
//        else
//            j=next[j];
//    }
//}
//int KMP()
//{
//    int i=0,j=0;
//    while(i<60)
//    {
//        if(j==-1||S[i]==T[j])
//        {
//            i++;
//            j++;
//        }
//        else
//            j=next[j];
//        if(j==len_T)
//            return 1;
//    }
//    return 0;
//}
//int main()
//{
//    int n,m,flag=0,temp=0;
//    while(~scanf("%d",&n))
//    {
//        while(n--)
//        {
//          flag=0,temp=0;
//          scanf("%d",&m);
//          for(int i=0; i<m; i++)
//                scanf("%s",str[i]);
//            for(int i=0; i<60; i++)
//            {
//                for(int j=3; i+j<=60; j++)
//                {
//                    int k;
//                    for(k=0; k<j; k++)
//                        T[k]=str[0][k+i];
//                    T[k]='\0';
//                    len_T=j;
//                    get_next();
//                    for(k=1; k<m; k++)
//                    {
//                        strcpy(S,str[k]);
//                        if(!KMP())
//                            break;
//                    }
//                    if(k!=m)
//                        break;
//                    else
//                    {
//                        flag=1;
//                        if(temp<j)
//                        {
//                            temp=j;
//                            strcpy(ans,T);
//                        }
//                        else if(temp==j)
//                        {
//                            if(strcmp(ans,T)>0)
//                                strcpy(ans,T);
//                        }
//                    }
//                }
//            }
//            if(flag)
//                printf("%s\n",ans);
//            else
//                printf("no significant commonalities\n");
//        }
//    }
//    return 0;
//}

// Corporate Identity
//#include<cstdio>
//#include<cstring>
//char str[4010][210];
//char T[210],S[210];
//char ans[210];
//int next[210];
//int len_T,len;
//void get_next()
//{
//    int i=0,j=-1;
//    next[0]=-1;
//    while(i<len_T)
//    {
//        if(j==-1||T[i]==T[j])
//        {
//            i++;
//            j++;
//            next[i]=j;
//        }
//        else
//            j=next[j];
//    }
//}
//int KMP()
//{
//    int i=0,j=0;
//    while(i<len)
//    {
//        if(j==-1||S[i]==T[j])
//        {
//            i++;
//            j++;
//        }
//        else
//            j=next[j];
//        if(j==len_T)
//            return 1;
//    }
//    return 0;
//}
//int main()
//{
//    int N,temp=0;
//    while(~scanf("%d",&N)&&N)
//    {
//        int temp=0;
//        for(int i=0; i<N; i++)
//            scanf("%s",str[i]);
//        len=strlen(str[0]);
//        T[0]='\0',ans[0]='\0',S[0]='\0';
//        for(int i=0; i<len; i++)
//            if(i+1<=len)
//            {
//                for(int j=1; i+j<=len; j++)
//                {
//                    int k;
//                    for(k=0; k<j; k++)
//                        T[k]=str[0][k+i];
//                    T[k]='\0';
//                    len_T=j;
//                    get_next();
//                    for(k=1; k<N; k++)
//                    {
//                        len_S=strlen(str[k]);
//                        strcpy(S,str[k]);
//                        if(!KMP())
//                            break;
//                    }
//                    if(k!=N)
//                        break;
//                    else
//                    {
//                        if(temp<j)
//                        {
//                            temp=j;
//                            strcpy(ans,T);
//                        }
//                        else if(temp==j)
//                        {
//                            if(strcmp(ans,T)>0)
//                                strcpy(ans,T);
//                        }
//                    }
//                }
//            }
//        if(strlen(ans)>0)
//            printf("%s\n",ans);
//        else
//            printf("IDENTITY LOST\n");
//    }
//    return 0;
//}

// Clairewd¡¯s message
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
const int maxn = 1e5 + 100;
char S[maxn], T[maxn];
char CT[30]; // Conversion Table
int next[maxn];
void get_next(int len
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < len)
    {
        if(j == -1 || T[i] == T[j])
        {
            i ++;
            j ++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int index_KMP(int len_T, int len_S)
{
    int i = 0, j = 0;
    while(i < len_S && j < len_T)
    {
        if(j == - 1 || S[i] == T[j])
        {
            i ++;
            j ++;
            if(i == len_S) return j;
        }
        else j = next[j];
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s%s", CT, T);
        int len_T = strlen(T);
        strcpy(S, T + (len_T + 1) / 2);
        printf("%s",T);
        for(int i = 0; i < len_T; i ++)
            for(int j = 0; j < 26; j ++)
                if(T[i] == CT[j])
                {
                    T[i] = j + 'a';
                    break;
                }
        get_next(len_T);
        int len_S = strlen(S);
        int index = index_KMP(len_T, len_S);
        for(int i = index; i < len_T - index; i ++)
            printf("%c", T[i]);
        puts("");

    }
    return 0;
}

