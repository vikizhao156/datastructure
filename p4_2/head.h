#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


//图的抽象类
template <class TypeOfVer,class TypeOfEdge>
class graph
{
public:
    virtual void insert(TypeOfVer x,TypeOfVer y,TypeOfEdge w)=0;
    virtual void remove(TypeOfVer x,TypeOfVer y)=0;
    virtual bool exist(TypeOfVer x,TypeOfVer y)const =0;
    int numOfVer()const {return Vers;}
    int numOfEdge()const {return Edges;}

protected:
    int Vers,Edges;
};


//邻接表类的定义
template <class TypeOfVer,class TypeOfEdge>
class adjListGraph:public graph<TypeOfVer,TypeOfEdge>
{
public:
    adjListGraph(int vSize,const TypeOfVer d[]);
    void insert(TypeOfVer x,TypeOfVer y,TypeOfEdge w);
    void remove(TypeOfVer x,TypeOfVer y);
    bool exist(TypeOfVer x,TypeOfVer y)const;
    ~adjListGraph();
    void prim(TypeOfEdge noEdge)const;
    //void dfs()const;
    //void bfs()const;
protected:
    int Vers,Edges;
private:
    struct edgeNode  //邻接表中存储边的结点类
    {
        int end;  //终点编号
        TypeOfEdge weight;//边的权值
        edgeNode *next;

        edgeNode(int e,TypeOfEdge w,edgeNode *n=NULL)
        {
            end=e;//边的终点
            weight=w;//权值
            next=n;
        }
    };

    struct verNode  //保存顶点的数据元素类型
    {
        TypeOfVer ver;//顶点值
        edgeNode *head;//对应的单链表的头指针

        verNode(edgeNode *h=NULL){head=h;}

    };

    verNode *verList;//指向保存顶点的数组的首地址

    int find(TypeOfVer v)const
    {
        for(int i=0;i<Vers;i++)
            if(verList[i].ver==v) return i;
    }


  //  void dfs(int start,bool visited[])const;
};

//adjListGraph类的构造函数和析构函数
template <class TypeOfVer,class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::adjListGraph(int vSize,const TypeOfVer d[])
{
    Vers=vSize;
    Edges=0;
    verList=new verNode [vSize];
    for(int i=0;i<Vers;i++) verList[i].ver=d[i];//顶点数组赋值

}

template <class TypeOfVer,class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::~adjListGraph()
{
    int i;
    edgeNode* p;

    for(i=0;i<Vers;i++)//析构边表
    {
        while((p=verList[i].head)!=NULL)//释放第i个结点的单链表
            {
                verList[i].head=p->next;
                delete p;
            }

    }
    delete []verList;//析构结点表
}

//insert函数的实现
template <class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::insert(TypeOfVer x,TypeOfVer y,TypeOfEdge w)
{
    int u=find(x);//例如寻找A是第几个结点
    int v=find(y);
    verList[u].head=new edgeNode(v,w,verList[u].head);//从头部插入，一行代码实现三个功能：1.创建2.加入边表3.改结点表中的head指针
    ++Edges;

}

//remove函数的实现
template <class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::remove(TypeOfVer x,TypeOfVer y)
{
    int u=find(x),v=find(y);
    edgeNode *p=verList[u].head,*q;

    if(p==NULL) return;//结点u没有相连的边

    if(p->end==v)  //单链表中的第一个结点就是被删除的边
    {
        verList[u].head=p->next;
        delete p;
        --Edges;
        return;
    }

    while(p->next!=NULL&&p->next->end!=v) p=p->next;//查找被删除的边
    if(p->next!=NULL)//删除
    {
        q=p->next;
        p->next=q->next;
        delete q;
        --Edges;
    }
}

//exist函数的实现
template <class TypeOfVer,class TypeOfEdge>
bool adjListGraph<TypeOfVer,TypeOfEdge>::exist(TypeOfVer x,TypeOfVer y)const
{
    int u=find(x),v=find(y);
    edgeNode *p=verList[u].head;

    while(p->next!=NULL&&p->end!=v) p=p->next;//查找

    if(p==NULL) return false;
    else return true;
}


//prim算法
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::prim(TypeOfEdge noEdge) const
{
   ofstream fout("primtree.txt");
    bool *flag = new bool[Vers];
  TypeOfEdge *lowCost = new TypeOfEdge[Vers];
  int *startNode = new int[Vers];
  edgeNode *p;
  TypeOfEdge min;
  int  start,i, j;
char start1;
  for (i = 0; i < Vers; ++i)
    {
	  flag[i] = false;
	  lowCost[i] = noEdge;
	   }
cout<<"请输入起始顶点"<<endl;
 cin>>start1;
start=find(start1);
  for ( i= 1; i < Vers; ++i) {
	  for (p = verList[start].head; p != NULL; p = p->next)
  	        if (!flag[p->end] && lowCost[p->end] > p->weight) {
		     lowCost[p->end] = p->weight;
	              startNode[p->end] = start;  }
	  flag[start] = true;
	  min = noEdge;
	  for (j = 0; j < Vers; ++j)
		  if (lowCost[j] < min) {min = lowCost[j]; start = j;}
	  cout << '(' << verList[startNode[start]].ver << ','<< verList[start].ver << ") weight:"<<lowCost[start]<<endl;
	  fout << '(' << verList[startNode[start]].ver << ','<< verList[start].ver << ") weight:"<<lowCost[start]<<endl;
	  lowCost[start] = noEdge;
      }
        fout.close();
  delete [] flag;
  delete [] startNode;
  delete [] lowCost;
}
#endif // HEAD_H
