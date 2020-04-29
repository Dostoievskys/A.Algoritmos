#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <vector>

void participantes();//Funci�n que muestra los participantes del grupo
void Implicancia(std::vector<std::string>&);
/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El c�digo de salida del programa
*/

int main(int argc, char** argv) {
    std::vector<std::string> argList;  // Aqui se almacena lo de argv y aqui voy modificando
    if(argc > 1){
        for(int i=1;i<argc;i++){
            argList.push_back(argv[i]);     //Agrego uno por uno lo recibido por consola ignorando el argv[0] que es el nombre del programa
        }
    }
    else{
        participantes();// Mostrar los integrantes}
    }
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Taller 01 ===" << std::endl;
    std::cout << std::endl << "Braulio Argando�a";
    std::cout << std::endl << "Fanny Rivero";
    std::cout << std::endl << "Jennifer Porti�o" << std::endl;
}

void Implicancia(std::vector<std::string> &argList){
    std::vector<std::string> aux;
    std::string letra1;
    std::string letra2;
    std::string letra3;
    int c=0;
    for(int i=0;i<argList.size();i++)
    {
        if (std::string(argList[i]) == "~"){
            c=i+1;
            if(std::string(argList[i]) == "p" || std::string(argList[i]) == "q" || std::string(argList[i]) == "r"){
                c+=1;
                letra1=std::string(argList[i]);
                if (std::string(argList[c]) == "=>")
                    {
                    c+=1;
                    if (std::string(argList[c]) == "p" || std::string(argList[c]) == "q" || std::string(argList[c]) == "r"){
                        letra2=std::string(argList[c]);
                        c+=1;
                        int j=0;
                        for(j=0; j<=i; j++){
                            aux.push_back(argList[j]);
                        }
                        aux.push_back("~");
                        aux.push_back(letra1);
                        aux.push_back("||");
                        aux.push_back(letra2);
                        int q=0;
                        c+=1;
                        for(int q=c; q<argList.size(); q++){
                        aux.push_back(argList[q]);
                        }
                        argList=aux;
                        aux.clear();
                    }
                }
            }
            else if (std::string(argList[i]) == "("){
                c+=1;
                if (std::string(argList[i]) == "p" || std::string(argList[i]) == "q" || std::string(argList[i]) == "r"){
                    letra1=std::string(argList[i]);
                    c+=1;
                    if (std::string(argList[i]) == "=>"){
                        c+=1;
                        if (std::string(argList[i]) == "=>"){
                            c+=1;
                            if (std::string(argList[i]) == "p" || std::string(argList[i]) == "q" || std::string(argList[i]) == "r"){
                                letra2=std::string(argList[i]);
                                c+=1;
                                if (std::string(argList[i]) == ")"){
                                    c+=1;
                                    for(int j=0; j<=i; j++){
                                        aux.push_back(argList[j]);
                                    }
                                    aux.push_back("~");
                                    aux.push_back(letra1);
                                    aux.push_back("||");
                                    aux.push_back(letra2);
                                    int q=0;
                                    c+=1;
                                    for(int q=c; q<argList.size(); q++)
                                    {
                                    aux.push_back(argList[q]);
                                    }
                                    argList=aux;
                                    aux.clear();
                                }
                            }
                        }
                }
            }

        else if (std::string(argList[i]) == "p" || std::string(argList[i]) == "q" || std::string(argList[i]) == "r")
        {
            letra1=std::string(argList[i]);
            c=i+1;
            if(std::string(argList[i]) == "&&" ){
                c+=1;
                if(std::string(argList[i]) == "(" ){
                    c+=1;
                    if(std::string(argList[i]) == "p" || std::string(argList[i]) == "q" || std::string(argList[i]) == "r"){
                        letra2=std::string(argList[i]);
                        c+=1;
                        if(std::string(argList[i]) == "=>" ){
                            c+=1;
                            if (std::string(argList[i]) == "p" || std::string(argList[i]) == "q" || std::string(argList[i]) == "r"){
                                letra3=std::string(argList[i]);
                                c+=1;
                                 if(std::string(argList[i]) == "(" )
                                {
                                    c+=1;
                                    for(int j=0; j<=i; j++){
                                        aux.push_back(argList[j]);
                                    }
                                    aux.push_back("(");
                                    aux.push_back(letra1);
                                    aux.push_back("&&");
                                    aux.push_back(letra2);
                                    int q=0;
                                    c+=1;
                                    for(int q=c; q<argList.size(); q++)
                                    {
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
    }
}
}
