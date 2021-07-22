#include <iostream>
#include <string>
#include "Factura.h"
#include "Computadoras.h"

using namespace std;
Computadoras::Computadoras() {
	establecerAño(0);
	establecerDia(0);
	establecerMes(0);
	establecerNumeroFactura(0);
	establecerCostoHora(0.0);
	establecerHora(0);
}
Computadoras::Computadoras(int dia, int mes, int año, int num, int hora, double costoH)
	:Factura(dia, mes, año, num) {
	establecerCostoHora(costoH);
	establecerHora(hora);
}
void Computadoras::establecerCostoHora(double costoH) {
	costoHora = costoH;
}
double Computadoras::obtenerCostoHora()const {
	return costoHora;
}
void Computadoras::establecerHora(int hora) {
	horaUso = hora;
}
int Computadoras::obtenerHora()const {
	return horaUso;
}
void Computadoras::calcularTotalPagar() const {
	cout << "Total :" << (obtenerCostoHora() * obtenerHora()) <<" Lps." << endl;
}
void Computadoras::crearFactura()const {
	Computadoras computadora;
	int horas;
	double costo;
	cout << "Alquiler de computadoras" << endl;
	cout << "Ingrese las horas de uso: " << endl;
	cin >> horas;
	computadora.establecerHora(horas);
	cout << "Ingrese el costo por hora: " << endl;
	cin >> costo;
	computadora.establecerCostoHora(costo);
	cout << endl;
	Factura::crearFactura();
	cout << "Precio por hora: " << computadora.obtenerCostoHora() << endl;
	cout << "Horas de uso: " << computadora.obtenerHora() << endl;
	computadora.calcularTotalPagar();
	cout << "_____________________________________________________________________" << endl;
}