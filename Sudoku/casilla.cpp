#include "casilla.h"
#include <time.h>
#include <iostream>

void PonerValor(casilla cas,int valor)
{
	if (cas.inicial==false)
		cas.valor=valor;
}

int HallarValor(casilla cas)
{
	int valor = cas.valor;
	return  valor;
}

void BorrarCasilla(casilla cas) //hace lo mismo que iniciar, no s� que piden con iniciar, ma�ana pregunto en IP
{
	if (cas.inicial==false)
		cas.valor=0;
}

void aleatorio(casilla cas,int valoresposibles)
{
	srand(time(NULL));
	PonerValor(cas,(rand()%valoresposibles)+1);
}