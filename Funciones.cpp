#include <iostream>
#include <time.h>
#include <string>
#include "rlutil.h"
#include "funciones_visuales.h"

using namespace std;

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
                    y = 2;
                }
                break;
            case 115: // abajo
                rlutil::locate(3,5+y);
                y++;
                if(y>2){
                    y = 0;
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
                    y = 3;
                }
                break;
            case 115: // abajo
                rlutil::locate(3,5+y);
                y++;
                if(y>3){
                    y = 0;
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
                    y = 2;
                }
                break;
            case 115: // abajo
                rlutil::locate(3,5+y);
                y++;
                if(y>2){
                    y = 0;
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
                    y = 3;
                }
                break;
            case 115: // abajo
                rlutil::locate(1,3+y);
                cout << " ";
                y++;
                if(y>3){
                    y = 0;
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
