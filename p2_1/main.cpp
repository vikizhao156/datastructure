#include <iostream>
#include "Huffman.h"
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stdio.h>
using namespace std;

void Init();        //初始化函数
void tips();        //提示函数
void encoding();    //
void decoding();
void codeprint();
void treeprint();

int n;
char str[53];
int weight[53];
int main()
{
  char select=1;

  while(select!='Q')
  {
      tips();
      cin>>select;
      switch (select)
    {
      case 'I':Init();break;
      case 'E':encoding();break;
      case 'D':decoding();break;
      case 'P':codeprint();break;
      case 'T':treeprint();break;

  }
  }
    return 0;

}

void Init()
{
     cin>>n;
     cout<<"请输入各字符权值，再输入各字符，最后一个权值与第一个字符间无需空格或回车作为分割"<<endl;
   for(int i=0;i<n;i++)
    cin>>weight[i];
    for (int i=0;i<n;i++)
        cin.get(str[i]);
    hfTree<char>tree(str,weight,n);
    hfTree<char>::hfCode result[n];
    tree.getCode(result);
   ofstream fout("hfmTree.txt");
 if (fout)
  { // 如果创建成功
    for (int i = 0; i < n; i++)
   {
    fout <<result[i].data<<" "; // 使用与cout同样的方式进行写入
   }
   fout<<endl;
      for (int i=0;i<n;i++)
    {
     fout<<result[i].code<<" ";
    }
  }
  fout.close();

}


void tips()
{
    cout<<"------------------------------------"<<endl;
    cout<<"--------------请选择操作------------"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"--------I-初始化Huffmantree---------"<<endl;
    cout<<"--------E-编码             ---------"<<endl;
    cout<<"--------D-解码             ---------"<<endl;
    cout<<"--------P-打印代码文件     ---------"<<endl;
    cout<<"--------T-打印Huffmantree  ---------"<<endl;
      cout<<"--------Q-退出             ---------"<<endl;
}

void encoding()
{
    hfTree<char>tree(str,weight,n);
    hfTree<char>::hfCode result[n];
    tree.getCode(result);
    ifstream fin("plainFile.txt");
    ofstream fout("codeFile.txt");
    char ch[1000];
    fin.getline(ch,1000);
    for(int i=0;i<strlen(ch);i++)
        for(int j=0;j<n;j++)
        if(result[j].data==ch[i])
        {fout<<result[j].code;
        break;}
        else continue;
    fout.close();

}

void decoding()
{
    int k;
    hfTree<char>tree(str,weight,n);
    hfTree<char>::hfCode result[n];
    tree.getCode(result);
     ifstream fin("codeFile.txt");
    ofstream fout("textFile.txt");
    char code[3000];
    fin>>code;
    for(int i=0;i<strlen(code);)
        for(int j=0;j<n;j++)
            {
            for(k=0;k<result[j].code.length();)
                if(code[i]==result[j].code[k])    //实现循环解码
                {
                    k++;i++;
                }
                else  break;
            if(k==result[j].code.length())
            {
                fout<<result[j].data;
            }
            else i=i-k;
            }
    fin.close();
    fout.close();

}

void codeprint()
{
   ifstream fin("codeFile.txt");
   ofstream fout("codeprint.txt");
   char code[300];
   fin>>code;
   for(int i=0;i<strlen(code);i++)
   {
       if((i+1)%50==0)   //五十格换一行
       {cout<<'\n';
       fout<<'\n';
       }
       cout<<code[i];
       fout<<code[i];
   }
   cout<<endl;
   fin.close();
   fout.close();
}

void treeprint()
{
    hfTree<char>tree(str,weight,n);
    hfTree<char>::hfCode result[n];
    tree.getCode(result);
    ofstream  fout("treeprint.txt");
    string temp;
    char temp1;
    int ceng=0;
    for (int i=0;i<n;i++)
        if(ceng<result[i].code.length()) ceng=result[i].code.length();//获得层数


    for(int j=0;j<n;j++)
    for(int i=0;i<n-1;i++)
    {
        if(result[i].code>result[i+1].code)
            {temp=result[i].code;
            temp1=result[i].data;
        result[i].code=result[i+1].code;
        result[i].data=result[i+1].data;         //根据长度与编码实现排序
        result[i+1].code=temp;
        result[i+1].data=temp1;
            }

    }
     for (int i=1;i<ceng+1;i++)
       {
           for(int k=0;k<n;k++)
               if(result[k].code.length()==i)
               {
                cout<<result[k].data<<"("<<result[k].code<<")"<<"    ";
                fout<<result[k].data<<"("<<result[k].code<<")"<<"    ";
                }  //依照层数写入文件
               cout<<endl;
               fout<<endl;

       }

     /*  int m=0;
       unsigned char T[100][100];
       ofstream fout("treeprint.txt");
       tree.convert_tree(T,0,&m,2*n-1);
       for(int i=1;i<=2*n-1;i++)
       {
           for(int j=0;T[i][j]!=0;j++)
           {
               if(T[i][j]==' '){fout<<" ";cout<<" ";}
               else {fout<<T[i][j]; cout<<T[i][j];}
           }
           cout<<endl;
       }
       fout.close();
     */
}

