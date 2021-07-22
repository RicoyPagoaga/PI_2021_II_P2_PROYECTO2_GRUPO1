#include <iostream>
#include <string>
#include <stdexcept>

#include "Cliente.h"
using namespace std;

Cliente::Cliente(string nombre, string apellido, string identificacion, string direccion, int edad, int _cuenta, double _Saldo)
	: Persona(nombre, apellido, identificacion, direccion, edad) {
	establecerSaldo(_Saldo);
	numeroCuenta = _cuenta;
}
void Cliente::establecerNumeroCuenta(int _cuenta) {
	if (_cuenta > 0 && _cuenta < 100)
		numeroCuenta = _cuenta;
}
int Cliente::obtenerNumeroCuenta()const {
	return numeroCuenta;
}
void Cliente::establecerSaldo(double _Saldo) {
	if (_Saldo < 0)
		cerr << "Los gastos deben ser > 0";
	Saldo = _Saldo;
}
double Cliente::obtenerSaldo()const {
	return Saldo;
}
void Cliente::agregarCliente() {
		//agregarPersona();
		cout << "\nSaldo: ";
		cin >> Saldo;
		establecerSaldo(Saldo);
}
void Cliente::imprimirInformacion() const {
	Persona::imprimirInformacion();
	cout << "Con saldo de: " << obtenerSaldo() << " Lps.";
}
