#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void recolectarAlimentos(const int TAM, int kgAlimentos[], int porcRefugio[]){
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
            cout << "Ha recolectado " << alimentoRecogido << " kg de alimentos" << endl;
            cout << "Lleva acumulado " << kgAlimentos[0] << " kg de alimentos" << endl;
            if(porcRefugio[0] >= 100){
                cout << "Lleva acumulado 100% del refugio" << endl;
            }else{
                cout << "Lleva acumulado " << porcRefugio[0] << "% del refugio" << endl;
            }
            break;
        case 2:
            cout << "Cosecha en arbusto" << endl;
            alimentoRecogido=(rand()%5+2);
            kgAlimentos[0] += alimentoRecogido;
            cout << "Ha recolectado " << alimentoRecogido << " kg de alimentos" << endl;
            cout << "Lleva acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
            if(porcRefugio[0] >= 100){
                cout << "Lleva acumulado 100% del refugio" << endl;
            }else{
                cout << "Lleva acumulado " << porcRefugio[0] << "% del refugio" << endl;
            }
            break;
        case 3:
            cout << "Cosecha en arboles" << endl;
            alimentoRecogido=(rand()%8+3);
            kgAlimentos[0] += alimentoRecogido;
            cout << "Ha recolectado " << alimentoRecogido << " kg de alimentos" << endl;
            cout << "Lleva acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
            if(porcRefugio[0] >= 100){
                cout << "Lleva acumulado 100% del refugio" << endl;
            }else{
                cout << "Lleva acumulado " << porcRefugio[0] << "% del refugio" << endl;
            }
            break;
        }
}

void recolectarMateriales(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia){

int materiales, materialesRecolectados;

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
                if(porcRefugio[0] >= 100){
                    porcRefugio[0] = 100;
                    if(diasDeArmado[0] == 0){
                        diasDeArmado[0] = dia;
                    }
                }
                cout << "Ha recolectado " << materialesRecolectados << " de materiales" << endl;
                if(porcRefugio[0] >= 100){
                    cout << "Lleva acumulado 100% del refugio" << endl;
                }else{
                    cout << "Lleva acumulado " << porcRefugio[0] << "% del refugio" << endl;
                }
                cout << "Lleva acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
                break;
            case 2:
                cout << "Ramas de arbustos" << endl;
                materialesRecolectados=(rand()%20+15);
                porcRefugio[0] += materialesRecolectados;
                if(porcRefugio[0] >= 100){
                    porcRefugio[0] = 100;
                if(diasDeArmado[0] == 0){
                    diasDeArmado[0] = dia;
                    }
                }
                cout << "Ha recolectado " << materialesRecolectados << " de materiales" << endl;
                if(porcRefugio[0] >= 100){
                    cout << "Lleva acumulado 100% del refugio" << endl;
                }else{
                    cout << "Lleva acumulado " << porcRefugio[0] << "% del refugio" << endl;
                }
                cout << "Lleva acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
                break;
            case 3:
                cout << "Barro" << endl;
                materialesRecolectados=(rand()%30+8);
                porcRefugio[0] += materialesRecolectados;
                if(porcRefugio[0] >= 100){
                    porcRefugio[0] = 100;
                    if(diasDeArmado[0] == 0){
                        diasDeArmado[0] = dia;
                    }
                }
                cout << "Ha recolectado " << materialesRecolectados << " de materiales" << endl;
                if(porcRefugio[0] >= 100){
                    cout << "Lleva acumulado 100% del refugio" << endl;
                }else{
                    cout << "Lleva acumulado " << porcRefugio[0] << "% del refugio" << endl;
                }
                cout << "Lleva acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
                break;
            case 4:
                cout << "Rocas" << endl;
                materialesRecolectados=(rand()%35+1);
                porcRefugio[0] += materialesRecolectados;
                if(porcRefugio[0] >= 100){
                    porcRefugio[0] = 100;
                    if(diasDeArmado[0] == 0){
                        diasDeArmado[0] = dia;
                    }
                }
                cout << "Ha recolectado " << materialesRecolectados << " de materiales" << endl;
                if(porcRefugio[0] >= 100){
                    cout << "Lleva acumulado 100% del refugio" << endl;
                }else{
                    cout << "Lleva acumulado " << porcRefugio[0] << "% del refugio" << endl;
                }
                cout << "Lleva acumulado " << kgAlimentos[0] << "kg de alimentos" << endl;
                break;
        }
    }else{
        dia -= 1;
        cout << "Te dije que el refugio ya esta 100% completado, vaya a recolectar alimentos" << endl;
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
                    diasDeArmado[i] = dia;
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

    cout << endl << "Promedio de kg de alimentos: " << prom << endl;
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

    for(int i=0; i<TAM; i++){
        if(diasDeArmado[i] > 5){
            cout << "Jugador " << i+1 << " en " << diasDeArmado[i] << " dias" << endl;
        }
    }
}
