#include "tablero.h"
#include "casilla.h"
#include <iostream>
#include <time.h>
using namespace std;

void inicializarTablero(tablero &tab)
{
	for (int i=0;i<tab.tamano*tab.tamano;i++)
	{
		for (int j=0;j<tab.tamano*tab.tamano;j++)
		{
			tab.table[i][j].inicial=false;
			tab.table[i][j].vacia=true;
			tab.table[i][j].valor=0;
		}
	}
}

bool conflicto(tablero tab,int fila,int columna) //true si hay, false si no
{
	bool conf = false;
	for (int i=0;i<tab.tamano*tab.tamano;i++)
	{
		for (int j=0;j<tab.tamano*tab.tamano;j++)
		{
			//Doble bucle

			if ((i/tab.tamano==fila/tab.tamano)&&(j/tab.tamano==columna/tab.tamano))
			{
				if ((tab.table[i][j].valor==tab.table[fila][columna].valor)&&(i!=fila&&j!=columna))
				{
					conf=true;
				}
			}
			if (tab.table[i][columna].valor==tab.table[fila][columna].valor&&i!=fila)
			{
				conf=true;
			}
			if (tab.table[fila][j].valor==tab.table[fila][columna].valor&&j!=columna)
			{
				conf=true;
			}
		}
	}
	return conf;
}

