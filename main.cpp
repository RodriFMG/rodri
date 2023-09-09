#include <iostream>
#include "P12.h"
int main() {
    cache<int, 10> c;  // El primer parametro define el tipo de contenido,
    // El segundo parametro define el limite

    c = {1, 2, 3, 4, 10}; // sobrecargar el operador = para aceptar
    // std::initializer list
    // si se agrega mas del limite se descarta
    // los valores
    c.push(11);     // Se agrega nuevos valores usando el metodo push
    c.push(15);

    std::cout << c.top() << std::endl; // retorna el ultimo valor ingresado
    c.pop(); // retira el ultimo 15
    c.pop(); // retira el ultimo 11
    c.pop(); // retira el ultimo 10
    c.pop(); // retira el ultimo 4
    c.pop(); // retira el ultimo 3
    c.pop(); // retira el ultimo 2
    c.pop(); // retira el ultimo 1
    c.pop(); // Si esta vacio no retira ningun valor

    c.clear();
    std::cout << std::boolalpha << c.empty() << std::endl;

    cache<std::string, 3> d;
    d.push("apple");
    d.push("banana");
    d.push("orange");
    d.push("lemon");    // Se elimina apple del cache
    d.push("grape");    // Se elimina banana del cache

    std::cout << d << std::endl; // grape lemon orange
}
