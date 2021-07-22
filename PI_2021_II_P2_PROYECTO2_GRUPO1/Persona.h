#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona
{
public:
	Persona();
	Persona(std::string, std::string, std::string, std::string, int);
	void establecerNombre(std::string);
	std::string obtenerNombre()const;
	void establecerApellido(std::string);
	std::string obtenerApellido()const;
	void establecerIdentificacion(std::string);
	std::string obtenerIdentificacion()const;
	void establecerDireccion(std::string);
	std::string obtenerDireccion()const;
	void establecerEdad(int);
	int obtenerEdad()const;
	virtual void imprimirInformacion()const;
	//void agregarPersona();
private:
	char primerNombre[10];
	char apellidoPaterno[15];
	char identificacion[15];
	char direccion[15];
	int edad;
};


#endif // !PERSONA_H

