#ifndef BIGNUM_H_INCLUDED
#define BIGNUM_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

class Longlongint
{
    friend Longlongint operator+(const Longlongint&,const Longlongint&);
    friend ostream &operator<<(ostream &,const Longlongint&);
    friend Longlongint operator-(const Longlongint&,const Longlongint&);

private:
    char  sign;    //符号
    char *num;     //数字
public:
    Longlongint(const char *n="");
    Longlongint(const Longlongint&);
    Longlongint&operator=(const Longlongint&);
    ~Longlongint(){delete num;}
};

char *add(const char *s1,const char *s2);  //返回有两个字符串相加结果的字符串；
char *sub(const char *s1,const char *s2);  //返回有两个字符串相减结果的字符串；
bool greaterr(const char *s1,const char *s2); //s1>s2的逻辑值



#endif // BIGNUM_H_INCLUDED
