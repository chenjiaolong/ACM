//sort的使用
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int n,array[1001];
//    while(scanf("%d",&n)!=EOF)
//    {
//        for(int i=0; i<n; i++)
//            scanf("%d",&array[i]);
//        sort(array,array+n);
//        for(int i=0; i<n; i++)
//            printf("%d%c",array[i],i==n-1?'\n':' ');
//    }
//    return 0;
//}

//改变sort的排序规则
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int cmp(int a,int b)
//{
//    return a>b;
//}
//int main()
//{
//    int n,array[1001];
//    while(scanf("%d",&n)!=EOF)
//    {
//        for(int i=0; i<n; i++)
//            scanf("%d",&array[i]);
//        sort(array,array+n,cmp);
//        int m=unique(array,array+n)-array;//去重
//        for(int i=0; i<m; i++)
//            printf("%d%c",array[i],i==n-1?'\n':' ');
//    }
//    return 0;
//}

//结构体sort排序加重载操作符
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//struct node
//{
//    int a,b;
//    bool operator <(const node &s)const//重载操作符
//    {
//        if(a==s.a)
//            return b<s.b;
//        return a<s.a;
//    }
//} array[101];
//int cmp(struct node a,struct node b)
//{
//    if(a.a==b.a)
//        return a.b<b.b;
//    return a.a<b.a;
//}
//int main()
//{
//    int n;
//    while(scanf("%d",&n)!=EOF)
//    {
//        for(int i=0; i<n; i++)
//            scanf("%d%d",&array[i].a,&array[i].b);
//        sort(array,array+n,cmp);//结构体sort排序
//        sort(array,array+n);//结构体重载操作符
//        for(int i=0; i<n; i++)
//            printf("%d %d\n",array[i].a,array[i].b);
//    }
//    return 0;
//}

//#include<cstdio>
//#include<algorithm>
//using namespace std;
//struct node
//{
//    int x,y;
//    bool operator<(const node &C)const
//    {
//        if(x==C.x)
//            return y<C.y;
//        return x<C.x;
//    }
//}array[100];
//int cmp(node p1,node p2)
//{
//    if(p1.x==p2.x)
//        return p1.y<p2.y;
//    return p1.x<p1.y;
//}
//int main()
//{
//    int n;
//    while(~scanf("%d",&n))
//    {
//        for(int i=0;i<n;i++)
//            scanf("%d%d",&array[i].x,&array[i].y);
//        //sort(array,array+n,cmp);//结构体sort排序
//        sort(array,array+n);//结构体重载操作符
//        for(int i=0;i<n;i++)
//            printf("%d %d\n",array[i].x,array[i].y);
//    }
//    return 0;
//}

//常用的库函数
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int a,b;
//    while(~scanf("%d%d",&a,&b))
//    {
//        printf("%d\n",__gcd(a,b));
//        printf("%d\n",max(a,b));
//        printf("%d\n",min(a,b));
//        swap(a,b);
//        printf("%d %d\n",a,b);
//    }
//}


#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
int main()
{
	vector<int >v;
	for(int i = 0; i < 5; i ++)
		v.push_back(i);
    // vector 的几种遍历方式
	for(int i = 0; i < v.size(); i ++)
		cout << v[i] << " ";
    cout << endl;
	for(vector<int > :: iterator it = v.begin(); it != v.end(); it ++)
        cout << *it << " ";
    cout << endl;
    for(auto it = v.begin(); it != v.end(); it ++)
        cout << *it << " ";
    cout << endl;
    for(auto i : v) // C++11标准
        cout << i << " ";
    cout << endl;
    //指定位置的插入
    auto it = v.begin() + 3;
    it = v.insert(it, 100);
    for(auto i : v)
        cout << i << " ";
    cout << endl;
    // 指定位置的删除
    v.erase(it);
    for(auto i : v)
        cout << i << " ";
    cout << endl;
	return 0;
}

//队列
//#include<queue>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    queue<int>q;
//    int n;
//    while(~scanf("%d",&n))
//    {
//        for(int i=0;i<n;i++)
//        {
//            int val;
//            scanf("%d",&val);
//            q.push(val);
//        }
//        while(!q.empty())
//        {
//            printf("%d\n",q.front());
//            q.pop();
//        }
//    }
//    return 0;
//}

//栈
//#include<stack>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int n;
//    stack<int>st;
//    while(~scanf("%d",&n))
//    {
//        for(int i=0; i<n; i++)
//        {
//            int val;
//            scanf("%d",&val);
//            st.push(val);
//        }
//        while(!st.empty())
//        {
//            printf("%d\n",st.top());
//            st.pop();
//        }
//    }
//    return 0;
//}

//优先队列
//#include<queue>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//priority_queue <int>q;
//int main()
//{
//    int n;
//    while(~scanf("%d",&n))
//    {
//        for(int i=0; i<n; i++)
//        {
//            int val;
//            scanf("%d",&val);
//            q.push(val);
//        }
//        while(!q.empty())
//        {
//            printf("%d ",q.top());
//            q.pop();
//        }
//    }
//    return 0;
//}

//结构体优先队列
//#include<queue>
//#include<vector>
//#include<cstdio>
//#include<cstring>
//#include<iostream>
//using namespace std;
//struct node
//{
//    int x,y;
//    bool operator<(const node &C)const
//    {
//        if(x==C.x)
//            return y<C.y;
//        return x<C.x;
//    }
//};
//priority_queue <node>q;
//int main()
//{
//    int n;
//    while(~scanf("%d",&n))
//    {
//        for(int i=0;i<n;i++)
//        {
//            node a;
//            scanf("%d%d",&a.x,&a.y);
//            q.push(a);
//        }
//        while(!q.empty())
//        {
//            printf("%d %d\n",q.top().x,q.top().y);
//            q.pop();
//        }
//    }
//    return 0;
//}

//map应用
//#include<map>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//using namespace std;
//map<char ,int >s;
//map<char ,char >s1;
//map<string,int >s2;
//map<string,string>s3;
//int main()
//{
//    s['a']=3;
//    printf("%d\n",s['a']);
//    s1['a']='b';
//    printf("%c\n",s1['a']);
//    s2["1234"]=4567;
//    printf("%d\n",s2["1234"]);
//    s3["wwww"]="aaaaaa";
//    printf("%s\n",s3["wwww"].c_str());
//    s.clear();
//    printf("%d\n",s['a']);
//    int a,b;
//    cin>>a>>b;
//    cout<<a<<" "<<b<<endl;
//    string s1,s2;
//    cin>>s1>>s2;
//    s1.push_back('a');
//    s2.append("aaaa");
//    cout<<s1<<"   "<<s2<<endl;
//    return 0;
//}
