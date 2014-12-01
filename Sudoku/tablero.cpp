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
void inicializarcajas(tablero &tab)
{
	switch (tab.tamano)
	{
	case 1: //En el tablero 1x1 solamente hay una caja
		tab.table[0][0].caja=1;
		break;
	case 2: 
		for (int i=0;i<tab.tamano*tab.tamano;i++)
		{
			for (int j=0;j<tab.tamano*tab.tamano;j++) //Con estos dos bucles se recorre el tablero entero
			{	
				//i=0,1 son cajas 1 y 3, i=2,3 son cajas 2 y 4
				switch (i) 
				{
					//Filas uno y dos
					case 0:
					case 1:
						switch (j)
						{
						case 0:
						case 1:
							tab.table[i][j].caja=1;
							break;
						case 3:
						case 4:
							tab.table[i][j].caja=2;
							break;
						default:
							break;
						}
						break;
					//Filas tres y cuatro
					case 3:
					case 4:
						switch (j)
						{
						case 0:
						case 1:
							tab.table[i][j].caja=3;
							break;
						case 3:
						case 4:
							tab.table[i][j].caja=4;
							break;
						default:
							break;
						}
						break;
				default:
					break;
				}
			}
		}
		break;

	//TamaÃ±o 3
	case 3:
		for (int i=0;i<tab.tamano*tab.tamano;i++)
		{
			for (int j=0;j<tab.tamano*tab.tamano;j++) //Con estos dos bucles se recorre el tablero entero
			{	
				//i=0,1,2 son cajas 1,4 y 7, i=3,4,5 son cajas 2, 5 y 8, i=6,7,8 son cajas 3,6 y 9
				switch (i) 
				{
				//Primeras tres filas
				case 0:
				case 1:
				case 2:
					switch (j)
					{
					case 0:
					case 1:
					case 2:
						tab.table[i][j].caja=1;
						break;
					case 3:
					case 4:
					case 5: 
						tab.table[i][j].caja=2;
						break;
					case 6:
					case 7:
					case 8:			
						tab.table[i][j].caja=3;
						break;
					default:
						break;
					}
					break;
				//Segundas tres filas
				case 3:
				case 4:
				case 5: 
					switch (j)
					{
					case 0:
					case 1:
					case 2:
						tab.table[i][j].caja=4;
						break;
					case 3:
					case 4:
					case 5: 
						tab.table[i][j].caja=5;
						break;
					case 6:
					case 7:
					case 8:	
						tab.table[i][j].caja=6;
						break;
					default:
						break;
					}
					break;
				//Ãšltimas tres filas
				case 6:
				case 7:
				case 8:	
					switch (j)
					{
					case 0:
					case 1:
					case 2:
						tab.table[i][j].caja=7;
						break;	
					case 3:
					case 4:
					case 5: 
						tab.table[i][j].caja=8;
						break;
					case 6:
					case 7:
					case 8:	
						tab.table[i][j].caja=9;
						break;
					default:
						break;
					}
					break;

				default:
					break;
				}
			}
		}
		break;

	//TamaÃ±o 4
	case 4:
		for (int i=0;i<tab.tamano*tab.tamano;i++)
		{
			for (int j=0;j<tab.tamano*tab.tamano;j++) //Con estos dos bucles se recorre el tablero entero
			{	
				switch (i) //i=1,2 son cajas 1 y 3, i=3,4 son cajas 2 y 4
				{
				//Primeras 4 filas
				case 0:
				case 1:
				case 2:
				case 3:
					switch (j)
					{
					case 0:
					case 1:
					case 2:
					case 3:
						tab.table[i][j].caja=1;
						break;
					
					case 4:
					case 5:
					case 6:
					case 7:
						tab.table[i][j].caja=2;
						break;

					case 8:
					case 9:
					case 10:
					case 11:
						tab.table[i][j].caja=3;
						break;

					case 12:
					case 13:
					case 14:
					case 15:
						tab.table[i][j].caja=4;
						break;

					default:
						break;
					}
					break;
				//Segundas cuatro filas
				case 4:
				case 5:
				case 6:
				case 7:
					switch (j)
					{
					case 0:
					case 1:
					case 2:
					case 3:
						tab.table[i][j].caja=5;
						break;
					
					case 4:
					case 5:
					case 6:
					case 7:
						tab.table[i][j].caja=6;
						break;

					case 8:
					case 9:
					case 10:
					case 11:
						tab.table[i][j].caja=7;
						break;

					case 12:
					case 13:
					case 14:
					case 15:
						tab.table[i][j].caja=8;
						break;

					default:
						break;
					}
				//Terceras cuatro filas
				case 8:
				case 9:
				case 10:
				case 11:
					switch (j)
					{
					case 0:
					case 1:
					case 2:
					case 3:
						tab.table[i][j].caja=9;
						break;
					
					case 4:
					case 5:
					case 6:
					case 7:
						tab.table[i][j].caja=10;
						break;
					
					case 8:
					case 9:
					case 10:
					case 11:
						tab.table[i][j].caja=11;
						break;

					case 12:
					case 13:
					case 14:
					case 15:
						tab.table[i][j].caja=12;
						break;

					default:
						break;
					}
				//Ãšltimas cuatro filas
				case 12:
				case 13:
				case 14:
				case 15:
					switch (j)
					{
					case 0:
					case 1:
					case 2:
					case 3:
						tab.table[i][j].caja=13;
						break;
					
					case 4:
					case 5:
					case 6:
					case 7:
						tab.table[i][j].caja=14;
						break;
					
					case 8:
					case 9:
					case 10:
					case 11:
						tab.table[i][j].caja=15;
						break;

					case 12:
					case 13:
					case 14:
					case 15:
						tab.table[i][j].caja=16;
						break;

					default:
						break;
					}
				default:
					break;
				}
			}
		}
		break;
	default:
		break;
	}
}

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
