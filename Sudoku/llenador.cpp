#include "tablero.h"

void llenador (tablero &tab)
{
		int fila = 0;
		int columna = 0;
		bool imposible = true; //Para evitar bucles infinitos en caso de que no haya valores posibles
		for (int z=1;z<=tab.tamano*tab.tamano;z++)
		{
			for (int i=0;i<tab.tamano*tab.tamano;i++)
			{
				if (tab.table[i][columna].valor!=z&&i!=fila)
					imposible=false;
			}
			for (int j=0;j<tab.tamano*tab.tamano;j++)
			{
				if (tab.table[fila][j].valor!=z&&j!=columna)
					imposible=false;
			}

		}
		if (tab.table[fila][columna].inicial==false)
		aleatorioTablero(tab,fila,columna);


/*
Esquema de como hacerlo:
1. Comprueba si hay algún valor posible.
2. Si no lo hay, se llama a sí misma en la casilla anterior
3. Si lo hay, genera un valor aleatorio válido para esa casilla.
4. Una vez generado un valor válido, si la casilla no es la última, se llama a sí mismo en la casilla siguiente.
5. Si ha llegado a la última casilla, el sudoku se ha generado correctamente.

Módulos usados:

bool conflicto
void aleatorio

*/
