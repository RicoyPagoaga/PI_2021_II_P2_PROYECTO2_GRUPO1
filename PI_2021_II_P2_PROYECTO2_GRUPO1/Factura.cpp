#include <iostream>
#include <string>
#include "Factura.h"

using namespace std;
Factura::Factura() {
	establecerNumeroFactura(0);
	establecerAño(0);
	establecerMes(0);
	establecerDia(0);
}
Factura::Factura(int num, int _año, int _mes, int _dia) {
	establecerNumeroFactura(num);
	establecerAño(_año);
	establecerMes(_mes);
	establecerDia(_dia);
}
void Factura::establecerNumeroFactura(int num) {
	numeroFactura = num;
}
int Factura::obtenerNumeroFactura() const {
	return numeroFactura;
}
void Factura::establecerAño(int _año) {
	año = _año;
}
int Factura::obtenerAño() const {
	return año;
}
void Factura::establecerMes(int _mes) {
	mes = _mes;
}
int Factura::obtenerMes() const {
	return mes;
}
void Factura::establecerDia(int _dia) {
	dia = _dia;
}
int Factura::obtenerDia() const {
	return dia;
}
void Factura::imprimirClienteInfo(Cliente cliente) const {
	cout << "Cliente: " << cliente.obtenerNombre() << " " << cliente.obtenerApellido() << endl;
	
}
void Factura::crearFactura() const {
	int num = 0, dia = 0, mes = 0, año = 0;
	string nom = " ", apel = " ";
	Factura factura;
	cout << "Escriba el numero de factura: "; cin >> num;
	factura.establecerNumeroFactura(num);
	cout << "Ingrese la fecha: " << endl;
	cout << " Dia: ";
	cin >> dia;
	cout << " Mes: ";
	cin >> mes;
	cout << " Año: ";
	cin >> año;
	factura.establecerDia(dia);
	factura.establecerMes(mes);
	factura.establecerAño(año);
	cout << "ingrese el nombre y apellido del cliente: " << endl;
	cout << "Nombre: "; cin >> nom;
	cout << "Apellido: "; cin >> apel;
	Cliente cliente;
	cliente.establecerNombre(nom);
	cliente.establecerApellido(apel);
	cout << "\n_____________________________________________________________________" << endl;
	cout << "Factura " << factura.obtenerNumeroFactura() << endl;
	cout << "Fecha: " << factura.obtenerDia() << "/" << factura.obtenerMes() << "/" << factura.obtenerAño() << endl;
	imprimirClienteInfo(cliente);
}