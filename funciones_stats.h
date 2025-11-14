#ifndef FUNCIONES_STATS_H_INCLUDED
#define FUNCIONES_STATS_H_INCLUDED
#include <string>
using namespace std;

void promedioAlimentos(const int TAM, int kgAlimentos[], int jugadoresVivos[], string nombres[]);
void refugioMasRapido(const int TAM, int nroEtapa, int diasDeArmado[], int jugadoresVivos[], string nombres[]);
void refugioMas5Dias(const int TAM, int nroEtapa, int diasDeArmado[], int jugadoresVivos[], string nombres[]);
void refugioMasRapido(const int TAM, int nroEtapa, int diasDeArmado[], int jugadoresVivos[], string nombres[]);
void tablaPosiciones(const int TAM, int nroEtapa, int kgAlimentos[] ,int diasDeArmado[], int jugadoresVivos[], string nombres[], int edades[]);
int estadisticasEtapa(const int TAM, int nroEtapa, int kgAlimentos[], int diasDeArmado[], int jugadoresVivos[], string nombres[], int edades[], int &dia, bool jugadorVivo);
void masRapidoEtapa3(const int TAM, int horasDeLlegada[], int jugadoresVivos[], string nombres[]);
void tablaPosicionesEtapa3(const int TAM, int horasDeLlegada[], int jugadoresVivos[], string nombres[], int edades[]);
void rangoEtario(const int TAM, int edades[], string nombres[]);
void reiniciarJuego(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int jugadoresVivos[], int &dia);
int estadisticasEtapa3(const int TAM, int kgAlimentos[], int diasDeArmado[], int jugadoresVivos[], int horasDeLlegada[], int porcRefugio[], string nombres[], int edades[],int &dia, bool jugadorVivo);

#endif // FUNCIONES_STATS_H_INCLUDED
