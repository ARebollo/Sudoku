//============================================================================
// Name        : SudokuEntorno.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "entorno.h"
#include "tablero.h"
#include "llenador.h"


using namespace std;

void runDemo() {

	int fila = 0,    //almacenan las coordenadas de la casilla
			columna = 0; //que está activa en cada momento

	bool salir = false;	//bandera que indica si el programa termina,
						//se activa al pulsar Escape

	tablero tab; 
	int matriz[16][16];	//matriz en la que se almacenan
									 //los valores inciales del tablero antes de pasarlos a tab

	int tamano;   //número de subtableros de Sudoku por fila
				   //o columna, valores posibles 1, 2, 3 o 4

	int aleatorioOFichero, numValores;

	int tiempoPausa = 500000;

	//se recupera la información almacenada en el fichero de configuración
	if (TEntornoCargarConfiguracion(matriz, tab.tamano, aleatorioOFichero,
			numValores)) {
		
		//Pasa los valores de matriz a tab
		for (int i = 0; i < tamano * tamano; i++)
		{
			for (int j = 0; j < tamano * tamano; j++) 
			{
				if (matriz[i][j]!=0)
					ponerValorInicial(tab.table[i][j],matriz[i][j]);
			}
		}

		// pinta la rejilla
		TEntornoIniciar(tamano);

		// pinta en pantalla el patrón de inicio leido del fichero de cinfiguración
		int valor;
		for (int i = 0; i < tab.tamano * tab.tamano; i++)
			for (int j = 0; j < tab.tamano * tab.tamano; j++) {
				valor = tab[i][j];

				if (valor > 0)
					TEntornoPonerNumeroInicial(i, j, valor);
			}

		TEntornoActivarCasilla(0, 0); // Coordenadas iniciales de movimientos

		// muestro los valores posibles para una determinada celda
		// void TEntornoMostrarValoresPosibles( int valor, int pos)

		int i = 1;		// indica la posición de pantalla donde pintar el valor

		TipoTecla tecla = TNada;   //almacena la tecla pulsada

		while (!salir) {

			tecla = TEntornoLeerTecla();

			switch (tecla) {
			case TIzquierda:
				TEntornoDesactivarCasilla(fila, columna);
				if (columna > 0)
					columna--;
				TEntornoActivarCasilla(fila, columna);
				for (i = 0; i < tab.tamano * tab.tamano; i++) 
				{
					if (conflicto(tab,fila,columna)==false)
						TEntornoMostrarValoresPosibles(i, i);
				}
				break;
			case TDerecha:
				TEntornoDesactivarCasilla(fila, columna);
				if (columna < (tamano * tamano) - 1)
					columna++;
				TEntornoActivarCasilla(fila, columna);
				for (i = 0; i < tab.tamano * tab.tamano; i++) 
				{
					if (conflicto(tab,fila,columna)==false)
						TEntornoMostrarValoresPosibles(i, i);
				}
				break;
			case TArriba:
				TEntornoDesactivarCasilla(fila, columna);
				if (fila > 0)
					fila--;
				TEntornoActivarCasilla(fila, columna);				
				for (i = 0; i < tab.tamano * tab.tamano; i++) 
				{
					if (conflicto(tab,fila,columna)==false)
						TEntornoMostrarValoresPosibles(i, i);
				}
				break;
			case TAbajo:
				TEntornoDesactivarCasilla(fila, columna);
				if (fila < (tamano * tamano) - 1)
					fila++;
				TEntornoActivarCasilla(fila, columna);
				for (i = 0; i < tab.tamano * tab.tamano; i++) 
				{
					if (conflicto(tab,fila,columna)==false)
						TEntornoMostrarValoresPosibles(i, i);
				}
				break;
			case TSalir:
				salir = true;
				break;
			case TS:
				TEntornoMostrarMensaje(Zona1,"Está seguro de que desea resolver el sudoku actual? Pulse Enter para aceptar o ESC para volver");
				TipoTecla Tecla = TNada;
				bool finalizado=false;
				do tecla = TEntornoLeerTecla();
				while(Tecla!=TEnter&&tecla!=TSalir);
				if (Tecla==TEnter)
					llenador(tab,0,0,finalizado);
				break;
			case TX:
				break;
			case TEnter:

				break;
			case TEliminar:

				break;
			case TUno:
			case TDos:
			case TTres:
			case TCuatro:
			case TCinco:
			case TSeis:
			case TSiete:
			case TOcho:
			case TNueve:
			case TA: // valor 10
			case TB: // valor 11
			case TC: // valor 12
			case TD: // valor 13
			case TE: // valor 14
			case TF: // valor 15
			case TG: // valor 16
				if (esInicial(tab.table[fila][columna])==false)
				{
					ponerValor(tab.table[fila][columna],tecla);
					TEntornoPonerNumero(fila,columna,tecla);
				}
				break;
			default:
				break;

			}  // fin switch

		} // Fin while

		TEntornoMostrarMensajeFin("         ¡¡¡¡Adios!!!!");
		TEntornoPausa(tiempoPausa);

	} else
		cout << "Error, no existe el fichero de configuración" << std::endl;
}


int main() {

	runDemo();

	return 0;
}
