#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void nombreYEdad(const int TAM, string nombres[], int edades[]){

    cout << "Ingrese su nombre: (Un solo nombre, sin espacios): ";
    cin >> nombres[0];
    cout << "Ingrese su edad: ";
    cin >> edades[0];

    string nombresDisponibles[7] = {"Ana", "Luis", "Carlos", "Maria", "Juan", "Pedro", "Lucia"};
    bool usado[7] = {false};

    for(int i=1; i<TAM; i++){
        int indice;
        do{
            indice = rand()%7;
        }while(usado[indice]);

        int edad = (rand()%70+18);
        edades[i] = edad;
        nombres[i] = nombresDisponibles[indice];
        usado[indice] = true;
    }
}

bool recolectarAlimentos(const int TAM, int kgAlimentos[], int porcRefugio[], int &dia){
    int alimentos, alimentoRecogido;
    system("cls");
    cout<<"Haz elegido recolectar alimentos"<<endl << endl;
    cout<<"1- Pesca en el rio "<<endl;
    cout<<"2- Cosecha en arbustos"<<endl;
    cout<<"3- Cosecha en arboles"<<endl;
    cin>>alimentos;

    switch(alimentos){
        case 1:
            cout << "Haz elegido pesca en el rio" << endl << endl;
            alimentoRecogido=(rand()%15+0);
            kgAlimentos[0] += alimentoRecogido;
            break;
        case 2:
            cout << "Haz elegido cosecha en arbusto" << endl << endl;
            alimentoRecogido=(rand()%10+3);
            kgAlimentos[0] += alimentoRecogido;
            break;
        case 3:
            cout << "Haz elegido cosecha en arboles" << endl<< endl;
            alimentoRecogido=(rand()%8+5);
            kgAlimentos[0] += alimentoRecogido;
            break;
        default:
            cout << "No ha elegido una opcion valida. Vuelva a seleccionar" << endl;
            dia -= 1;
            return false;
            break;
        }
        cout << "Haz recolectado " << alimentoRecogido << " kg de alimentos" << endl << endl;
        cout << "Llevas acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
        if(porcRefugio[0] >= 100){
            cout << "Llevas acumulado 100% del refugio" << endl;
        }else{
            cout << "Llevas acumulado " << porcRefugio[0] << "% del refugio" << endl;
        }
        return true;
}

bool recolectarMateriales(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia){

    int materiales, materialesRecolectados;
    system("cls");
    if(porcRefugio[0] < 100){
        cout<<"Haz elegido recolectar materiales"<<endl;
        cout<<"1- Ramas de arboles "<<endl;
        cout<<"2- Ramas de arbustos"<<endl;
        cout<<"3- Barro"<<endl;
        cout<<"4- Rocas"<<endl;
        cin>>materiales;

        switch(materiales){
            case 1:
                cout << "Haz elegido ramas de arboles" << endl << endl;
                materialesRecolectados=(rand()%15+10);
                porcRefugio[0] += materialesRecolectados;
                break;
            case 2:
                cout << "Haz elegido ramas de arbustos" << endl << endl;
                materialesRecolectados=(rand()%20+15);
                porcRefugio[0] += materialesRecolectados;
                break;
            case 3:
                cout << "Haz elegido barro" << endl << endl;
                materialesRecolectados=(rand()%30+8);
                porcRefugio[0] += materialesRecolectados;
                break;
            case 4:
                cout << "Haz elegido rocas" << endl << endl;
                materialesRecolectados=(rand()%35+5);
                porcRefugio[0] += materialesRecolectados;
                break;
            default:
                cout << "No ha elegido una opcion valida. Vuelva a seleccionar" << endl;
                dia -= 1;
                return false;
                break;
        }
        if(porcRefugio[0] >= 100){
            porcRefugio[0] = 100;
            if(diasDeArmado[0] == 0){
                diasDeArmado[0] = dia+1;
            }
        }
        cout << "Haz recolectado " << materialesRecolectados << " de materiales" << endl << endl;
        if(porcRefugio[0] >= 100){
            cout << "Llevas acumulado 100% del refugio" << endl;
        }else{
            cout << "Llevas acumulado " << porcRefugio[0] << "% del refugio" << endl;
        }
        cout << "Llevas acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
        return true;
    }else{
        dia -= 1;
        cout << "Te dije que el refugio ya esta 100% completado, mejor ir a recolectar alimentos" << endl;
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

    cout << "Promedio de kg de alimentos: " << prom << endl;
    for(int i=0; i<TAM; i++){
        if(kgAlimentos[i] > prom){
            cout << nombres[i] << ": " << kgAlimentos[i] << "Kgs" << endl;
        }
    }

}

void refugioMasRapido(const int TAM, int diasDeArmado[], string nombres[]){

    int menor = 8;
    int pos;
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
        for(int j = 0; j < TAM - i - 1; j++){

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
                int auxDias = copiaDiasDeArmado[j];
                copiaDiasDeArmado[j] = copiaDiasDeArmado[j + 1];
                copiaDiasDeArmado[j + 1] = auxDias;

                int tempKg = copiaKgAlimentos[j];
                copiaKgAlimentos[j] = copiaKgAlimentos[j + 1];
                copiaKgAlimentos[j + 1] = tempKg;

                string tempNombre = copiaNombres[j];
                copiaNombres[j] = copiaNombres[j + 1];
                copiaNombres[j + 1] = tempNombre;

                int tempEdad = copiaEdades[i];
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
            cout << "eliminado\t" << copiaNombres[i] << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << "\t\t" << copiaEdades[i] << endl;
        } else {
            cout << puesto++ << "\t\t" << copiaNombres[i] << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << "\t\t" << copiaEdades[i] << endl;
        }
    }
}


int estadisticasEtapa1(const int TAM, int kgAlimentos[], int diasDeArmado[], string nombres[], int edades[], int &dia, bool jugadorVivo){

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
                promedioAlimentos(TAM, kgAlimentos, nombres);
                break;
            case 2:
                refugioMasRapido(TAM, diasDeArmado, nombres);
                break;
            case 3:
                refugioMas5Dias(TAM, diasDeArmado, nombres);
                break;
            case 4:
                tablaPosicionesEtapa1(TAM, diasDeArmado, kgAlimentos, nombres, edades);
                break;
            case 5:
                if(jugadorVivo){
                    return opcionStats;
                    break;
                }else{
                    cout << "Jugador elimiinado. No puede avanzar a la segunda etapa." << endl;
                    break;
                }
            case 0:
                break;
            default:
                cout << "No ha elegido una opcion valida. Vuelva a seleccionar" << endl;
                break;
        }
        system("pause");
        system("cls");

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
    }

    return opcionStats;

}

void chequearVivos(const int TAM, int kgAlimentos[], int diasDeRefugio[], int jugadoresVivos[]){

    int vivos = 0;

    for (int i = 0; i < TAM; i++) {

        if(kgAlimentos[i] >= 14 && diasDeRefugio[i] != 0){
            jugadoresVivos[i] = 1;
            vivos++;
        }else{
            jugadoresVivos[i] = 0;
        }
    }

}

bool recolectarMaterialesBalsa(const int TAM, int kgAlimentos[], int porcBalsa[], int diasDeArmado[], int &dia){

    int materiales, materialesRecolectados;
    system("cls");
    if(porcBalsa[0] < 100){
        cout<<"Haz elegido recolectar materiales"<<endl;
        cout<<"1- Troncos de arboles"<<endl;
        cout<<"2- Hojas de palmera"<<endl;
        cout<<"3- Lianas" << endl;
        cin>>materiales;

        switch(materiales){
            case 1:
                cout << "Haz elegido troncos de arboles" << endl << endl;
                materialesRecolectados=(rand()%15+10);
                porcBalsa[0] += materialesRecolectados;
                break;
            case 2:
                cout << "Haz elegido hojas de palmera" << endl << endl;
                materialesRecolectados=(rand()%20+15);
                porcBalsa[0] += materialesRecolectados;
                break;
            case 3:
                cout << "Haz elegido lianas" << endl << endl;
                materialesRecolectados=(rand()%30+8);
                porcBalsa[0] += materialesRecolectados;
                break;
            default:
                cout << "No ha elegido una opcion valida. Vuelva a seleccionar" << endl;
                dia -= 1;
                return false;
                break;
        }
        if(porcBalsa[0] >= 100){
            porcBalsa[0] = 100;
            if(diasDeArmado[0] == 0){
                diasDeArmado[0] = dia+1;
            }
        }
        cout << "Haz recolectado " << materialesRecolectados << " de materiales" << endl << endl;
        if(porcBalsa[0] >= 100){
            cout << "Llevas acumulado 100% de la balsa" << endl;
        }else{
            cout << "Llevas acumulado " << porcBalsa[0] << "% de la balsa" << endl;
        }
        cout << "Llevas acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
        return true;
    }else{
        dia -= 1;
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

    cout << "Promedio de kg de alimentos: " << prom << endl;
    for(int i=0; i<TAM; i++){
        if(kgAlimentos[i] > prom && jugadoresVivos[i] == 1){
            cout << nombres[i] << ": " << kgAlimentos[i] << "Kgs" << endl;
        }
    }

}

void refugioMasRapidoEtapa2(const int TAM, int diasDeArmado[], int jugadoresVivos[], string nombres[]){

    int menor = 8;
    int pos;
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
        for(int j = 0; j < TAM - i - 1; j++){

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
                cout << "eliminado\t" << copiaNombres[i] << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << "\t\t" << copiaEdades[i] << endl;
            }else{
                cout << puesto++ << "\t\t" << copiaNombres[i] << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << "\t\t" << copiaEdades[i] << endl;
            }
        }
    }
}

int estadisticasEtapa2(const int TAM, int kgAlimentos[], int diasDeArmado[], int jugadoresVivos[], string nombres[], int edades[], int &dia, bool jugadorVivo){

    system("pause");
    system("cls");
    int opcionStats;
    cout << "===========================================================================" << endl;
    cout << "                           ESTADISTICAS ETAPA 2                            " << endl;
    cout << "===========================================================================" << endl;
    cout << "1- Participantes que superaron el promedio de kg de alimentos recolectados" << endl;
    cout << "2- Participante mas rapido en construir su balsa" << endl;
    cout << "3- Tabla de posiciones" << endl;
    cout << "4- Continuar a la tercera etapa" << endl;
    cout << "0- Salir del juego" << endl;
    cin >> opcionStats;

    while(opcionStats != 0){
        system("cls");
        switch(opcionStats){
            case 1:
                promedioAlimentosEtapa2(TAM, kgAlimentos, jugadoresVivos, nombres);
                break;
            case 2:
                refugioMasRapidoEtapa2(TAM, diasDeArmado, jugadoresVivos, nombres);
                break;
            case 3:
                tablaPosicionesEtapa2(TAM, diasDeArmado, kgAlimentos, jugadoresVivos, nombres, edades);
                break;
            case 4:
                if(jugadorVivo){
                    return opcionStats;
                    break;
                }else{
                    cout << "Jugador elimiinado. No puede avanzar a la tercera etapa." << endl;
                    break;
                }
            case 0:
                break;
            default:
                cout << "No ha elegido una opcion valida. Vuelva a seleccionar" << endl;
                break;
        }
        system("pause");
        system("cls");

        cout << "===========================================================================" << endl;
        cout << "                           ESTADISTICAS ETAPA 2                            " << endl;
        cout << "===========================================================================" << endl;
        cout << "1- Participantes que superaron el promedio de kg de alimentos recolectados" << endl;
        cout << "2- Participante mas rapido en construir su balsa" << endl;
        cout << "3- Tabla de posiciones" << endl;
        cout << "4- Continuar a la tercera etapa" << endl;
        cout << "0- Salir del juego" << endl;
        cin >> opcionStats;
    }

    return opcionStats;
}

void eleccionFinal(int eleccion, int horasDeLlegada[]){

    bool opcionValida = false;

    do {
        system("cls");
        cout << "Etapa 3." << endl;
        cout << "Elija una direccion para escapar con la balsa: " << endl << endl;
        cout << "1- Norte" << endl;
        cout << "2- Sur" << endl;
        cout << "3- Este" << endl;
        cout << "4- Oeste" << endl;
        cin >> eleccion;

        switch(eleccion) {
            case 1:
                system("cls");
                cout << "Haz elegido el camino Norte." << endl << endl;
                horasDeLlegada[0] = (rand() % 12 + 4);
                cout << "Haz tardado " << horasDeLlegada[0] << " horas en llegar al destino." << endl << endl;
                cout << "Texto Sobrevivio" << endl;
                opcionValida = true;
            break;

            case 2:
                system("cls");
                cout << "Haz elegido el camino Sur." << endl << endl;
                horasDeLlegada[0] = (rand() % 16 + 4);
                cout << "Haz tardado " << horasDeLlegada[0] << " horas en llegar al destino." << endl;
                cout << "El camino elegido estaba obstruido por ramas de arboles" << endl;
                cout << "caidos en el primer tramo, pero luego, gracias a la corriente a favor," << endl;
                cout << "tomaste velocidad y lograste llegar en un excelente tiempo." << endl << endl;
                opcionValida = true;
            break;

            case 3:
                system("cls");
                cout << "Haz elegido el camino Este." << endl << endl;
                horasDeLlegada[0] = (rand() % 3 + 25);
                cout << "Haz tardado " << horasDeLlegada[0] << " horas." << endl;
                cout << "Texto Murio" << endl;
                opcionValida = true;
            break;

            case 4:
                system("cls");
                cout << "Haz elegido el camino Oeste." << endl << endl;
                horasDeLlegada[0] = (rand() % 3 + 25);
                cout << "Haz tardado " << horasDeLlegada[0] << " horas." << endl;
                cout << "Texto Murio" << endl;
                opcionValida = true;
            break;

            default:
                system("cls");
                cout << "No ha elegido una opcion valida. Vuelva a seleccionar." << endl;
                system("pause");
            break;
        }

    }while(!opcionValida);

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
    int menor = 35;

    for(int i=0; i<TAM; i++){

        if((horasDeLlegada[i] < menor && horasDeLlegada[i] != 0) && jugadoresVivos[i] != 0){
            menor = horasDeLlegada[i];
            pos = i;
        }
    }

    cout << nombres[pos] << " en " << menor << " horas" << endl;

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
                cout << "eliminado\t" << copiaNombres[i] << "\t\t" << copiaHoras[i] << "\t\t" << copiaEdades[i] << endl;
            }else{
                if(copiaHoras[i] == copiaHoras[i+1]){
                    cout << puesto << "\t\t" << copiaNombres[i] << "\t\t" << copiaHoras[i] << "\t\t" << copiaEdades[i] << endl;
                }else{
                    cout << puesto++ << "\t\t" << copiaNombres[i] << "\t\t" << copiaHoras[i] << "\t\t" << copiaEdades[i] << endl;
                }
            }
        }
    }
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

    int opcionStats;
    cout << "===========================================================================" << endl;
    cout << "                           ESTADISTICAS ETAPA 3                            " << endl;
    cout << "===========================================================================" << endl;
    cout << "1- Participante mas rapido en llegar al destino" << endl;
    cout << "2- Tabla de posiciones" << endl;
    cout << "3- Volver a jugar" << endl;
    cout << "0- Salir" << endl;
    cin >> opcionStats;

    while(opcionStats != 0){
        system("cls");
        switch(opcionStats){
            case 1:
                masRapidoEtapa3(TAM, horasDeLlegada, jugadoresVivos, nombres);
                break;
            case 2:
                tablaPosicionesEtapa3(TAM, horasDeLlegada, jugadoresVivos, nombres, edades);
                break;
            case 3:
                reiniciarJuego(TAM, kgAlimentos, porcRefugio, diasDeArmado, jugadoresVivos, dia);
                return opcionStats;
                break;
            case 0:
                return opcionStats;
                break;
            default:
                cout << "No ha elegido una opcion valida. Vuelva a seleccionar" << endl;
                break;

        }

        system("pause");
        system("cls");
        cout << "===========================================================================" << endl;
        cout << "                           ESTADISTICAS ETAPA 3                            " << endl;
        cout << "===========================================================================" << endl;
        cout << "1- Participante mas rapido en llegar al destino" << endl;
        cout << "2- Tabla de posiciones" << endl;
        cout << "3- Volver a jugar" << endl;
        cout << "0- Salir" << endl;
        cin >> opcionStats;
    }

    return opcionStats;
}
