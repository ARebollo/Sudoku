#include "tablero.h"
#include <iostream>
#include <time.h>
using namespace std;

void llenador (tablero &tab,int fila,int columna,bool &finalizado)
{
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
		if (finalizado==false)
		{
				if (esInicial(tab.table[fila][columna])==false)
				{
					//
					
					int i=0;
					while (i<tab.tamano*tab.tamano&&finalizado==false)
					{
						//ponerValor(tab.table[fila][columna],valoresPosibles[i]);
						//TEntornoPonerNumero(fila,columna,[valoresPosibles[i]);
						tab.table[fila][columna].valor=valoresPosibles[i];
						i++;
						if (conflicto(tab,fila,columna)==false)
						{
							if (columna==tab.tamano*tab.tamano-1&&fila==tab.tamano*tab.tamano-1)
							{
								finalizado=true;
								llenador(tab,fila,columna,finalizado);
							}
							else if (columna==tab.tamano*tab.tamano-1)
							{
								llenador (tab,fila+1,0,finalizado);
							}
							else
							{
								llenador (tab,fila,columna+1,finalizado);
							}
						}
						if (i==tab.tamano*tab.tamano&&finalizado==false)
						{
							//ponerValor(tab.table[fila][columna],0);
							//TEntornoPonerNumero(fila,columna,0);
							tab.table[fila][columna].valor=0;
						}
					}
				}		
				else 
				{
					if (columna==tab.tamano*tab.tamano-1&&fila==tab.tamano*tab.tamano-1)
						{
							finalizado=true;
						}
					else if (columna==tab.tamano*tab.tamano-1)
						{
							llenador (tab,fila+1,0,finalizado);
						}
						else
						{
							llenador (tab,fila,columna+1,finalizado);
						}
				}
		}
}
