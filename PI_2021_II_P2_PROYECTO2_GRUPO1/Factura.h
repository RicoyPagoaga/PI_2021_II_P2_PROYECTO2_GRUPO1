#ifndef FACTURA_H
#define FACTURA_H

#include <string>
#include "Cliente.h"

class Factura
{
public:
	Factura();
	Factura(int, int, int, int);
	void establecerNumeroFactura(int);
	int obtenerNumeroFactura() const;
	void establecerAño(int);
	int obtenerAño()const;
	void establecerMes(int);
	int obtenerMes()const;
	void establecerDia(int);
	int obtenerDia()const;

	void imprimirClienteInfo(Cliente) const;
	virtual void crearFactura() const;



private:
	int numeroFactura;
	int año;
	int mes;
	int dia;
	Cliente cliente;
};





#endif // !FACTURA_H
