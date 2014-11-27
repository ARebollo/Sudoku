#include "tablero.h"

void llenador (tablero &tab)
{
		int fila = 0;
		int columna = 0;
		bool imposible = true; //Para evitar bucles infinitos en caso de que no haya valores posibles
		for (int z=1;z<=tab.tamanio*tab.tamanio;z++)
		{
			for (int i=0;i<tab.tamanio*tab.tamanio;i++)
			{
				if (tab.table[i][columna].valor!=z&&i!=fila)
					imposible=false;
			}
			for (int j=0;j<tab.tamanio*tab.tamanio;j++)
			{
				if (tab.table[fila][j].valor!=z&&j!=columna)
					imposible=false;
			}

		}
		if (tab.table[fila][columna].inicial==false)
		aleatorioTablero(tab,fila,columna);
