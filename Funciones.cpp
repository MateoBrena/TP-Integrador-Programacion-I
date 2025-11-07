#include <iostream>
#include <time.h>
#include <string>

using namespace std;

bool recolectarAlimentos(const int TAM, int kgAlimentos[], int porcRefugio[], int &dia){
    int alimentos, alimentoRecogido;
    system("cls");
    cout<<"Eligio recolectar alimentos"<<endl;
    cout<<"1- Pesca en el rio "<<endl;
    cout<<"2- Cosecha en arbustos"<<endl;
    cout<<"3- Cosecha en arboles"<<endl;
    cin>>alimentos;

    switch(alimentos){
        case 1:
            cout << "Pesca en el rio" << endl;
            alimentoRecogido=(rand()%15+0);
            kgAlimentos[0] += alimentoRecogido;
            break;
        case 2:
            cout << "Cosecha en arbusto" << endl;
            alimentoRecogido=(rand()%10+3);
            kgAlimentos[0] += alimentoRecogido;
            break;
        case 3:
            cout << "Cosecha en arboles" << endl;
            alimentoRecogido=(rand()%8+5);
            kgAlimentos[0] += alimentoRecogido;
            break;
        default:
            cout << "No ha elegido una opcion valida. Vuelva a seleccionar" << endl;
            dia -= 1;
            return false;
            break;
        }
        cout << "Ha recolectado " << alimentoRecogido << " kg de alimentos" << endl;
        cout << "Lleva acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
        if(porcRefugio[0] >= 100){
            cout << "Lleva acumulado 100% del refugio" << endl;
        }else{
            cout << "Lleva acumulado " << porcRefugio[0] << "% del refugio" << endl;
        }
        return true;
}

bool recolectarMateriales(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia){

    int materiales, materialesRecolectados;
    system("cls");
    if(porcRefugio[0] < 100){
        cout<<"Eligio recolectar materiales"<<endl;
        cout<<"1- Ramas de arboles "<<endl;
        cout<<"2- Ramas de arbustos"<<endl;
        cout<<"3- Barro"<<endl;
        cout<<"4- Rocas"<<endl;
        cin>>materiales;

        switch(materiales){
            case 1:
                cout << "Ramas de arboles" << endl;
                materialesRecolectados=(rand()%15+10);
                porcRefugio[0] += materialesRecolectados;
                break;
            case 2:
                cout << "Ramas de arbustos" << endl;
                materialesRecolectados=(rand()%20+15);
                porcRefugio[0] += materialesRecolectados;
                break;
            case 3:
                cout << "Barro" << endl;
                materialesRecolectados=(rand()%30+8);
                porcRefugio[0] += materialesRecolectados;
                break;
            case 4:
                cout << "Rocas" << endl;
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
        cout << "Ha recolectado " << materialesRecolectados << " de materiales" << endl;
        if(porcRefugio[0] >= 100){
            cout << "Lleva acumulado 100% del refugio" << endl;
        }else{
            cout << "Lleva acumulado " << porcRefugio[0] << "% del refugio" << endl;
        }
        cout << "Lleva acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
        return true;
    }else{
        dia -= 1;
        cout << "Te dije que el refugio ya esta 100% completado, vaya a recolectar alimentos" << endl;
        return false;
    }
}

void recoleccionBots(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int jugadoresVivos[], int &dia){

    for(int i=1; i<TAM; i++){

        if(jugadoresVivos[i] == 1){
            int eleccion = (rand()%2+1);

            if(eleccion == 1){
                kgAlimentos[i] += (rand()%10+3);
            }else{
                porcRefugio[i] += (rand()%40+10);
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

void promedioAlimentos(const int TAM, int kgAlimentos[]){

    int acum = 0;
    for(int i=0; i<TAM; i++){
        acum += kgAlimentos[i];
    }

    float prom = float(acum)/TAM;

    cout << "Promedio de kg de alimentos: " << prom << endl;
    for(int i=0; i<TAM; i++){
        if(kgAlimentos[i] > prom){
            cout << "Jugador " << i+1 << ": " << kgAlimentos[i] << "Kgs" << endl;
        }
    }

}

void refugioMasRapido(const int TAM, int diasDeArmado[]){

    int menor = 8;
    int pos;
    for(int i=0; i<TAM; i++){
        if(diasDeArmado[i] < menor && diasDeArmado[i] > 0){
            menor = diasDeArmado[i];
            pos = i;
        }
    }

    cout << "Jugador " << pos+1 << " en " << menor << " dias" << endl;
}

void refugioMas5Dias(const int TAM, int diasDeArmado[]){

    int cont = 0;
    for(int i=0; i<TAM; i++){
        if(diasDeArmado[i] > 5){
            cont++;
            cout << "Jugador " << i+1 << " en " << diasDeArmado[i] << " dias" << endl;
        }
    }

    if(cont == 0){
        cout << "Ningun jugador completo el refugio en mas de 5 dias" << endl;
    }
}

void tablaPosicionesEtapa1(const int TAM, int diasDeArmado[], int porcRefugio[], int kgAlimentos[]){

    int nroJugador[TAM];
    int copiaDiasDeArmado[TAM];
    int copiaKgAlimentos[TAM];

    for(int i=0; i<TAM; i++) {
        nroJugador[i] = i;
        copiaDiasDeArmado[i] = diasDeArmado[i];
        copiaKgAlimentos[i] = kgAlimentos[i];
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

                int tempNro = nroJugador[j];
                nroJugador[j] = nroJugador[j + 1];
                nroJugador[j + 1] = tempNro;
            }
        }
    }

    cout << "Puesto\t\tJugador\t\tDias de armado\t\tKgs de alimento\n";
    cout << "------------------------------------------------------------------------\n";

    int puesto = 1;
    for(int i=0; i<TAM; i++){
        if (copiaDiasDeArmado[i] == 0 || copiaKgAlimentos[i] < 14) {
            cout << "eliminado\t" << nroJugador[i]+1 << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << endl;
        } else {
            cout << puesto++ << "\t\t" << nroJugador[i]+1 << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << endl;;
        }
    }
}

int chequearVivos(const int TAM, int kgAlimentos[], int diasDeRefugio[], int jugadoresVivos[]){

    int vivos = 0;

    for (int i = 0; i < TAM; i++) {

        if(kgAlimentos[i] >= 14 && diasDeRefugio[i] != 0){
            jugadoresVivos[i] = 1;
            vivos++;
        }else{
            jugadoresVivos[i] = 0;
        }
    }

    return vivos;
}

bool recolectarMaterialesBalsa(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia){

    int materiales, materialesRecolectados;
    system("cls");
    if(porcRefugio[0] < 100){
        cout<<"Eligio recolectar materiales"<<endl;
        cout<<"1- Troncos de arboles"<<endl;
        cout<<"2- Hojas de palmera"<<endl;
        cout<<"3- Caña" << endl;
        cin>>materiales;

        switch(materiales){
            case 1:
                cout << "Troncos de arboles" << endl;
                materialesRecolectados=(rand()%15+10);
                porcRefugio[0] += materialesRecolectados;
                break;
            case 2:
                cout << "Hojas de palmera" << endl;
                materialesRecolectados=(rand()%20+15);
                porcRefugio[0] += materialesRecolectados;
                break;
            case 3:
                cout << "Caña" << endl;
                materialesRecolectados=(rand()%30+8);
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
        cout << "Ha recolectado " << materialesRecolectados << " de materiales" << endl;
        if(porcRefugio[0] >= 100){
            cout << "Lleva acumulado 100% de la balsa" << endl;
        }else{
            cout << "Lleva acumulado " << porcRefugio[0] << "% de la balsa" << endl;
        }
        cout << "Lleva acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
        return true;
    }else{
        dia -= 1;
        cout << "Te dije que la balsa ya esta 100% completado, vaya a recolectar alimentos" << endl;
        return false;
    }
}

void promedioAlimentosEtapa2(const int TAM, int kgAlimentos[], int jugadoresVivos[]){

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
    for(int i=0; i<vivos; i++){
        if(kgAlimentos[i] > prom && jugadoresVivos[i] == 1){
            cout << "Jugador " << i+1 << ": " << kgAlimentos[i] << "Kgs" << endl;
        }
    }

}

void refugioMasRapidoEtapa2(const int TAM, int diasDeArmado[], int jugadoresVivos[]){

    int acum = 0;
    int vivos = 0;
    for(int i=0; i<TAM; i++){
        if(jugadoresVivos[i] == 1){
            vivos++;
        }
    }

    int menor = 8;
    int pos;
    for(int i=0; i<vivos; i++){
        if(diasDeArmado[i] < menor && diasDeArmado[i] > 0){
            if(jugadoresVivos[i] == 1){
                menor = diasDeArmado[i];
                pos = i;
            }
        }
    }

    cout << "Jugador " << pos+1 << " en " << menor << " dias" << endl;
}

void tablaPosicionesEtapa2(const int TAM, int diasDeArmado[], int porcRefugio[], int kgAlimentos[], int jugadoresVivos[]){

    int vivos = 0;

    for(int i=0; i<TAM; i++){
        if(jugadoresVivos[i]){
            vivos++;
        }
    }

    int nroJugador[vivos];
    int copiaDiasDeArmado[vivos];
    int copiaKgAlimentos[vivos];

    for(int i=0; i<vivos; i++) {
        nroJugador[i] = i;
        copiaDiasDeArmado[i] = diasDeArmado[i];
        copiaKgAlimentos[i] = kgAlimentos[i];
    }


    for(int i=0; i<vivos - 1; i++){
        for(int j = 0; j < vivos - i - 1; j++){

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
                int tempDias = copiaDiasDeArmado[j];
                copiaDiasDeArmado[j] = copiaDiasDeArmado[j + 1];
                copiaDiasDeArmado[j + 1] = tempDias;

                int tempKg = copiaKgAlimentos[j];
                copiaKgAlimentos[j] = copiaKgAlimentos[j + 1];
                copiaKgAlimentos[j + 1] = tempKg;

                int tempNro = nroJugador[j];
                nroJugador[j] = nroJugador[j + 1];
                nroJugador[j + 1] = tempNro;
            }
        }
    }

    cout << "Puesto\t\tJugador\t\tDias de armado\t\tKgs de alimento\n";
    cout << "------------------------------------------------------------------------\n";

    int puesto = 1;
    for(int i=0; i<vivos; i++){
        if (copiaDiasDeArmado[i] == 0 || copiaKgAlimentos[i] < 14) {
            cout << "eliminado\t" << nroJugador[i]+1 << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << endl;
        } else {
            cout << puesto++ << "\t\t" << nroJugador[i]+1 << "\t\t\t" << copiaDiasDeArmado[i] << "\t\t\t" << copiaKgAlimentos[i] << endl;;
        }
    }
}

void eleccionFinal(int eleccion, int horasDeLlegada[]){

    cout << "Etapa 3. Elija una direccion de escape: " << endl << endl;
    cout << "1- Norte" << endl;
    cout << "2- Sur" << endl;
    cout << "3- Este" << endl;
    cout << "4- Oeste" << endl;
    cin >> eleccion;

    switch(eleccion){
        case 1:
            cout << "Norte" << endl;
            horasDeLlegada[0] = (rand()%2+10);
            cout << "Has tardado " << horasDeLlegada[0] << " horas en llegar al destino" << endl;
            cout << "Texto Sobrevivio" << endl;
        break;
        case 2:
            cout << "Sur" << endl;
            horasDeLlegada[0] = (rand()%2+16);
            cout << "Has tardado " << horasDeLlegada[0] << " horas en llegar al destino" << endl;
            cout << "Texto Sobrevivio" << endl;
        break;
        case 3:
            cout << "Este" << endl;
            horasDeLlegada[0] = (rand()%3+25);
            cout << "Has tardado " << horasDeLlegada[0] << "horas" <<endl;
            cout << "Texto Murio" << endl;
        break;
        case 4:
            cout << "Oeste" << endl;
            horasDeLlegada[0] = (rand()%3+25);
            cout << "Has tardado " << horasDeLlegada[0] << " horas" << endl;
            cout << "Texto Murio" << endl;
        break;
        default:
            cout << "No ha elegido una opcion valida. Vuelva a seleccionar" << endl;
        break;

    }

}

void eleccionFinalBots(int vivos, int horasDeLlegada[], int jugadoresVivos[]){

    for(int i=1; i<vivos; i++){
        if(jugadoresVivos[i] == 1){
            horasDeLlegada[i]=(rand()%30+1);
        }
    }
}

void masRapidoEtapa3(int vivos, int horasDeLlegada[], int jugadoresVivos[]){

    int menor = 30;
    int pos;
    for(int i=0; i<vivos; i++){
        if(horasDeLlegada[i] < menor && jugadoresVivos[i] != 0){
            menor = horasDeLlegada[i];
            pos = i;
        }
    }

    cout << "Jugador " << pos+1 << " en " << menor << " horas" << endl;

}

void tablaPosicionesEtapa3(int vivos, int horasDeLlegada[]){
    int i, j;
    int nroJugador[vivos];

    for(int i=0; i<vivos; i++){
        nroJugador[i] = i;
    }

    for (i = 0; i < vivos - 1; i++) {
        for (j = 0; j < vivos - i - 1; j++) {
            if (horasDeLlegada[j] > horasDeLlegada[j + 1]) {

                int temp = horasDeLlegada[j];
                horasDeLlegada[j] = horasDeLlegada[j + 1];
                horasDeLlegada[j + 1] = temp;

                int tempNro = nroJugador[j];
                nroJugador[j] = nroJugador[j + 1];
                nroJugador[j + 1] = tempNro;
            }
        }
    }

    cout << "Puesto\t\tJugador\t\tHoras de llegada\n";
    cout << "------------------------------------------------------------------------\n";

    int puesto = 1;
    for(int i=0; i<vivos; i++){
        if (horasDeLlegada[i] > 24){
            cout << "eliminado\t" << nroJugador[i]+1 << "\t\t\t" << horasDeLlegada[i] << endl;
        } else {
            cout << puesto++ << "\t\t" << nroJugador[i]+1 << "\t\t\t" << horasDeLlegada[i] << endl;;
        }
    }
}
