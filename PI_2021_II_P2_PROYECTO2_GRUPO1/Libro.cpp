#include <iostream>
#include <string>
#include <stdexcept>

#include "Libro.h"
using namespace std;


Libro::Libro(string _nombre, string _autor, string _tipoLibro, int _año) {
	establecerNombre(_nombre);
	establecerAutor(_autor);
	establecerTipoLibro(_tipoLibro);
	establecerAño(_año);
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
void Libro::establecerAño(int _año) {
	año = _año;
}
int Libro::obtenerAño()const {
	return año;
}

void Libro::mostrarLibro() {
	cout << obtenerNombre() << " - " << obtenerAutor() << " , " << obtenerTipoLibro() << ", " << obtenerAño() << endl;
}