#include "Node.h"
#include <iostream>

Node* create(int n);               //�����б�

Node* add(Node*exp1,Node* exp2);   //�ӷ�����

void  view(Node*exp);              //�������

void clear_list(Node*exp);         //������

Node* sub(Node*exp1,Node* exp2);   //��������

Node* der(Node*exp1);              //��������

Node* multi(Node*exp1,Node* exp2); //�˷�����

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

