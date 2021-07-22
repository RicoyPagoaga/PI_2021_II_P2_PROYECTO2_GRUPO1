#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include "Cliente.h"
//#include "Persona.h"

class Libro : public Cliente
{
public:
	Libro(std::string, std::string, std::string, int);
	void establecerNombreLibro(std::string);
	std::string obtenerNombreLibro() const;
	void establecerAutor(std::string);
	std::string obtenerAutor() const;
	void establecerTipoLibro(std::string);
	std::string obtenerTipoLibro() const;
	void establecerAño(int);
	int obtenerAño()const;

	void mostrarLibro();
private:
	std::string nombreLibro;
	std::string autor;
	std::string tipoDeLibro;
	int año;

};


#endif // !LIBRO_H
