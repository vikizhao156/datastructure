#ifndef parking_lot_manage_h
#define parking_lot_manage_h

#include <iostream>

using namespace std;

#define maxm 2
struct car // 车辆结构体
{
    int id;
    int reachtime;
    int lefttime;
};

struct StackCar   //停车场栈
{
    int top;
    car *CarStack[maxm + 1];
};
struct QCarNode   //链队中的汽车结点结构体
{
    car *data;    //汽车信息
    QCarNode *next;
};
struct LinkQueueCar  //便道
{
    QCarNode *head;   //对头指针
    QCarNode *rear;    //队尾指针
};
class CarSystem{
    StackCar *parking_lot, *leaveLine;   //停车场栈，车辆出停车场时的临时栈
    LinkQueueCar *waitQueue;    //便道
public:
    CarSystem();      //构造函数
    ~CarSystem();           //析构函数
    void Arrival();          //车辆进站
    void Leave();            //车辆出站
    void charge(car *p,int time);   //离开车辆缴费相关信息
    void ShowInfo();   //显示车位情况
    void Carstack();   //停车场中车位状况
    void Carqueue();    //便道中车位状况
    void QueueCarLeave();   //便道中车辆离开
};

#endif
