#include <iostream>
#include <time.h>
#include <string>
#include "rlutil.h"
#include "Funciones.h"
#include "funciones_visuales.h"
#include "funciones_stats.h"

using namespace std;

int main(){
    srand(time(NULL));
    const int TAM = 8;
    string nombres[TAM];
    int edades[TAM]={};
    int dia;
    int kgAlimentos[TAM]= {};
    int porcRefugio[TAM]= {};
    int diasDeArmado[TAM]= {};
    int horasDeLlegada[TAM] = {};
    int jugadoresVivos[TAM] = {1,1,1,1,1,1,1,1};
    rlutil::hidecursor();
    mostrarBannerInicial();
    int opcion = 1;

    while(opcion != 0){

        std::string opcionesMenu[] = {" Nuevo Juego ", "    Salir    "};

        int seleccion = mostrarMenu(opcionesMenu, 2, 1, 1);

        if(seleccion == 0){
            opcion = 1;
        }else{
            opcion = 0;
        }

        if(opcion == 1){
            system("cls");
            nombreYEdad(TAM, nombres, edades);
            int nroEtapa = 1;
            mostrarTextosEtapa(nroEtapa, nombres);
            porcRefugio[0]=50;
            int eleccion;
            string opcionesMenu[2] = {};
            for(dia=0; dia<7; dia++){
                rlutil::locate(1,1);
                cout << "Dia " << dia+1 << endl << endl;
                opcionesMenu[0] = "Recolectar alimentos";
                if (porcRefugio[0] < 100){
                    opcionesMenu[1] = "Recolectar materiales";
                }else{
                    opcionesMenu[1] = "Refugio Completado";
                }

                bool seguir = true;
                do{
                    int seleccion = mostrarMenu(opcionesMenu, 2, 2, 3);
                    if (seleccion == 0) {
                        eleccion = 1;
                        seguir = false;
                    } else {
                        eleccion = 2;
                        seguir = false;
                    }
                }while(seguir);

                if(eleccion == 1){
                    recolectarAlimentos(TAM, kgAlimentos, porcRefugio, dia);
                    recoleccionBots(TAM, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, dia);
                }else if(eleccion == 2){
                    bool turnoMaterialesValido = recolectarMateriales(TAM, kgAlimentos, porcRefugio, diasDeArmado, dia);
                    if(turnoMaterialesValido){
                        recoleccionBots(TAM, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, dia);
                    }
                }
                system("pause");
                system("cls");
            }
            mostrarTablasFinEtapa(TAM, nroEtapa, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, horasDeLlegada ,nombres);
            bool jugadorVivo = (kgAlimentos[0] >= 14 && diasDeArmado[0] != 0);
            int resultadoEstadisticasEtapa1 = estadisticasEtapa(TAM, nroEtapa, kgAlimentos, diasDeArmado, jugadoresVivos, nombres, edades, dia, jugadorVivo);
            if(resultadoEstadisticasEtapa1 == 0){
                system("cls");
                cout << endl << "Juego terminado. Gracias por jugar" << endl;
                return 0;
            }
            if(resultadoEstadisticasEtapa1 == 4 && jugadorVivo){
                nroEtapa++;
                mostrarTextosEtapa(nroEtapa, nombres);
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
                porcRefugio[0] = 50;
                string opcionesMenu[2] = {};
                for (dia=0; dia<6; dia++){
                    cout << "Dia " << dia+1 << endl;
                    opcionesMenu[0] = "Recolectar alimentos";
                    if (porcRefugio[0] < 100){
                        opcionesMenu[1] = "Recolectar materiales";
                    }else{
                        opcionesMenu[1] = "Balsa Completada";
                    }

                    bool seguir = true;
                    do{
                        int seleccion = mostrarMenu(opcionesMenu, 2, 2, 3);
                        if (seleccion == 0) {
                            eleccion = 1;
                            seguir = false;
                        } else {
                            eleccion = 2;
                            seguir = false;
                        }
                    }while(seguir);

                    if(eleccion == 1){
                        recolectarAlimentos(TAM, kgAlimentos, porcRefugio, dia);
                        recoleccionBots(TAM, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, dia);
                    }else if(eleccion == 2){
                        bool turnoMaterialesValido = recolectarMaterialesBalsa(TAM, kgAlimentos, porcRefugio, diasDeArmado, dia);
                        if(turnoMaterialesValido){
                            recoleccionBots(TAM, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, dia);
                        }
                    }
                    system("pause");
                    system("cls");
                }
                mostrarTablasFinEtapa(TAM, nroEtapa, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, horasDeLlegada ,nombres);
                bool jugadorVivo = (kgAlimentos[0] >= 14 && diasDeArmado[0] != 0);
                int resultadoEstadisticasEtapa2 = estadisticasEtapa(TAM, nroEtapa, kgAlimentos, diasDeArmado, jugadoresVivos, nombres, edades, dia, jugadorVivo);
                if(resultadoEstadisticasEtapa2 == 0){
                    system("cls");
                    cout << endl << "Juego terminado. Gracias por jugar" << endl;
                    return 0;
                }
                if(resultadoEstadisticasEtapa2 == 4 && jugadorVivo){
                    nroEtapa++;
                    mostrarTextosEtapa(nroEtapa, nombres);
                    chequearVivos(TAM, kgAlimentos, diasDeArmado, jugadoresVivos);
                    eleccionFinal(eleccion, horasDeLlegada);
                    eleccionFinalBots(TAM, horasDeLlegada, jugadoresVivos);
                    mostrarTablasFinEtapa(TAM, nroEtapa, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, horasDeLlegada ,nombres);
                }
                int resultadoEstadisticasEtapa3 = estadisticasEtapa3(TAM, kgAlimentos, diasDeArmado, jugadoresVivos, horasDeLlegada, porcRefugio, nombres, edades,dia, jugadorVivo);
                if(resultadoEstadisticasEtapa3 == 0){
                    system("cls");
                    cout << endl << "Juego terminado. Gracias por jugar" << endl;
                    return 0;
                }
            }
        }
    }
    system("cls");
    cout << endl << "Juego terminado. Gracias por jugar" << endl;

    return 0;
}
