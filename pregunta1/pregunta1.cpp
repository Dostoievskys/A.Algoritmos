#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

using namespace std;

void participantes();//Función que muestra los participantes del grupo
bool vallenguaje(std::string);
bool condicion(std::string);

int main(int argc, char** argv){
    std::string argList = argv[1];  // Aqui se almacena lo de argv y aqui voy modificando
    if (argc >1) {
        if ( vallenguaje(argList) == false ){   // Validacion del lenguaje a , b , o , *
            cout << "No cumple la condicion" << endl ;
            return 0;
        }else {
            if ( condicion(argList) == false ){  // Validacion de las condiciones del lenguaje
                cout << "No cumple la condicion" << endl ;
                return 0;
            }
            cout << "Palabra totalmente valida " << endl;
            return EXIT_SUCCESS;
        }

    }else{
        // Mostrar los integrantes
        participantes();
    }
    return EXIT_SUCCESS;
}

bool vallenguaje(std::string argList){
    char asterisco;
    asterisco= '\52';
    int c=0;
    for(int i=0;i<argList.size();i++){
        if(argList[i] == 'a' || argList[i] == 'b' || argList[i] == 'o' || argList[i] == asterisco ){
            c++;
        }
    }
    if (c == argList.size())
        return true;
    else
        return false;
}
bool condicion(std::string argList){
  char cond;
  cond = '\52';
  if (argList[0] == 'a' ){
        for(int i=0;i<argList.size();i++){
            if(argList[i] == cond){
                return false;
            }
        }
        return true;
    }
    return false;
}

void participantes(){
    std::cout << std::endl << "=== Taller 01 ===" << std::endl;
    std::cout << std::endl << "Braulio Argandoña"; // Reemplazar por su nombre
    std::cout << std::endl << "Jennifer Portiño"; // Reemplazar por su nombre
    std::cout << std::endl << "Fanny Rivero" << std::endl; // Reemplazar por su nombre
}
