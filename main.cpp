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
    string nombres[TAM];
    int edades[TAM]={};
    int kgAlimentos[TAM]={};
    int porcRefugio[TAM]={};
    int diasDeArmado[TAM]={};
    int horasDeLlegada[TAM] = {};
    int jugadoresVivos[TAM] = {1,1,1,1,1,1,1,1};

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

        cout<<"================================================="<<endl << endl;
        cout<<"1- Iniciar juego. "<<endl<<endl;
        cout<<"0- Salir. "<<endl<<endl;
        cout<<"================================================="<<endl << endl;
        cin>>opcion;

        if(opcion == 1){
            system("cls");
            nombreYEdad(TAM, nombres, edades);
            system("pause");
            system("cls");
            cout << "Ha comenzado un nuevo juego." << endl << endl;
            cout << "Etapa 1. Tienes 7 dias para recolectar alimentos y materiales para tu refugio" << endl << endl;
            porcRefugio[0] = 50;
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
                        recoleccionBots(TAM, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, dia);
                    }
                }else if(eleccion == 2){
                    bool turnoMaterialesValido = recolectarMateriales(TAM, kgAlimentos, porcRefugio, diasDeArmado, dia);
                    if(turnoMaterialesValido){
                        recoleccionBots(TAM, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, dia);
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
                cout << "Alimentos de " << nombres[i] << ": " << kgAlimentos[i] << "kgs" << endl;
            }
            cout << endl << "TABLA DE PORCENTAJE DE REFUGIO:" << endl;
            for(int i=0; i<TAM; i++){
                cout << "Refugio de " << nombres[i] << ": " << porcRefugio[i] << "%" << endl;
            }
            cout << endl << "TABLA DE DIAS DE ARMADO DE REFUGIO:" << endl;
            for(int i=0; i<TAM; i++){
                cout << "Refugio de " << nombres[i] << " armado en: " << diasDeArmado[i] << " dias" << endl;
            }
            bool jugadorVivo = (kgAlimentos[0] >= 14 && diasDeArmado[0] != 0);
            system("pause");
            system("cls");
            int resultadoEstadisticasEtapa1 = estadisticasEtapa1(TAM, kgAlimentos, diasDeArmado, nombres, edades, dia, jugadorVivo);
            if(resultadoEstadisticasEtapa1 == 0){
                cout << endl << "Juego terminado. Gracias por jugar" << endl;
                return 0;
            }
            if(resultadoEstadisticasEtapa1 == 5 && jugadorVivo){
                chequearVivos(TAM, kgAlimentos, diasDeArmado, jugadoresVivos);
                for(int i=0; i<TAM; i++){
                    if(jugadoresVivos[i] == 1){
                        kgAlimentos[i] -= 14;
                    }else{
                        kgAlimentos[i] = 0;
                    }
                    diasDeArmado[i] = 0;
                    porcRefugio[i] = 0;
                }
                cout << "Etapa 2." << endl;
                cout << "Tienes 6 dias para recolectar alimentos y materiales para tu balsa de escape" << endl << endl;
                porcRefugio[0] = 50;
                for (dia=0; dia<6; dia++){
                    cout << "Dia " << dia+1 << endl;
                    if(porcRefugio[0] < 100){
                        cout << "1- Recolectar alimentos" << endl;
                        cout << "2- Recolectar materiales" << endl;
                    }else{
                        cout << "1- Recolectar alimentos" << endl;
                        cout << "Balsa Completada" << endl;
                    }
                    cin >>eleccion;

                    if(eleccion == 1){
                        bool turnoAlimentosValido = recolectarAlimentos(TAM, kgAlimentos, porcRefugio, dia);
                        if(turnoAlimentosValido){
                            recoleccionBots(TAM, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, dia);
                        }
                    }else if(eleccion == 2){
                        bool turnoMaterialesValido = recolectarMaterialesBalsa(TAM, kgAlimentos, porcRefugio, diasDeArmado, dia);
                        if(turnoMaterialesValido){
                            recoleccionBots(TAM, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, dia);
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
                    if(jugadoresVivos[i] == 1){
                        cout << "Alimentos de " << nombres[i] << ": " << kgAlimentos[i] << "kgs" << endl;
                    }
                }
                cout << endl << "TABLA DE PORCENTAJE DE BALSA:" << endl;
                for(int i=0; i<TAM; i++){
                    if(jugadoresVivos[i] == 1){
                        cout << "Balsa de " << nombres[i] << ": " << porcRefugio[i] << "%" << endl;
                    }
                }
                cout << endl << "TABLA DE DIAS DE ARMADO DE BALSA:" << endl;
                for(int i=0; i<TAM; i++){
                    if(jugadoresVivos[i] == 1){
                        cout << "Balsa de " << nombres[i] << " armada en: " << diasDeArmado[i] << " dias" << endl;
                    }
                }
                bool jugadorVivo = (kgAlimentos[0] >= 14 && diasDeArmado[0] != 0);
                int resultadoEstadisticasEtapa2 = estadisticasEtapa2(TAM, kgAlimentos, diasDeArmado, jugadoresVivos, nombres, edades, dia, jugadorVivo);
                if(resultadoEstadisticasEtapa2 == 0){
                    cout << endl << "Juego terminado. Gracias por jugar" << endl;
                    return 0;
                }
                if(resultadoEstadisticasEtapa2 == 4 && jugadorVivo){
                    chequearVivos(TAM, kgAlimentos, diasDeArmado, jugadoresVivos);
                    eleccionFinal(eleccion, horasDeLlegada);
                    eleccionFinalBots(TAM, horasDeLlegada, jugadoresVivos);
                    system("pause");
                    system("cls");
                    cout << "TABLA DE DIAS DE LLEGADA:" << endl;
                    for(int i=0; i<TAM; i++){
                        if(jugadoresVivos[i] == 1){
                            cout << "Horas de " << nombres[i] << ": " << horasDeLlegada[i] << "hs" << endl;
                        }
                    }
                    system("pause");
                    system("cls");

                }
                int resultadoEstadisticasEtapa3 = estadisticasEtapa3(TAM, kgAlimentos, diasDeArmado, jugadoresVivos, horasDeLlegada, porcRefugio, nombres, edades,dia, jugadorVivo);
                if(resultadoEstadisticasEtapa3 == 0){
                    cout << endl << "Juego terminado. Gracias por jugar" << endl;
                    return 0;
                }
            }
        }
    }

    if(opcion == 0){
        cout << endl << "Juego terminado. Gracias por jugar" << endl;
    }

    return 0;
}
