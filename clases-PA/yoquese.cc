#include <iostream>
//Programa que imprime mide el nivel de las mentiras en las mujeres
int main() {
    std::cout << "Medidor de mentiras en las mujeres: " << std::endl;
    std::string nombre;
    while(std::cin) {
        std::cin >> nombre;
    if (nombre == "Vicky" || nombre == "vicky") {
        while(true) {
            std::cout << "Mentirosa" << " " << '\t';
        }
    } else {
        std::cout << "Algo mentirosa (es mujer)" << std::endl;
    }
    }
    return 0;
}

