#include "head.h"

using namespace std;

int InDegree[N],res[N];
int S,C,n,l,num,op,ave,s1,tot;
bool flag;
bool vis[N];
struct node1
{
    char id[4],pre[N][4];
    int cre,k;//creѧ�� k���޿γ�����
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

int TopSort_Queue()//�Կγ̽�����������
{
    memset(vis,0,sizeof(vis));//���ʼ�¼����
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
    memset(head,0,sizeof(head));   //��������
    memset(InDegree,0,sizeof(InDegree));
    l = 0;
    for (int i=1;i<=n;i++)//��ӱ�ʾֱ�����޿γ̵������
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
                cout<<"����ʧ�ܣ��γ̱�Ų�����!\n";
                return ;
            }
        }
    }
    int tmp = TopSort_Queue();
    if (!tmp)
    {
       cout<<"����ʧ�ܣ������޿γ��д����߼�����\n";
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
            cout<<"����ʧ�� ���пγ̵�ѧ�ִ���ÿѧ��ѧ������\n"<<course[res[i]].id;
            return ;
        }
     //   cout<<course[res[i]].id<<endl;
    }
    if (s1 > S)
    {
        cout<<"����ʧ�� ѧ������ѧ�����Ʋ���������ý�ѧ�ƻ��ı��ƣ�\n";
        return ;
    }
    cout<<"��������ı���Ŀ��\n";
   cout<<"����1��ʹÿ��ѧ�ڵ�ѧϰ������������\n";
   cout<<"����2��ʹ�γ̾���������ǰ�漸��ѧ��\n";
 cout<<"����1��2����ɷ����ƶ�������0�˳�����\n";

    ofstream outFile;
    outFile.open("result.txt", ios::out);//��������ļ�result.txt

    while (~scanf("%d", &op))
    {
        if (op == 1)
        {
            outFile<<"����1:\n";
            cout<<"����1:\n";
            ave = num / S;//ѧ��ƽ��ֵ
            s1 = 0;//��ʾ����ѧ��
            int i = 1;
            while (i<=num)
            {
                s1++;
                int tot = 0;//�ۼ�һ��ѧ�ڵ�ѧ���ܺ�
                int j = i;
                while (j<=num && j-i+1<=ave && tot <= C)//��֤ÿ��ѧ�ڰ��ŵĿγ���Ŀ������ƽ��������ѧ����������
                    tot += course[res[j++]].cre;
                outFile<<"��"<<s1<<" ѧ��: ";
                cout<<"��"<<s1<<" ѧ��: ";
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
            outFile<<"����2:\n";
            cout<<"����2:\n";
            s1 = 0;
            int i = 1;
            while (i<=num)
            {
                s1++;
                int tot = 0;
                int j = i;
                while (j<=num && tot <= C)//�����ܶ�Ľ��γ̰�����ǰ����ѧ��
                    tot += course[res[j++]].cre;
                outFile<<"��"<<s1<<" ѧ��: ";
                cout<<"��"<<s1<<" ѧ��: ";
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
    cout<<"������ѧ������S ÿѧ��ѧ������C �Լ�ѧ������N\n";
    cout<<"S = ";
    scanf("%d", &S);
    printf("C = ");
    scanf("%d", &C);
    printf("N = ");
    scanf("%d", &n);
    cout<<"������γ̱�� ѧ�� ���޿γ̵�����Ŀ�͸��γ̱��\n";
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
