#include <iostream>
#include "head.h"
#include "head.cpp"
using namespace std;
int main()
{
    cht namehash;
    set namelist[30];
    createnewlist(namelist);
    namehash.createhashx(namelist);
    namehash.clear();
    namehash.createhashe(namelist);
      return 0;
}
