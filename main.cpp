#include <iostream>
#include "matrix.h"
#include <random>
using namespace std;

void question_1_1(){
    // Constructor por parametros
    utec::matrix m1(4, 5);
    // Ingreso de datos
    for (int i = 0; i < m1.rows(); ++i) {
        for (int j = 0; j < m1.cols(); ++j) {
            m1(i, j) = rand() % 100;
        }
    }
    // Impresion de libreria
    std::cout << m1;


}
void question_1_2(){
    random_device rd;
    utec::matrix m1(8, 9);
    utec::matrix m2(4, 5);
    uniform_int_distribution<int> dis(0, 100);
    for (size_t i = 0; i < m1.rows(); ++i)
        for (size_t j = 0; j < m1.cols(); ++j)
            m1(i, j) = dis(rd);
    // Copia
    utec::matrix m3 = m1;
    for (size_t i = 0; i < m2.rows(); ++i)
        for (size_t j = 0; j < m2.cols(); ++j)
            m2(i, j) = dis(rd);
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    cout << m1 << endl << m2 << endl;
    // Move
    std::swap(m1, m2); //falta arreglar para ponerlo como std::swap(m1,m2);
    m2(0, 0) = 100;
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    cout << m1 << endl << m2 << endl << m3 <<endl;
}

void question_1_3(){
    random_device rd;
    utec::matrix m1(8, 9);
    utec::matrix m2(4, 5);
    uniform_int_distribution<int> dis(0, 100);
    for (size_t i = 0; i < m1.rows(); ++i)
        for (size_t j = 0; j < m1.cols(); ++j)
            m1(i, j) = dis(rd);
    // Copia
    utec::matrix m3 = m1;
    for (size_t i = 0; i < m2.rows(); ++i)
        for (size_t j = 0; j < m2.cols(); ++j)
            m2(i, j) = dis(rd);
    // Comparando matrices
    cout << boolalpha << (m1 == m2) << endl;
    cout << boolalpha << (m3 == m1) << endl;
    cout << boolalpha << (m2 != m3) << endl;
}

void question_1_4(){
    using SIZE_TYPE = std::size_t;
    SIZE_TYPE rows = 0, cols = 0;
    cin >> rows >> cols;
    utec::matrix m1(rows, cols);
    for (size_t i = 0; i < m1.rows(); ++i)
        for (size_t j = 0; j < m1.cols(); ++j)
            cin >> m1(i, j);
    std::cout<<"******************"<<"\n";

    cin >> rows >> cols;

    utec::matrix m2(rows, cols);
    for (size_t i = 0; i < m2.rows(); ++i)
        for (size_t j = 0; j < m2.cols(); ++j)
            cin >> m2(i, j);
    std::cout<<"******************"<<"\n";

    cin >> rows >> cols;
    utec::matrix m3(rows, cols);
    for (size_t i = 0; i < m3.rows(); ++i)
        for (size_t j = 0; j < m3.cols(); ++j)
            cin >> m3(i, j);
    std::cout<<"******************"<<"\n";
    // Multiplicación entre matrices
    cout << m2 * m3 << endl; //falta arreglar para que imprima directamente el cout<<m2*m3<<endl;
    // Suma de matrices
    auto m4 = m1 + m2;
    cout << m4 << endl;
    // Autoincremento
    m1 *= 5;
    cout << m1 << endl;
    // Multiplicación escalar
    auto m5 = 4 * m1 * 2 + m4;
    cout << m5 << endl;
}





int main() {
    question_1_2();


    return 0;
}
