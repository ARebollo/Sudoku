#ifndef CASILLA_H_
#define CASILLA_H_


struct casilla {
	int valor;
	bool inicial; //True si es un valor inicial del tablero
};

//Inicializa una casilla
void iniciar(casilla c);

//Pone un valor en una casilla pedida
void PonerValor(casilla c,int valor);

//Devuelve el valor en la casilla pedida
int HallarValor(casilla c);

//Pone el valor de la casilla pedida a 0
void BorrarCasilla(casilla c);

//True si está vacía, false si no
bool EstaVacia(casilla c);

//Aleatoriza una casilla pedida con un valor válido con un máximo especificado
void aleatorio(casilla c,int valoresposibles);


#endif // !CASILLA_H_
