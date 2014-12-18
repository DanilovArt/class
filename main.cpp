//Данилов Артем Дмитриевич
//  main.cpp
//Реализовать класс МАТЕМАТИЧЕСКАЯ МАТРИЦА.
//Требуемые методы: конструктор (с заданием размерности),
//деструктор,
//конструктор копирования,
//оператор присваивания,
//чтение/изменение любого элемента матрицы, вывод матрицы в поток, ввод матрицы из потока, сложение
//(соответствующие элементы матриц
//складываются), вычитание (аналогично), умножение/деление на число (все элементы умножаются/делятся на это число),
//умножение двух матриц.

#include "Mathmatrix.h"
#include <fstream>

int main(void){
    Mathmatrix matrix1, matrix2,matrix3;
    ifstream input("/Users/artemdanilov/Desktop/ Test6/Test6/in.txt"),input2("/Users/artemdanilov/Desktop/ Test6/Test6/in2.txt");
    input >> matrix1;
    cout << "Первая матрица "<<endl<<matrix1;
    input2 >> matrix2;
    cout <<"Вторая матрица "<<endl<< matrix2;
    matrix3= matrix1 + matrix2;
    cout<<"Сложение матриц"<<endl<<matrix3;
    matrix3=matrix1 - matrix2;
    cout <<"Вычитание матриц" <<endl<<matrix3;
    matrix3 = matrix2*matrix1;
    cout <<"Умножение матриц"<<endl<< matrix3;
    matrix1.mult(4);
    cout<<"Умножение на число"<<endl<<matrix1;
    matrix1.del(2);
    cout<<"Деление матрицы на число"<<endl<<matrix1;
    Mathmatrix matrix10;
    matrix10= Mathmatrix(2,3);
    Mathmatrix *mat = new Mathmatrix;
    cout<<mat;
    return 0;
}
