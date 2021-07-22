#ifndef EMPLEADOTEMPORAL_H
#define EMPLEADOTEMPORAL_H
#include "Persona.h"

class EmpleadoTemporal : public Persona
{
public:
	EmpleadoTemporal();
	EmpleadoTemporal(std::string, std::string, std::string, std::string, int, std::string = "", int = 0, double = 0.0);
	void establecerNumeroSeguroSocial(std::string);
	std::string obtenerNumeroSeguroSocial() const;
	void establecerNumeroCuenta(int);
	void establecerVentas(double);
	double obtenerVentas() const;
	int obtenerNumeroCuenta() const;
	virtual double calcularIngresos() const;
	virtual void imprimirInformacion() const override;
private:
	int numeroCuenta;
	char numeroSeguroSocial[15];
	double Ventas;
};


#endif // !EMPLEADOTEMPORAL_H
