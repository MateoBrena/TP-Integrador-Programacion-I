#include <iostream>
#include "rlutil.h"
#include <string>
#include "funciones_visuales.h"

using namespace std;

void mostrarBannerInicial(){

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

}

int mostrarMenu(string opciones[], int cantidad, int x, int y){

    int pos = 0;
    int tecla;
    while (true) {

        rlutil::locate(x,y);

        // Mostrar opciones
        for (int i = 0; i < cantidad; i++) {
            if (i == pos) {
                mostrarSeleccionado(opciones[i], x, y + i, true);
            } else {
                mostrarSeleccionado(opciones[i], x, y + i, false);
            }
        }

        tecla = rlutil::getkey();

        switch (tecla) {
            case 119: //arriba
                pos--;
                if (pos < 0) pos = cantidad - 1;
                break;

            case 115: //abajo
                pos++;
                if (pos >= cantidad) pos = 0;
                break;

            case 1: // ENTER
                return pos;   // devuelve el índice seleccionado
        }
    }
}

void mostrarSeleccionado(string texto, int posX, int posY, bool seleccionado){

    if(seleccionado){
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::setColor(rlutil::BLACK);
        rlutil::locate(posX-2, posY);
        cout << (char)175 << "  " << texto << "  " << (char)174 << endl;
    }else{
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::GREY);
        rlutil::locate(posX-2, posY);
        cout << "   " << texto << "   " << endl;
    }

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::GREY);
}

void mostrarTextosEtapa(int nroEtapa, string nombres[]){

    if(nroEtapa == 1){
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
    }else if(nroEtapa == 2){
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
    }else{

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
    }
}

void mostrarTablasFinEtapa(const int TAM, int nroEtapa, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int jugadoresVivos[], int horasDeLlegada[], string nombres[]){

    if(nroEtapa == 1){
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
    }else if(nroEtapa == 2){
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
    }else{
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
}
