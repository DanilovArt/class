//
//  main.cpp
// 
//

#include "Mathmatrix.h"


Mathmatrix::Mathmatrix(){
    matrix.resize(1);
    matrix[0].resize(1);
    matrix[0][0] = 0;
}

Mathmatrix::Mathmatrix(int m,int n)
{
    matrix.resize(m);
    for (int i = 0; i < m; i++)
        matrix[i].resize(n);
}

Mathmatrix::Mathmatrix(const Mathmatrix& mass){
    int m = mass.matrix.size(), n=mass.matrix[0].size();
    matrix.resize(m);
    for (int i = 0; i < m; i++)
        matrix[i].resize(n);
    for (int i = 0; i < m;i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = mass.matrix[i][j];
}

Mathmatrix & Mathmatrix::operator=(const Mathmatrix& mass){
    
    if (this == &mass)
        return *this;
    else{
        int m=mass.matrix.size(),n = mass.matrix[0].size();
        matrix.resize(m);
        for (int i = 0; i < m; i++)
            matrix[i].resize(n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = mass.matrix[i][j];
        return *this;
    }
}

ostream& operator<<(ostream& outp, const Mathmatrix& mass){
    int m=mass.matrix.size(), n=mass.matrix[0].size();
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            outp << mass.matrix[i][j] << " ";
        outp << endl;
    }
    return outp;
}

istream& operator>>(istream& inp, Mathmatrix& mass){
    int m, n;
    inp >> m >> n;
    mass.matrix.resize(m);
    for (int i = 0; i < m; i++)
        mass.matrix[i].resize(n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            inp >> mass.matrix[i][j];
    return inp;
}

Mathmatrix Mathmatrix::operator+(Mathmatrix const &right)const {
    int m=matrix.size(), n=matrix[0].size();
    if((right.matrix.size()==m)&&(right.matrix[0].size()==n)){
    Mathmatrix supp(m,n);
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            supp.matrix[i][j]= matrix[i][j]+right.matrix[i][j];
    
    return supp;
    }
    return *this;
}

Mathmatrix  operator-(const Mathmatrix& left, const Mathmatrix& right){
    int m = left.matrix.size(), n = left.matrix[0].size();
    if((right.matrix.size()==m)&&(right.matrix[0].size()==n)){
        Mathmatrix supp(m,n);
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                supp.matrix[i][j]= left.matrix[i][j]-right.matrix[i][j];
        
        return supp;
    }
    return left;
}

void Mathmatrix::mult(int number){
    int m=matrix.size(), n=matrix[0].size();
    for (int i = 0; i < m;i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] *= number;
}

void Mathmatrix::del(int number){
    if (number != 0){
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] /= number;
    }
}

void Mathmatrix::change(int number, int i,int j){
    int m=matrix.size(), n=matrix[0].size();
    i-=1;
    j-=1;
    if (i<m)
        if (j<n) {
            matrix[i][j]=number;
        }
}

int Mathmatrix::readel(int i, int j){
    int k=0;
    int m=matrix.size(), n=matrix[0].size();
    i-=1;
    j-=1;
    if (i<m)
        if (j<n) {
            k=matrix[i][j];
        }
    return k;
}


Mathmatrix operator*(const Mathmatrix& left, const Mathmatrix& right){
    int m = left.matrix.size(), n = left.matrix[0].size(), a = right.matrix.size(), b = right.matrix[0].size();
    if (n != a){
        return left;
    }
    else{
        Mathmatrix supp(m, b);
        for (int i = 0 ;i < m; i++) {
            for (int j = 0; j < b; j++){
                supp.matrix[i][j] = 0;
                for (int k = 0; k < n; k++){
                    supp.matrix[i][j] = supp.matrix[i][j] + left.matrix[i][k] * right.matrix[k][j];
                }
            }
        }
        return supp;
    }
}


Mathmatrix::~Mathmatrix()
{
    matrix.clear();
}



