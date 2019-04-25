#include "Node.h"
#include <iostream>


Node* create(int n)       //输入数据 构建链表
{
    Node*p ,*res,*q;
    double coef=1;
    int expn;
    q=res=p=new Node;

   for(int i=1;i<n+1;i++)
     {
       p->next=new Node;
       p=p->next;
       cin>>coef>>expn;
        p->coef=coef;
        p->exp=expn;

       }
       p->next=NULL;
        //检索同类项并合并
       for(p=res->next;p!=NULL;p=p->next)
        for(q=p->next;q!=NULL;q=q->next)
       {
           if(p->exp==q->exp)
           {p->coef=p->coef+q->coef;
            p->next=q->next;
            delete q;
            q=p;
           }

       }

    return res;

};
Node* add(Node*exp1,Node* exp2)  //链表加法
{
    Node *res,*p,*tmp;

    res=p=new Node() ;

    exp1=exp1->next;
    exp2=exp2->next;
    while(exp1!=NULL&&exp2!=NULL){
        if((exp1->exp==exp2->exp)&&(exp1->coef+exp2->coef==0))
            {exp1=exp1->next;
            exp2=exp2->next;
            }
        else if(exp1->coef==0&&exp1->exp==0) exp1=exp1->next;
        else if(exp2->coef==0&&exp2->exp==0) exp2=exp2->next;

        else
       {
           if(exp1->exp<exp2->exp)
        {
            p->next=new Node(exp1->coef,exp1->exp);
            exp1=exp1->next;
        }
        else if(exp1->exp>exp2->exp){
            p->next=new Node(exp2->coef,exp2->exp);
            exp2=exp2->next;
        }
        else if (exp1->coef+exp2->coef!=0)
            {p->next=new Node(exp1->coef+exp2->coef,exp2->exp);
            exp1=exp1->next;
            exp2=exp2->next;}

            p=p->next;
       }
    }
    if(exp1==NULL) tmp=exp2;
    else tmp=exp1;
    while (tmp!=NULL){
        p->next=new Node(tmp->coef,tmp->exp);
        tmp=tmp->next;
        p=p->next;
    }

    return res;
};

void  view(Node*p1)    //排序，打印
{
     Node*p,*q;
     q=p=p1->next;
     int expn1;
     double coef1;
      //冒泡排序
       for(p = p1 -> next; p != NULL; p = p -> next)
          for(q = p -> next; q != NULL; q = q -> next)
               if((p->exp) < (q -> exp)){
                   int s = q -> exp; q -> exp = p -> exp; p -> exp = s;
                   double z = q->coef;q->coef=p->coef;p->coef=z;}

       p=p1->next;
    while (p!=NULL)
         {
            if(p->exp!=0&&p->exp!=1&&p->coef!=1&&p->coef!=-1)
             cout<<p->coef<<"x^"<<p->exp;
             else if(p-> exp==0&&p->coef!=0) cout<<p->coef;
             else if((p->exp==1)&&(p->coef!=1)&&(p->coef!=- 1)) cout<<p->coef<<"x";
             else if(p->coef==1&&p->exp!=1) cout<<"x^"<<p->exp;
             else if(p->coef==1&&p->exp==1) cout<<"x";
             else if(p->coef==-1&&p->exp!=1) cout<<"-x^"<<p->exp;
             else if(p->coef==-1&&p->exp==1) cout<<"-x";
             // a little bug
             p=p->next;
             if (p&&p->coef>0)
                cout<<"+";
         }
      if((p1->next==NULL)||(p1->next->next==NULL&&p1->next->coef==0)) cout<<0;
}


void clear_list(Node*exp)   //释放空间
{
     Node*tmp;

     while(exp)
    {

        tmp=exp->next;
        delete exp;
        exp=tmp;
    }
}

Node* sub(Node*exp1,Node* exp2)    //减法函数
{
  Node*p,*res,*q;

  double coef=1;
    int expn;
    res=p=new Node;

   for(q=exp2->next;q!=NULL;q=q->next)
     {
       p->next=new Node;
       p=p->next;
        p->coef=-q->coef;
        p->exp=q->exp;

       }
       p->next=NULL;
   p= add(exp1,res);
   clear_list(res);
   return p;

}
Node* der(Node*exp1)
{
    Node*p,*res,*q,*tmp;

  double coef=1;
    int expn;
    res=p=new Node;

   for(q=exp1->next;q!=NULL;q=q->next)
     {
       p->next=new Node;
       p=p->next;
        p->coef=q->coef;
        p->exp=q->exp;
      }
      p->next=NULL;
    for(p=res->next;p!=NULL;p=p->next)
    {
        if(p->exp!=0)
            {
            p->coef=p->coef*p->exp;
            p->exp=p->exp-1;
            }
        else {

            p->coef=0;
            p->exp=0;

        }
    }
    return res;
}
Node* multi(Node*exp1,Node* exp2)
{
    Node *res,*p,*q,*tmp1,*tmp2;
    res=p=new Node();
    for(tmp1=exp1->next;tmp1!=NULL;tmp1=tmp1->next)
    {
        if(tmp1->coef!=0)
        for(tmp2=exp2->next;tmp2!=NULL;tmp2=tmp2->next)
        {
        if(tmp2->coef!=0)
         {
             p->next=new Node;
          p=p->next;
          p->coef=tmp1->coef*tmp2->coef;
          p->exp=tmp1->exp+tmp2->exp;
         }
        else continue;
        }
        else continue;
    }
    for(p=res->next;p!=NULL;p=p->next)
     for(q=p->next;q!=NULL;q=q->next)
       {
           if(p->exp==q->exp)
           {p->coef=p->coef+q->coef;
            p->next=q->next;
            delete q;
            q=p;
           }

       }
    return res;
}

