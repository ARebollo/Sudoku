#include "tablero.h"
#include <iostream>
#include <time.h>
using namespace std;

void mostrarMatriz(tablero tab)
{
	for (int i=0;i<tab.tamano*tab.tamano;i++)
	{
		for (int j=0;j<tab.tamano*tab.tamano;j++)
		{
			cout <<tab.table[i][j].valor;
			if (j==(tab.tamano*tab.tamano-1))
				cout <<endl;
		}
	}
}


void llenador (tablero &tab,int fila,int columna,bool finalizado)
{
		srand (time(NULL));
		int valoresPosibles[MAXTtamano];
		//Genera un vector con todos los valores posibles para la casilla en orden aleatorio
		for (int y=0;y<tab.tamano*tab.tamano;y++)
		{
			bool yaCogido=false;
			do
			{
				valoresPosibles[y]=(rand()%(tab.tamano*tab.tamano))+1;
				yaCogido=false;
				for (int x=0;x<y;x++)
				{
					if (valoresPosibles[x]==valoresPosibles[y])
						yaCogido=true;
				}
			}
			while (yaCogido==true);
		}
		//Fin generador vector	
		if (!finalizado)
		{
			for (int i=0;i<tab.tamano*tab.tamano;i++)
			{
				if (esInicial(tab.table[fila][columna])==false)
				{
					ponerValor(tab.table[fila][columna],valoresPosibles[i]);
					if (conflicto(tab,fila,columna)==false)
					{
						if (columna==tab.tamano*tab.tamano-1&&fila==tab.tamano*tab.tamano-1)
							llenador (tab,fila,columna,true);
						if (columna!=tab.tamano*tab.tamano-1)
							llenador (tab,fila,columna+1,false);
						else llenador (tab,fila+1,0,false);
					}
				}
				else 
				{
					if (columna==tab.tamano*tab.tamano-1&&fila==tab.tamano*tab.tamano-1)
						llenador(tab,fila,columna,true);
					if (columna!=tab.tamano*tab.tamano-1)
							llenador (tab,fila,columna+1,false);
					else llenador (tab,fila+1,0,false);
				}
			}
		}
}
		
