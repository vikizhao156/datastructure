#ifndef node_h
#define node_h

#include <iostream>

using namespace std;

class Node   //�����
{
    public:
      double coef;  //����ϵ��
      int exp;      //����ָ��

      Node *next;
      Node(){next=NULL;} //Ĭ�Ϲ��캯��
      Node(double n1,int n2,Node*p=NULL):coef(n1),exp(n2),next(p){}

};

#endif
