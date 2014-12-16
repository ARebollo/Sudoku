#ifndef TABLERO_H_
#define TABLERO_H_
#include "casilla.h"
const int MAXTtamano = 16;
//Casilla se puede reutilizar para otros juegos, pero en el sudoku requiere tener un identificador de en qu� caja est�


typedef casilla Tmatriz[MAXTtamano][MAXTtamano];

struct tablero {
	Tmatriz table;
	int tamano;
};
//Asigna a cada casilla una caja (1 para tama�o 1, 4 para tama�o 2, etc). Las cajas se numeran de izquierda a derecha y de arriba abajo
void inicializarcajas(tablero &tab);



//PRE: fila, columna < MAXtamano
//POST: Devuelve true si el valor en tablero.table[fila][columna] tiene alg�n conflicto con alg�n otro valor
bool conflicto (tablero tab,int fila,int columna);

#endif // !TABLERO_H_
