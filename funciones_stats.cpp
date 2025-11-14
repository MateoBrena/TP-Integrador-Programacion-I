#include <iostream>
#include "rlutil.h"
#include <string>
#include "funciones_visuales.h"
#include "funciones_stats.h"

using namespace std;

void promedioAlimentos(const int TAM, int kgAlimentos[], int jugadoresVivos[], string nombres[]){

    int acum = 0;
    int vivos = 0;
    for(int i=0; i<TAM; i++){
        if(jugadoresVivos[i] == 1){
            acum += kgAlimentos[i];
            vivos++;
        }
    }

    float prom = float(acum)/vivos;

    cout << "PROMEDIO DE KGS DE ALIMENTO: " << prom << " KG" <<endl;
    cout << "JUGADORES QUE SUPERARON EL PROMEDIO DE KGS DE ALIMENTO: " << endl << endl;
    for(int i=0; i<TAM; i++){
        if(kgAlimentos[i] > prom && jugadoresVivos[i] == 1){
            cout << nombres[i] << ": " << kgAlimentos[i] << "Kgs" << endl;
        }
    }

}

void refugioMasRapido(const int TAM, int nroEtapa, int diasDeArmado[], int jugadoresVivos[], string nombres[]){

    int menor = 8;
    int pos;

    if(nroEtapa == 1){
        cout << "JUGADOR MAS RAPIDO EN CONSTRUIR SU REFUGIO: " << endl << endl;
    }else{
        cout << "JUGADOR MAS RAPIDO EN CONSTRUIR SU BALSA: " << endl << endl;
    }

    for(int i=0; i<TAM; i++){
        if(diasDeArmado[i] < menor && diasDeArmado[i] > 0){
            if(jugadoresVivos[i] == 1){
                menor = diasDeArmado[i];
                pos = i;
            }
        }
    }

    cout << nombres[pos] << " en " << menor << " dias" << endl;

}

void refugioMas5Dias(const int TAM, int nroEtapa, int diasDeArmado[], int jugadoresVivos[], string nombres[]){

    int cont = 0;
    if(nroEtapa == 1){
        cout << "JUGADORES QUE TARDARON MAS DE 5 DIAS EN CONSTRUIR SU REFUGIO:" << endl << endl;
    }else{
        cout << "JUGADORES QUE TARDARON MAS DE 5 DIAS EN CONSTRUIR SU BALSA:" << endl << endl;
    }

    for(int i=0; i<TAM; i++){
        if(diasDeArmado[i] > 5 && jugadoresVivos[i] == 1){
            cont++;
            cout << nombres[i] << " en " << diasDeArmado[i] << " dias" << endl;
        }
    }

    if(cont == 0){
        if(nroEtapa == 1){
            cout << "Ningun jugador ha completado el refugio en mas de 5 dias" << endl;
        }else{
            cout << "Ningun jugador ha completado la balsa en mas de 5 dias" << endl;
        }
    }
}

void tablaPosiciones(const int TAM, int nroEtapa, int kgAlimentos[] ,int diasDeArmado[], int jugadoresVivos[], string nombres[], int edades[]){

    string copiaNombres[TAM];
    int copiaDiasDeArmado[TAM];
    int copiaKgAlimentos[TAM];
    int copiaJugadoresVivos[TAM];
    int copiaEdades[TAM];

    for(int i=0; i<TAM; i++) {
        copiaNombres[i] = nombres[i];
        copiaDiasDeArmado[i] = diasDeArmado[i];
        copiaKgAlimentos[i] = kgAlimentos[i];
        copiaJugadoresVivos[i] = jugadoresVivos[i];
        copiaEdades[i] = edades[i];
    }

    for(int i=0; i<TAM - 1; i++){
        for(int j=0; j < TAM - i - 1; j++){

            bool cambiar = false;
            bool actualValido = (copiaDiasDeArmado[j] != 0 && copiaKgAlimentos[j] >= 14);
            bool siguienteValido = (copiaDiasDeArmado[j + 1] != 0 && copiaKgAlimentos[j + 1] >= 14);

            // 1- Válidos primero siempre
            if(!actualValido && siguienteValido){
                cambiar = true;
            }else if(actualValido && !siguienteValido){
                cambiar = false;
            }else if(actualValido && siguienteValido){
                //2- Ambos válidos entonces ordena por días (ascendente), luego por kg (descendente)
                if(copiaDiasDeArmado[j] > copiaDiasDeArmado[j + 1]){
                    cambiar = true;
                }
                else if(copiaDiasDeArmado[j] == copiaDiasDeArmado[j + 1] &&
                         copiaKgAlimentos[j] < copiaKgAlimentos[j + 1]){
                    cambiar = true;
                }
            }else{
                // 3- Ambos inválidos entonces ordena por días (0 cuenta como el peor)
                if (copiaDiasDeArmado[j] == 0 && copiaDiasDeArmado[j + 1] != 0) {
                    // el actual tiene 0 entonces va a la derecha
                    cambiar = true;
                } else if (copiaDiasDeArmado[j] != 0 && copiaDiasDeArmado[j + 1] == 0) {
                    // el siguiente tiene 0 entonces no cambia
                    cambiar = false;
                } else {
                    // ambos distintos de 0 entonces comparar igual que los validos.
                    if (copiaDiasDeArmado[j] > copiaDiasDeArmado[j + 1])
                        cambiar = true;
                    else if (copiaDiasDeArmado[j] == copiaDiasDeArmado[j + 1] &&
                             copiaKgAlimentos[j] < copiaKgAlimentos[j + 1])
                        cambiar = true;
                }
            }

            if (cambiar){
                string tempNombre = copiaNombres[j];
                copiaNombres[j] = copiaNombres[j + 1];
                copiaNombres[j + 1] = tempNombre;

                int tempDias = copiaDiasDeArmado[j];
                copiaDiasDeArmado[j] = copiaDiasDeArmado[j + 1];
                copiaDiasDeArmado[j + 1] = tempDias;

                int tempKg = copiaKgAlimentos[j];
                copiaKgAlimentos[j] = copiaKgAlimentos[j + 1];
                copiaKgAlimentos[j + 1] = tempKg;

                int tempVivos = copiaJugadoresVivos[j];
                copiaJugadoresVivos[j] = copiaJugadoresVivos[j + 1];
                copiaJugadoresVivos[j + 1] = tempVivos;

                int tempEdad = copiaEdades[j];
                copiaEdades[j] = copiaEdades[j + 1];
                copiaEdades[j + 1] = tempEdad;
            }
        }
    }

    cout << "Puesto\t\tJugador\t\tDias de armado\t\tKgs de alimento\t\tEdad\n";
    cout << "------------------------------------------------------------------------------------\n";

    int puesto = 1;
    for(int i=0; i<TAM; i++){
        if(copiaJugadoresVivos[i] == 1){
            if (copiaDiasDeArmado[i] == 0 || copiaKgAlimentos[i] < 14) {
                rlutil::setColor(rlutil::RED);
                cout << "eliminado\t" << copiaNombres[i] << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << "\t\t" << copiaEdades[i] << endl;
            }else{
                rlutil::setColor(rlutil::GREY);
                cout << puesto++ << "\t\t" << copiaNombres[i] << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << "\t\t" << copiaEdades[i] << endl;
            }
        }
    }
    rlutil::setColor(rlutil::GREY);
}

int estadisticasEtapa(const int TAM, int nroEtapa, int kgAlimentos[], int diasDeArmado[], int jugadoresVivos[], string nombres[], int edades[], int &dia, bool jugadorVivo){

    int opcionStats = 1;
    int y = 0;
    do{
        rlutil::locate(1,1);
        cout << "===========================================================================" << endl;
        rlutil::locate(1,2);
        if(nroEtapa == 1){
            cout << "                           ESTADISTICAS ETAPA 1                            " << endl;
        }else{
            cout << "                           ESTADISTICAS ETAPA 2                            " << endl;
        }
        rlutil::locate(1,3);
        cout << "===========================================================================" << endl;
        mostrarSeleccionado("Participantes que superaron el promedio de kg de alimentos recolectados", 3, 4, y==0);
        if(nroEtapa == 1){
            mostrarSeleccionado("Participantes mas rapido en construir su refugio", 3, 5, y==1);
        }else{
            mostrarSeleccionado("Participantes mas rapido en construir su balsa", 3, 5, y==1);
        }
        if(nroEtapa == 1){
            mostrarSeleccionado("Participantes que tardaron mas de 5 dias en constuir su refugio", 3, 6, y==2);
        }else{
            mostrarSeleccionado("Participantes que tardaron mas de 5 dias en constuir su balsa", 3, 6, y==2);
        }
        mostrarSeleccionado("Tabla de posiciones", 3, 7, y==3);
        if(nroEtapa == 1){
            mostrarSeleccionado("Continuar a la segunda etapa", 3, 8, y==4);
        }else{
            mostrarSeleccionado("Continuar a la tercer etapa", 3, 8, y==4);
        }
        mostrarSeleccionado("Salir", 3, 9, y==5);
        int tecla = rlutil::getkey();
        switch(tecla){
            case 119: //arriba
                rlutil::locate(3,4+y);
                y--;
                if(y<0){
                    y = 5;
                }
                break;
            case 115: // abajo
                rlutil::locate(3,4+y);
                y++;
                if(y>5){
                    y = 0;
                }
                break;
            case 1: // enter
                    switch(y){
                        case 0:
                            system("cls");
                            promedioAlimentos(TAM, kgAlimentos, jugadoresVivos, nombres);
                            system("pause");
                            system("cls");
                            break;
                        case 1:
                            system("cls");
                            refugioMasRapido(TAM, nroEtapa, diasDeArmado, jugadoresVivos, nombres);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            system("cls");
                            refugioMas5Dias(TAM, nroEtapa, diasDeArmado, jugadoresVivos, nombres);
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            system("cls");
                            tablaPosiciones(TAM, nroEtapa, kgAlimentos, diasDeArmado, jugadoresVivos, nombres, edades);
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            system("cls");
                            if(jugadorVivo){
                                opcionStats = y;
                                return opcionStats;
                                break;
                            }else{
                                cout << "Jugador eliminado. No puede avanzar a la segunda etapa." << endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                        case 5:
                            opcionStats = 0;
                            break;
                        }
                break;
            }
    }while(opcionStats != 0);

    return opcionStats;
}

void masRapidoEtapa3(const int TAM, int horasDeLlegada[], int jugadoresVivos[], string nombres[]){

    int pos;
    int menor = 25;
    int cant = 0;

    cout << "JUGADOR MAS RAPIDO EN ESCAPAR:" << endl << endl;
    for(int i=0; i<TAM; i++){

        if((horasDeLlegada[i] < menor && horasDeLlegada[i] != 0) && jugadoresVivos[i] != 0){
            menor = horasDeLlegada[i];
            pos = i;
            cant++;
        }
    }

    if(cant != 0){
        cout << nombres[pos] << " en " << menor << " horas" << endl;
    }else{
        cout << "Ningun jugador ha conseguido escapar." << endl;
    }

}

void rangoEtario(const int TAM, int edades[], string nombres[]){

    int menor = 100;
    int mayor = 0;
    string nombreMayor;
    string nombreMenor;

    for (int i=0; i<TAM; i++) {
        if(edades[i] < menor){
            menor = edades[i];
            nombreMenor = nombres[i];
        }
        if(edades[i] > mayor){
            mayor = edades[i];
            nombreMayor = nombres[i];
        }
    }

    int rango = mayor - menor;

    cout << "Rango etario de los participantes: " << rango << " anios" << endl << endl;
    cout << "Participante mayor: " << nombreMayor << " " << mayor << " anios" << endl;
    cout << "Participante mas joven: " << nombreMenor << " " << menor << " anios" << endl << endl;

}

void tablaPosicionesEtapa3(const int TAM, int horasDeLlegada[], int jugadoresVivos[], string nombres[], int edades[]){

    string copiaNombres[TAM];
    int copiaHoras[TAM];
    int copiaJugadoresVivos[TAM];
    int copiaEdades[TAM];

    for(int i=0; i<TAM; i++){
        copiaNombres[i] = nombres[i];
        copiaHoras[i] = horasDeLlegada[i];
        copiaJugadoresVivos[i] = jugadoresVivos[i];
        copiaEdades[i] = edades[i];
    }

    for(int i = 0; i < TAM - 1; i++) {
        for(int j = 0; j < TAM - i - 1; j++){
            bool cambiar = false;

            if(copiaHoras[j] == 0 && copiaHoras[j + 1] != 0){
                cambiar = true;
            }else if(copiaHoras[j] != 0 && copiaHoras[j + 1] == 0){
                cambiar = false;
            }else if(copiaHoras[j] > copiaHoras[j + 1]){
                cambiar = true;
            }

            if(cambiar){
                string tempNombre = copiaNombres[j];
                copiaNombres[j] = copiaNombres[j + 1];
                copiaNombres[j + 1] = tempNombre;

                int tempHora = copiaHoras[j];
                copiaHoras[j] = copiaHoras[j + 1];
                copiaHoras[j + 1] = tempHora;

                int tempVivo = copiaJugadoresVivos[j];
                copiaJugadoresVivos[j] = copiaJugadoresVivos[j + 1];
                copiaJugadoresVivos[j + 1] = tempVivo;

                int tempEdad = copiaEdades[j];
                copiaEdades[j] = copiaEdades[j + 1];
                copiaEdades[j + 1] = tempEdad;
            }
        }
    }

    cout << "Puesto\t\tJugador\t\tHoras\t\tEdad\n";
    cout << "---------------------------------------------------------------\n";

    int puesto = 1;
    for(int i=0; i<TAM; i++){
        if(copiaJugadoresVivos[i]){
            if(copiaHoras[i] == 0){
                rlutil::setColor(rlutil::RED);
                cout << "no ha llegado\t" << copiaNombres[i] << "\t\t" << copiaHoras[i] << "\t\t" << copiaEdades[i] << endl;
            }else{
                if(copiaHoras[i] == copiaHoras[i+1]){
                    rlutil::setColor(rlutil::GREY);
                    cout << puesto << "\t\t" << copiaNombres[i] << "\t\t" << copiaHoras[i] << "\t\t" << copiaEdades[i] << endl;
                }else{
                    rlutil::setColor(rlutil::GREY);
                    cout << puesto++ << "\t\t" << copiaNombres[i] << "\t\t" << copiaHoras[i] << "\t\t" << copiaEdades[i] << endl;
                }
            }
        }
    }
    rlutil::setColor(rlutil::GREY);
}

void reiniciarJuego(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int jugadoresVivos[], int &dia){

    for(int i=0; i<TAM; i++){
        kgAlimentos[i] = 0;
        porcRefugio[i] = 0;
        diasDeArmado[i] = 0;
        jugadoresVivos[i] = 1;
    }

    dia = 0;
}


int estadisticasEtapa3(const int TAM, int kgAlimentos[], int diasDeArmado[], int jugadoresVivos[], int horasDeLlegada[], int porcRefugio[], string nombres[], int edades[],int &dia, bool jugadorVivo){

    int opcionStats = 1;
    int y = 0;
    system("cls");
    do{
        rlutil::locate(1,1);
        cout << "===========================================================================" << endl;
        rlutil::locate(1,2);
        cout << "                           ESTADISTICAS ETAPA 3                            " << endl;
        rlutil::locate(1,3);
        cout << "===========================================================================" << endl;
        mostrarSeleccionado("Participante mas rapido en escapar", 3, 4, y==0);
        mostrarSeleccionado("Rango etario de los participantes", 3, 5, y==1);
        mostrarSeleccionado("Tabla de posiciones", 3, 6, y==2);
        mostrarSeleccionado("Volver a jugar", 3, 7, y==3);
        mostrarSeleccionado("Salir", 3, 8, y==4);
        int tecla = rlutil::getkey();
        switch(tecla){
            case 119: //arriba
                rlutil::locate(3,4+y);
                y--;
                if(y<0){
                    y = 4;
                }
                break;
            case 115: // abajo
                rlutil::locate(3,4+y);
                y++;
                if(y>4){
                    y = 0;
                }
                break;
            case 1: // enter
                    switch(y){
                        case 0:
                            system("cls");
                            masRapidoEtapa3(TAM, horasDeLlegada, jugadoresVivos, nombres);
                            system("pause");
                            system("cls");
                            break;
                        case 1:
                            system("cls");
                            rangoEtario(TAM, edades, nombres);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            system("cls");
                            tablaPosicionesEtapa3(TAM, horasDeLlegada, jugadoresVivos, nombres, edades);
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            system("cls");
                            reiniciarJuego(TAM, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, dia);
                            return opcionStats = 3;
                        case 4:
                            opcionStats = 0;
                            break;
                        }
                break;
            }
    }while(opcionStats != 0);

    return opcionStats;
}
