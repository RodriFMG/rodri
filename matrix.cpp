#include "matrix.h"
#include<random>
#include<iostream>

int& utec::matrix::operator()(int a, int b) const{
    return data[a][b];
}

utec::matrix::matrix(int a, int b){
    filas = a;
    columnas = b;
    data = new int*[filas];
    for(int i=0;i<filas;i+=1){
        data[i] = new int[columnas];
    }
}

int utec::matrix::rows() const { //se pone utec::matrix::rows, porque el utec::matrix es para que reconozca a la clase
    //el matrix::rows para que se pueda acceder a los atributos de la clase.
    return filas;
}

int utec::matrix::cols() const{
    return columnas;
}
std::ostream& utec::operator<<(std::ostream& out, const utec::matrix& pe){

    for(int i=0;i<pe.rows();i+=1){
        for(int j=0;j<pe.cols();j+=1){
            out<< pe(i,j) << "\t";
        }
        out <<"\n";
    }

    return out;
}

std::istream& utec::operator>>(std::istream& in, utec::matrix &pe) {
    return in >> pe(pe.filas,pe.columnas);
}
utec::matrix& utec::matrix::operator=( const utec::matrix& pe) {

    for(int i=0;i<filas;i+=1){
        delete[] data[i];
    }
    delete[] data;

    filas = pe.filas;
    columnas = pe.columnas;

    data = new int*[filas];
    for(int i=0;i<filas;i+=1){
        data[i] = new int[columnas];
    }

    for(int i=0;i<filas;i+=1){
        for(int j=0;j<columnas;j+=1){
            (*this)(i,j) =  pe.data[i][j];
        }
    }

}
//Falta un constructor para evitar el error
void utec::swap( utec::matrix& p1,  utec::matrix& p2){
    std::swap(p1.filas,p2.filas); //cambia las filas y columnas para que ambos tengan la data pero
    std::swap(p1.columnas,p2.columnas); //con las filas y columnas de los otros para que
    std::swap(p1.data,p2.data); //despues pueda realizarse el cambio de manera efectiva
}

utec::matrix::~matrix(){
    for(int i=0;i<filas;i+=1){
        delete[] data[i];
    }

    delete[] data;
}

utec::matrix::matrix(matrix& pe) {
    filas = pe.filas;
    columnas = pe.columnas;
    data = new int*[filas];
    for(int i=0;i<filas;i+=1){
        data[i] = new int[columnas];
    }

    for(int i=0;i<filas;i+=1){
        for(int j=0;j<columnas;j+=1){
            (*this)(i,j) = pe(i,j); // con el *this estoy llamando a data
        }
    }

}

bool utec::matrix::operator==(matrix& pe){
    bool n=true;
    for(int i=0;i<filas;i+=1){
        for(int j=0;j<columnas;j+=1){
            if((*this)(i,j) != pe(i,j)){
                n = false;
                return n;
            }
        }
    }
    return n;

}

bool utec::matrix::operator!=(matrix& pe){
    bool n=false;
    for(int i=0;i<filas;i+=1){
        for(int j=0;j<columnas;j+=1){
            if((*this)(i,j) == pe(i,j)){
                n = true;
                return n;
            }
        }
    }
    return n;
}

utec::matrix utec::matrix::operator*(const matrix& pe1) const { //si pongo el const afuera afecta al objeto de la clase directa
    //si lo pongo adentro de los () afecta al objeto de los parametros
    if(columnas == pe1.filas){
        matrix pe3(pe1.filas,pe1.columnas); //crea una matriz dinamica con las filas de la 1era matriz y las columnas
        // de la 2da matriz

        for(int i=0;i<pe3.filas;i+=1){
            for(int j=0;j<pe3.columnas;j+=1){
                pe3(i,j) = 0;
            }
        }

        for(int i=0;i<pe3.filas;i+=1){
            for(int j=0;j<pe3.columnas;j+=1){
                for(int k=0 ; k<columnas;k+=1){
                    pe3(i,j) += (*this)(i,k) * pe1(k,j);
                }
            }
        }

        return pe3;
    }


}

utec::matrix utec::matrix::operator+(matrix& pe){
    if((filas == pe.filas) and (columnas == pe.columnas)){
        matrix pe3(filas,columnas);

        for(int i=0;i<filas;i+=1){
            for(int j=0;j<columnas;j+=1){
                pe3(i,j) = 0;
            }
        }

        for(int i=0;i<filas;i+=1){
            for(int j=0;j<columnas;j+=1){
                pe3(i,j) = (*this)(i,j) + pe(i,j);
            }
        }
        return pe3;
    }
    return utec::matrix();
}

utec::matrix& utec::matrix::operator*=(int pe){

    for(int i=0;i<filas;i+=1){
        for(int j=0;j<columnas;j+=1){
            (*this)(i,j) *= pe;
        }
    }
    return *this; //solo se puede retornar *this si es una funcion con la clase
}

utec::matrix utec::matrix::operator*(int pe){
    utec::matrix te((*this).filas,(*this).columnas);

    for(int i=0;i<filas;i+=1){
        for(int j=0;j<columnas;j+=1){
            te(i,j) = 0;
            te(i,j) = (*this)(i,j);
            te(i,j) *= pe;
        }
    }

    return te;
}

utec::matrix utec::operator*(int pe,  matrix& te) { //asi se pone cuando estamos ingresando con friends
    return te*pe; //se podría hacer directo porque estamos aplicando la sobrecarga de arriba
}