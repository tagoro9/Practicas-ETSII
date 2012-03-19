#include "bitsetmatrix.h"

BitsetMatrix::BitsetMatrix(int row, int column, string bitset) {
	_row = row;
	_column = column;
	matrix.resize((row*column),Bitset(0,8));
	int times = (row*column);
	//Inicializar matriz a partir de una cadena
	if ((bitset != "") && (bitset.length() == row*column*8)) {
		//La cadena viene dada por columnas
		vector<string> aux;
		for (int i = 0; i < times; i++) {
			string cadena = bitset.substr(i*8,8);
			aux.push_back(cadena);
		}
		//Inicializar los elementos de la matriz (por columnas)
		for (int j(0),k(0); j < column; j++) {
			for (int i = 0; i < row; i++) {
				matrix[j+column*i] = aux[k];
				k++;
			}
		}
	}
}

BitsetMatrix::BitsetMatrix(const BitsetMatrix &other) {
	_column = other.get_columns();
	_row = other.get_rows();
	matrix.clear();
	matrix.resize(_column*_row,Bitset(0,8));
	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _column; j++) {
			matrix[i*_column+j] = (other(i,j));
		}
	}
}

Bitset BitsetMatrix::operator()(const int i, const int j) const {
	if ((i < _row) && (j < _column))
		return matrix[i*_column+j];
	return Bitset("00000000");
}

void BitsetMatrix::set(const int i, const int j, const Bitset bitset) {
	if ((i < _row) && (j < _column))
		matrix[i*_row+j] = bitset;
}

Bitset BitsetMatrix::get_column(const int j) const {
	string col = "";
	for (int i = 0; i < _row; i++)
		col += matrix[i*_column+j].to_s();
	return Bitset(col);
}

Bitset BitsetMatrix::operator[](const int j) const {
	return get_column(j);
}

Bitset BitsetMatrix::get_row(const int j) const {
	string fil = "";
	int start = j*_column;
	for (int i = 0; i < _column; i++) {
		fil += matrix[i+start].to_s();
	}
	return Bitset(fil);
}

void BitsetMatrix::set_row(const int j, Bitset bitset) {
	if (bitset.size() == 8*_column) {
		int start = j*_column;
		for(int i = 0; i < _column; i++) {
			matrix[i+start] = bitset.subset((_column -i -1)*8,8);
		}
	}
}

void BitsetMatrix::set_column(const int j, Bitset bitset) {
	if (bitset.size() == 8*_row) {
		for (int i = 0; i < _row; i++) {
			matrix[i*_column+j] = bitset.subset((_row-i-1)*8,8);
		}
	}
}

BitsetMatrix &BitsetMatrix::operator= (const BitsetMatrix &other) {
	_column = other.get_columns();
	_row = other.get_rows();
	matrix.clear();
	matrix.resize(_row*_column,Bitset(0,8));
	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _column; j++) {
			matrix[i*_column+j] = (other(i,j));
		}
	}
}

void BitsetMatrix::rotate(const int column, const int pos, const char MODE) {
	Bitset b_column = get_column(column);
	switch (MODE) {
		case (LEFT): {
			//La primera pasa a ultimo lugar
			b_column.rotate(pos*8);
			break;
		}
		case (RIGHT): {
			//La ultima pasa a primer lugar
			b_column.rotate(pos*8,RIGHT);
			break;
		}
	}
	set_column(column,b_column);
}

void BitsetMatrix::rotate_row(const int row, const int pos, const char MODE) {
	Bitset b_row = get_row(row);
	switch (MODE) {
		case (LEFT): {
			//La primera pasa a ultimo lugar
			b_row.rotate(pos*8);
			break;
		}
		case (RIGHT): {
			//La ultima pasa a primer lugar
			b_row.rotate(pos*8,RIGHT);
			break;
		}
	}
	set_row(row,b_row);
}

string BitsetMatrix::to_s(const char STYLE, const char MODE) const{
	string out = "";
	switch (STYLE) {
		case LINEAL: {
			for (int i = 0; i < _column; i++)
				out += get_column(i).to_s(HEX,8);
			break;
		}
		case MATRIX: {
			for (int i = 0; i < _row; i++) {
				for (int j = 0; j < _column; j++) {
					out += (matrix[i*_column+j]).to_s(HEX,8) + " ";
				}
				out += "\n";
			}
			break;
		}
	}
	return out;
}

ostream &operator<< (ostream &sout, const BitsetMatrix &other) {
	sout << other.to_s(MATRIX);
	return sout;
}
