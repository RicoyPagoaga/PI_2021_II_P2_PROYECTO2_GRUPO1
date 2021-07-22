#include <iostream>
#include <string>
#include "AlquilerLibro.h"
#include "Factura.h"

using namespace std;

AlquilerLibro::AlquilerLibro() {
	establecerAño(0);
	establecerDia(0);
	establecerMes(0);
	establecerNumeroFactura(0);
	establecerCostoAlquiler(0.0);
	establecerDiasAlquiler(0);
}
AlquilerLibro::AlquilerLibro(int dia, int mes, int año, int num, int tiempo, double costo) 
	: Factura(dia, mes, año, num) {
	establecerCostoAlquiler(costo);
	establecerDiasAlquiler(tiempo);
}
void AlquilerLibro::establecerCostoAlquiler(double costo) {
	costoAlquiler = costo;
}
double AlquilerLibro::obtenerCostoAlquiler() const {
	return costoAlquiler;
}
void AlquilerLibro::establecerDiasAlquiler(int tiempo) {
	diasAlquiler = tiempo;
}
int AlquilerLibro::obtenerDiasAlquiler()const {
	return  diasAlquiler;
}
void AlquilerLibro::calcularTotalPagar() const {
	cout << "Total: " << (obtenerCostoAlquiler() * obtenerDiasAlquiler()) << "Lps" << endl;
}
void AlquilerLibro::crearFactura()const {
	 AlquilerLibro libro;
	int dias;
	double costo;
	cout << "Alquiler de libros" << endl;
	cout << "Ingrese los dias de alquiler: " << endl;
	cin >> dias;
	libro.establecerDiasAlquiler(dias);
	cout << "Ingrese el costo por dia: " << endl;
	cin >> costo;
	libro.establecerCostoAlquiler(costo);

	cout << endl;
	Factura::crearFactura();
	cout << "Precio por hora: " << libro.obtenerCostoAlquiler() << endl;
	cout << "Dias de alquiler: " << libro.obtenerDiasAlquiler() << endl;
	libro.calcularTotalPagar();
	cout << "_____________________________________________________________________" << endl;
}