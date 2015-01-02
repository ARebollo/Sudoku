#ifndef LLENADOR_H_
#define LLENADOR_H_

//Rellena el tablero tab con valores aleatorios que conformen un sudoku válido. No cambia valores marcados como iniciales
//La bandera finalizado ha de comenzar como false y la llamada inicial ha de hacerse con fila,columna==0
void llenador(tablero &tab,int fila,int columna,bool &finalizado);
#endif // !LLENADOR_H_
