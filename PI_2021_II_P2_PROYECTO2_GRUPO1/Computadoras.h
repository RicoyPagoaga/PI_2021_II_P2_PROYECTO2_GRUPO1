#ifndef COMPUTADORAS_H
#define COMPUTADORAS_H
#include "Persona.h"
#include "Factura.h"
#include <string>

class Computadoras : public Factura
{
public:
	Computadoras();
	Computadoras(int, int, int, int, int, double);
	void establecerHora(int);
	int obtenerHora()const;
	void establecerCostoHora(double);
	double obtenerCostoHora()const;

	void calcularTotalPagar() const;
	virtual void crearFactura() const override;



private:
	int horaUso;
	double costoHora;

};

#endif // !COMPUTADORAS_H

