#include <iostream>
#include <time.h>
#include <string>
#include "rlutil.h"
#include "Funciones.h"

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
            El sol esta saliendo, los sonidos de animales te rodean.)" << endl << endl;
    system("pause");
    system("cls");

    int opcion = 1;

    while(opcion != 0){

        int comienzo = 1;
        int y = 0;
        do{
            rlutil::locate(1,1);
            cout<<"================================================="<<endl;
            mostrarSeleccionado(" Nuevo Juego ", 2, 2, y==0);
            mostrarSeleccionado("    Salir    ", 2, 3, y==1);
            rlutil::locate(1,4);
            cout<<"================================================="<<endl;
            int tecla = rlutil::getkey();
            switch(tecla){
                case 119: //arriba
                    rlutil::locate(2,2+y);
                    y--;
                    if(y<0){
                        y = 0;
                    }
                    break;
                case 115: // abajo
                    rlutil::locate(2,2+y);
                    y++;
                    if(y>1){
                        y = 1;
                    }
                    break;
                case 1: // enter
                    if(y == 0){
                        comienzo = 0;
                        opcion = 1;
                    }else{
                        comienzo = 0;
                        opcion = 0;
                    }
                    break;
            }
       }while(comienzo != 0);

        if(opcion == 1){
            system("cls");
            nombreYEdad(TAM, nombres, edades);
            system("pause");
            system("cls");
            cout << "Ha comenzado un nuevo juego." << endl << endl;
            cout << "Etapa 1" << endl << endl;
            cout << "Empiezas a escuchar un zumbido, es cada vez mas fuerte y sientes que se va acercando. Cuando levantas la vista" << endl;
            cout << "ves a un dron con una camara, te esta enfocando y da vueltas sobre ti hasta ponerse a la altura de tus ojos." << endl;
            cout << "Entonces, escuchas una voz que sale del dron. 'Bienvenido  " <<  nombres[0] << ", que bueno que hayas despertado."<<endl;
            cout << "Tienes mucho que hacer si quieres salir de la jungla con vida. No hay tiempo para explicaciones, debes recolectar" << endl;
            cout << "alimentos y construir un refugio. La jungla es despiadada, necesitas 2kg de alimentos por dia y un refugio completo" << endl;
            cout << "si quieres avanzar a la siguiente etapa. Debes completarlo en 7 dias, o seras eliminado, mucha suerte!'" << endl;
            cout << "El dron vuela hacia arriba rapidamente y desaparece en cuestion de segundos, decides comenzar a recolectar." << endl << endl;
            system("pause");
            system("cls");
            //porcRefugio[0]=50;
            int eleccion;
            for(dia=0; dia<7; dia++){
                rlutil::locate(1,1);
                cout << "Dia " << dia+1 << endl << endl;
                int y = 0;
                int opp = 1;
                do{
                    mostrarSeleccionado("Recolectar alimentos", 3, 3, y==0);
                    if(porcRefugio[0] < 100){
                        mostrarSeleccionado("Recolectar materiales", 3, 4, y==1);
                    }else{
                        mostrarSeleccionado("Refugio Completado", 3, 4, y==1);
                    }
                    int tecla = rlutil::getkey();
                    switch(tecla){
                        case 119: //arriba
                            rlutil::locate(3,3+y);
                            y--;
                            if(y<0){
                                y = 0;
                            }
                            break;
                        case 115: // abajo
                            rlutil::locate(3,3+y);
                            y++;
                            if(y>1){
                                y = 1;
                            }
                            break;
                        case 1: // enter
                            if(y == 0){
                                opp = 0;
                                eleccion = 1;
                            }else{
                                opp = 0;
                                eleccion = 2;
                            }
                            break;
                        }
                }while(opp != 0);

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
            cout << "TABLA DE ALIMENTOS:" << endl;
            for(int i=0; i<TAM; i++){
                if(kgAlimentos[i] < 14){
                    rlutil::setColor(rlutil::RED);
                    cout << "Alimentos de " << nombres[i] << ": " << kgAlimentos[i] << "kgs" << endl;
                }else{
                    rlutil::setColor(rlutil::GREY);
                    cout << "Alimentos de " << nombres[i] << ": " << kgAlimentos[i] << "kgs" << endl;
                }

            }
            rlutil::setColor(rlutil::GREY);
            cout << endl << "TABLA DE PORCENTAJE DE REFUGIO:" << endl;
            for(int i=0; i<TAM; i++){
                if(porcRefugio[i] < 100){
                    rlutil::setColor(rlutil::RED);
                    cout << "Porcentaje de refugio de " << nombres[i] << ": " << porcRefugio[i] << "%" << endl;
                }else{
                    rlutil::setColor(rlutil::GREY);
                    cout << "Porcentaje de refugio de " << nombres[i] << ": " << porcRefugio[i] << "%" << endl;
                }
            }
            rlutil::setColor(rlutil::GREY);
            cout << endl << "TABLA DE DIAS DE ARMADO DE REFUGIO:" << endl;
            for(int i=0; i<TAM; i++){
                if(diasDeArmado[i] == 0){
                    rlutil::setColor(rlutil::RED);
                    cout << "Refugio de " << nombres[i] << " armado en: " << diasDeArmado[i] << " dias" << endl;
                } else{
                    rlutil::setColor(rlutil::GREY);
                    cout << "Refugio de " << nombres[i] << " armado en: " << diasDeArmado[i] << " dias" << endl;
                }

            }
            rlutil::setColor(rlutil::GREY);
            system("pause");
            system("cls");
            bool jugadorVivo = (kgAlimentos[0] >= 14 && diasDeArmado[0] != 0);
            int resultadoEstadisticasEtapa1 = estadisticasEtapa1(TAM, kgAlimentos, diasDeArmado, nombres, edades, dia, jugadorVivo);
            if(resultadoEstadisticasEtapa1 == 0){
                system("cls");
                cout << endl << "Juego terminado. Gracias por jugar" << endl;
                return 0;
            }
            if(resultadoEstadisticasEtapa1 == 4 && jugadorVivo){
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
                cout << "Etapa 2" << endl << endl;
                cout << "El zumbido caracteristico vuelve a escucharse entre los arboles, cada vez mas cerca." << endl;
                cout << "Las hojas se agitan, los insectos huyen, y de pronto, el mismo dron de antes aparece" << endl;
                cout << "frente a ti, girando lentamente mientras su camara te enfoca de arriba a abajo." << endl;
                cout << "Una voz conocida resuena desde sus altavoces. 'Vaya, vaya, " << nombres[0] << "... sinceramente," << endl;
                cout << "no apostaba ni un centavo a que sobrevivirias la primera etapa. Pero mirate,"<< endl;
                cout << "todavia con pulso... felicitaciones!'" << endl;
                cout << "El dron emite un pitido que parece una risa digital y continua: 'Sin embargo, no cantes victoria tan pronto." << endl;
                cout << "Has superado la parte facil. Ahora deberas construir una balsa si quieres escapar de esta jungla.'" << endl;
                cout << "'Tienes solo 6 dias para reunir los materiales, armar la estructura y dejarla lista para zarpar." << endl;
                cout << "Si el rio te encuentra sin una balsa, bueno... digamos que los cocodrilos estaran encantados de conocerte.'" << endl;
                cout << "'Ah! Por cierto, espero que hayas juntado suficiente alimento, aun necesitas 2 kilos por dia, no lo olvides!'" << endl << endl;
                cout << "El dron se eleva lentamente, dando un ultimo giro sobre ti. 'Buena suerte, " << nombres[0] << ". La vas a necesitar...'" << endl << endl;
                system("pause");
                system("cls");
                //porcRefugio[0] = 50;
                for (dia=0; dia<6; dia++){
                    cout << "Dia " << dia+1 << endl;
                    int y = 0;
                    int opp = 1;
                    do{
                        mostrarSeleccionado("Recolectar alimentos", 3, 3, y==0);
                        if(porcRefugio[0] < 100){
                            mostrarSeleccionado("Recolectar materiales", 3, 4, y==1);
                        }else{
                            mostrarSeleccionado("Balsa completada", 3, 4, y==1);
                        }
                        int tecla = rlutil::getkey();
                        switch(tecla){
                            case 119: //arriba
                                rlutil::locate(3,3+y);
                                y--;
                                if(y<0){
                                    y = 0;
                                }
                                break;
                            case 115: // abajo
                                rlutil::locate(3,3+y);
                                y++;
                                if(y>1){
                                    y = 1;
                                }
                                break;
                            case 1: // enter
                                if(y == 0){
                                    opp = 0;
                                    eleccion = 1;
                                }else{
                                    opp = 0;
                                    eleccion = 2;
                                }
                                break;
                            }
                    }while(opp != 0);

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
                cout << "TABLA DE ALIMENTOS:" << endl;
                for(int i=0; i<TAM; i++){
                    if(jugadoresVivos[i] == 1){
                        if(kgAlimentos[i] < 14){
                            rlutil::setColor(rlutil::RED);
                            cout << "Alimentos de " << nombres[i] << ": " << kgAlimentos[i] << "kgs" << endl;
                        }else{
                            rlutil::setColor(rlutil::GREY);
                            cout << "Alimentos de " << nombres[i] << ": " << kgAlimentos[i] << "kgs" << endl;
                        }
                    }
                }
                rlutil::setColor(rlutil::GREY);
                cout << endl << "TABLA DE PORCENTAJE DE BALSA:" << endl;
                for(int i=0; i<TAM; i++){
                    if(jugadoresVivos[i] == 1){
                        if(porcRefugio[i] < 100){
                            rlutil::setColor(rlutil::RED);
                            cout << "Porcentaje de balsa de " << nombres[i] << ": " << porcRefugio[i] << "%" << endl;
                        }else{
                            rlutil::setColor(rlutil::GREY);
                            cout << "Porcentaje de balsa de " << nombres[i] << ": " << porcRefugio[i] << "%" << endl;
                        }
                    }
                }
                rlutil::setColor(rlutil::GREY);
                cout << endl << "TABLA DE DIAS DE ARMADO DE BALSA:" << endl;
                for(int i=0; i<TAM; i++){
                    if(jugadoresVivos[i] == 1){
                        if(diasDeArmado[i] == 0){
                            rlutil::setColor(rlutil::RED);
                            cout << "Balsa de " << nombres[i] << " armada en: " << diasDeArmado[i] << " dias" << endl;
                        }else{
                            rlutil::setColor(rlutil::GREY);
                            cout << "Balsa de " << nombres[i] << " armada en: " << diasDeArmado[i] << " dias" << endl;
                        }
                    }
                }
                rlutil::setColor(rlutil::GREY);
                system("pause");
                system("cls");
                bool jugadorVivo = (kgAlimentos[0] >= 14 && diasDeArmado[0] != 0);
                int resultadoEstadisticasEtapa2 = estadisticasEtapa2(TAM, kgAlimentos, diasDeArmado, jugadoresVivos, nombres, edades, dia, jugadorVivo);
                if(resultadoEstadisticasEtapa2 == 0){
                    system("cls");
                    cout << endl << "Juego terminado. Gracias por jugar" << endl;
                    return 0;
                }
                if(resultadoEstadisticasEtapa2 == 3 && jugadorVivo){
                    cout << "Etapa 3" << endl << endl;
                    cout << "El sol comienza a ocultarse tras los arboles cuando escuchas nuevamente el zumbido familiar." << endl;
                    cout << "El dron aparece descendiendo lentamente, su camara fija en ti, como si no pudiera creer lo que ve." << endl;
                    cout << "'Increible, " << nombres[0] << "... de verdad llegaste hasta aqui?' dice con un tono entre sorpresa" << endl;
                    cout << "y sarcasmo. 'Pensaba que ya serias parte del menu de la jungla, pero parece que me equivoque otra vez.'" << endl;
                    cout << "El dron da una vuelta sobre ti, emitiendo un sonido que parece una carcajada digital." << endl;
                    cout << "'Bueno, felicidades. Has llegado a la ultima etapa. Tu balsa esta lista, pero el reto aun no termina.'" << endl;
                    cout << "'Frente a ti hay cuatro caminos por el rio. Dos te llevaran a la libertad, el resto al desastre absoluto.'" << endl;
                    cout << "'No hay pistas, no hay ayudas, solo tu instinto. Tienes que elegir sabiamente si quieres salir vivo.'" << endl;
                    cout << "El dron se queda en silencio unos segundos, como si disfrutara de la tension del momento." << endl;
                    cout << "'Supongo que ya sabes lo que viene, " << nombres[0] << ". La decision final es tuya. Que empiece la suerte.'" << endl;
                    cout << "El dron asciende rapidamente, perdiendose entre las copas de los arboles mientras su zumbido se apaga." << endl;
                    cout << "Miras el rio frente a ti. Cuatro caminos, una sola oportunidad. Tomas aire y te preparas para decidir." << endl << endl;
                    system("pause");
                    system("cls");
                    chequearVivos(TAM, kgAlimentos, diasDeArmado, jugadoresVivos);
                    eleccionFinal(eleccion, horasDeLlegada);
                    eleccionFinalBots(TAM, horasDeLlegada, jugadoresVivos);
                    system("pause");
                    system("cls");
                    cout << "TABLA DE DIAS DE LLEGADA:" << endl;
                    for(int i=0; i<TAM; i++){
                        if(jugadoresVivos[i] == 1){
                            if(horasDeLlegada[i] == 0){
                                rlutil::setColor(rlutil::RED);
                                cout << "Horas de " << nombres[i] << ": " << horasDeLlegada[i] << "hs" << endl;
                            }else{
                                rlutil::setColor(rlutil::GREY);
                                cout << "Horas de " << nombres[i] << ": " << horasDeLlegada[i] << "hs" << endl;
                            }
                        }
                    }
                    rlutil::setColor(rlutil::GREY);
                    system("pause");
                    system("cls");
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

Este es el main.cpp de mi proyecto de juego. Crees que puedes armar un readme.MD para acompañarlo?
