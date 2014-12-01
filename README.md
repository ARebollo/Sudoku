Sudoku
======

La parte de las cajas se puede hacer directamente en el módulo conflicto haciendo la división del número de fila por el tamaño del tablero:

Ejemplo para 3x3 con la casilla [numfila][numcolumna]:

for (i=0;i<tamano;i++)
{
  for (j=0;j<tamano;i++)
  {
  if ((i/tamano==numfila/tamano)&&j/tamano==numcolumna/tamano)
  {
  if (valorcasilla[i][j]==valorcasilla[numfila][numcolumna])
  conflicto=true;
  }
  }
}
