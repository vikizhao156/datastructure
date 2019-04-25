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
        //输出信息
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

        else cout<<"停车场无车";

}
void CarSystem::charge(car *p, int time)
{
  int chargemoney;
    p->lefttime=time;
    chargemoney=(p->lefttime-p->reachtime)*100;
    cout<<"\n-----------缴费信息----------"<<endl;
    cout<<"\n该车的车牌号为"<<p->id<<endl;
    cout<<"\n该车的到达时间为"<<p->reachtime<<endl;
    cout<<"\n该车的离开时间为"<<p->lefttime<<endl;
    cout<<"\n该车应缴纳费用"<<chargemoney<<"元"<<endl;
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

void CarSystem::Carstack()     //车场车位显示
{
    int i;
    cout<<endl<<"----------停车场信息更新-------------";
    if (parking_lot->top>0)
    {

        cout << "\n车位号\t" << "       到达时间    \t" << "车牌号\n";
        for (i = 1; i <= parking_lot->top; i++)
        {
            cout << "  " << i << "         \t";
            cout <<parking_lot->CarStack[i]->reachtime<<"            \t"<< parking_lot->CarStack[i]->id;
            cout<<endl;
        }
    }
    else cout<<"\n车场无车";
      cout<<"\n------------------------------------\n";
}


 void CarSystem::Carqueue()
 {
     QCarNode *p;
     p=waitQueue->head->next;
      cout<<endl<<"------------便道信息更新-------------"<<endl;
     if(waitQueue->head!=waitQueue->rear)
        {
            cout<<"队头（显示车牌号）"<<endl;
            while(p!=NULL)
            {
                cout<<p->data->id<<endl;
                p=p->next;
            }
            cout<<"队尾";
        }
        else cout<<"便道中无车";
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
            cout<<"车牌号为"<<p->data->id<<"的车辆已离开便道"<<endl;
            delete p;
        }
    else cout<<"便道中无车"<<endl;
 }
void CarSystem::ShowInfo()
{
    char str;
    cout << "请输入查看列表:" << endl;
    cout << "---   1.停车场车位状况-->请按 p     ---" << endl;
    cout << "---   2.便道停车位状况-->请按 q     ---" << endl;
    cout << "---   3.返回主菜单    -->请按 b   ---" << endl;
    cin>>str;
    switch(str){
    case 'p':Carstack();break;
    case 'q':Carqueue();break;
    case 'b':break;
    default:break;
    }

}

