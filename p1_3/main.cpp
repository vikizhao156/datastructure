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
        default: cout<<"���벻�Ϻ��淶";
        }
    }
    return 0;
}

void showMenu()
{
     cout << "********************************************" << endl;
    cout << "******              ͣ �� �� �� �� ϵ ͳ                    ******" << endl;
    cout << "******       A:�������ﳵ���������복�ƺź͵���ʱ��         ******" << endl;
    cout << "******       D:�����뿪�����������복�ƺź��뿪ʱ��         ******" << endl;
    cout << "******       Q:�����뿪����������복�ƺ�                   ******" << endl;
    cout << "******       C:��ѯ����                                     ******" << endl;
    cout << "******       E:�˳�����                                     ******" << endl;
    cout << "\n\t\n\t\t��ѡ��";

}
