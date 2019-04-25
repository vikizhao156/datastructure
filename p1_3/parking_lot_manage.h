#ifndef parking_lot_manage_h
#define parking_lot_manage_h

#include <iostream>

using namespace std;

#define maxm 2
struct car // �����ṹ��
{
    int id;
    int reachtime;
    int lefttime;
};

struct StackCar   //ͣ����ջ
{
    int top;
    car *CarStack[maxm + 1];
};
struct QCarNode   //�����е��������ṹ��
{
    car *data;    //������Ϣ
    QCarNode *next;
};
struct LinkQueueCar  //���
{
    QCarNode *head;   //��ͷָ��
    QCarNode *rear;    //��βָ��
};
class CarSystem{
    StackCar *parking_lot, *leaveLine;   //ͣ����ջ��������ͣ����ʱ����ʱջ
    LinkQueueCar *waitQueue;    //���
public:
    CarSystem();      //���캯��
    ~CarSystem();           //��������
    void Arrival();          //������վ
    void Leave();            //������վ
    void charge(car *p,int time);   //�뿪�����ɷ������Ϣ
    void ShowInfo();   //��ʾ��λ���
    void Carstack();   //ͣ�����г�λ״��
    void Carqueue();    //����г�λ״��
    void QueueCarLeave();   //����г����뿪
};

#endif
