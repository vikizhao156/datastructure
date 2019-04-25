#include <iostream>
#include "parking_lot_manage.h"

using namespace std;

void showMenu();
int main()
{
    char command='A';
    showMenu();
    CarSystem CAR;
    while (command!='E')
    {
        cin>>command;
        switch (command){
        case 'A':
            CAR.Arrival();
            CAR.Carstack();
            break;
        case 'D':
             CAR.Leave();
             CAR.Carstack();
             break;
        case 'C':
             CAR.ShowInfo();
             break;
        case 'Q':
              CAR.QueueCarLeave();
              CAR.Carqueue();
              break;
        case 'E':break;
        default: cout<<"输入不合乎规范";
        }
    }
    return 0;
}

void showMenu()
{
     cout << "********************************************" << endl;
    cout << "******              停 车 场 管 理 系 统                    ******" << endl;
    cout << "******       A:车辆到达车场，请输入车牌号和到达时间         ******" << endl;
    cout << "******       D:车辆离开车场，请输入车牌号和离开时间         ******" << endl;
    cout << "******       Q:车辆离开便道，请输入车牌号                   ******" << endl;
    cout << "******       C:查询功能                                     ******" << endl;
    cout << "******       E:退出程序                                     ******" << endl;
    cout << "\n\t\n\t\t请选择：";

}
