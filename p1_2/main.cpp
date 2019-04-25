#include "Node.h"
#include <iostream>

Node* create(int n);               //创建列表

Node* add(Node*exp1,Node* exp2);   //加法函数

void  view(Node*exp);              //输出函数

void clear_list(Node*exp);         //清理函数

Node* sub(Node*exp1,Node* exp2);   //减法函数

Node* der(Node*exp1);              //导数函数

Node* multi(Node*exp1,Node* exp2); //乘法函数

int main()
{

    Node* exp1,*exp2,*exp3,*exp4,*exp5,*exp6;
    Node* tmp;
    int n1;
    int n2;
    cin>>n1;
    exp1=create(n1);
    cin>>n2;
    exp2=create(n2);

    exp3=add(exp1,exp2);
   // exp4=sub(exp1,exp2);
   // exp5=multi(exp1,exp2);
   // exp6=der(exp1);
    //view(exp3);cout<<"  ";
    //view(exp4);cout<<"  ";
    //view(exp5);cout<<"  ";
    view(exp3);
    clear_list(exp1);
    clear_list(exp2);
     clear_list(exp3);
     clear_list(exp4);
     clear_list(exp5);
     clear_list(exp6);


    return 0;
}

