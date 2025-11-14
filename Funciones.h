#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>
using namespace std;

void nombreYEdad(const int TAM, string nombres[], int edades[]);
void recolectarAlimentos(const int TAM, int kgAlimentos[], int porcRefugio[], int &dia);
bool recolectarMateriales(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia);
void recoleccionBots(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int jugadoresVivos[],int &dia);
void chequearVivos(const int TAM, int kgAlimentos[], int diasDeRefugio[], int jugadoresVivos[]);
bool recolectarMaterialesBalsa(const int TAM, int kgAlimentos[], int porcBalsa[], int diasDeArmado[], int &dia);
void eleccionFinal(int eleccion,int horasDeLlegada[]);
void eleccionFinalBots(const int TAM, int horasDeLlegada[], int jugadoresVivos[]);

#endif // FUNCIONES_H_INCLUDED
