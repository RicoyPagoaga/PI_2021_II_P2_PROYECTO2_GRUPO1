#include <string>
#include <iostream>
#include <stdexcept>

#include "Persona.h"

using namespace std;

Persona::Persona() {
	establecerNombre(" ");
	establecerApellido(" ");
	establecerDireccion(" ");
	establecerIdentificacion(" ");
	establecerEdad(1);
}
Persona::Persona(string nombre, string apellido, string _direccion, string _identificacion, int _edad) {
	establecerNombre(nombre);
	establecerApellido(apellido);
	establecerDireccion(_direccion);
	establecerIdentificacion(_identificacion);
	establecerEdad(_edad);
}
void Persona::establecerNombre(string nombre) {
	int longitud = nombre.size();
	longitud = (longitud < 10 ? longitud : 9);
	nombre.copy(primerNombre, longitud);
	primerNombre[longitud] = '\0';
}
string Persona::obtenerNombre()const {
	return primerNombre;
}
void Persona::establecerApellido(string apellido) {
	int longitud = apellido.size();
	longitud = (longitud < 15 ? longitud : 14);
	apellido.copy(apellidoPaterno, longitud);
	apellidoPaterno[longitud] = '\0';
}
string Persona::obtenerApellido()const {
	return apellidoPaterno;
}
void Persona::establecerDireccion(string _direccion) {
	int longitud = _direccion.size();
	longitud = (longitud < 15 ? longitud : 14);
	_direccion.copy(identificacion, longitud);
	direccion[longitud] = '\0';
}
string Persona::obtenerDireccion()const {
	return direccion;
}
void Persona::establecerIdentificacion(string _identificacion) {
	int longitud = _identificacion.size();
	longitud = (longitud < 15 ? longitud : 14);
	_identificacion.copy(identificacion, longitud);
	apellidoPaterno[longitud] = '\0';
}
string Persona::obtenerIdentificacion()const {
	return identificacion;
}
void Persona::establecerEdad(int _edad) {
	if (_edad < 0)
		throw "La edad debe ser >0";
	edad = _edad;
}
int Persona::obtenerEdad()const {
	return edad;
}
void Persona::imprimirInformacion()const {
	cout << "Nombre: " << obtenerNombre() << " Apellido: " << obtenerApellido()
		<< "\nDireccion: " << obtenerDireccion() << " Identificacion: " << obtenerIdentificacion();
}
//void Persona::agregarPersona() {
//	cout << "Ingrese nombre: \n";
//	cin >> primerNombre;
//	cout << "Ingrese Apellido: \n";
//	cin >> apellidoPaterno;
//	cout << "Ingrese numero de indetificacion: \n";
//	cin >> identificacion;
//	cout << "Ingrese edad: \n";
//	cin >> edad;
//	cout << "Ingrese direccion: \n";
//	cin >> direccion;
//}