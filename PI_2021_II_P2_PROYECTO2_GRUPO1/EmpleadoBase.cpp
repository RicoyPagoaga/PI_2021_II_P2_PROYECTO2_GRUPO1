#include <stdexcept>
#include <iostream> 
#include "EmpleadoBase.h"
using namespace std;

EmpleadoBase::EmpleadoBase() {
}
EmpleadoBase::EmpleadoBase(string nombre, string apellido,
	string _direccion, string _identificacion,
	int _edad, string seguro, int numero, double ventas, double salariobase) {
	establecerSalarioBase(salariobase);
}
void EmpleadoBase::establecerSalarioBase(double salariobase) {
	if (salariobase >= 0.0)
		salarioBase = salariobase;
	else
		throw invalid_argument("El salario debe ser >= 0.0");
}
double EmpleadoBase::obtenerSalarioBase() const {
	return salarioBase;
}
double EmpleadoBase::calcularIngresos() const {
	return obtenerSalarioBase() + EmpleadoTemporal::calcularIngresos();
}
void EmpleadoBase::imprimirInformacion() const {
	cout << "Empleado con salario base" << endl;
	Persona::imprimirInformacion();
	cout << endl << "Con salario base: " << obtenerSalarioBase()
		<< endl << "y salario final: " << calcularIngresos();
}