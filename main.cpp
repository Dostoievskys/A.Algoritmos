#include <iostream>
#include <cstdlib>


using namespace std;

//Función que muestra los participantes del grupo
void participantes();

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {

    /**
     * Incluir acá la lógica del programa
     *
     */
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
    std::cout << std::endl << "Braulito"; // Reemplazar por su nombre
    std::cout << std::endl << "Pedrito"; // Reemplazar por su nombre
    std::cout << std::endl << "Jennifer" << std::endl; // Reemplazar por su nombre
}
