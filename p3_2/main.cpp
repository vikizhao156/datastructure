#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

struct Score
{
    int key[7];   //1-6Ϊ��Ŀ 0Ϊ�ܷ�
     Score *next;
};

void PrintScore(Score *L);    //��ӡ����
Score* createdata();          //�ɼ������ɺ���
Score* BubbleSort(Score *L,int a[]);//������
void clearscore(Score *L);  //�ͷſռ�
int n;                     //��������
int main()
{

   Score *L,*q;
   int a[7];
   a[0]=0;
   double time;
   cout<<"�����뵥�����ȴ���"<<endl;
   for(int i=1;i<7;i++)
   {
       cin>>a[i];
   }

   L=createdata();
   BubbleSort(L,a);
   cout<<endl;
   cout<<"�����Ĵ���Ϊ"<<endl;
   cout<<setw(8)<<"�ܷ�"<<setw(8)<<"��Ŀ1"<<setw(8)<<"��Ŀ2"<<setw(8)<<"��Ŀ3"<<setw(8)<<"��Ŀ4"<<setw(8)<<"��Ŀ5"<<setw(8)<<"��Ŀ6"<<endl;
   PrintScore(L);
   clearscore(L);

    return 0;
}

Score* createdata()
{
    Score*p,*q,*head;

    p=head=new Score;
   /* cout<<p<<endl;
    cout<<L->next<<endl;*/
    srand(time(0));//����
    cout<<"������������Ҫ�����ݸ�����һ��ѧ����Ϊһ������"<<endl;
    cin>>n;
    cout<<setw(8)<<"�ܷ�"<<setw(8)<<"��Ŀ1"<<setw(8)<<"��Ŀ2"<<setw(8)<<"��Ŀ3"<<setw(8)<<"��Ŀ4"<<setw(8)<<"��Ŀ5"<<setw(8)<<"��Ŀ6"<<endl;
    for(int i=0;i<n;i++)
    {
         p=p->next=new Score;
        //p=new Score;
        p->key[0]=0;
        for (int j=1;j<7;j++)
          {
            p->key[j]=rand()%101;//����0~100�������
            p->key[0]=p->key[0]+p->key[j];
          }
           for(int k=0;k<7;k++)
       {
           cout<<setw(8)<<p->key[k];
       }
       cout<<endl;

    }
    p->next=NULL;


    return head;

}
void clearscore(Score *L)
{
    Score *p,*temp;
    p=L->next;
    while(p!=NULL)
  {
      temp=p;
    p=p->next;
    delete temp;
  }
    L->next=NULL;
}
Score* BubbleSort(Score *L,int a[])
{
    Score *p;
    int temp=0;
    p=L->next;
//����ʵ��
       for (int k=0;k<n;k++)
        {
            while(p->next!=NULL)
           {
               if(p->key[a[0]]<p->next->key[a[0]])//�ܷ�����
            {
                for(int j=0;j<7;j++)
         {
             temp=p->key[j];
             p->key[j]=p->next->key[j];
             p->next->key[j]=temp;
         }
          p=p->next;
        }
        else if(p->key[a[0]]==p->next->key[a[0]]&&p->key[a[1]]<p->next->key[a[1]])//���ȼ���ߵĿ�Ŀ����
            {
                for(int j=0;j<7;j++)
         {
             temp=p->key[j];
             p->key[j]=p->next->key[j];
             p->next->key[j]=temp;
         }
          p=p->next;
        }
        else if(p->key[a[0]]==p->next->key[a[0]]&&p->key[a[1]]==p->next->key[a[1]]&&p->key[a[2]]<p->next->key[a[2]])
            {
                for(int j=0;j<7;j++)
         {
             temp=p->key[j];
             p->key[j]=p->next->key[j];
             p->next->key[j]=temp;
         }
          p=p->next;
        }
         else if(p->key[a[0]]==p->next->key[a[0]]&&p->key[a[1]]==p->next->key[a[1]]&&p->key[a[2]]==p->next->key[a[2]]&&p->key[a[3]]<p->next->key[a[3]])
            {
                for(int j=0;j<7;j++)
         {
             temp=p->key[j];
             p->key[j]=p->next->key[j];
             p->next->key[j]=temp;
         }
          p=p->next;
        }
        else if(p->key[a[0]]==p->next->key[a[0]]&&p->key[a[1]]==p->next->key[a[1]]&&p->key[a[2]]==p->next->key[a[2]]&&p->key[a[3]]==p->next->key[a[3]]&&p->key[a[4]]<p->next->key[a[4]])
            {
                for(int j=0;j<7;j++)
         {
             temp=p->key[j];
             p->key[j]=p->next->key[j];
             p->next->key[j]=temp;
         }
          p=p->next;
        }
        else if(p->key[a[0]]==p->next->key[a[0]]&&p->key[a[1]]==p->next->key[a[1]]&&p->key[a[2]]==p->next->key[a[2]]&&p->key[a[3]]==p->next->key[a[3]]&&p->key[a[4]]==p->next->key[a[4]]&&p->key[a[5]]<p->next->key[a[5]])
            {
                for(int j=0;j<7;j++)
         {
             temp=p->key[j];
             p->key[j]=p->next->key[j];
             p->next->key[j]=temp;
         }
          p=p->next;
        }
        else if(p->key[a[0]]==p->next->key[a[0]]&&p->key[a[1]]==p->next->key[a[1]]&&p->key[a[2]]==p->next->key[a[2]]&&p->key[a[3]]==p->next->key[a[3]]&&p->key[a[4]]==p->next->key[a[4]]&&p->key[a[5]]==p->next->key[a[5]]&&p->key[a[6]]<p->next->key[a[6]])
            {
                for(int j=0;j<7;j++)
         {
             temp=p->key[j];
             p->key[j]=p->next->key[j];
             p->next->key[j]=temp;
         }
          p=p->next;
        }
        else  p=p->next;

           }
           p=L->next;
        }
       return L;
}

void PrintScore(Score *L)
{
    Score *q;
    q=L->next;
while(q)
   {
       for(int k=0;k<7;k++)
    {
           cout<<setw(8)<<q->key[k];
       }
       cout<<endl;
       q=q->next;
   }
}
