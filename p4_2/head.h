#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


//ͼ�ĳ�����
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


//�ڽӱ���Ķ���
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
    struct edgeNode  //�ڽӱ��д洢�ߵĽ����
    {
        int end;  //�յ���
        TypeOfEdge weight;//�ߵ�Ȩֵ
        edgeNode *next;

        edgeNode(int e,TypeOfEdge w,edgeNode *n=NULL)
        {
            end=e;//�ߵ��յ�
            weight=w;//Ȩֵ
            next=n;
        }
    };

    struct verNode  //���涥�������Ԫ������
    {
        TypeOfVer ver;//����ֵ
        edgeNode *head;//��Ӧ�ĵ������ͷָ��

        verNode(edgeNode *h=NULL){head=h;}

    };

    verNode *verList;//ָ�򱣴涥���������׵�ַ

    int find(TypeOfVer v)const
    {
        for(int i=0;i<Vers;i++)
            if(verList[i].ver==v) return i;
    }


  //  void dfs(int start,bool visited[])const;
};

//adjListGraph��Ĺ��캯������������
template <class TypeOfVer,class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::adjListGraph(int vSize,const TypeOfVer d[])
{
    Vers=vSize;
    Edges=0;
    verList=new verNode [vSize];
    for(int i=0;i<Vers;i++) verList[i].ver=d[i];//�������鸳ֵ

}

template <class TypeOfVer,class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::~adjListGraph()
{
    int i;
    edgeNode* p;

    for(i=0;i<Vers;i++)//�����߱�
    {
        while((p=verList[i].head)!=NULL)//�ͷŵ�i�����ĵ�����
            {
                verList[i].head=p->next;
                delete p;
            }

    }
    delete []verList;//��������
}

//insert������ʵ��
template <class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::insert(TypeOfVer x,TypeOfVer y,TypeOfEdge w)
{
    int u=find(x);//����Ѱ��A�ǵڼ������
    int v=find(y);
    verList[u].head=new edgeNode(v,w,verList[u].head);//��ͷ�����룬һ�д���ʵ���������ܣ�1.����2.����߱�3.�Ľ����е�headָ��
    ++Edges;

}

//remove������ʵ��
template <class TypeOfVer,class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::remove(TypeOfVer x,TypeOfVer y)
{
    int u=find(x),v=find(y);
    edgeNode *p=verList[u].head,*q;

    if(p==NULL) return;//���uû�������ı�

    if(p->end==v)  //�������еĵ�һ�������Ǳ�ɾ���ı�
    {
        verList[u].head=p->next;
        delete p;
        --Edges;
        return;
    }

    while(p->next!=NULL&&p->next->end!=v) p=p->next;//���ұ�ɾ���ı�
    if(p->next!=NULL)//ɾ��
    {
        q=p->next;
        p->next=q->next;
        delete q;
        --Edges;
    }
}

//exist������ʵ��
template <class TypeOfVer,class TypeOfEdge>
bool adjListGraph<TypeOfVer,TypeOfEdge>::exist(TypeOfVer x,TypeOfVer y)const
{
    int u=find(x),v=find(y);
    edgeNode *p=verList[u].head;

    while(p->next!=NULL&&p->end!=v) p=p->next;//����

    if(p==NULL) return false;
    else return true;
}


//prim�㷨
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
cout<<"��������ʼ����"<<endl;
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
