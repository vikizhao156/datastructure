#include <iostream>
#include <ctime>
#include <cstdlib>
#include "head.h"
using namespace std;

int main()
{
  //手动输入模块
    char s[31];
    char str1,str2;
    int weight,len;
    cout<<"please input the points(example:abcdefg)"<<endl;
    cin>>s;
     adjListGraph<char,int> g(strlen(s),s);
    cout<<"please input the number of edges "<<endl;
    cin>>len;
    srand(time(0));
 for(int i=0;i<len;i++)
    {
        cout<<"please insert the edges :point1 point2 (example: a b )"<<endl;
        cin>>str1>>str2;
        weight=rand()%100;
        g.insert(str1,str2,weight);
        g.insert(str2,str1,weight);
    }
    g.prim(100);
//测试数据
/*
adjListGraph<char,int> g(8,"abcdefgh");
g.insert('a','b',4);
 g.insert('a','c',3);
 g.insert('b','c',5);
 g.insert('b','d',5);
 g.insert('b','e',9);
 g.insert('c','d',5);
 g.insert('c','h',5);
 g.insert('d','e',7);
 g.insert('d','f',6);
 g.insert('d','g',5);
 g.insert('d','h',4);
 g.insert('e','f',3);
 g.insert('f','g',2);
 g.insert('g','h',6);
 g.insert('b','a',4);
 g.insert('c','a',3);
 g.insert('c','b',5);
 g.insert('d','b',5);
 g.insert('e','b',9);
 g.insert('d','c',5);
 g.insert('h','c',5);
 g.insert('e','d',7);
 g.insert('f','d',6);
 g.insert('g','d',5);
 g.insert('h','d',4);
 g.insert('f','e',3);
 g.insert('g','f',2);
 g.insert('h','g',6);
 g.prim(100);*/



    return 0;
}
