#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>
using namespace std;

void mostrarSeleccionado(string texto, int posX, int posY, bool seleccionado);
void nombreYEdad(const int TAM, string nombres[], int edades[]);
bool recolectarAlimentos(const int TAM, int kgAlimentos[], int porcRefugio[], int &dia);
bool recolectarMateriales(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia);
void recoleccionBots(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int jugadoresVivos[],int &dia);
void promedioAlimentos(const int TAM, int kgAlimentos[], string nombres[]);
void refugioMasRapido(const int TAM, int diasDeArmado[], string nombres[]);
void refugioMas5Dias(const int TAM, int diasDeArmado[], string nombres[]);
void tablaPosicionesEtapa1(const int TAM, int diasDeArmado[], int kgAlimentos[], string nombres[], int edades[]);
int estadisticasEtapa1(const int TAM, int kgAlimentos[], int diasDeArmado[], string nombres[], int edades[], int &dia, bool jugadorVivo);
void chequearVivos(const int TAM, int kgAlimentos[], int diasDeRefugio[], int jugadoresVivos[]);
bool recolectarMaterialesBalsa(const int TAM, int kgAlimentos[], int porcBalsa[], int diasDeArmado[], int &dia);
void tablaPosicionesEtapa2(const int TAM, int diasDeArmado[], int kgAlimentos[], int jugadoresVivos[], string nombres[], int edades[]);
void promedioAlimentosEtapa2(const int TAM, int kgAlimentos[], int jugadoresVivos[], string nombres[]);
void refugioMasRapidoEtapa2(const int TAM, int diasDeArmado[], int jugadoresVivos[], string nombres[]);
int estadisticasEtapa2(const int TAM, int kgAlimentos[], int diasDeArmado[], int jugadoresVivos[], string nombres[], int edades[], int &dia, bool jugadorVivo);
void eleccionFinal(int eleccion,int horasDeLlegada[]);
void eleccionFinalBots(const int TAM, int horasDeLlegada[], int jugadoresVivos[]);
void masRapidoEtapa3(const int TAM, int horasDeLlegada[], int jugadoresVivos[], string nombres[]);
void tablaPosicionesEtapa3(const int TAM, int horasDeLlegada[], int jugadoresVivos[], string nombres[], int edades[]);
void reiniciarJuego(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int jugadoresVivos[], int &dia);
void rangoEtario(const int TAM, int edades[], string nombres[]);
int estadisticasEtapa3(const int TAM, int kgAlimentos[], int diasDeArmado[], int jugadoresVivos[], int horasDeLlegada[], int porcRefugio[], string nombres[], int edades[],int &dia, bool jugadorVivo);

#endif // FUNCIONES_H_INCLUDED

