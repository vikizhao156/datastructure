#include <iostream>
#include <cstring>
#include "bignum.h"

using namespace std;

Longlongint::Longlongint(const char *n)
{
    char *temp;
    switch (n[0]){
       case '+':sign='+';break;      //符号位定义
       case '-':sign='-';break;
       default:sign='+';
    }
    int len1;
    if (n[0]=='+'||n[0]=='-')
        len1=strlen(n)-1;
    else
        len1=strlen(n);
    temp=new char[len1+1];

    if (n[0]=='+'||n[0]=='-')
       for(int i=0;i<len1;i++)
    {
        temp[i]=n[i+1];                //除符号
    }
    else
        for(int i=0;i<len1;i++)
    {
        temp[i]=n[i];
    }
    temp[len1]='\0';
    for(int i=0;i<len1;i++)
        {
            if(temp[i]==',')
                for(int j=i;j<len1+1;j++)   //消除','
                temp[j]=temp[j+1];
        }
    if(strcmp(temp,"0")==0) temp="";      //特殊情况，若temp=0，直接附空字符串值
    int len=strlen(temp);

    num=new char[len+1];
    for(int i=0;i<len;i++) num[len-i-1]=temp[i];  //用数组倒序存储数字
    num[len]='\0';
    delete temp;
}

Longlongint::Longlongint(const Longlongint &other)
{
    sign=other.sign;
    num=new char [strlen(other.num)+1];
    strcpy(num,other.num);             //拷贝构造

}
Longlongint&Longlongint::operator=(const Longlongint &right)
{
    if(this==&right) return *this;

    delete num;
    sign=right.sign;
    num=new char[strlen(right.num)+1];
    strcpy(num,right.num);          //赋值 包括符号赋值及字符串赋值
    return *this;
}
ostream &operator<<(ostream &os,const Longlongint &obj)
{
    char *temp;
    int dounum=strlen(obj.num)/4-1;  //输出增加的','数目
   int k=0,pause=0;
    if(strlen(obj.num)==0) os<<0;
    else{
        if(obj.sign=='-')
        os<<obj.sign;
         temp=new char[dounum+strlen(obj.num)+1];
       for(int j=0;j<strlen(obj.num);j++)
        {
            temp[j+k]=obj.num[j];
            pause++;
            if(pause==4)//每四位加一个‘，’
            {
                k++;
                temp[j+k]=',';
                pause=0;
            }
        }
        temp[dounum+strlen(obj.num)+1]='\0';
        if(temp[strlen(temp)-1]==',') temp[strlen(temp)-1]='\0';//消除首位‘，’
        for(int i=strlen(temp)-1;i>=0;--i) os<<temp[i];
        delete temp;                                       //输出增加'，'
    }
    return os;
}
Longlongint operator+(const Longlongint&n1,const Longlongint &n2)
{
    Longlongint n;
    delete n.num;
    if(n1.sign==n2.sign){
        n.sign=n1.sign;
        n.num=add(n1.num,n2.num);  //若符号相同，直接将n1数字与n2数字相加
    }
    else if(greaterr(n1.num,n2.num)){
        n.sign=n1.sign;
        n.num=sub(n1.num,n2.num);  //若符号不同 则用绝对值大的数减去绝对值小的数
    }
    else{
        n.sign=n2.sign;
        n.num=sub(n2.num,n1.num);
    }
    return n;
}
Longlongint operator-(const Longlongint&n1,const Longlongint &n2)
{
    Longlongint n(n2);
    if(n.sign=='+') n.sign='-';
    else n.sign='+';

    return n1+n;   //改变减数符号 利用加法完成
}

char *add(const char*s1,const char*s2)//绝对值相加函数
{
    int len1=strlen(s1);
    int len2=strlen(s2);
    int minLen=(len1>len2?len2:len1);
    int len=(len1>len2?len1:len2)+1;  //相加后字符串的长度
    int carry=0,result;  //carry模拟进位
    int i=0;
    char *num=new char [len+1];
    for( i=0;i<minLen;i++)  //对都存在的位数，模拟手动相加进位
    {
        result=s1[i]-'0'+s2[i]-'0'+carry;
        num[i]=result%10+'0';   //取本位结果
        carry=result/10;        //进位
    }
    while(i<len1){
        result=s1[i]-'0'+carry;  //对S1或S2都存在的位数，直接补充至和上
        num[i]=result%10+'0';
        carry=result/10;
        ++i;

    }
      while(i<len2){
        result=s2[i]-'0'+carry;
        num[i]=result%10+'0';
        carry=result/10;
        ++i;

    }
    if(carry!=0) num[i++]=carry+'0';//最高进位
    num[i]='\0';
    return num;

}

char *sub(const char*s1,const char*s2)
{
    if(!strcmp(s1,s2)) return "";
    int len1=strlen(s1);
    int len2=strlen(s2);
    int minus=0; //借位记录
    int i=0;
    char *tmp=new char [len1+1];

    for( i=0;i<len2;++i)
    {
        tmp[i]=s1[i]-s2[i]-minus;
        if(tmp[i]<0){tmp[i]+=10;minus=1;}
        else {minus=0;}
        tmp[i]+='0';
    }
    while (i<len1)
    {
        tmp[i]=s1[i]-'0'-minus;
        if(tmp[i]<0){tmp[i]+=10;minus=1;}
        else minus=0;
        tmp[i]+='0';
        ++i;
    }
    do{
        --i;
    }while(i>=0&&tmp[i]=='0');

    tmp[i+1]='\0';
    return tmp;

}
bool greaterr(const char *s1,const char *s2)
{
    int len1=strlen(s1),len2=strlen(s2);
    if(len1>len2) return true;
    else if(len1<len2) return false;   //s1长度长于s2长度 则s1>s2；

    for (int i=len1-1;i>=0;--i)
    {
        if(s1[i]>s2[i]) return true;  //s1高位大 返回true
        else if(s1[i]<s2[i]) return false;
    }

    return false;
}

