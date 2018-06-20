//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int T,n,i,j;
//    char ch[100],str[100];
//    while(~scanf("%d",&T))
//    {
//        for(i=1; i<=T; i++)
//        {
//            scanf("%d",&n);
//            int cnt=0;
//            int vis[15] = {0};
//            for(j=1; j<=n; j++)
//            {
//                scanf("%s%s",ch,str);
//                if(ch[0]=='A'&&strcmp(str,"Accepted")==0&&vis[0]==0)
//                {
//                    cnt++;
//                    vis[0]=1;
//                }
//                else if(ch[0]=='B'&&strcmp(str,"Accepted")==0&&vis[1]==0)
//                {
//                    cnt++;
//                    vis[1]=1;
//                }
//                else if(ch[0]=='C'&&strcmp(str,"Accepted")==0&&vis[2]==0)
//                {
//                    cnt++;
//                    vis[2]=1;
//                }
//                else if(ch[0]=='D'&&strcmp(str,"Accepted")==0&&vis[3]==0)
//                {
//                    cnt++;
//                    vis[3]=1;
//                }
//
//                else if(ch[0]=='E'&&strcmp(str,"Accepted")==0&&vis[4]==0)
//                {
//                    cnt++;
//                    vis[4]=1;
//                }
//                else if(ch[0]=='F'&&strcmp(str,"Accepted")==0&&vis[5]==0)
//                {
//                    cnt++;
//                    vis[5]=1;
//                }
//                else if(ch[0]=='G'&&strcmp(str,"Accepted")==0&&vis[6]==0)
//                {
//                    cnt++;
//                    vis[6]=1;
//                }
//                else if(ch[0]=='H'&&strcmp(str,"Accepted")==0&&vis[7]==0)
//                {
//                    cnt++;
//                    vis[7]=1;
//                }
//                else if(ch[0]=='I'&&strcmp(str,"Accepted")==0&&vis[8]==0)
//                {
//                    cnt++;
//                    vis[8]=1;
//                }
//                else if(ch[0]=='J'&&strcmp(str,"Accepted")==0&&vis[9]==0)
//                {
//                    cnt++;
//                    vis[9]=1;
//                }
//                else if(ch[0]=='K'&&strcmp(str,"Accepted")==0&&vis[10]==0)
//                {
//                    cnt++;
//                    vis[10]=1;
//                }
//                else if(ch[0]=='L'&&strcmp(str,"Accepted")==0&&vis[11]==0)
//                {
//                    cnt++;
//                    vis[11]=1;
//                }
//            }
//            printf("Case #%d: %d\n",i,cnt);
//        }
//    }
//    return 0;
//}

#include<stdio.h>
struct node
{
    char name[50];
    int year;
} per[1010];
void Zodiac(int Y)
{
    switch(Y%12)
    {
    case 0:
        printf("Monkey");
        break;
    case 1:
        printf("Cock");
        break;
    case 2:
        printf("Dog");
        break;
    case 3:
        printf("Boar");
        break;
    case 4:
        printf("Rat");
        break;
    case 5:
        printf("Ox");
        break;
    case 6:
        printf("Tiger");
        break;
    case 7:
        printf("Hare");
        break;
    case 8:
        printf("Dragon");
        break;
    case 9:
        printf("Snake");
        break;
    case 10:
        printf("Horse");
        break;
    case 11:
        printf("Sheep");
        break;
    }
}
int main()
{
    int T,Y,n,i,j;
    scanf("%d",&T);
    for(i=1; i<=T; i++)
    {
        scanf("%d",&Y);
        scanf("%d",&n);
        for(j=0; j<n; j++)
            scanf("%s%d",per[j].name,&per[j].year);
        printf("Case #%d:\n",i);
        for(j=0; j<n; j++)
        {
            if(per[j].year%12==Y%12)
                printf("Destined");
            else
            {
                Zodiac(Y);
                printf(" ");
                printf("%s",per[j].name);
            }
            printf(" ");
            Zodiac(per[j].year);
            printf("\n");
        }

    }
    return 0;
}

