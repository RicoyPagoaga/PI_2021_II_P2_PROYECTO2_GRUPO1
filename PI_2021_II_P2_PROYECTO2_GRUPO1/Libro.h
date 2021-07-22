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
	void establecerA�o(int);
	int obtenerA�o()const;

	void mostrarLibro();
private:
	std::string nombreLibro;
	std::string autor;
	std::string tipoDeLibro;
	int a�o;

};


#endif // !LIBRO_H
