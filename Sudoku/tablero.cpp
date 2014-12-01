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

void aleatorioTablero(tablero &tab,int fila,int columna)
{
		bool conf = false;
		do
			{
<<<<<<< HEAD
                //Para cada tamaño del teclado
				switch (tab.tamano)
=======
                //Para cada tamaÃ±o del teclado
				switch (tab.tamanio)
>>>>>>> origin/master
				{
				case 1:
					tab.table[fila][columna].casi.valor=1;
					break;
				case 2:
					aleatorio(tab.table[fila][columna].casi,4);
					break;
				case 3:
					aleatorio(tab.table[fila][columna].casi,9);
					break;
				case 4:
					aleatorio(tab.table[fila][columna].casi,16);
					break;
				default:
					break;
				}
				conf=conflicto(tab,fila,columna);
			}
			while (conflicto(tab,fila,columna==true));
}
