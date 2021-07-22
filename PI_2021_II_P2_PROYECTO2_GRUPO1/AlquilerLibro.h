#ifndef ALQUILER_LIBRO_H
#define ALQUILER_LIBRO_H
#include "Libro.h"
#include "Factura.h"
#include <string>
class AlquilerLibro : public Factura
{
public:
	AlquilerLibro();
	AlquilerLibro(int, int,int,int,int, double);
	void establecerDiasAlquiler(int);
	int obtenerDiasAlquiler() const;
	void establecerCostoAlquiler(double);
	double obtenerCostoAlquiler() const;

	void calcularTotalPagar() const;
	virtual void crearFactura() const override;

private:
	int diasAlquiler;
	double costoAlquiler;
};


#endif // !ALQUILER_LIBRO_H

