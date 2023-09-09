//
// Created by RODRIGO on 9/09/2023.
//

#ifndef PESDA_P12_H
#define PESDA_P12_H
#include <iostream>
#include <initializer_list>
#include <string>

template<class T,size_t N>
class cache{
private:
    T* apuntador = nullptr;
    size_t tam = 0;

public:
    virtual ~cache(){
        delete[] apuntador;
    }

    cache(){ //si quiero que el objeto una vez creado tenga un tamaño dinamico.
        apuntador = new T[0];
    };

    cache& operator=(std::initializer_list<T> lts){
        auto pe = lts.begin();
        delete[] apuntador;

        if(size(lts)>N){
            tam = N;
            apuntador = new T[tam];
            for(int i=0;i<N;i+=1){
                apuntador[i] = *pe;
                pe++;
            }
        }
        else{
            tam = std::size(lts);
            apuntador = new T[tam];
            for(size_t i = 0;i < lts.size(); ++i){
                apuntador[i] = *pe;
                ++pe;
            }
        }

        return *this;
    }

    void push(const T pe) {

        //funciona para actualizar el valor de T cada vez que llamo a la funcion void
        //cuando llama otra vez a la funcion, no se vuelve a actaulizar su valor con 0, sino que se mantiene el valor
        //que se obtuvo en la funcion anterior, inclusive si este igualado a un int.

        static size_t te = N;
        if (tam < N) {
            apuntador[tam] = pe;
            ++tam;
        } //si pongo solo if, el cuando tam==N tamben esta entrando.
        else if(tam==N){
            --te;

            apuntador[te-2] = apuntador[te-1];

            if(te==0){
                te = N;
            }

            apuntador[te-1] = pe;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const cache<T,N>& pe){
        for(size_t i =0 ; i<pe.tam;i+=1){
            os<<pe.apuntador[i]<<" ";
        }

        return os;
    }

    void pop() {
        if(tam == 0){
            return;
        }

        else{

            for(size_t i = tam ;0>tam;--i){
                apuntador[i-1] = apuntador[i];
            }
            tam-=1; //esto se utiliza cuando quiero eliminar el ultimo elemento del contenedor
            //se usa despues de hacer todo el proceso.
        }

    }

    T top(){
        return apuntador[tam-1];
    }

    void clear(){
        tam = 0;
        apuntador = nullptr;
    }

    bool empty(){
        if(tam==0){
            return true;
        }
        return false;
    }
};
#endif //PESDA_P12_H

//throw std::runtime_error(""); sirve para crear una excepcion a un error cuand oesta compilando,
//se puede escribir un mensaje para advertir.