#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
bool recolectarAlimentos(const int TAM, int kgAlimentos[], int porcRefugio[], int &dia);
bool recolectarMateriales(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia);
void recoleccionBots(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int jugadoresVivos[],int &dia);
void promedioAlimentos(const int TAM, int kgAlimentos[]);
void refugioMasRapido(const int TAM, int diasDeArmado[]);
void refugioMas5Dias(const int TAM, int diasDeArmado[]);
void tablaPosicionesEtapa1(const int TAM, int diasDeArmado[], int porcRefugio[], int kgAlimentos[]);
int chequearVivos(const int TAM, int kgAlimentos[], int diasDeRefugio[], int jugadoresVivos[]);
bool recolectarMaterialesBalsa(const int TAM, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int &dia);
void promedioAlimentosEtapa2(const int TAM, int kgAlimentos[], int jugadoresVivos[]);
void refugioMasRapidoEtapa2(const int TAM, int diasDeArmado[], int jugadoresVivos[]);
void tablaPosicionesEtapa2(const int TAM, int diasDeArmado[], int porcRefugio[], int kgAlimentos[], int jugadoresVivos[]);
void eleccionFinal(int eleccion,int horasDeLlegada[]);
void eleccionFinalBots(int vivos, int horasDeLlegada[], int jugadoresVivos[]);
void masRapidoEtapa3(int vivos, int horasDeLlegada[], int jugadoresVivos[]);
void tablaPosicionesEtapa3(int vivos, int horasDeLlegada[]);
#endif // FUNCIONES_H_INCLUDED

