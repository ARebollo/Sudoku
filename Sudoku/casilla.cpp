#include "casilla.h"
#include <time.h>
#include <iostream>

void ponerValor(casilla &c,int valor)
{
	if (c.inicial==false)
		c.valor=valor;
	c.vacia=false;
}

void ponerValorInicial(casilla &c,int valor)
{
	c.valor=valor;
	c.vacia=false;
	c.inicial=true;
}

int hallarValor(casilla c)
{
	int valor = c.valor;
	return  valor;
}

<<<<<<< HEAD

=======
>>>>>>> origin/master
bool esInicial(casilla c)
{
	return c.inicial;
}

bool estaVacia(casilla c)
{
	return c.vacia;
}

void BorrarCasilla(casilla c)

{
	if (c.inicial==false)
		c.vacia=true;
}

bool EstaVacia(casilla c)
{
	bool vacia = false;
	if (c.valor==0)
		vacia = true;
	return vacia;
}

void aleatorio(casilla &c,int valoresposibles)
{
	srand(time(NULL));
	ponerValor(c,(rand()%valoresposibles)+1);
	c.vacia=false;
}
