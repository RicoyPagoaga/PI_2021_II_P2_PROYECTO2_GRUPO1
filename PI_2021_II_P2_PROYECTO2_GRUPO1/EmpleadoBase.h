#ifndef EMPLEADOBASE_H
#define EMPLEADOBASE_H

#include "EmpleadoTemporal.h"

class EmpleadoBase : public EmpleadoTemporal
{
public:
	EmpleadoBase();
	virtual ~EmpleadoBase() {};
	EmpleadoBase(std::string, std::string, std::string, std::string, int, std::string = "", int = 0, double = 0.0, double = 0.0);
	void establecerSalarioBase(double);
	double obtenerSalarioBase() const;
	virtual double calcularIngresos() const override;
	virtual void imprimirInformacion() const override;

private:
	double salarioBase;
};


#endif // !EMPLEADOBASE_H
