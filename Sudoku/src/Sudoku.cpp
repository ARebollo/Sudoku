//============================================================================
// Name        : SudokuEntorno.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "entorno.h"

using namespace std;

void runDemo() {

	int fila = 0,    //almacenan las coordenadas de la casilla
			columna = 0; //que está activa en cada momento

	bool conflicto = false; //bandera para almacenar si hay algún conflicto en la casilla actual

	bool salir = false;	//bandera que indica si el programa termina,
						//se activa al pulsar Escape

	int tab[MAXtamano][MAXtamano]; //matriz en la que se almacenan
									 //los valores inciales del tablero

	int tamano;   //número de subtableros de Sudoku por fila
				   //o columna, valores posibles 1, 2, 3 o 4

	int aleatorioOFichero, numValores;

	int tiempoPausa = 500000;

	//se recupera la información almacenada en el fichero de configuración
	if (TEntornoCargarConfiguracion(tab, tamano, aleatorioOFichero,
			numValores)) {

		// pinta la rejilla
		TEntornoIniciar(tamano);

		// pinta en pantalla el patrón de inicio leido del fichero de cinfiguración
		int valor;
		for (int i = 0; i < tamano * tamano; i++)
			for (int j = 0; j < tamano * tamano; j++) {
				valor = tab[i][j];

				if (valor > 0)
					TEntornoPonerNumeroInicial(i, j, valor);
			}

		TEntornoActivarCasilla(0, 0); // Coordenadas iniciales de movimientos

		// muestro los valores posibles para una determinada celda
		// void TEntornoMostrarValoresPosibles( int valor, int pos)

		int i = 1;		// indica la posición de pantalla donde pintar el valor

		for (i = 1; i < tamano * tamano; i++) {
			TEntornoMostrarValoresPosibles(i, i);
		}

		TipoTecla tecla = TNada;   //almacena la tecla pulsada

		while (!salir) {

			tecla = TEntornoLeerTecla();

			switch (tecla) {
			case TIzquierda:
				TEntornoDesactivarCasilla(fila, columna);
				if (columna > 0)
					columna--;
				TEntornoActivarCasilla(fila, columna);
				break;
			case TDerecha:
				TEntornoDesactivarCasilla(fila, columna);
				if (columna < (tamano * tamano) - 1)
					columna++;
				TEntornoActivarCasilla(fila, columna);
				break;
			case TArriba:
				TEntornoDesactivarCasilla(fila, columna);
				if (fila > 0)
					fila--;
				TEntornoActivarCasilla(fila, columna);
				break;
			case TAbajo:
				TEntornoDesactivarCasilla(fila, columna);
				if (fila < (tamano * tamano) - 1)
					fila++;
				TEntornoActivarCasilla(fila, columna);
				break;
			case TSalir:
				salir = true;
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
