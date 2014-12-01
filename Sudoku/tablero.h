#ifndef TABLERO_H_
#define TABLERO_H_
#include "casilla.h"
const int MAXTtamano = 16;
//Casilla se puede reutilizar para otros juegos, pero en el sudoku requiere tener un identificador de en qué caja está

typedef casilla Tmatriz[MAXTtamano][MAXTtamano];

struct tablero {
	Tmatriz table;
	int tamano;
};

//PRE: fila, columna < MAXtamano
//POST: Devuelve true si el valor en tablero.table[fila][columna] tiene algún conflicto con algún otro valor
bool conflicto (tablero tab,int fila,int columna);

#endif // !TABLERO_H_
