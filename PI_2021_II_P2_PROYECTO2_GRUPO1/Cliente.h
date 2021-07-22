#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Persona.h"

class Cliente : public Persona
{
public:
	Cliente(std::string = "", std::string = "", std::string = "", std::string = "", int = 0, int = 0, double = 0.0);
	void establecerSaldo(double);
	double obtenerSaldo()const;
	void establecerNumeroCuenta(int);
	int obtenerNumeroCuenta()const;
	void agregarCliente();
	virtual void imprimirInformacion() const override;


private:
	int numeroCuenta;
	double Saldo;
};

#endif // !CLIENTE_H

