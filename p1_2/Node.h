#ifndef node_h
#define node_h

#include <iostream>

using namespace std;

class Node   //结点类
{
    public:
      double coef;  //各项系数
      int exp;      //各项指数

      Node *next;
      Node(){next=NULL;} //默认构造函数
      Node(double n1,int n2,Node*p=NULL):coef(n1),exp(n2),next(p){}

};

#endif
