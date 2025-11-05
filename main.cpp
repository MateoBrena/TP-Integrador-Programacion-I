#include <iostream>
#include <time.h>
#include <string>
#include "Funciones.h"

using namespace std;

int main(){

    srand(time(NULL));
    const int TAM=8;
    int eleccion;
    int dia;
    int kgAlimentos[TAM]={0};
    int porcRefugio[TAM]={0};
    int diasDeArmado[TAM]={0};

    cout<< R"(
    ================================================================
       ____  ___  ___  _________  ________  ___      _________
       |\  \|\  \|\  \|\   ___  \|\   ____\|\  \     |\   __  \
       \ \  \ \  \\\  \ \  \\ \  \ \  \___|\ \  \    \ \  \|\  \
     __ \ \  \ \  \\\  \ \  \\ \  \ \  \  __\ \  \    \ \   __  \
    |\  \\_\  \ \  \\\  \ \  \\ \  \ \  \|\  \ \  \____\ \  \ \  \
    \ \________\ \_______\ \__\\ \__\ \_______\ \_______\ \__\ \__\
     \|________|\|_______|\|__| \|__|\|_______|\|_______|\|__|\|__|

    ================================================================
                        SUPERVIVENCIA EN LA SELVA
    ================================================================

            Te despiertas en medio de una jungla densa...
            No recuerdas como llegaste aqui.
            El sol esta cayendo, los sonidos de animales te rodean.)" << endl << endl;
    system("pause");
    system("cls");

    int opcion = 1;

    while(opcion != 0){

        cout<<"================================================="<<endl;
        cout<<"1- Iniciar juego. "<<endl;
        cout<<"0- Salir. "<<endl;
        cout<<"================================================="<<endl;
        cin>>opcion;

        if(opcion == 1){
            system("cls");
            cout << "Ha comenzado un nuevo juego" << endl;
            cout << "Etapa 1. Tienes 7 dias para recolectar alimentos y materiales para tu refugio" << endl << endl;
            for (dia=0; dia<7; dia++){
                cout << "Dia " << dia+1 << endl;
                if(porcRefugio[0] < 100){
                    cout << "1- Recolectar alimentos" << endl;
                    cout << "2- Recolectar materiales" << endl;
                }else{
                    cout << "1- Recolectar alimentos" << endl;
                    cout << "Refugio Completado" << endl;
                }
                cin >>eleccion;

                if(eleccion == 1){
                    bool turnoAlimentosValido = recolectarAlimentos(TAM, kgAlimentos, porcRefugio, dia);
                    if(turnoAlimentosValido){
                        recoleccionBots(TAM, kgAlimentos, porcRefugio, diasDeArmado, dia);
                    }
                }else if(eleccion == 2){
                    bool turnoMaterialesValido = recolectarMateriales(TAM, kgAlimentos, porcRefugio, diasDeArmado, dia);
                    if(turnoMaterialesValido){
                        recoleccionBots(TAM, kgAlimentos, porcRefugio, diasDeArmado, dia);
                    }
                }else{
                    dia -= 1;
                    cout << "No ha elegido una opcion valida. Vuelva a seleccionar" << endl;
                }
                system("pause");
                system("cls");
            }
            cout << "TABLA DE ALIMENTOS:" << endl;
            for(int i=0; i<TAM; i++){
                cout << "Alimentos de jugador " << i+1 << ": " << kgAlimentos[i] << "kgs" << endl;
            }
            cout << endl << "TABLA DE PORCENTAJE DE REFUGIO:" << endl;
            for(int i=0; i<TAM; i++){
                cout << "Refugio de jugador " << i+1 << ": " << porcRefugio[i] << "%" << endl;
            }
            cout << endl << "TABLA DE DIAS DE ARMADO DE REFUGIO:" << endl;
            for(int i=0; i<TAM; i++){
                cout << "Refugio de jugador " << i+1 << " armado en: " << diasDeArmado[i] << " dias" << endl;
            }

            system("pause");
            system("cls");
            int opcionStats;
            cout << "===========================================================================" << endl;
            cout << "                           ESTADISTICAS ETAPA 1                            " << endl;
            cout << "===========================================================================" << endl;
            cout << "1- Participantes que superaron el promedio de kg de alimentos recolectados" << endl;
            cout << "2- Participante mas rapido en construir su refugio" << endl;
            cout << "3- Participantes que tardaron mas de 5 dias en constuir su refugio" << endl;
            cout << "4- Tabla de posiciones" << endl;
            cout << "5- Continuar a la segunda etapa" << endl;
            cout << "0- Salir del juego" << endl;
            cin >> opcionStats;

            while(opcionStats != 0){
                system("cls");
                switch(opcionStats){
                    case 1:
                         promedioAlimentos(TAM, kgAlimentos);
                        break;
                    case 2:
                        refugioMasRapido(TAM, diasDeArmado);
                        break;
                    case 3:
                        refugioMas5Dias(TAM, diasDeArmado);
                        break;
                    case 4:
                        cout << "Proximamente..." << endl;
                        break;
                    case 5:
                        cout << "Etapa 2" << endl;
                        break;
                    case 0:
                        break;
                }
                system("pause");
                system("cls");
                cout << "============================================" << endl;
                cout << "          ESTADISTICAS ETAPA 1              " << endl;
                cout << "============================================" << endl;
                cout << "1- Participantes que superaron el promedio de kg de alimentos recolectados" << endl;
                cout << "2- Paricipante mas rapido en construir su refugio" << endl;
                cout << "3- Participantes que tardaron mas de 5 dias en constuir su refugio" << endl;
                cout << "4- Tabla de posiciones" << endl;
                cout << "5- Continuar a la segunda etapa" << endl;
                cout << "0- Salir del juego" << endl;
                cin >> opcionStats;
            }
            if(opcionStats == 0){
                break;
            }
        }
    }

    cout << endl << "Ha salido del juego" << endl;

    return 0;
}
