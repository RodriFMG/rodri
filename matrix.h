

//
// Created by RODRIGO on 29/08/2023.
//

#ifndef TAREA_MATRIZ_CLASE_H
#define TAREA_MATRIZ_CLASE_H
#include <iostream>


namespace utec{
    using SIZE_TYPE = std::size_t;
    class matrix{
    private:
        int** data = nullptr;
        SIZE_TYPE filas;
        SIZE_TYPE columnas;
    public:
        matrix() = default; //sirve para crear el objeto sin la necesidad de colocar ni un parametro
        matrix(int a, int b);
        [[nodiscard]] int rows() const;
        [[nodiscard]] int cosl() const;
        int& operator()(int a, int b) const; // sirve para llamar directamente a la data[i][j], pero con (i,j)
        matrix(matrix&& p1) ; //Constructor move
        matrix& operator=(const matrix& pe) ; //para pasar un contenido a otro entre objetos
        matrix(matrix& p1); //esto sirve para pasar de manera seguro de un contenido a otro, cuando creemos el objeto
        bool operator==(matrix& pe);
        bool operator!=(matrix& pe);
        virtual ~matrix();
        //dos argumentos, no más.
        matrix operator*(const matrix& pe1)const;

        matrix operator+(matrix& pe);
        matrix& operator*=(int pe); //cuando solo ponemos el objeto, sirve para trabajar directamente con los parametros
        //privados de la matriz (sin que haya ni un objeto como parametro).
        matrix operator*(int pe);
        friend matrix operator*(int pe, matrix& te); //si quiero hacer un cambio directo retornando o sin retornar,
        //tengo que usar si o si el &, para que modifique y lo guarde, y no solo lo retorne sin modificar.
        friend void swap( matrix& p1,  matrix& p2); // intercambio de contenido entre 2 objetos

    };

    std::ostream& operator<<(std::ostream& os, const matrix& pe); //sirve para imprimir el objeto
    std::istream& operator>>(std::istream& in, matrix& pe); //los ostream& y los istram& solo reconocen
    void swap(matrix& p1, matrix& p2);

    //Si quiero crear una funcion que permita modificar los objetos, tengo que crear un constructor que me apoye en el cambio
}

#endif //TAREAMATRICES_SINTEMPLATES_DASD_H
