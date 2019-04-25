#include <iostream>
#include "parking_lot_manage.h"

using namespace std;

void CarSystem::Arrival()
{
    car *car1;
    QCarNode *car2;
    int time;
    int id;
   cin>>id>>time;
  car1=new car;
   car1->id=id;
   car1->reachtime=time;
    if(parking_lot->top<maxm)
    {
        parking_lot->top++;
        parking_lot->CarStack[parking_lot->top]=car1;
    }
    else
    {
       car2=new QCarNode;
       car2->data=car1;
       car2->next=NULL;
       waitQueue->rear->next=car2;
       waitQueue->rear=car2;
    }

}
void CarSystem::Leave()
{
    int id,time,item=-1;
    cin>>id>>time;
    car*p;
    QCarNode*q;
    for(int i=1;i<maxm+1;i++)
      if( parking_lot->CarStack[i]->id==id)
        item=i;

   if(parking_lot->top > 0)
   {
       while (parking_lot->top>item)
       {
           leaveLine->top++;
            leaveLine->CarStack[leaveLine->top] = parking_lot->CarStack[parking_lot->top];
            parking_lot->CarStack[parking_lot->top] = NULL;
            parking_lot->top--;
       }
       p=parking_lot->CarStack[parking_lot->top];
       parking_lot->CarStack[parking_lot->top] = NULL;
       parking_lot->top--;
        while(leaveLine->top>0)
        {
            parking_lot->top++;
            parking_lot->CarStack[parking_lot->top]=leaveLine->CarStack[leaveLine->top];
            leaveLine->CarStack[leaveLine->top]=NULL;
            leaveLine->top--;
        }
        //�����Ϣ
        charge(p,time);
        if(waitQueue->head!=waitQueue->rear&&parking_lot->top<maxm)
        {
            parking_lot->top++;
             parking_lot->CarStack[parking_lot->top]=waitQueue->head->next->data;
            parking_lot->CarStack[parking_lot->top]->reachtime=time;

            q=waitQueue->head->next;

            waitQueue->head->next=q->next;
             if(q==waitQueue->rear)
                waitQueue->rear=waitQueue->head;
            delete q;
        }
   }

        else cout<<"ͣ�����޳�";

}
void CarSystem::charge(car *p, int time)
{
  int chargemoney;
    p->lefttime=time;
    chargemoney=(p->lefttime-p->reachtime)*100;
    cout<<"\n-----------�ɷ���Ϣ----------"<<endl;
    cout<<"\n�ó��ĳ��ƺ�Ϊ"<<p->id<<endl;
    cout<<"\n�ó��ĵ���ʱ��Ϊ"<<p->reachtime<<endl;
    cout<<"\n�ó����뿪ʱ��Ϊ"<<p->lefttime<<endl;
    cout<<"\n�ó�Ӧ���ɷ���"<<chargemoney<<"Ԫ"<<endl;
    delete p;
}

CarSystem::CarSystem()
{
    parking_lot=new StackCar;
    parking_lot->top=0;
    parking_lot->CarStack[0]=NULL;

    leaveLine=new StackCar;
     leaveLine->top=0;
     leaveLine->CarStack[0]=NULL;

     waitQueue=new LinkQueueCar;
     waitQueue->head=new QCarNode;
     waitQueue->rear=waitQueue->head;

}



CarSystem::~CarSystem()
{
    QCarNode *p;

    int rec;
    while(parking_lot->top!=0)
       {
        rec=parking_lot->top;
        --parking_lot->top;
        delete parking_lot->CarStack[rec];
       };
       while (waitQueue->head!= waitQueue->rear)
    {
        p = waitQueue->head;
        waitQueue->head = waitQueue->head->next;
        delete p;
    }


}

void CarSystem::Carstack()     //������λ��ʾ
{
    int i;
    cout<<endl<<"----------ͣ������Ϣ����-------------";
    if (parking_lot->top>0)
    {

        cout << "\n��λ��\t" << "       ����ʱ��    \t" << "���ƺ�\n";
        for (i = 1; i <= parking_lot->top; i++)
        {
            cout << "  " << i << "         \t";
            cout <<parking_lot->CarStack[i]->reachtime<<"            \t"<< parking_lot->CarStack[i]->id;
            cout<<endl;
        }
    }
    else cout<<"\n�����޳�";
      cout<<"\n------------------------------------\n";
}


 void CarSystem::Carqueue()
 {
     QCarNode *p;
     p=waitQueue->head->next;
      cout<<endl<<"------------�����Ϣ����-------------"<<endl;
     if(waitQueue->head!=waitQueue->rear)
        {
            cout<<"��ͷ����ʾ���ƺţ�"<<endl;
            while(p!=NULL)
            {
                cout<<p->data->id<<endl;
                p=p->next;
            }
            cout<<"��β";
        }
        else cout<<"������޳�";
    cout<<"\n------------------------------------\n";

 }

 void CarSystem::QueueCarLeave()
 {
     int id;
     cin>>id;
     QCarNode *p,*q;
     if(waitQueue->head!=waitQueue->rear)
        {
            p=waitQueue->head->next;
            q=waitQueue->head;
            while(p->data->id!=id)
            {
            q = p;
            p = p->next;
            }
            q->next=p->next;
            cout<<"���ƺ�Ϊ"<<p->data->id<<"�ĳ������뿪���"<<endl;
            delete p;
        }
    else cout<<"������޳�"<<endl;
 }
void CarSystem::ShowInfo()
{
    char str;
    cout << "������鿴�б�:" << endl;
    cout << "---   1.ͣ������λ״��-->�밴 p     ---" << endl;
    cout << "---   2.���ͣ��λ״��-->�밴 q     ---" << endl;
    cout << "---   3.�������˵�    -->�밴 b   ---" << endl;
    cin>>str;
    switch(str){
    case 'p':Carstack();break;
    case 'q':Carqueue();break;
    case 'b':break;
    default:break;
    }

}

