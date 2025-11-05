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
            alimentoRecogido=(rand()%10+0);
            kgAlimentos[0] += alimentoRecogido;
            break;
        case 2:
            cout << "Cosecha en arbusto" << endl;
            alimentoRecogido=(rand()%5+2);
            kgAlimentos[0] += alimentoRecogido;
            break;
        case 3:
            cout << "Cosecha en arboles" << endl;
            alimentoRecogido=(rand()%8+3);
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
                materialesRecolectados=(rand()%35+1);
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

void recoleccionBots(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia){

    for(int i=1; i<TAM; i++){
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
