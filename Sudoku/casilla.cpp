#include "casilla.h"
#include <time.h>
#include <iostream>

void ponerValor(casilla cas,int valor)
{
	if (cas.inicial==false)
		cas.valor=valor;
	cas.vacia=false;
}

void ponerValorInicial(casilla cas,int valor)
{
	cas.valor=valor;
	cas.vacia=false;
	cas.inicial=true;
}

int hallarValor(casilla cas)
{
	int valor = cas.valor;
	return  valor;
}

<<<<<<< HEAD
bool esInicial(casilla c)
{
	return c.inicial;
}

bool estaVacia(casilla c)
{
	return c.vacia;
}

void BorrarCasilla(casilla cas)

{
	if (cas.inicial==false)
		cas.vacia=true;
}

bool EstaVacia(casilla cas)
{
	bool vacia = false;
	if (cas.valor==0)
		vacia = true;
	return vacia;
}

void aleatorio(casilla cas,int valoresposibles)
{
	srand(time(NULL));

	ponerValor(cas,(rand()%valoresposibles)+1);
	cas.vacia=false;
}
