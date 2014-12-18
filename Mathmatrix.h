//
//  Mathmatrix.h
//
//


#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Mathmatrix
{private:
    vector<vector<int>> matrix;
public:
    //конструктор по умолчанию
    Mathmatrix();
    //конструктор с заданием размерности
    Mathmatrix(int m,int n);
    //конструкор копирования
    Mathmatrix(const Mathmatrix &mass);
    //присваивание
    Mathmatrix & operator=(const Mathmatrix& mass);
    //сложение
    Mathmatrix  operator+(const Mathmatrix& right)const ;
    //вычитание
    friend Mathmatrix  operator-(const Mathmatrix& left,const Mathmatrix& right);
    //умножение
    friend Mathmatrix operator*(const Mathmatrix& left, const Mathmatrix& right);
    //умножение
    void mult(int number);
    //деление
    void del(int number);
    
    friend istream&  operator >> (istream& inp, Mathmatrix& mass);
    
    friend ostream& operator << (ostream& outp, const Mathmatrix& mass);
    
    ~Mathmatrix();
};

