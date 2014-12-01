#include "tablero.h"
#include <iostream>
#include <time.h>


/*
La parte de las cajas se puede hacer directamente en el módulo conflicto haciendo la división del número de fila por el tamaño del tablero:

Ejemplo para 3x3 con la casilla [numfila][numcolumna]:

for (i=0;i<tamano*tamano;i++)
{
  for (j=0;j<tamano*tamano;j++)
  {
  if ((i/tamano==numfila/tamano)&&j/tamano==numcolumna/tamano)
  {
  if (valorcasilla[i][j]==valorcasilla[numfila][numcolumna])
  conflicto=true;
  }
  }
}
*/

//primer numero es la fila, segundo la columna


bool conflicto(tablero tab,int fila,int columna) //true si hay, false si no
{
	bool conf = false;
	for (int i=0;i<tab.tamano*tab.tamano;i++)
	{
		if (tab.table[i][columna].valor==tab.table[fila][columna].valor&&i!=fila)
			conf=true;
	}
	for (int j=0;j<tab.tamano*tab.tamano;j++)
	{
		if (tab.table[fila][j].valor==tab.table[fila][j].valor&&j!=columna)
			conf=true;
	}
	for (i=0;i<tamano*tamano;i++)
	{
	 	for (j=0;j<tamano*tamano;j++)
	 	{
  			if ((i/tamano==numfila/tamano)&&j/tamano==numcolumna/tamano)
  			{
  				if (valorcasilla[i][j]==valorcasilla[numfila][numcolumna])
  				conf=true;
  			}
		 }
	}
	return conf;
}
