#include <iostream>
#include <string>
#include <stdexcept>

#include "Libro.h"
using namespace std;


Libro::Libro(string _nombre, string _autor, string _tipoLibro, int _a�o) {
	establecerNombre(_nombre);
	establecerAutor(_autor);
	establecerTipoLibro(_tipoLibro);
	establecerA�o(_a�o);
}
void Libro::establecerNombreLibro(string _nombre) {
	nombreLibro = _nombre;
}
string Libro::obtenerNombreLibro()const {
	return nombreLibro;
}
void Libro::establecerAutor(string _autor) {
	autor = _autor;
}
string Libro::obtenerAutor()const {
	return autor;
}
void Libro::establecerTipoLibro(string _tipoLibro) {
	tipoDeLibro = _tipoLibro;
}
string Libro::obtenerTipoLibro()const {
	return tipoDeLibro;
}
void Libro::establecerA�o(int _a�o) {
	a�o = _a�o;
}
int Libro::obtenerA�o()const {
	return a�o;
}

void Libro::mostrarLibro() {
	cout << obtenerNombre() << " - " << obtenerAutor() << " , " << obtenerTipoLibro() << ", " << obtenerA�o() << endl;
}