#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <vector>

//Función que muestra los participantes del grupo
void participantes();
void Idempotencia(std::vector<std::string>&, std::string);     //Funcion Idempotencia simplifica p,q o r -> a = p,q o r; hay asignar el valor

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
*/

int main(int argc, char** argv) {
    std::vector<std::string> argList;  // Aqui se almacena lo de argv y aqui voy modificando
    std::string a="p";                 // Variable para comparar en idempotencia, fue de ejemplo
    if (argc > 1) {
        for(int i=1;i<argc;i++){
            argList.push_back(argv[i]);     //Agrego uno por uno lo recibido por consola ignorando el argv[0] que es el nombre del programa
        }
    }
    else {
        // Mostrar los integrantes
        participantes();
    }
    std::cout << std::endl << "=== Original ===" << std::endl;  //Imprimo lo ingresado inicialmente
    for(int i=0;i<argList.size();i++){
        std::cout<<argList[i]<<" Posicion: "<<i<<std::endl;
    }
    Idempotencia(argList, a);                                    //Maravillosa funcion; a puede ser "q", "p" o "r" como str no usar char
    std::cout << std::endl << "=== Modificada ===" << std::endl; //Imprimo lo modificado post idempotencia
    for(int i=0;i<argList.size();i++){
        std::cout<<argList[i]<<" Posicion: "<<i<<std::endl;
    }
    system("Pause");
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Taller 01 ===" << std::endl;
    std::cout << std::endl << "Braulio Argandoña";
    std::cout << std::endl << "Fanny Rivero";
    std::cout << std::endl << "Jennifer Portiño" << std::endl;
}

void Idempotencia(std::vector<std::string> &argList, std::string a){
    std::vector<std::string> aux;
    int c;
    for(int i=0;i<argList.size();i++)   {
        if (std::string(argList[i]) == a){    //Encuentra a=p,q o r
            c=i+1;
            if (std::string(argList[c]) == "||" || std::string(argList[c]) == "&&" ){ //Encuentra && o ||
                c+=1;
                if (std::string(argList[c]) == a){              //Encuentra a nuevamente y verifica la estructura de una idempotencia
                    int j=0;
                    for(j; j<=i; j++){
                        aux.push_back(argList[j]);              //Agrega todo lo anterior a la idempotencia y la variable a al aux
                    }
                    c+=1;
                    for(int q=c; q<argList.size(); q++){
                        aux.push_back(argList[q]);              //Agrega todo lo posterior a la idempotencia al aux
                    }
                    argList=aux;                                //Lista se modifica con lo que sirve
                    aux.clear();                                //Limpia el auxiliar
                }
            }
        }else{
            if (std::string(argList[i]) == "~"){
                c=i+1;
                if (std::string(argList[c]) == a){
                    c+=1;
                    if (std::string(argList[c]) == "||" || std::string(argList[c]) == "&&" ){
                        c+=1;
                        if (std::string(argList[c]) == "~"){
                            c+=1;
                            if (std::string(argList[c]) == a){
                                int j=0;
                                for(j; j<=i+1; j++){
                                    aux.push_back(argList[j]);
                                }
                                c+=1;
                                for(int q=c; q<argList.size(); q++){
                                    aux.push_back(argList[q]);
                                }
                                argList=aux;
                                aux.clear();
                                }
                        }
                    }
                }
            }
        }
    }
}
