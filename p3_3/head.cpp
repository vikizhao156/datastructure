#include "head.h"

#include <cstring>
#include <iostream>
//线性探测法插入
void cht::insertx(const set &x,int &cnt)
{
    int init,pos;
    init=pos=x.key%size;
    do
    {
        if(names[pos].state!=1)
        {
            names[pos].data=x;
            names[pos].state=1;
            ++cnt;
            return;
        }
        pos=(pos+1)%size;
        ++cnt;
    }while(pos!=init);
}
 
//二次探测法插入
void cht::inserte(const set &x,int &cnt)
{
    int init,pos,n=1;
    init=pos=x.key%size;
    do
    {
        if(names[pos].state!=1)
        {
            names[pos].data=x;
            names[pos].state=1;
            ++cnt;
            return;
        }
        pos=init+n*n;
        while(pos>size-1)
        {
            pos-=size;
        }
        ++cnt;
        ++n;
    }while(pos!=init);
}
 
//调用inserte，并输出平均查找长度和排序后的表
void cht::createhashe(set namelist[])
{
    int cnt=0;
    for(int i=0;i<size;++i)
    {
        inserte(namelist[i],cnt);
    }
    cout<<"二次探测法平均查找长度为"<<cnt/size;
    cout<<"，用该方法建立的哈希表为：\n";
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<strlen(names[i].data.name);++j)
        {
            cout<<names[i].data.name[j];
        }
        cout<<endl;
    }
   
}
 
//调用insertx，并输出平均查找长度和排序后的表
void cht::createhashx(set namelist[])
{
    int cnt=0;
    for(int i=0;i<size;++i)
    {
        insertx(namelist[i],cnt);
    }
    cout<<"线性探测法平均查找长度为"<<cnt/size;
    cout<<"，用该方法建立的哈希表为：\n";
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<strlen(names[i].data.name);++j)
        {
            cout<<names[i].data.name[j];
        }
        cout<<endl;
    }
}
 
//创建原始姓名表及其关键字值
void createlist(char a[],int i,set namelist[])
{
    int len=strlen(a),j=0;
    namelist[i].name=new char [len];
    namelist[i].key=0;
    while(j<len)
    {
        namelist[i].name[j]=a[j];
        namelist[i].key+=1+a[j]-'a';//姓名对应的key计算方法：姓名中的a对应1，b对应2，以此类推
        ++j;
    }
}
 
//提示用户输入姓名，调用createlist
void createnewlist(set namelist[])
{
    cout<<"请输入三十个人名（全部为小写拼音，如zhangsan）：\n";
    for(int i=0;i<30;++i)
    {
        char nam[20];
        cout<<"请输入第"<<i+1<<"个人名：";
        char ch;
        int j=0;
        ch=cin.get();
        while(ch!='\n')
        {
            nam[j]=ch;
            ch=cin.get();
            j++;
        }
        if(ch=='\n')
        {
            nam[j]='\0';
        }
        createlist(nam,i,namelist);
    }
}
 
//state均变为0，方便后续使用二次探测法
void cht::clear()
{
    for(int i=0;i<size;++i)
    {
        names[i].state=0;
    }
}
 
