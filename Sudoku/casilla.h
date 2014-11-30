#ifndef CASILLA_H_
#define CASILLA_H_


struct casilla {
	int valor;
	bool inicial; //True si es un valor inicial del tablero
	bool vacia;
};

//Inicializa una casilla
void iniciar(casilla c);

//Pone un valor en una casilla pedida
void ponerValor(casilla c,int valor);

//Poner un valor inicial en una casilla pedida
void ponerValorInicial(casilla cas,int valor);

//True si es inicial, false si no
bool esInicial(casilla c);

//True si esta vacia, false si no
bool estaVacia(casilla c);

//Devuelve el valor en la casilla pedida
int hallarValor(casilla c);

//Pone el valor de la casilla pedida a 0
void borrarCasilla(casilla c);

//True si está vacía, false si no
bool EstaVacia(casilla c);

//Aleatoriza una casilla pedida con un valor válido con un máximo especificado
void aleatorio(casilla c,int valoresposibles);


#endif // !CASILLA_H_
