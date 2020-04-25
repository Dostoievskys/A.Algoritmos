#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

//Función que muestra los participantes del grupo
void participantes();

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
    1 Braulio
    2 Jennifer
    3 Fanny
    4 Braulio
    5 Jennifer
    6 Fanny
    7 Braulio
    8 Jennifer
    9 Fanny
 */
int main(int argc, char** argv) {

    /**
     * Incluir acá la lógica del programa
     *
     */
    string lala="( ~ p || ~ p ) ( ~ p || ~ p ) ( ~ p || ~ p ) ( ~ p || ~ p ) ( ~ p || ~ p ) ( ~ p || ~ p )";
    cout << lala <<endl;
    int largo=lala.length();
    cout<<largo<<endl;
    if (argc > 0) { //Era mayor que 1
        // @TODO programar proyecto
        for(int i=0; i<lala.length(); i++){//el largo es argv.lenght()
              int c, t=0;
              char aux[lala.length()];
              int a=112;
              if(lala[i]==a){
                c=i+2;
                if(lala[c]=='&'|| lala[c]=='|'){
                        c+=3;
                    if(lala[c]=='p'){
                        int t=0;
                        for(t;t<=i;t++){
                            aux[t]=lala[t];
                        }
                        for(int u=c+1; u<lala.length();u++){
                            aux[t]=lala[u];
                            t++;
                        }
                        lala=aux;
                        i=i+7;
                        }

                    if(lala[i-2]=='~'&& lala[c] =='~'){
                            c+=2;
                            if(lala[c]=='p'){
                            for(t;t<=i;t++){
                                aux[t]=lala[t];
                            }
                            for(int u=c+1; u<lala.length();u++){
                                aux[t]=lala[u];
                                t++;
                            }
                            lala=aux;
                            i=i+7;
                            }
                        }
                    }
                }
              }
    } else {
        // Mostrar los integrantes
        participantes();
    }
    cout << lala <<endl;
    system("Pause");
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Taller 01 ===" << std::endl;
    std::cout << std::endl << "Braulio Argandoña"; // Reemplazar por su nombre
    std::cout << std::endl << "Fanny Rivero"; // Reemplazar por su nombre
    std::cout << std::endl << "Jennifer Portiño" << std::endl; // Reemplazar por su nombre
}

