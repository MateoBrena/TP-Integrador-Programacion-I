#ifndef FUNCIONES_VISUALES_H_INCLUDED
#define FUNCIONES_VISUALES_H_INCLUDED
#include <string>
using namespace std;

void mostrarBannerInicial();
void mostrarSeleccionado(string texto, int posX, int posY, bool seleccionado);
int mostrarMenu(string opciones[], int cantidad, int x, int y);
void mostrarTextosEtapa(int nroEtapa, string nombres[]);
void mostrarTablasFinEtapa(const int TAM, int nroEtapa, int kgAlimentos[], int porcRefugio[], int diasDeArmado[], int jugadoresVivos[], int horasDeLlegada[],string nombres[]);

#endif // FUNCIONES_VISUALES_H_INCLUDED
