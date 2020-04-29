#include <iostream>
#include <cstdlib>

using namespace std;

void participantes();//Función que muestra los participantes del grupo

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {
    if (argc > 1) {
        // @TODO programar proyecto
    } else {
        // Mostrar los integrantes
        participantes();
    }
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Taller 01 ===" << std::endl;
    std::cout << std::endl << "Braulio Argandoña"; // Reemplazar por su nombre
    std::cout << std::endl << "Fanny Rivero"; // Reemplazar por su nombre
    std::cout << std::endl << "Jennifer Portiño" << std::endl; // Reemplazar por su nombre
}
