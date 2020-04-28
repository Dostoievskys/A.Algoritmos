#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <vector>

//Función que muestra los participantes del grupo
void participantes();
void Simplificar(std::vector<std::string>&, std::string);     //Funcion Simplificar simplifica p,q o r -> a = p,q o r; hay asignar el valor

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
        std::cout<<argList[i];
    }
    std::cout<<std::endl;
    Simplificar(argList, a);
    std::cout << std::endl << "=== Modificada ===" << std::endl;
    for(int i=0;i<argList.size();i++){
        std::cout<<argList[i];
    }
    Simplificar(argList, a); //PROBAR CON main ( ~ p ^&^& ~ p ) ( ~ p ^|^| ~ p ) ( p ^&^& p ) ( p ^|^| p ) ( ~ p ^&^& p ) ( p ^&^& ~ p ) ( ~ p ^|^| p ) ( p ^|^| ~ p )
    std::cout << std::endl << "=== Modificada 2DA VEZ ===" << std::endl; //ahí estan todas la validaciones que hice
    for(int i=0;i<argList.size();i++){
        std::cout<<argList[i];
    }
    std::cout << std::endl
    system("Pause");
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Taller 01 ===" << std::endl;
    std::cout << std::endl << "Braulio Argandoña";
    std::cout << std::endl << "Fanny Rivero";
    std::cout << std::endl << "Jennifer Portiño" << std::endl;
}

void Simplificar(std::vector<std::string> &argList, std::string a){
    std::vector<std::string> aux;
    int c;
    for(int i=0;i<argList.size();i++)   {
        if (std::string(argList[i]) == a){  //VERIFICA SI ES P, Q O R
            c=i+1;
            if (std::string(argList[c]) == "||" || std::string(argList[c]) == "&&" ){ //VERIFICA SI SIGUE ESTA ESTRUCTURA P && / P ||
                c+=1;
                if (std::string(argList[c]) == a){     //VERIFICA SI SIGUE ESTA ESTRUCTURA P && P / P || P
                    int j=0;
                    if(std::string(argList[i-1]) == "("){ //VERIFICA SI SIGUE ESTA ESTRUCTURA (P && P / (P || P
                        for(j;j<i-1;j++){
                            aux.push_back(argList[j]); //AGREGA TODO LO ANTERIOR AL PARENTESIS
                        }
                    }else{
                        for(j;j<i;j++){
                            aux.push_back(argList[j]); //AGREGA TODO LO ANTERIOR A P EN CASO DE NO EXISTIR PARENTESIS ANTE P
                        }
                    }
                    aux.push_back(a); //AGREGA LA EXPRESION SIMPLIFICADA DE P&&P/P||P
                    c++;;
                    if(std::string(argList[c]) == ")"){
                        for(int q=c+1; q<argList.size(); q++){
                            aux.push_back(argList[q]);              //AGREGA TODO LO POSTERIOR AL PARENTESIS
                        }
                    }else{
                        for(int q=c; q<argList.size(); q++){        //AGREGA TODO LO POSTERIOR
                            aux.push_back(argList[q]);
                        }
                    }
                    argList=aux;                                   //SE PROCEDE A TRASPASAR LA SIMPLIFICACION DESDE AUX A LA LISTA ORIGINAL
                    aux.clear();                                   //SE LIMPIA LISTA AUX
                }else{
                    if(std::string(argList[c]) == "~"){            //VERIFICA SI LA SEGUNDA P ES NEGATIVA
                        c++;
                        if(std::string(argList[c]) == a){          //VERIFICA SI SIGUE LA ESTRUCTURA P&&~P / P||~P...
                            if(std::string(argList[c-2]) == "&&"){ //VERIFICA SI SIGUE LA ESTRUCTURA P&&~P...
                                int j=0;
                                if(std::string(argList[c-4]) == "("){ //VERIFICA SI SIGUE LA ESTRUCTURA (P&&~P...
                                     for(j; j<i-1; j++){
                                         aux.push_back(argList[j]);   //AGREGA TODO LO ANTERIOR AL PARENTESIS
                                     }
                                }else{
                                     for(j; j<i; j++){
                                         aux.push_back(argList[j]);   //AGREGA TODO LO ANTERIOR
                                     }
                                }
                                aux.push_back("F");                  //AGREGA LA EXPRESION SIMPLIFICADA DE P&&~P
                                if(std::string(argList[c+1]) == ")"){  //VERIFICA SI SIGUE LA ESTRUCTURA (P&&~P)
                                     for(int q=c+2;q<argList.size();q++){
                                         aux.push_back(argList[q]);  //AGREGA TODO LO POSTERIOR AL PARENTESIS
                                     }
                                }else{
                                    for(int q=c+1;q<argList.size();q++){
                                        aux.push_back(argList[q]);   //AGREGA TODO LO POSTERIOR
                                    }
                                }
                                argList=aux;                           //SE PROCEDE A TRASPASAR LA SIMPLIFICACION DESDE AUX A LA LISTA ORIGINAL
                                aux.clear();                           //SE LIMPIA AUX
                            }else{                                     //VERIFICA SI SIGUE LA ESTRUCTURA P||~P...
                                int j=0;
                                if(std::string(argList[c-4]) == "("){ //VERIFICA SI SIGUE LA ESTRUCTURA (P||~P...
                                     for(j; j<i-1; j++){
                                         aux.push_back(argList[j]);   //AGREGA TODO LO ANTERIOR AL PARENTESIS
                                     }
                                }else{
                                     for(j; j<i-1; j++){
                                         aux.push_back(argList[j]);   //AGREGA TODO LO ANTERIOR
                                     }
                                }
                                aux.push_back("V");                  //AGREGA LA EXPRESION SIMPLIFICADA DE P||~P
                                if(std::string(argList[c+1]) == ")"){  //VERIFICA SI SIGUE LA ESTRUCTURA (P||~P)
                                     for(int q=c+2;q<argList.size();q++){
                                         aux.push_back(argList[q]);  //AGREGA TODO LO POSTERIOR AL PARENTESIS
                                     }
                                }else{
                                    for(int q=c+1;q<argList.size();q++){
                                        aux.push_back(argList[q]);   //AGREGA TODO LO POSTERIOR
                                    }
                                }
                                argList=aux;                           //SE PROCEDE A TRASPASAR LA SIMPLIFICACION DESDE AUX A LA LISTA ORIGINAL
                                aux.clear();
                            }

                        }
                    }
                }
            }
        }else{
            if (std::string(argList[i]) == "~"){                        //PARTE CON LA ESTRUCTURA ~...
                c=i+1;
                if (std::string(argList[c]) == a){                      //VERIFICA SI SIGUE LA ESTRUCTURA ~P
                    c++;
                    if (std::string(argList[c]) == "||" || std::string(argList[c]) == "&&" ){ //VERIFICA SI SIGUE LA ESTRUCTURA ~P&&.../~P||...
                        c++;
                        if (std::string(argList[c]) == "~"){                                   //VERIFICA SI SIGUE LA ESTRUCTURA ~P&&~.../~P||~...
                            c++;
                            if (std::string(argList[c]) == a){                                 //VERIFICA SI SIGUE LA ESTRUCTURA ~P&&~P.../~P||~P...
                                int j=0;
                                if(std::string(argList[i-1]) == "("){                          //VERIFICA SI SIGUE LA ESTRUCTURA (~P&&~P.../(~P||~P...
                                    for(j; j<i-1; j++){
                                        aux.push_back(argList[j]);                             //AGREGA TODO LO ANTERIOR AL PARENTESIS
                                    }
                                }else{                                                         //SI NO HAY PARENTESIS...
                                    for(j; j<i; j++){
                                        aux.push_back(argList[j]);                             //AGREGA TODO LO ANTERIOR
                                    }
                                }
                                aux.push_back("~");                                            //AGREGA LA EXPRESION P&&P/P||P SIMPLIFICADA
                                aux.push_back(a);
                                c++;
                                if(std::string(argList[c]) == ")"){                            //VERIFICA SI SIGUE LA ESTRUCTURA (~P&&~P)/(~P||~P)
                                    for(int q=c+1; q<argList.size(); q++){
                                        aux.push_back(argList[q]);                             //AGREGA TODO LO POSTERIOR AL PARENTESIS
                                    }
                                }else{                                                         //SI NO HAY PARENTESIS...
                                    for(int q=c; q<argList.size(); q++){
                                        aux.push_back(argList[q]);                             //AGREGA TODO LO POSTERIOR
                                    }
                                }
                                argList=aux;                                                   //SE PROCEDE A TRASPASAR LA SIMPLIFICACION DESDE AUX A LA LISTA ORIGINAL
                                aux.clear();                                                   //LIMPIA AUX
                                }
                        }else{
                            if(std::string(argList[c]) == a){                                  //VERIFICA SI SIGUE LA ESTRUCTURA ~P&&P.../~P||P...
                                if(std::string(argList[c-1]) == "&&"){                         //VERIFICA SI SIGUE LA ESTRUCTURA ~P&&P
                                    int j=0;
                                    if(std::string(argList[c-4]) == "("){                      //VERIFICA SI ESTA ENTRE PARENTESIS
                                        for(j=0;j<i-1;j++){
                                            aux.push_back(argList[j]);                         //AGREGA TODO LO ANTERIOR AL PARENTESIS
                                        }
                                    }else{                                                     //SI NO EXISTE PARENTESIS...
                                        for(j=0;j<i-1;j++){
                                            aux.push_back(argList[j]);                         //AGREGA TODO LO ANTERIOR
                                        }
                                    }
                                    aux.push_back("F");                                        //SIMPLIFICA ~P&&P A F
                                    if(std::string(argList[c+1]) == ")"){
                                        for(j=c+2;j<argList.size();j++){
                                            aux.push_back(argList[j]);                         //AGREGA TODO LO POSTERIOR AL PARENTESIS
                                        }
                                    }else{
                                        for(j=c+1;j<argList.size();j++){
                                            aux.push_back(argList[j]);                         //AGREGA TODO LO POSTERIOR SI NO EXISTE PARENTESIS
                                        }
                                    }
                                    argList=aux;
                                    aux.clear();
                                }else{                                                         //VERIFICA SI SIGUE LA ESTRUCTURA ~P||P
                                    int j=0;
                                    if(std::string(argList[c-4]) == "("){                      //VERIFICA SI ESTA ENTRE PARENTESIS
                                        for(j=0;j<i-1;j++){
                                            aux.push_back(argList[j]);
                                        }
                                    }else{                                                     //AGREGAR ANTERIOR A ESTRUCTURA
                                        for(j=0;j<i;j++){
                                            aux.push_back(argList[j]);
                                        }
                                    }
                                    aux.push_back("V");                                        //EXPRESION SIMPLIFICADA
                                    if(std::string(argList[c+1]) == ")"){
                                        for(j=c+2;j<argList.size();j++){
                                            aux.push_back(argList[j]);
                                        }
                                    }else{                                                     //AGREGAR POSTERIOR A ESTRUCTURA
                                        for(j=c+1;j<argList.size();j++){
                                            aux.push_back(argList[j]);
                                        }
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
}
