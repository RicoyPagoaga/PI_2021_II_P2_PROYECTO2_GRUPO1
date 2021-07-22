#include <string>
#include <stdexcept> 
#include <iostream> 
#include "EmpleadoTemporal.h"
using namespace std;

EmpleadoTemporal::EmpleadoTemporal() {
	establecerNumeroSeguroSocial(" ");
}
EmpleadoTemporal::EmpleadoTemporal(string nombre, string apellido, string _direccion, string _identificacion,
	int _edad, string seguro, int numero, double ventas)
	:Persona(nombre, apellido, _direccion, _identificacion, _edad) {
	establecerNumeroCuenta(numero), establecerVentas(ventas), establecerNumeroSeguroSocial(seguro);
}

string EmpleadoTemporal::obtenerNumeroSeguroSocial() const {
	return numeroSeguroSocial;
}
void EmpleadoTemporal::establecerNumeroSeguroSocial(string seguro) {
	int longitud = seguro.size();
	longitud = (longitud < 15 ? longitud : 14);
	seguro.copy(numeroSeguroSocial, longitud);
	numeroSeguroSocial[longitud] = '\0';
}
void EmpleadoTemporal::establecerVentas(double ventas) {
	if (ventas >= 0.0)
		Ventas = ventas;
	else
		throw invalid_argument("Las ventas debe ser >= 0");
}
double EmpleadoTemporal::obtenerVentas() const {
	return Ventas;
}
void EmpleadoTemporal::establecerNumeroCuenta(int numero) {
	if (numero > 0 && numero < 100)
		numeroCuenta = numero;
	else
		throw invalid_argument("El numero de cuenta debe ser 0-100");
}
int EmpleadoTemporal::obtenerNumeroCuenta() const {
	return numeroCuenta;
}
void EmpleadoTemporal::imprimirInformacion() const {
	cout << "Empleado Temporal: ";
	Persona::imprimirInformacion();
	cout << endl << " Salario: " << calcularIngresos();
}
double EmpleadoTemporal::calcularIngresos() const {
	return (obtenerVentas() * 0.5);
}