//宇航员 poj 1835
//#include<map>
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//map<string,int>s;
//int main()
//{
//
//    int m,n,x;
//    char dest[20];
//    int xx,yy,zz;
//    scanf("%d",&m);
//    for(int i=1; i<=m; i++)
//    {
//        s["forward"]=0;
//        s["right"]=1;
//        s["up"]=2;
//        s["back"]=3;
//        s["left"]=4;
//        s["down"]=5;
//        xx=0,yy=0,zz=0;
//        int dir=0;
//        scanf("%d",&n);
//        for(int j=1; j<=n; j++)
//        {
//            scanf("%s%d",dest,&x);
//            if(strcmp(dest,"back")==0)
//            {
//                int temp=s["forward"];
//                s["forward"]=s["back"];
//                s["back"]=temp;
//                temp=s["right"];
//                s["right"]=s["left"];
//                s["left"]=temp;
//            }
//            else if(strcmp(dest,"left")==0)
//            {
//                int temp=s["forward"];
//                s["forward"]=s["left"];
//                s["left"]=s["back"];
//                s["back"]=s["right"];
//                s["right"]=temp;
//            }
//            else if(strcmp(dest,"right")==0)
//            {
//                int temp=s["forward"];
//                s["forward"]=s["right"];
//                s["right"]=s["back"];
//                s["back"]=s["left"];
//                s["left"]=temp;
//            }
//            else if(strcmp(dest,"up")==0)
//            {
//                int temp=s["forward"];
//                s["forward"]=s["up"];
//                s["up"]=s["back"];
//                s["back"]=s["down"];
//                s["down"]=temp;
//            }
//            else if(strcmp(dest,"down")==0)
//            {
//                int temp=s["forward"];
//                s["forward"]=s["down"];
//                s["down"]=s["back"];
//                s["back"]=s["up"];
//                s["up"]=temp;
//            }
//            switch(s["forward"])
//            {
//            case 0:
//                xx+=x;
//                break;
//            case 1:
//                yy+=x;
//                break;
//            case 2:
//                zz+=x;
//                break;
//            case 3:
//                xx-=x;
//                break;
//            case 4:
//                yy-=x;
//                break;
//            case 5:
//                zz-=x;
//                break;
//            }
//        }
//        dir=s["forward"];
//        printf("%d %d %d %d\n",xx,yy,zz,dir);
//    }
//    return 0;
//}

//中位数
//#include<stdio.h>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//long long array[1000000];
//int main()
//{
//    int N;
//    while(~scanf("%d",&N))
//    {
//        for(int i=0; i<N; i++)
//            scanf("%d",&array[i]);
//        sort(array,array+N);
//        if(N&1)
//            printf("%.1f\n",(double)array[N/2]);
//        else
//            printf("%.1f\n",(array[N/2-1]+array[N/2])/2.0);
//
//    }
//    return 0;
//}

//字符串的拼接，文章（网业）格式规格化
#include<map>
#include<string>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
//    freopen("test0.in","r",stdin);
//    freopen("test0.out","w",stdout);
    string str,s;
    while(cin>>s)
    {
        if(str.size()+s.size()>=80)
        {
            cout<<str<<endl;
            str.clear();
            str.append(s);
            continue;
        }
        if(s!="<hr>"&&s!="<br>")
        {
            if(str.size())
            {
                str.append(" ");
                str.append(s);
            }
            else
                str.append(s);
            s.clear();
        }
        else if(s=="<br>")
        {
            cout<<str<<endl;
            str.clear();
        }
        else if(s=="<hr>")
        {
            if(str.size())
                cout<<str<<endl;
            printf("--------------------------------------------------------------------------------\n");
            str.clear();
        }
    }
    cout<<str<<endl;
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}

//洗poker牌
//#include<map>
//#include<string>
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int N,C,cnt=0;
//    int time;
//    int flag=0;
//    char s1[150],ss1[150],s2[150],ss2[150],str[300],str2[300];
//    scanf("%d",&N);
//    while(N--)
//    {
//        time=1;
//        cnt=cnt+1;
//        scanf("%d",&C);
//        scanf("%s%s",s1,s2);
//        scanf("%s",str);
//        strcpy(ss1,s1);
//        strcpy(ss2,s2);
//        flag=1;
//        while(flag)
//        {
//            for(int i=0; i<C; i++)
//            {
//                str2[2*i]=s2[i];
//                str2[2*i+1]=s1[i];
//            }
//            str2[2*C]='\0';
//            if(strcmp(str,str2)==0)
//            {
//                printf("%d %d\n",cnt,time);
//                break;
//            }
//            else
//            {
//                time=time+1;
//                for(int i=0; i<C; i++)
//                {
//                    s1[i]=str2[i];
//                    s2[i]=str2[C+i];
//                }
//            }
//            if(strcmp(s1,ss1)==0&&strcmp(s2,ss2)==0)
//                flag=0;
//        }
//        if(!flag)
//            printf("%d -1\n",cnt);
//    }
//    return 0;
//}

//Flesch Reading Ease 统计并计算
//#include<map>
//#include<string>
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    string str;
//    float fres;
//    char syll[6]= {'a','e','i','o','u','y'};
//    int words=0,syllables=0,sentences=0;
//    while(cin>>str)
//    {
//        words++;
//        int i;
//        int len=str.size();
//        if(str[len-1]==':'||str[len-1]==';'||str[len-1]=='.'||str[len-1]=='!'||str[len-1]=='?')
//        {
//            sentences++;
//            len=len-1;
//        }
//        if(str[len-1]==',')
//        {
//            len=len-1;
//        }
//        if(len<=3)
//        {
//            syllables++;
//            continue;
//        }
//        for(i=0; i<len; i++)
//        {
//            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='y'
//                    ||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='Y')
//            {
//                if(str[i]=='e'||str[i]=='E')
//                {
//                    if(i==len-1)
//                    {
//                        if(str[i-1]=='l'||str[i-1]=='L')
//                            syllables++;
//                        break;
//                    }
//                    if(i+1==len-1)
//                        if(str[i+1]=='s'||str[i+1]=='d'||str[i+1]=='S'||str[i+1]=='D')
//                            break;
//                }
//                i++;
//                if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='y'
//                        ||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='Y')
//                {
//                    for(; i<len; i++)
//                    {
//                        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='y'
//                                ||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='Y')
//                            continue;
//                        else
//                            break;
//                    }
//                }
//                syllables++;
//            }
//        }
//        //cout<<str<<" ";
//        //printf("%d %d %d\n",words,sentences,syllables);
//    }
//    fres=(float)(206.835-1.015*(words*1.0/sentences)-84.6*(syllables*1.0/words));
//    printf("%.2f\n",fres);
//    return 0;
//}

//a chessboard position and the chess notation
//#include<map>
//#include<string>
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    char chessboard[17][33];
//    for(int i=0; i<17; i++)
//        scanf("%s",chessboard[i]);
//    printf("White: ");
//    for(int i=15; i>=1; i=i-2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='K')
//                printf("K%c%d,",(j/4)+97,8-i/2);
//    }
//    for(int i=15; i>=1; i=i-2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='Q')
//                printf("Q%c%d,",(j/4)+97,8-i/2);
//    }
//    for(int i=15; i>=1; i=i-2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='R')
//                printf("R%c%d,",(j/4)+97,8-i/2);
//    }
//    for(int i=15; i>=1; i=i-2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='B')
//                printf("B%c%d,",(j/4)+97,8-i/2);
//    }
//    for(int i=15; i>=1; i=i-2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='N')
//                printf("N%c%d,",(j/4)+97,8-i/2);
//    }
//    int cnt=0;
//    for(int i=15; i>=1; i=i-2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='P')
//                cnt++;
//    }
//    int num=0;
//    for(int i=15; i>=1; i=i-2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='P')
//            {
//                num++;
//                printf("%c%d%c",(j/4)+97,8-i/2,num==cnt?'\n':',');
//            }
//
//    }
//    printf("Black: ");
//    for(int i=1; i<16; i=i+2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='k')
//                printf("K%c%d,",(j/4)+97,8-i/2);
//    }
//    for(int i=1; i<16; i=i+2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='q')
//                printf("Q%c%d,",(j/4)+97,8-i/2);
//    }
//    for(int i=1; i<16; i=i+2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='r')
//                printf("R%c%d,",(j/4)+97,8-i/2);
//    }
//    for(int i=1; i<16; i=i+2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='b')
//                printf("B%c%d,",(j/4)+97,8-i/2);
//    }
//    for(int i=1; i<16; i=i+2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='n')
//                printf("N%c%d,",(j/4)+97,8-i/2);
//    }
//    cnt=0;
//    for(int i=1; i<16; i=i+2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='p')
//                cnt++;
//    }
//    num=0;
//    for(int i=1; i<16; i=i+2)
//    {
//        for(int j=0; j<33; j++)
//            if(chessboard[i][j]=='p')
//            {
//                num++;
//                printf("%c%d%c",(j/4)+97,8-i/2,num==cnt?'\n':',');
//            }
//
//    }
//    return 0;
//}
