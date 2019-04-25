#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <iostream>

using namespace std;
struct set
{
    int key;
    char *name;
};
class cht
{
    private:
    struct node
    {
        int state;//0空1非空
        set data;
        node(){state=0;};
    };
    node *names;
    int size;
    public:
    cht(){size=30;names=new node [size];};
    ~cht(){delete []names;};
    void insertx(const set &x,int &cnt);
    void inserte(const set &x,int &cnt);
    void createhashx(set namelist[]);
    void createhashe(set namelist[]);
    void clear();
};
void createlist(char a[],int i,set namelist[]);
void createnewlist(set namelist[]);
#endif // HEAD_H_INCLUDED
 
 
