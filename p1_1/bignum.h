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
    char  sign;    //����
    char *num;     //����
public:
    Longlongint(const char *n="");
    Longlongint(const Longlongint&);
    Longlongint&operator=(const Longlongint&);
    ~Longlongint(){delete num;}
};

char *add(const char *s1,const char *s2);  //�����������ַ�����ӽ�����ַ�����
char *sub(const char *s1,const char *s2);  //�����������ַ������������ַ�����
bool greaterr(const char *s1,const char *s2); //s1>s2���߼�ֵ



#endif // BIGNUM_H_INCLUDED
