#ifndef BITSETMATRIX_H_
#define BITSETMATRIX_H_

#include "../bitset/bitset.h"

using namespace std;

const char LINEAL = 'l';
const char MATRIX = 'm';

class BitsetMatrix {
private:
	int _column, _row;
	//Cada bitset de la matriz tendra longitud 8
	vector<Bitset> matrix;
public:
	//Constructor, se le pasan dimensiones y cadena para inicializar (por columnas)
	BitsetMatrix(int row, int column = 1, string bitset = "");
	//Constructor de copia
	BitsetMatrix(const BitsetMatrix &other);
	virtual ~BitsetMatrix() {};
	//Obtener el valor de _column
	int get_columns() const {return _column;};
	//Obtener el valor de _row
	int get_rows() const {return _row;};
	int size() const {return _row*_column;};
	//Imprimir la matriz en un string
	string to_s(const char STYLE = MATRIX, const char MODE = HEX) const;
	//Acceder a una posicion de la matriz
	Bitset operator()(const int i, const int j) const;
	//Modificar un elemento de la matriz
	void set(const int i, const int j,const Bitset bitset);
	//Obtener en un bitset una palabra columna
	Bitset get_column(const int j) const;
	//Obtener en un bitset una palabra columna
	Bitset operator[](const int j) const;
	//Optener en un bitset una palabra fila
	Bitset get_row(const int j) const;
	//Modificar el valor de una fila
	void set_row(const int j, Bitset bitset);
	//Modificar el valor de una columna
	void set_column(const int j, Bitset bitset);
	//Rotar n posiciones una columna
	void rotate(const int column, const int pos, const char MODE = LEFT);
	//Rotar n posiciones una fila
	void rotate_row(const int row, const int pos, const char MODE = LEFT);
	//Operador de asignacion
	BitsetMatrix &operator= (const BitsetMatrix &other);
};

//Imprimir en flujo
ostream &operator<< (ostream &sout, const BitsetMatrix &other);

#endif /* BITSETMATRIX_H_ */
