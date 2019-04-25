#ifndef PAIXU_H
#define PAIXU_H

# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <ctime>
# include <iomanip>

# define N 1000
# define SR 100000

using namespace std;
int A[N],B[N],C[N],D[N],E[N],F[N],G[N],H[N];
int change(int *a,int *b);
void BubbleSort(int a[],int n);           //a1 aa
void simpleInsert(int a[],int n);         //b,bb
void simpleSelect(int a[],int n);         //c cc
void quicksort(int a[],int low,int high); //d dd
void quicksort(int a[],int n);
int divide(int a[],int low,int high);
void shellsort(int a[],int n);           //e ee
void heapSort(int a[],int n);            //f ff
void percolateDown(int a[],int hole,int n);
void mergeSort(int a[],int left,int right);
void merge(int a[],int left,int mid,int right);
void mergeSort(int a[],int n);        //g gg
void insertSortHalf(int a[],int n);   //h hh
void fanBubbleSort(int a[],int n);
void total_ram();
void zhengxu();
void fanxu();
int a1=0,aa=0,b=0,bb=0,c=0,cc=0,d=0,dd=0,e=0,ee=0,f=0,ff=0,g=0,gg=0,h=0,hh=0;
#endif // PAIXU_H
