#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
bool recolectarAlimentos(const int TAM, int kgAlimentos[], int porcRefugio[], int &dia);
bool recolectarMateriales(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia);
void recoleccionBots(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia);
void promedioAlimentos(const int TAM, int kgAlimentos[]);
void refugioMasRapido(const int TAM, int diasDeArmado[]);
void refugioMas5Dias(const int TAM, int diasDeArmado[]);
#endif // FUNCIONES_H_INCLUDED

