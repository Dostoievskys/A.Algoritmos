#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include<stdio.h>
#include <string>
#include <vector>

void participantes();//Funci�n que muestra los participantes del grupo
void Idempotencia(std::vector<std::string>&, std::string);     //Funcion Idempotencia simplifica p,q o r -> a = p,q o r; hay asignar el valor
void DeMorgan(std::vector<std::string>&);
void Conmutativa(std::vector<std::string>&);

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El c�digo de salida del programa
*/

int main(int argc, char** argv) {
    std::vector<std::string> argList;  // Aqui se almacena lo de argv y aqui voy modificando
    std::string a="p";                 // Variable para comparar en idempotencia, fue de ejemplo
    if (argc > 1) {
        for(int i=1;i<argc;i++){
            argList.push_back(argv[i]);     //Agrego uno por uno lo recibido por consola ignorando el argv[0] que es el nombre del programa
        }
        std::cout << std::endl << "=== Original ===" << std::endl;  //Imprimo lo ingresado inicialmente
        for(int i=0;i<argList.size();i++){
            std::cout<<argList[i]<<" Posicion: "<<i<<std::endl;}
        //Llamado de funciones
        //DeMorgan(argList);
        //Idempotencia(argList, a); //Maravillosa funcion; a puede ser "q", "p" o "r" como str no usar char
        Conmutativa(argList);

        std::cout << std::endl << "=== Modificada ===" << std::endl; //Imprimo lo modificado post idempotencia
        for(int i=0;i<argList.size();i++){
            std::cout<<argList[i]<<" Posicion: "<<i<<std::endl;}
    }
    else {
        participantes();//Mostrar los integrantes
    }
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Taller 01 ===" << std::endl;
    std::cout << std::endl << "Braulio Argando\244a";
    std::cout << std::endl << "Fanny Rivero";
    std::cout << std::endl << "Jennifer Porti\244o" << std::endl;
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

void DeMorgan(std::vector<std::string> &argList){
    std::vector<std::string> aux;

    for(int i=0;i<argList.size();i++){ //Recorre argList
        if(std::string(argList[i])=="~" ){ //Busca la negacion
                if(std::string(argList[i+1])=="("){ //Pregunta si hay un parentesis despues de la negacion y hace un intercambio
                    aux = argList;
                    aux[i] = "(";
                    aux[i+1]= "~";
                    argList=aux;
                    for(int j=i;j<aux.size();j++){//recorre el auxiliar
                            if(std::string(aux[j])=="&"){//si encuentra un & lo cambia por |
                                argList[j]= "|";
                                //Si despues del & hay una letra p, q o r, agrega el ~ correspondiente
                                if(std::string(aux[j+1])=="p" || std::string(argList[j+1])=="q" || std::string(argList[j+1])=="r"){
                                    argList.insert(argList.begin()+j+1,"~"); //Agrega al vector en la posicion argList.begin()+j+1 el argumento "~"
                                }
                            }
                            if(std::string(aux[j])=="|"){//si encuentra un | lo cambia por &
                                argList[j]= "&";
                                if(std::string(aux[j+1])=="p" || std::string(argList[j+1])=="q" || std::string(argList[j+1])=="r"){
                                    argList.insert(argList.begin()+j+1,"~");
                                }
                            }
                    }
                }
                //Se repite el codigo anterior pero ahora para un parentesis [
                if(std::string(argList[i+1])=="["){ //Pregunta si hay un parentesis despues de la negacion y hace un intercambio
                    aux = argList;
                    aux[i] = "[";
                    aux[i+1]="~";
                    argList=aux;
                    for(int j=i;j<aux.size();j++){
                            if(std::string(aux[j])=="&"){
                                argList[j]= "|";
                                if(std::string(aux[j+1])=="p" || std::string(argList[j+1])=="q" || std::string(argList[j+1])=="r"){
                                    argList.insert(argList.begin()+j+1,"~");
                                }
                            }
                            if(std::string(aux[j])=="|"){
                                argList[j]= "&";
                                if(std::string(aux[j+1])=="p" || std::string(argList[j+1])=="q" || std::string(argList[j+1])=="r"){
                                    argList.insert(argList.begin()+j+1,"~");
                                }
                            }
                    }
                }
            }
        }
    }

void Conmutativa(std::vector<std::string> &argList){
    std::vector<std::string> aux;

    for(int i=0;i<argList.size();i++){
        if(std::string(argList[i])=="p"){
            if(i+3 < argList.size()){
                aux=argList;
                aux[i] = aux[i+3];
                aux[i+3]= "p";
                argList=aux;
                aux.clear();
            }
        }
        if(std::string(argList[i])=="q"){
            if(i+3 < argList.size()){
                aux=argList;
                aux[i] = argList[i+3];
                aux[i+3]= "q";
                argList=aux;
                aux.clear();
            }
        }
        if(std::string(argList[i])=="r"){
            if(i+3 < argList.size()){
                aux=argList;
                aux[i] = argList[i+3];
                aux[i+3]= "r";
                argList=aux;
                aux.clear();
            }
        }
    }
}
