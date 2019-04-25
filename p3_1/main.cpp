# include "paixu.h"

using namespace std;

int main()
{
    int i=0,num=N,case1=0;
    srand(time(0));
   total_ram();
   zhengxu();
   fanxu();

    return 0;
}


void zhengxu()
{
    int i=0,case1=0,num=N;

   cout<<endl<<"------------------数据为正序--------------------";
    for (case1=0;case1<5;case1++)
  {
      for(i=0;i<num;i++)
      {
        A[i]=B[i]=C[i]=D[i]=E[i]=F[i]=G[i]=H[i]=rand()%SR;
      }
    /*  for(i=0;i<num;i++)
      {
        cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<" "<<D[i]<<" "<<F[i]<<" "<<G[i]<<" "<<H[i]<<endl;
      }*/
      quicksort(A,num);quicksort(B,num);quicksort(C,num);quicksort(D,num);quicksort(E,num);quicksort(F,num);quicksort(G,num);quicksort(H,num);
      cout<<endl<<"case"<<case1+1<<":"<<endl;
      BubbleSort(A,num);
      cout<<endl<<"BubbleSort:"<<"compare times"<<a1<<"   movetimes"<<aa;
      simpleInsert(B,num);
       cout<<endl<<"simpleInsert:"<<"compare times"<<b<<"   movetimes"<<bb;
        simpleSelect(C,num);
       cout<<endl<<"simpleSelect:"<<"compare times"<<c<<"   movetimes"<<cc;
            quicksort(D,num);
       cout<<endl<<"quicksort:"<<"compare times"<<d<<"   movetimes"<<dd;
            shellsort(E,num);
       cout<<endl<<"shellsort:"<<"compare times"<<e<<"   movetimes"<<ee;
             heapSort(F,num);
       cout<<endl<<"heapSort:"<<"compare times"<<f<<"   movetimes"<<ff;
             mergeSort(G,num);
       cout<<endl<<"mergeSort:"<<"compare times"<<g<<"   movetimes"<<gg;
         insertSortHalf(H,num);
       cout<<endl<<"insertSortHalf:"<<"compare times"<<h<<"   movetimes"<<hh;
       a1=0;d=0;dd=0;e=0;ee=0;
       aa=0;b=0;bb=0;c=0;cc=0;
       g=0;gg=0;f=0;ff=0;
       h=0;hh=0;
     /* for(i=0;i<num;i++)
      {
        cout<<endl<<A[i]<<" "<<B[i]<<" "<<C[i]<<" "<<D[i]<<" "<<F[i]<<" "<<G[i]<<" "<<H[i];
      }*/
 }
     cout<<endl<<"------------------------------------------";
}

void fanxu()
{
   int case1=0,i=0,num=N;
     cout<<endl<<"-----------------数据为逆序---------------------";
     for (case1=0;case1<5;case1++)
  {
      for(i=0;i<num;i++)
      {
        A[i]=B[i]=C[i]=D[i]=E[i]=F[i]=G[i]=H[i]=rand()%SR;
      }
    /*  for(i=0;i<num;i++)
      {
        cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<" "<<D[i]<<" "<<F[i]<<" "<<G[i]<<" "<<H[i]<<endl;
      }*/
      fanBubbleSort(A,num);
      fanBubbleSort(B,num);
      fanBubbleSort(C,num);
      fanBubbleSort(D,num);
      fanBubbleSort(E,num);
      fanBubbleSort(F,num);
      fanBubbleSort(G,num);
      fanBubbleSort(H,num);
      cout<<endl<<"case"<<case1+1<<":"<<endl;
      BubbleSort(A,num);
      cout<<endl<<"BubbleSort:"<<"compare times"<<a1<<"   movetimes"<<aa;
      simpleInsert(B,num);
       cout<<endl<<"simpleInsert:"<<"compare times"<<b<<"   movetimes"<<bb;
        simpleSelect(C,num);
       cout<<endl<<"simpleSelect:"<<"compare times"<<c<<"   movetimes"<<cc;
            quicksort(D,num);
       cout<<endl<<"quicksort:"<<"compare times"<<d<<"   movetimes"<<dd;
            shellsort(E,num);
       cout<<endl<<"shellsort:"<<"compare times"<<e<<"   movetimes"<<ee;
             heapSort(F,num);
       cout<<endl<<"heapSort:"<<"compare times"<<f<<"   movetimes"<<ff;
             mergeSort(G,num);
       cout<<endl<<"mergeSort:"<<"compare times"<<g<<"   movetimes"<<gg;
         insertSortHalf(H,num);
       cout<<endl<<"insertSortHalf:"<<"compare times"<<h<<"   movetimes"<<hh;
       a1=0;d=0;dd=0;e=0;ee=0;
       aa=0;b=0;bb=0;c=0;cc=0;
       g=0;gg=0;f=0;ff=0;
       h=0;hh=0;
     /* for(i=0;i<num;i++)
      {
        cout<<endl<<A[i]<<" "<<B[i]<<" "<<C[i]<<" "<<D[i]<<" "<<F[i]<<" "<<G[i]<<" "<<H[i];
      }*/
 }
 cout<<endl<<"------------------------------------------";
}

void total_ram()
{
    int i=0,num=N,case1=0;
    cout<<endl<<"---------------数据排序完全随机分布-------------------";
   for (case1=0;case1<5;case1++)
  {
      for(i=0;i<num;i++)
      {
        A[i]=B[i]=C[i]=D[i]=E[i]=F[i]=G[i]=H[i]=rand()%SR;
      }
      cout<<endl<<"case"<<case1+1<<":"<<endl;
      BubbleSort(A,num);
      cout<<endl<<"BubbleSort:"<<"compare times"<<a1<<"   movetimes"<<aa;
      simpleInsert(B,num);
       cout<<endl<<"simpleInsert:"<<"compare times"<<b<<"   movetimes"<<bb;
        simpleSelect(C,num);
       cout<<endl<<"simpleSelect:"<<"compare times"<<c<<"   movetimes"<<cc;
            quicksort(D,num);
       cout<<endl<<"quicksort:"<<"compare times"<<d<<"   movetimes"<<dd;
            shellsort(E,num);
       cout<<endl<<"shellsort:"<<"compare times"<<e<<"   movetimes"<<ee;
             heapSort(F,num);
       cout<<endl<<"heapSort:"<<"compare times"<<f<<"   movetimes"<<ff;
             mergeSort(G,num);
       cout<<endl<<"mergeSort:"<<"compare times"<<g<<"   movetimes"<<gg;
         insertSortHalf(H,num);
       cout<<endl<<"insertSortHalf:"<<"compare times"<<h<<"   movetimes"<<hh;
       a1=0;d=0;dd=0;e=0;ee=0;
       aa=0;b=0;bb=0;c=0;cc=0;
       g=0;gg=0;f=0;ff=0;
       h=0;hh=0;
  }
  cout<<endl<<"------------------------------------------";
}
int change(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
    return 3;
}

void BubbleSort(int a[],int n)
{
    int i,j;
    bool flag=true;
    for (i=1;i<n&&flag;++i)
      {
          flag=false;
        for(j=0;j<n-i;j++)
        {
            if (a[j+1]<a[j])
        {
            aa+=change(&a[j+1],&a[j]);
            flag=true;
        }
        a1++;
      }
}
}

void simpleInsert(int a[],int n)
{
    int k;
    int tmp;
    for (int j=1;j<n;j++)
    {
        tmp=a[j];
        for(b++,bb++,k=j-1;tmp<a[k]&&k>=0;--k,b++,bb++)
            a[k+1]=a[k];
        a[k+1]=tmp;bb++;
    }
}
void simpleSelect(int a[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(c++,j=i+1;j<n;++j,c++)
            if(a[j]<a[min]) min=j;
        cc+=change(&a[i],&a[min]);
    }
}
void quicksort(int a[],int low,int high)
{
    int mid;
    if(low>=high) return;
    mid=divide(a,low,high);
    quicksort(a,low,mid-1);
    quicksort(a,mid+1,high);
}
void quicksort(int a[],int n)
{
    quicksort(a,0,n-1);
}
int divide(int a[],int low,int high)
{
    int k=a[low];
    dd++;
    do{
        while(low<high&&a[high]>=k) {--high;d++;}
        d++;
        if(low<high){a[low]=a[high];++low;dd++;}
        while (low<high&&a[low]<=k)  {++low;d++;}
        d++;
        if(low<high)  {a[high]=a[low];--high;dd++;}
    }while(low!=high);
    a[low]=k;
    dd++;
    return low;
}

void shellsort(int a[],int n)
{
    int step,j,i;
    int temp;
    for(step=n/2;step>0;step/=2)
        for(i=step;i<n;++i)
    {
        temp=a[i];ee++;
        for(j=i-step;j>=0&&a[j]>temp;j-=step)
       {
           a[j+step]=a[j];
           e++;
           ee++;
       }
       e++;
        a[j+step]=temp;
        ee++;
    }
}

void percolateDown(int a[],int hole,int n)
{
    int child;
    int tmp=a[hole];
    ff++;
    for(;hole*2+1<n;hole=child)
    {
        child=hole*2+1;
        f+=2;
        if(child!=n-1&&a[child+1]>a[child])
            {child++;}
        if(a[child]>tmp) {a[hole]=a[child];ff++;}
        else break;
    }
    a[hole]=tmp;ff++;
}

void heapSort(int a[],int n)
{
    int i;
    int tmp;
    for(i=n/2-1;i>=0;i--)
        percolateDown(a,i,n);
    for(i=n-1;i>0;--i)
    {
        tmp=a[0];
        a[0]=a[i];
        a[i]=tmp;
        ff+=3;
        percolateDown(a,0,i);
    }
}

void merge(int a[],int left,int mid,int right)
{
    int *tmp=new int [right-left+1];
    int i=left,j=mid,k=0;

    while(i<mid&&j<=right)
        {if(a[i]<a[j]) tmp[k++]=a[i++];
        else tmp[k++]=a[j++];
        g++;gg++;}
    while(i<mid) {tmp[k++]=a[i++];gg++;}
    while(j<=right) {tmp[k++]=a[j++];gg++;}

    for(i=0,k=left;k<=right;) {a[k++]=tmp[i++];gg++;}
    delete []tmp;
}

void mergeSort(int a[],int left,int right)
{
    int mid=(left+right)/2;

    if(left==right) return;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    merge(a,left,mid+1,right);
}

void mergeSort(int a[],int n)
{
    mergeSort(a,0,n-1);
}

void insertSortHalf(int a[],int n){
	int i,j,low,high,mid,temp;
	for(i = 1;i<n;i++){
		temp =a[i]; hh++;
		low=  0;
		high = i-1;
		while(low<=high){
			mid = (low+high)/2;
			h++;
			if(temp>a[mid])
				low=  mid+1;
			else
				high = mid-1;
		}

		for(j=  i-1;j>=high+1;j--)
			{a[j+1] = a[j];hh++;}

		a[high+1] = temp;hh++;
	}
}
void fanBubbleSort(int a[],int n)
{
    int i,j;
    bool flag=true;
    for (i=1;i<n&&flag;++i)
      {
          flag=false;
        for(j=0;j<n-i;j++)
        {
            if (a[j+1]>a[j])
        {
            change(&a[j+1],&a[j]);
            flag=true;
        }
      }
}
}

