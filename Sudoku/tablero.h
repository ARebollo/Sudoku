#ifndef TABLERO_H_
#define TABLERO_H_
#include "casilla.h"
const int MAXtamano = 16;

typedef casilla Tmatriz[MAXtamano][MAXtamano];

struct tablero {
	Tmatriz table;
	int tamano;
};

//PRE: fila, columna < MAXtamano
//POST: Devuelve true si el valor en tablero.table[fila][columna] tiene algún conflicto con algún otro valor
//Complejidad: O(n)
bool conflicto (tablero tab,int fila,int columna);

#endif // !TABLERO_H_
