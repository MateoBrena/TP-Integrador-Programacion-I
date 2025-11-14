#include <iostream>
#include <time.h>
#include <string>
#include "rlutil.h"

using namespace std;

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

void nombreYEdad(const int TAM, string nombres[], int edades[]){

    cout << "Ingrese su nombre: ";
    getline(cin, nombres[0]);

    cout << "Ingrese su edad: ";
    cin >> edades[0];

    string nombresDisponibles[9] = {"Ana", "Luis", "Carlos", "Maria", "Juan", "Pedro", "Lucia", "Diego", "Sofia"};
    bool usado[9] = {false};

    for(int i=1; i<TAM; i++){
        int indice;
        do{
            indice = (rand()%9);
        }while(usado[indice]);

        int edad = (rand()%71+18);
        edades[i] = edad;
        nombres[i] = nombresDisponibles[indice];
        usado[indice] = true;
    }
}

void recolectarAlimentos(const int TAM, int kgAlimentos[], int porcRefugio[], int &dia){

    system("cls");
    int alimentoRecogido;
    int y = 0;
    int eleccion = 1;

    do{
        rlutil::locate(1,1);
        cout<<"Haz elegido recolectar alimentos"<<endl;
        rlutil::locate(1,3);
        cout << "Elige donde recolectar alimentos: " << endl;
        mostrarSeleccionado("Pesca en el rio", 3, 5, y==0);
        mostrarSeleccionado("Cosecha en arbustos", 3, 6, y==1);
        mostrarSeleccionado("Caza con lanza", 3, 7, y==2);
        int tecla = rlutil::getkey();
        switch(tecla){
            case 119: //arriba
                rlutil::locate(3,5+y);
                y--;
                if(y<0){
                    y = 0;
                }
                break;
            case 115: // abajo
                rlutil::locate(3,5+y);
                y++;
                if(y>2){
                    y = 2;
                }
                break;
            case 1: // enter
                    switch(y){
                        case 0:
                            rlutil::locate(1,9);
                            cout << "Haz elegido pesca en el rio" << endl << endl;
                            alimentoRecogido=(rand()%15+0);
                            kgAlimentos[0] += alimentoRecogido;
                            eleccion = 0;
                            break;
                        case 1:
                            rlutil::locate(1,9);
                            cout << "Haz elegido cosecha en arbusto" << endl << endl;
                            alimentoRecogido=(rand()%10+3);
                            kgAlimentos[0] += alimentoRecogido;
                            eleccion = 0;
                            break;
                        case 2:
                            rlutil::locate(1,9);
                            cout << "Haz elegido caza con lanza" << endl<< endl;
                            alimentoRecogido=(rand()%8+5);
                            kgAlimentos[0] += alimentoRecogido;
                            eleccion = 0;
                            break;
                        }
                break;
        }
    }while(eleccion != 0);

    rlutil::locate(1,11);
    cout << "Haz recolectado " << alimentoRecogido << " kg de alimentos" << endl;
    rlutil::locate(1,13);
    if(kgAlimentos[0] >= 14){
        rlutil::setColor(rlutil::GREEN);
        cout << "Llevas acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
    }else{
        rlutil::setColor(rlutil::RED);
        cout << "Llevas acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
    }
    rlutil::locate(1,14);
    if(porcRefugio[0] >= 100){
        rlutil::setColor(rlutil::GREEN);
        cout << "Llevas acumulado 100% del refugio" << endl;
    }else{
        rlutil::setColor(rlutil::RED);
        cout << "Llevas acumulado " << porcRefugio[0] << "% del refugio" << endl;
    }
    rlutil::setColor(rlutil::GREY);
}

bool recolectarMateriales(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia){

    system("cls");
    int materialesRecolectados;
    int y = 0;
    int eleccion = 1;

    if(porcRefugio[0] < 100){
        do{
        rlutil::locate(1,1);
        cout<<"Haz elegido recolectar materiales"<<endl;
        rlutil::locate(1,3);
        cout << "Elige el material a recolectar: " << endl;
        mostrarSeleccionado("Ramas de arbol", 3, 5, y==0);
        mostrarSeleccionado("Ramas en arbusto", 3, 6, y==1);
        mostrarSeleccionado("Barro", 3, 7, y==2);
        mostrarSeleccionado("Rocas", 3, 8, y==3);
        int tecla = rlutil::getkey();
        switch(tecla){
            case 119: //arriba
                rlutil::locate(3,5+y);
                y--;
                if(y<0){
                    y = 0;
                }
                break;
            case 115: // abajo
                rlutil::locate(3,5+y);
                y++;
                if(y>3){
                    y = 3;
                }
                break;
            case 1: // enter
                    switch(y){
                        case 0:
                            rlutil::locate(1,10);
                            cout << "Haz elegido ramas de arbol" << endl << endl;
                            materialesRecolectados=(rand()%15+10);
                            porcRefugio[0] += materialesRecolectados;
                            eleccion = 0;
                            break;
                        case 1:
                            rlutil::locate(1,10);
                            cout << "Haz elegido ramas de arbustos" << endl << endl;
                            materialesRecolectados=(rand()%20+15);
                            porcRefugio[0] += materialesRecolectados;
                            eleccion = 0;
                            break;
                        case 2:
                            rlutil::locate(1,10);
                            cout << "Haz elegido barro" << endl << endl;
                            materialesRecolectados=(rand()%30+8);
                            porcRefugio[0] += materialesRecolectados;
                            eleccion = 0;
                            break;
                        case 3:
                            rlutil::locate(1,10);
                            cout << "Haz elegido rocas" << endl << endl;
                            materialesRecolectados=(rand()%35+5);
                            porcRefugio[0] += materialesRecolectados;
                            eleccion = 0;
                            break;
                        }
                break;
            }
        }while(eleccion != 0);

        if(porcRefugio[0] >= 100){
            porcRefugio[0] = 100;
            if(diasDeArmado[0] == 0){
                diasDeArmado[0] = dia+1;
            }
        }
        rlutil::locate(1,12);
        cout << "Haz recolectado " << materialesRecolectados <<"% de materiales" << endl << endl;
        rlutil::locate(1,14);
        if(kgAlimentos[0] >= 14){
            rlutil::setColor(rlutil::GREEN);
            cout << "Llevas acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
        }else{
            rlutil::setColor(rlutil::RED);
            cout << "Llevas acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
        }
        rlutil::locate(1,15);
        if(porcRefugio[0] >= 100){
            rlutil::setColor(rlutil::GREEN);
            cout << "Llevas acumulado 100% del refugio" << endl;
        }else{
            rlutil::setColor(rlutil::RED);
            cout << "Llevas acumulado " << porcRefugio[0] << "% del refugio" << endl;
        }
        rlutil::setColor(rlutil::GREY);
        return true;
    }else{
        dia --;
        rlutil::locate(1,1);
        cout << "Te dije que el refugio ya esta 100% completado, mejor ir a recolectar alimentos" << endl << endl;
        return false;
    }
}

void recoleccionBots(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int jugadoresVivos[], int &dia){

    for(int i=1; i<TAM; i++){

        if(jugadoresVivos[i] == 1){
            int eleccion = (rand()%2+1);

            if(porcRefugio[i] == 100){
                eleccion = 1;
            }else if(kgAlimentos[i] > 14){
                eleccion = 2;
            }

            if(eleccion == 1){
                kgAlimentos[i] += (rand()%8+3);
            }else{
                porcRefugio[i] += (rand()%30+10);
                if(porcRefugio[i] >= 100){
                    porcRefugio[i] = 100;
                    if(diasDeArmado[i] == 0){
                        diasDeArmado[i] = dia+1;
                    }
                }
            }
        }
    }
}

void promedioAlimentos(const int TAM, int kgAlimentos[], string nombres[]){

    int acum = 0;
    for(int i=0; i<TAM; i++){
        acum += kgAlimentos[i];
    }

    float prom = float(acum)/TAM;

    cout << "PROMEDIO DE KG DE ALIMENTOS: " << prom << "KG" << endl;
    cout << "JUGADORES QUE SUPERARON EL PROMEDIO DE KG DE ALIMENTOS:" << endl << endl;
    for(int i=0; i<TAM; i++){
        if(kgAlimentos[i] > prom){
            cout << nombres[i] << ": " << kgAlimentos[i] << "Kgs" << endl;
        }
    }

}

void refugioMasRapido(const int TAM, int diasDeArmado[], string nombres[]){

    int menor = 8;
    int pos;
    cout << "JUGADOR MAS RAPIDO EN CONSTRUIR SU REFUGIO:" << endl << endl;
    for(int i=0; i<TAM; i++){
        if(diasDeArmado[i] < menor && diasDeArmado[i] > 0){
            menor = diasDeArmado[i];
            pos = i;
        }
    }

    cout << nombres[pos] << " en " << menor << " dias" << endl;
}

void refugioMas5Dias(const int TAM, int diasDeArmado[], string nombres[]){

    int cont = 0;
    cout << "JUGADORES QUE TARDARON MAS DE 5 DIAS EN CONSTRUIR SU REFUGIO:" << endl << endl;
    for(int i=0; i<TAM; i++){
        if(diasDeArmado[i] > 5){
            cont++;
            cout << nombres[i] << " en " << diasDeArmado[i] << " dias" << endl;
        }
    }

    if(cont == 0){
        cout << "Ningun jugador ha completado el refugio en mas de 5 dias" << endl;
    }
}

void tablaPosicionesEtapa1(const int TAM, int diasDeArmado[], int kgAlimentos[], string nombres[], int edades[]){

    string copiaNombres[TAM];
    int copiaDiasDeArmado[TAM];
    int copiaKgAlimentos[TAM];
    int copiaEdades[TAM];

    for(int i=0; i<TAM; i++) {
        copiaNombres[i] = nombres[i];
        copiaDiasDeArmado[i] = diasDeArmado[i];
        copiaKgAlimentos[i] = kgAlimentos[i];
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
                    // ambos distintos de 0 entonces compara igual que los validos.
                    if (copiaDiasDeArmado[j] > copiaDiasDeArmado[j + 1])
                        cambiar = true;
                    else if (copiaDiasDeArmado[j] == copiaDiasDeArmado[j + 1] &&
                             copiaKgAlimentos[j] < copiaKgAlimentos[j + 1])
                        cambiar = true;
                }
            }

            if (cambiar){
                int tempDias = copiaDiasDeArmado[j];
                copiaDiasDeArmado[j] = copiaDiasDeArmado[j + 1];
                copiaDiasDeArmado[j + 1] = tempDias;

                int tempKg = copiaKgAlimentos[j];
                copiaKgAlimentos[j] = copiaKgAlimentos[j + 1];
                copiaKgAlimentos[j + 1] = tempKg;

                string tempNombre = copiaNombres[j];
                copiaNombres[j] = copiaNombres[j + 1];
                copiaNombres[j + 1] = tempNombre;

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
        if (copiaDiasDeArmado[i] == 0 || copiaKgAlimentos[i] < 14) {
            rlutil::setColor(rlutil::RED);
            cout << "eliminado\t" << copiaNombres[i] << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << "\t\t" << copiaEdades[i] << endl;
        } else {
            rlutil::setColor(rlutil::GREY);
            cout << puesto++ << "\t\t" << copiaNombres[i] << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << "\t\t" << copiaEdades[i] << endl;
        }
    }
    rlutil::setColor(rlutil::GREY);
}


int estadisticasEtapa1(const int TAM, int kgAlimentos[], int diasDeArmado[], string nombres[], int edades[], int &dia, bool jugadorVivo){

    int opcionStats = 1;
    int y = 0;
    do{
        rlutil::locate(1,1);
        cout << "===========================================================================" << endl;
        rlutil::locate(1,2);
        cout << "                           ESTADISTICAS ETAPA 1                            " << endl;
        rlutil::locate(1,3);
        cout << "===========================================================================" << endl;
        mostrarSeleccionado("Participantes que superaron el promedio de kg de alimentos recolectados", 3, 4, y==0);
        mostrarSeleccionado("Participantes mas rapido en construir su refugio", 3, 5, y==1);
        mostrarSeleccionado("Participantes que tardaron mas de 5 dias en constuir su refugio", 3, 6, y==2);
        mostrarSeleccionado("Tabla de posiciones", 3, 7, y==3);
        mostrarSeleccionado("Continuar a la segunda etapa", 3, 8, y==4);
        mostrarSeleccionado("Salir", 3, 9, y==5);
        int tecla = rlutil::getkey();
        switch(tecla){
            case 119: //arriba
                rlutil::locate(3,4+y);
                y--;
                if(y<0){
                    y = 0;
                }
                break;
            case 115: // abajo
                rlutil::locate(3,4+y);
                y++;
                if(y>5){
                    y = 5;
                }
                break;
            case 1: // enter
                    switch(y){
                        case 0:
                            system("cls");
                            promedioAlimentos(TAM, kgAlimentos, nombres);
                            system("pause");
                            system("cls");
                            break;
                        case 1:
                            system("cls");
                            refugioMasRapido(TAM, diasDeArmado, nombres);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            system("cls");
                            refugioMas5Dias(TAM, diasDeArmado, nombres);
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            system("cls");
                            tablaPosicionesEtapa1(TAM, diasDeArmado, kgAlimentos, nombres, edades);
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

void chequearVivos(const int TAM, int kgAlimentos[], int diasDeRefugio[], int jugadoresVivos[]){

    for (int i = 0; i < TAM; i++){
        if(kgAlimentos[i] >= 14 && diasDeRefugio[i] != 0){
            jugadoresVivos[i] = 1;
        }else{
            jugadoresVivos[i] = 0;
        }
    }
}

bool recolectarMaterialesBalsa(const int TAM, int kgAlimentos[], int porcBalsa[], int diasDeArmado[], int &dia){

    system("cls");
    int materialesRecolectados;
    int y = 0;
    int eleccion = 1;

    if(porcBalsa[0] < 100){
        do{
        rlutil::locate(1,1);
        cout<<"Haz elegido recolectar materiales"<<endl;
        rlutil::locate(1,3);
        cout << "Elige el material a recolectar: " << endl;
        mostrarSeleccionado("Troncos de arbol", 3, 5, y==0);
        mostrarSeleccionado("Hojas de palmera", 3, 6, y==1);
        mostrarSeleccionado("Lianas", 3, 7, y==2);
        int tecla = rlutil::getkey();
        switch(tecla){
            case 119: //arriba
                rlutil::locate(3,5+y);
                y--;
                if(y<0){
                    y = 0;
                }
                break;
            case 115: // abajo
                rlutil::locate(3,5+y);
                y++;
                if(y>2){
                    y = 2;
                }
                break;
            case 1: // enter
                    switch(y){
                        case 0:
                            rlutil::locate(1,10);
                            cout << "Haz elegido troncos de arbol" << endl << endl;
                            materialesRecolectados=(rand()%15+10);
                            porcBalsa[0] += materialesRecolectados;
                            eleccion = 0;
                            break;
                        case 1:
                            rlutil::locate(1,10);
                            cout << "Haz elegido hojas de palmera" << endl << endl;
                            materialesRecolectados=(rand()%20+15);
                            porcBalsa[0] += materialesRecolectados;
                            eleccion = 0;
                            break;
                        case 2:
                            rlutil::locate(1,10);
                            cout << "Haz elegido lianas" << endl << endl;
                            materialesRecolectados=(rand()%30+8);
                            porcBalsa[0] += materialesRecolectados;
                            eleccion = 0;
                            break;
                        }
                break;
            }
        }while(eleccion != 0);

        if(porcBalsa[0] >= 100){
            porcBalsa[0] = 100;
            if(diasDeArmado[0] == 0){
                diasDeArmado[0] = dia+1;
            }
        }
        rlutil::locate(1,12);
        cout << "Haz recolectado " << materialesRecolectados <<"% de materiales" << endl << endl;
        rlutil::locate(1,14);
        if(kgAlimentos[0] >= 14){
            rlutil::setColor(rlutil::GREEN);
            cout << "Llevas acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
        }else{
            rlutil::setColor(rlutil::RED);
            cout << "Llevas acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
        }
        rlutil::locate(1,15);
        if(porcBalsa[0] >= 100){
            rlutil::setColor(rlutil::GREEN);
            cout << "Llevas acumulado 100% de la balsa" << endl;
        }else{
            rlutil::setColor(rlutil::RED);
            cout << "Llevas acumulado " << porcBalsa[0] << "% de la balsa" << endl;
        }
        rlutil::setColor(rlutil::GREY);
        return true;
    }else{
        dia --;
        rlutil::locate(1,1);
        cout << "Te dije que la balsa ya esta 100% completada, mejor ir a recolectar alimentos" << endl;
        return false;
    }
}

void promedioAlimentosEtapa2(const int TAM, int kgAlimentos[], int jugadoresVivos[], string nombres[]){

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

void refugioMasRapidoEtapa2(const int TAM, int diasDeArmado[], int jugadoresVivos[], string nombres[]){

    int menor = 8;
    int pos;
    cout << "JUGADOR MAS RAPIDO EN CONSTRUIR SU BALSA: " << endl << endl;
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

void tablaPosicionesEtapa2(const int TAM, int diasDeArmado[], int kgAlimentos[], int jugadoresVivos[], string nombres[], int edades[]){

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

int estadisticasEtapa2(const int TAM, int kgAlimentos[], int diasDeArmado[], int jugadoresVivos[], string nombres[], int edades[], int &dia, bool jugadorVivo){

    int opcionStats = 1;
    int y = 0;
    system("cls");
    do{
        rlutil::locate(1,1);
        cout << "===========================================================================" << endl;
        rlutil::locate(1,2);
        cout << "                           ESTADISTICAS ETAPA 2                            " << endl;
        rlutil::locate(1,3);
        cout << "===========================================================================" << endl;
        mostrarSeleccionado("Participantes que superaron el promedio de kg de alimentos recolectados", 3, 4, y==0);
        mostrarSeleccionado("Participantes mas rapido en construir su balsa", 3, 5, y==1);
        mostrarSeleccionado("Tabla de posiciones", 3, 6, y==2);
        mostrarSeleccionado("Continuar a la tercer etapa", 3, 7, y==3);
        mostrarSeleccionado("Salir", 3, 8, y==4);
        int tecla = rlutil::getkey();
        switch(tecla){
            case 119: //arriba
                rlutil::locate(3,4+y);
                y--;
                if(y<0){
                    y = 0;
                }
                break;
            case 115: // abajo
                rlutil::locate(3,4+y);
                y++;
                if(y>4){
                    y = 4;
                }
                break;
            case 1: // enter
                    switch(y){
                        case 0:
                            system("cls");
                            promedioAlimentosEtapa2(TAM, kgAlimentos, jugadoresVivos, nombres);
                            system("pause");
                            system("cls");
                            break;
                        case 1:
                            system("cls");
                            refugioMasRapidoEtapa2(TAM, diasDeArmado, jugadoresVivos, nombres);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            system("cls");
                            tablaPosicionesEtapa2(TAM, diasDeArmado, kgAlimentos, jugadoresVivos, nombres, edades);
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            system("cls");
                            if(jugadorVivo){
                                opcionStats = y;
                                return opcionStats;
                                break;
                            }else{
                                cout << "Jugador eliminado. No puede avanzar a la tercer etapa." << endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                        case 4:
                            opcionStats = 0;
                            break;
                        }
                break;
            }
    }while(opcionStats != 0);

    return opcionStats;

}

void eleccionFinal(int eleccion, int horasDeLlegada[]){

    string textos[4] = {
        // Gana 1
        "El camino elegido fue tranquilo y sin obstaculos. La corriente te ha guiado suavemente\n"
        "entre los arboles hasta salir de la selva. Luego de unas pocas horas, la corriente se termina\n"
        "en una amplia y tranquila laguna. Por fin, luego de varios dias en la selva, llegaste a un lugar seguro.",

        // Gana 2
        "El camino elegido estaba obstruido por ramas de arboles caidos, decidiste seguir por un arroyo\n"
        "a tu derecha. Afortunadamente el arroyo estaba despejado, tomaste velocidad y lograste llegar\n"
        "en un excelente tiempo.",

        // Pierde 1
        "Mientras avanzabas lentamente por el rio, varios cocodrilos emergieron del agua, dificultando el paso.\n"
        "Uno de los cocodrilos ataca tu balsa, provocando una rotura que te obliga a ir a la orilla.\n"
        "Tu balsa ha quedado destruida. Debiste continuar a pie. Se aproxima la noche y ya no tienes alimentos.",

        // Pierde 2
        "La corriente es extremadamente fuerte, avanzas muy rapido. El rio comienza a volverse tortuoso y la balsa\n"
        "es cada vez mas dificil de controlar.La corriente te embiste con una roca y la balsa se llena de agua rapidamente.\n"
        "Lograste llegar a la orilla, pero tu transporte es inutilizable. Tomas tu alimento y continuas a pie."
    };

    // Resultado asociado a cada texto: 1 = gana, 0 = pierde
    int resultado[4] = {1, 1, 0, 0};

    // Mezclamos textos y resultados ya que hay dos textos ganadores y dos perdedores, no se pueden mezclar.
    for(int i=0; i<10; i++){ // Mezclamos 10 veces, totalmente overkill pero bueno, te da la sensación de mejor mezclado.
        int a = rand()%4;
        int b = rand()%4;
        // intercambio en vector de textos
        string tempTexto = textos[a];
        textos[a] = textos[b];
        textos[b] = tempTexto;
        // intercambio en vector de resultados
        int tempRes = resultado[a];
        resultado[a] = resultado[b];
        resultado[b] = tempRes;
    }

    string direcciones[4] = {"Norte", "Sur", "Este", "Oeste"};

    system("cls");
    int opcionFinal = 1;
    int y = 0;
    do {
        rlutil::locate(1,1);
        cout << "Etapa 3." << endl;
        rlutil::locate(1,2);
        cout << "Elija una direccion para escapar con la balsa: " << endl << endl;
        mostrarSeleccionado("Norte", 1, 3, y == 0);
        mostrarSeleccionado("Sur", 1, 4, y == 1);
        mostrarSeleccionado("Este", 1, 5, y == 2);
        mostrarSeleccionado("Oeste", 1, 6, y == 3);
        int tecla = rlutil::getkey();
        switch(tecla){
            case 119: //arriba
                rlutil::locate(1,3+y);
                cout << " ";
                y--;
                if(y<0){
                    y = 0;
                }
                break;
            case 115: // abajo
                rlutil::locate(1,3+y);
                cout << " ";
                y++;
                if(y>3){
                    y = 3;
                }
                break;
            case 1: // enter
                    switch(y){
                        case 0:
                            system("cls");
                            cout << "Haz elegido el camino " << direcciones[y] << "." << endl << endl;
                            cout << textos[y] << endl << endl;
                            opcionFinal = 0;
                            break;
                        case 1:
                            system("cls");
                            cout << "Haz elegido el camino " << direcciones[y] << "." << endl << endl;
                            cout << textos[y] << endl << endl;
                            opcionFinal = 0;
                            break;
                        case 2:
                            system("cls");
                            cout << "Haz elegido el camino " << direcciones[y] << "." << endl << endl;
                            cout << textos[y] << endl << endl;
                            opcionFinal = 0;
                            break;
                        case 3:
                            system("cls");
                            cout << "Haz elegido el camino " << direcciones[y] << "." << endl << endl;
                            cout << textos[y] << endl << endl;
                            opcionFinal = 0;
                        }
                break;
            }
    }while(opcionFinal != 0);

    if (resultado[y] == 1) {
        horasDeLlegada[0] = (rand()%12+4);
        rlutil::setColor(rlutil::GREY);
        cout << "Haz tardado " << horasDeLlegada[0] << " horas..." << endl;
        cout << "Felicidades! Haz logrado escapar" << endl << endl;
    } else {
        horasDeLlegada[0] = (rand()%4+25);
        rlutil::setColor(rlutil::RED);
        cout << "Haz tardado " << horasDeLlegada[0] << " horas..." << endl;
        cout << "Lamentablemente, no haz llegado a tiempo." << endl << endl;
    }
    rlutil::setColor(rlutil::GREY);

    if(horasDeLlegada[0] > 24){
        horasDeLlegada[0] = 0;
    }
}

void eleccionFinalBots(const int TAM, int horasDeLlegada[], int jugadoresVivos[]){

    for(int i=1; i<TAM; i++){
        if(jugadoresVivos[i] == 1){
            horasDeLlegada[i]=(rand()%30+3);
            if(horasDeLlegada[i] > 24){
                horasDeLlegada[i] = 0;
            }
        }
    }
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
        cout << "Ningun jugador ha llegado a escapar." << endl;
    }

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
                    y = 0;
                }
                break;
            case 115: // abajo
                rlutil::locate(3,4+y);
                y++;
                if(y>4){
                    y = 4;
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
