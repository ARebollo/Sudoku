#include "tablero.h"
#include <iostream>
#include <time.h>

bool conflicto(tablero tab,int fila,int columna) //true si hay, false si no
{
	bool conf = false;
	for (int i=0;i<tab.tamano*tab.tamano;i++)
	{
		for (int j=0;j<tab.tamano*tab.tamano;j++)
		{
			if (i%tab.tamano==fila%tab.tamano&&j%tab.tamano==columna%tab.tamano)
			{
				if (tab.table[i][j].valor==tab.table[fila][columna].valor&&!(i==fila&&j==columna))
					conf=true;
			}
			if (tab.table[i][columna].valor==tab.table[fila][columna].valor&&i!=fila)
				conf=true;
			if (tab.table[fila][j].valor==tab.table[fila][j].valor&&j!=columna)
				conf=true;
		}
	}
	return conf;
}

