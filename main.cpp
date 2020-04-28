#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <vector>

void participantes();//Funci�n que muestra los participantes del grupo
void Asociativa(std::vector<std::string>&);
/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El c�digo de salida del programa
*/

int main(int argc, char** argv) {
    std::vector<std::string> argList;  // Aqui se almacena lo de argv y aqui voy modificando
    std::string a="p"; // Variable para comparar en idempotencia, fue de ejemplo
    if (argc > 1) {
        for(int i=1;i<argc;i++){
            argList.push_back(argv[i]);     //Agrego uno por uno lo recibido por consola ignorando el argv[0] que es el nombre del programa
        }
    }
    else {
        // Mostrar los integrantes
        participantes();
        }

    Asociativa (argList);
    std::cout << std::endl << "=== Modificada ===" << std::endl; //Imprimo lo modificado post idempotencia
    for(int i=0;i<argList.size();i++){
        std::cout<<argList[i]<<" Posicion: "<<i<<std::endl;
    }
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Taller 01 ===" << std::endl;
    std::cout << std::endl << "Braulio Argando�a";
    std::cout << std::endl << "Fanny Rivero";
    std::cout << std::endl << "Jennifer Porti�o" << std::endl;
}
void Asociativa(std::vector<std::string> &argList)
{

    std::vector<std::string> aux;
    for(int i=0;i<argList.size();i++)
    { //Recorre argList
        if(std::string(argList[i])== "["){ //Busca el corchete
            int c=i+1;
            if (std::string(argList[c]) == "("){
                c+=1;
                if (std::string(argList[c]) == "p" ){
                    c+=1;
                    if (std::string(argList[c]) == "&&"){
                        c+=1;
                        if (std::string(argList[c]) == "q"){
                            c+=1;
                            if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "&&"){
                                    c+=1;
                                    if (std::string(argList[c]) == "r"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]"){
                                        for(int j= 0; j<=i; j++)
                                        {
                                            aux.push_back(argList[j]);              //Agrega todo lo anterior a estructura al aux
                                        }
                                        aux.push_back(" [");
                                        aux.push_back(" p");
                                        aux.push_back(" &&");
                                        aux.push_back(" (");
                                        aux.push_back(" q");
                                        aux.push_back(" &&");
                                        aux.push_back(" r");
                                        aux.push_back(" )");
                                        aux.push_back(" ]");
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
                            }
                        }
                    }
                    else if (std::string(argList[c]) == "r"){
                        c+=1;
                        if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "&&"){
                                    c+=1;
                                    if (std::string(argList[c]) == "q"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]")
                                        {
                                                for(int j= 0; j<=i; j++)
                                                {
                                                    aux.push_back(argList[j]);
                                                }
                                                aux.push_back(" [");
                                                aux.push_back(" p");
                                                aux.push_back(" &&");
                                                aux.push_back(" (");
                                                aux.push_back(" r");
                                                aux.push_back(" &&");
                                                aux.push_back(" q");
                                                aux.push_back(" )");
                                                aux.push_back(" ]");
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
                        }
                    }
                }
            if (std::string(argList[c]) == "q" )
            {
                    c+=1;
                    if (std::string(argList[c]) == "&&"){
                        c+=1;
                        if (std::string(argList[c]) == "p"){
                            c+=1;
                            if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "&&"){
                                    c+=1;
                                    if (std::string(argList[c]) == "r"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]"){
                                        for(int j= 0; j<=i; j++)
                                        {
                                            aux.push_back(argList[j]);              //Agrega todo lo anterior a estructura al aux
                                        }
                                        aux.push_back(" [");
                                        aux.push_back(" q");
                                        aux.push_back(" &&");
                                        aux.push_back(" (");
                                        aux.push_back(" p");
                                        aux.push_back(" &&");
                                        aux.push_back(" r");
                                        aux.push_back(" )");
                                        aux.push_back(" ]");
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
                        }
                    }
                    }
                    if (std::string(argList[c]) == "r"){
                        c+=1;
                        if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "&&"){
                                    c+=1;
                                    if (std::string(argList[c]) == "p"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]"){
                                        for(int j= 0; j<=i; j++)
                                        {
                                            aux.push_back(argList[j]);              //Agrega todo lo anterior a estructura al aux
                                        }
                                        aux.push_back(" [");
                                        aux.push_back(" q");
                                        aux.push_back(" &&");
                                        aux.push_back(" (");
                                        aux.push_back(" r");
                                        aux.push_back(" &&");
                                        aux.push_back(" p");
                                        aux.push_back(" )");
                                        aux.push_back(" ]");
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
                        }
                    }
               }
            if (std::string(argList[c]) == "r" ){
                c=c+1;
                if (std::string(argList[c]) == "&&"){
                        c+=1;
                        if (std::string(argList[c]) == "p"){
                            c+=1;
                            if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "&&"){
                                    c+=1;
                                    if (std::string(argList[c]) == "q"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]"){
                                        for(int j= 0; j<=i; j++)
                                        {
                                            aux.push_back(argList[j]);              //Agrega todo lo anterior a estructura al aux
                                        }
                                        aux.push_back(" [");
                                        aux.push_back(" r");
                                        aux.push_back(" &&");
                                        aux.push_back(" (");
                                        aux.push_back(" p");
                                        aux.push_back(" &&");
                                        aux.push_back(" q");
                                        aux.push_back(" )");
                                        aux.push_back(" ]");
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
                            }
                        }
                    if (std::string(argList[c]) == "q"){
                            c+=1;
                            if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "&&"){
                                    c+=1;
                                    if (std::string(argList[c]) == "p"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]"){
                                        for(int j= 0; j<=i; j++)
                                        {
                                            aux.push_back(argList[j]);              //Agrega todo lo anterior a estructura al aux
                                        }
                                        aux.push_back(" [");
                                        aux.push_back(" r");
                                        aux.push_back(" &&");
                                        aux.push_back(" (");
                                        aux.push_back(" q");
                                        aux.push_back(" &&");
                                        aux.push_back(" p");
                                        aux.push_back(" )");
                                        aux.push_back(" ]");
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
                            }
                        }
                    }
                }
            if (std::string(argList[c]) == "p" ){
                    c+=1;
                    if (std::string(argList[c]) == "||"){
                        c+=1;
                        if (std::string(argList[c]) == "q"){
                            c+=1;
                            if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "||"){
                                    c+=1;
                                    if (std::string(argList[c]) == "r"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]"){
                                        for(int j= 0; j<=i; j++)
                                        {
                                            aux.push_back(argList[j]);              //Agrega todo lo anterior a estructura al aux
                                        }
                                        aux.push_back(" [");
                                        aux.push_back(" p");
                                        aux.push_back(" ||");
                                        aux.push_back(" (");
                                        aux.push_back(" q");
                                        aux.push_back(" ||");
                                        aux.push_back(" r");
                                        aux.push_back(" )");
                                        aux.push_back(" ]");
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
                            }
                        }
                    if (std::string(argList[c]) == "r"){
                            c+=1;
                            if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "||"){
                                    c+=1;
                                    if (std::string(argList[c]) == "q"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]"){
                                        for(int j= 0; j<=i; j++)
                                        {
                                            aux.push_back(argList[j]);              //Agrega todo lo anterior a estructura al aux
                                        }
                                        aux.push_back(" [");
                                        aux.push_back(" p");
                                        aux.push_back(" ||");
                                        aux.push_back(" (");
                                        aux.push_back(" r");
                                        aux.push_back(" ||");
                                        aux.push_back(" q");
                                        aux.push_back(" )");
                                        aux.push_back(" ]");
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
                            }
                        }
                    }
                 if (std::string(argList[c]) == "q" ){
                    c+=1;
                    if (std::string(argList[c]) == "||"){
                        c+=1;
                        if (std::string(argList[c]) == "p"){
                            c+=1;
                            if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "||"){
                                    c+=1;
                                    if (std::string(argList[c]) == "r"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]"){
                                        for(int j= 0; j<=i; j++)
                                        {
                                            aux.push_back(argList[j]);              //Agrega todo lo anterior a estructura al aux
                                        }
                                        aux.push_back(" [");
                                        aux.push_back(" q");
                                        aux.push_back(" ||");
                                        aux.push_back(" (");
                                        aux.push_back(" p");
                                        aux.push_back(" ||");
                                        aux.push_back(" r");
                                        aux.push_back(" )");
                                        aux.push_back(" ]");
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
                            }
                        }
                        if (std::string(argList[c]) == "r"){
                            c+=1;
                            if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "||"){
                                    c+=1;
                                    if (std::string(argList[c]) == "p"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]"){
                                        for(int j= 0; j<=i; j++)
                                        {
                                            aux.push_back(argList[j]);              //Agrega todo lo anterior a estructura al aux
                                        }
                                        aux.push_back(" [");
                                        aux.push_back(" q");
                                        aux.push_back(" ||");
                                        aux.push_back(" (");
                                        aux.push_back(" r");
                                        aux.push_back(" ||");
                                        aux.push_back(" p");
                                        aux.push_back(" )");
                                        aux.push_back(" ]");
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
                            }
                        }
                    }
                }
                if (std::string(argList[c]) == "r" ){
                    c+=1;
                    if (std::string(argList[c]) == "||"){
                        c+=1;
                        if (std::string(argList[c]) == "p"){
                            c+=1;
                            if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "||"){
                                    c+=1;
                                    if (std::string(argList[c]) == "q"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]"){
                                        for(int j= 0; j<=i; j++)
                                        {
                                            aux.push_back(argList[j]);              //Agrega todo lo anterior a estructura al aux
                                        }
                                        aux.push_back(" [");
                                        aux.push_back(" r");
                                        aux.push_back(" ||");
                                        aux.push_back(" (");
                                        aux.push_back(" p");
                                        aux.push_back(" ||");
                                        aux.push_back(" q");
                                        aux.push_back(" )");
                                        aux.push_back(" ]");
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
                            }
                        if (std::string(argList[c]) == "||"){
                        c+=1;
                        if (std::string(argList[c]) == "q"){
                            c+=1;
                            if (std::string(argList[c]) == ")"){
                                c+=1;
                                if (std::string(argList[c]) == "||"){
                                    c+=1;
                                    if (std::string(argList[c]) == "p"){
                                        c+=1;
                                        if (std::string(argList[c]) == "]"){
                                        for(int j= 0; j<=i; j++)
                                        {
                                            aux.push_back(argList[j]);              //Agrega todo lo anterior a estructura al aux
                                        }
                                        aux.push_back(" [");
                                        aux.push_back(" r");
                                        aux.push_back(" ||");
                                        aux.push_back(" (");
                                        aux.push_back(" q");
                                        aux.push_back(" ||");
                                        aux.push_back(" p");
                                        aux.push_back(" )");
                                        aux.push_back(" ]");
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
