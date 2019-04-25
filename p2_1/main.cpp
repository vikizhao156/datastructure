#include <iostream>
#include "Huffman.h"
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stdio.h>
using namespace std;

void Init();        //��ʼ������
void tips();        //��ʾ����
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
     cout<<"��������ַ�Ȩֵ����������ַ������һ��Ȩֵ���һ���ַ�������ո��س���Ϊ�ָ�"<<endl;
   for(int i=0;i<n;i++)
    cin>>weight[i];
    for (int i=0;i<n;i++)
        cin.get(str[i]);
    hfTree<char>tree(str,weight,n);
    hfTree<char>::hfCode result[n];
    tree.getCode(result);
   ofstream fout("hfmTree.txt");
 if (fout)
  { // ��������ɹ�
    for (int i = 0; i < n; i++)
   {
    fout <<result[i].data<<" "; // ʹ����coutͬ���ķ�ʽ����д��
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
    cout<<"--------------��ѡ�����------------"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"--------I-��ʼ��Huffmantree---------"<<endl;
    cout<<"--------E-����             ---------"<<endl;
    cout<<"--------D-����             ---------"<<endl;
    cout<<"--------P-��ӡ�����ļ�     ---------"<<endl;
    cout<<"--------T-��ӡHuffmantree  ---------"<<endl;
      cout<<"--------Q-�˳�             ---------"<<endl;
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
                if(code[i]==result[j].code[k])    //ʵ��ѭ������
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
       if((i+1)%50==0)   //��ʮ��һ��
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
        if(ceng<result[i].code.length()) ceng=result[i].code.length();//��ò���


    for(int j=0;j<n;j++)
    for(int i=0;i<n-1;i++)
    {
        if(result[i].code>result[i+1].code)
            {temp=result[i].code;
            temp1=result[i].data;
        result[i].code=result[i+1].code;
        result[i].data=result[i+1].data;         //���ݳ��������ʵ������
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
                }  //���ղ���д���ļ�
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

