#include "head.h"

using namespace std;

int InDegree[N],res[N];
int S,C,n,l,num,op,ave,s1,tot;
bool flag;
bool vis[N];
struct node1
{
    char id[4],pre[N][4];
    int cre,k;//cre学分 k先修课程总数
};
node1 course[N];
int head[N];
struct node
{
    int x,y,next;
};
node edge[M];
void add(int x,int y)
{
    l++;
    edge[l].x = x;edge[l].y = y;
    edge[l].next = head[x];head[x] = l;
}

int TopSort_Queue()//对课程进行拓扑排序
{
    memset(vis,0,sizeof(vis));//访问记录清零
    Queue<int> Q(N);
    for (int i=1;i<=n;i++)
        if (InDegree[i] == 0) Q.Push(i);
    while (!Q.IsEmpty())
    {
        int v = Q.front();
        res[++num] = v;
        vis[v] = 1;
        Q.Pop();
        for (int p=head[v];p;p = edge[p].next)
        {
            int u = edge[p].y;
            InDegree[u]--;
            if (InDegree[u] == 0) Q.Push(u);
        }
    }
    for (int i=1;i<=n;i++)
        if (!vis[i]) return 0;
    return 1;
}

void solve()
{
    memset(head,0,sizeof(head));   //数据清零
    memset(InDegree,0,sizeof(InDegree));
    l = 0;
    for (int i=1;i<=n;i++)//添加表示直接先修课程的有向边
    {
        for (int j = 1;j<=course[i].k;j++)
        {
            flag = 0;
            for (int i1 = 1;i1<=n;i1++)
                if (!strcmp(course[i1].id, course[i].pre[j]))
                {
                    add(i1,i);
                    InDegree[i]++;
                    flag = 1;
                }
            if (!flag)
            {
                cout<<"构建失败，课程编号不存在!\n";
                return ;
            }
        }
    }
    int tmp = TopSort_Queue();
    if (!tmp)
    {
       cout<<"构建失败，在先修课程中存在逻辑错误\n";
        return ;
    }
    tot = 0;
    s1 = 0;
    for (int i=1;i<=num;i++)
    {
        tot += course[res[i]].cre;
        if (tot > C)
        {
            s1++;
            tot = course[res[i]].cre;
        }
        if (course[res[i]].cre > C)
        {
            cout<<"编制失败 下列课程的学分大于每学期学分限制\n"<<course[res[i]].id;
            return ;
        }
     //   cout<<course[res[i]].id<<endl;
    }
    if (s1 > S)
    {
        cout<<"编制失败 学期数及学分限制不足以满足该教学计划的编制！\n";
        return ;
    }
    cout<<"请输入你的编制目标\n";
   cout<<"方案1是使每个学期的学习负担尽量均匀\n";
   cout<<"方案2是使课程尽量集中在前面几个学期\n";
 cout<<"输入1或2来完成方案制定，输入0退出程序\n";

    ofstream outFile;
    outFile.open("result.txt", ios::out);//建立输出文件result.txt

    while (~scanf("%d", &op))
    {
        if (op == 1)
        {
            outFile<<"策略1:\n";
            cout<<"策略1:\n";
            ave = num / S;//学分平均值
            s1 = 0;//表示各个学期
            int i = 1;
            while (i<=num)
            {
                s1++;
                int tot = 0;//累计一个学期的学分总和
                int j = i;
                while (j<=num && j-i+1<=ave && tot <= C)//保证每个学期安排的课程数目不超过平均数且在学分限制以内
                    tot += course[res[j++]].cre;
                outFile<<"第"<<s1<<" 学期: ";
                cout<<"第"<<s1<<" 学期: ";
                for (int k = i;k<j;k++)
                   {
                       outFile<<course[res[k]].id<<' ';
                     cout<<course[res[k]].id<<' ';
                   }
                outFile<<endl;
                cout<<endl;
                i = j;
            }
        }
        else if (op == 2)
        {
            outFile<<"策略2:\n";
            cout<<"策略2:\n";
            s1 = 0;
            int i = 1;
            while (i<=num)
            {
                s1++;
                int tot = 0;
                int j = i;
                while (j<=num && tot <= C)//尽可能多的将课程安排在前几个学期
                    tot += course[res[j++]].cre;
                outFile<<"第"<<s1<<" 学期: ";
                cout<<"第"<<s1<<" 学期: ";
                for (int k = i;k<j;k++)
                    {
                        outFile<<course[res[k]].id<<' ';
                        cout<<course[res[k]].id<<' ';
                    }
                outFile<<endl;
                cout<<endl;
                i = j;
            }
        }
        else
        {
            cout<<"Thank you!\n";
            return ;
        }
    }
}
int main()
{
    cout<<"请输入学期总数S 每学期学分限制C 以及学科总数N\n";
    cout<<"S = ";
    scanf("%d", &S);
    printf("C = ");
    scanf("%d", &C);
    printf("N = ");
    scanf("%d", &n);
    cout<<"请输入课程编号 学分 先修课程的总数目和各课程编号\n";
    for (int i=1;i<=n;i++)
    {
        scanf("%s %d", course[i].id, &course[i].cre);
        scanf("%d", &course[i].k);
        for (int j=1;j<=course[i].k;j++)
            scanf("%s", course[i].pre[j]);
    }

    solve();
    return 0;
}
