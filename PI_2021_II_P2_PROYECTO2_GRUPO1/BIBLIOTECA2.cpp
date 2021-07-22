#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Cliente.h"
#include "Libro.h"
#include "EmpleadoBase.h"
#include "EmpleadoTemporal.h"
#include "Computadoras.h"
#include "AlquilerLibro.h"

using namespace std;
int escribirOpcionCliente() {
	cout << "\nMenu Clientes\n";
	cout << "(1) Nuevo registro de cliente (necesita numero de cuenta).\n"
		<< "(2) Actualizar un archivo excistente.\n"
		<< "(3) Administración Empleados.\n"
		<< "(4) Eliminar cliente (necesita numero de cuenta).\n"
		<< "(5) Guardar\n"
		<< "(6) Leer archivo .txt\n"
		<< "(7) Salir.\n";
	int opcionCliente;
	cin >> opcionCliente;
	return opcionCliente;
}
int obtenerCuenta(const char* const indicador);
void crearClienteNuevo();
void actualizarArchivoClientes(fstream& actualizarArchivo);
void creartxt (fstream& leerDelArchivo);
void listartxt();
void guardar(fstream& leerDelArchivo);
void imprimirLineaClientes(ostream& salida, const Cliente& clientes);
enum OpcionesCliente { NUEVO_CLIENTE = 1, ACTUALIZAR_CLIENTE, ADMINISTRACION, ELIMINAR_CLIENTE, GUARDAR, 
	LISTAR, TERMINAR };
enum OpcionEmpleadoTemporal {
	CREAR_EMPLEADO = 8, ACTUALIZAR_EMPLEADO, ELIMINAR_EMPLEADO, GUARDAR_EMPLEADO, LEER_EMPLEADO, TERMINA
};
enum OpcionEmpleadoBase {
	CREAREB = 14, CREAREMP, ACTUALIZAREMP, NUEVOEMP, ELIMINAREMP, GUARDAREMP, LEEREMP, TER
};
enum OpcionComputadoras {
	CREARC = 22, CREAR_C, ACTUALIZAR_C, NUEVO_C, ELIMINAR_C, GUARDAR_C, LEER_C, FINALIZAR
};
enum OpcionLibro {
	CREARL = 30, CREAR_L, ACTUALIZAR_L, NUEVO_L, ELIMINAR_L, GUARDAR_L, LEER_L, FINAL
};
enum OpcionFactura {
	CREARF = 38, CREAR_F, ACTUALIZAR_F, NUEVA_F, ELIMINAR_F, GUARDAR_F, LEER_F, F
};
enum OpcionAlquilerLibro {
	CREARAL = 46, CREAR_AL, ACTUALIZAR_AL, NUEVO_AL, ELIMINAR_AL, GUARDAR_AL, LEER_AL, FIN
};
enum OpcionAlquilerComputadora {
	CREARAC = 54, CREAR_AC, ACTUALIZAR_AC, NUEVO_AC, ELIMINAR_AC, GUARDAR_AC, LEER_AC, T
};

ofstream clientedat();
ofstream empleadobasedat();
void creartxtEmpleadobase(fstream& leerDelArchivo);
ofstream empleadoTemporaldat();
void creartxtEmpleadoTemporal(fstream& leerDelArchivo);
ofstream computadorasdat();
void creartxtcomputadorasdat(fstream& leerDelArchivo);
ofstream librodat();
void creartxtlibro(fstream& leerDelArchivo);
ofstream facturadat();
void creartxtfactura(fstream& leerDelArchivo);
ofstream alquilerlibrodat();
void creartxtalquilerlibro(fstream& leerDelArchivo);
ofstream alquilerComputdoradat();
void creartxtalquilerComputadora(fstream& leerDelArchivo);

int main() {
	ofstream Clientedat,dat,empleadoTdat,Computadorasdat,Librodat,Facturadat,alquilerLdat,alquilerCdat;
	//Clientedat = clientedat();
	dat = empleadobasedat();
	empleadoTdat = empleadoTemporaldat();
	Computadorasdat = computadorasdat();
	Librodat = librodat();
	Facturadat = facturadat();
	alquilerLdat = alquilerlibrodat();
	alquilerCdat = alquilerComputdoradat();
	
	fstream ListaClientesEntrada("Lista de Clientes.dat", ios::in | ios::out | ios::binary);
	if (!ListaClientesEntrada) {
		cerr << "No se pudo crear el archivo.";
		system("pause");
		exit(EXIT_FAILURE); 
	}
	int opcionCliente;
	while ((opcionCliente = escribirOpcionCliente()) != TERMINAR)
	{
		switch (opcionCliente)
		{
		case NUEVO_CLIENTE:
			crearClienteNuevo();
			break;

		case ACTUALIZAR_CLIENTE:
			actualizarArchivoClientes(ListaClientesEntrada);
			break;

		case ADMINISTRACION:
			//administracion(ListaClientes);
			break;

		case ELIMINAR_CLIENTE:
			//eliminarRegistroClientes(ListaClientes);
			break;

		case GUARDAR:
			guardar(ListaClientesEntrada);
			break;
		case LISTAR:
			creartxt(ListaClientesEntrada);
			listartxt();
			creartxtEmpleadobase(ListaClientesEntrada);
			creartxtEmpleadoTemporal(ListaClientesEntrada);
			creartxtcomputadorasdat(ListaClientesEntrada);
			creartxtlibro(ListaClientesEntrada);
			creartxtfactura(ListaClientesEntrada);
			creartxtalquilerlibro(ListaClientesEntrada);
			creartxtalquilerComputadora(ListaClientesEntrada);
			break;
		default:
			cerr << "Opcion Invalida";
			break;
		}
	}
	system("pause");
	return 0;
}
int obtenerCuenta(const char* const indicador) {
		int numeroCuenta;
		do
		{
			cout << indicador << "Ingrese el numero de cuenta (1-100)" << endl;
			cin >> numeroCuenta;
		} while (numeroCuenta < 1 || numeroCuenta > 100);
		return numeroCuenta;
	}
void crearClienteNuevo() {
	Cliente clienteNuevo;
	fstream ListaClientesSalida("Lista de Clientes.dat", ios::in | ios::out | ios::binary);
	if (!ListaClientesSalida)
	{
		cerr << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}
	Cliente cliente;
	int numeroCuenta;
	string apellidoPaterno;
	string primerNombre;
	string DNI;
	double saldo;
	cout << "Escriba el numero de cuenta de 1 a 100, 0 para terminar\n";
	cin >> numeroCuenta;
	while (numeroCuenta > 0 && numeroCuenta <= 100)
	{
		cout << "Escriba apellido paterno, primer nombre, Identificacion y saldo\n";
				cin >> apellidoPaterno;
				cin >> primerNombre;
				cin >> DNI;
				cin >> saldo;
				cliente.establecerNumeroCuenta(numeroCuenta);
				cliente.establecerApellido(apellidoPaterno);
				cliente.establecerNombre(primerNombre);
				cliente.establecerIdentificacion(DNI);
				cliente.establecerSaldo(saldo);
				ListaClientesSalida.seekp((cliente.obtenerNumeroCuenta() - 1) *
					sizeof(Cliente));
				ListaClientesSalida.write(reinterpret_cast<const char*>(&cliente),
					sizeof(Cliente));
				cout << "Escriba el numero de cuenta\n";
				cin >> numeroCuenta;
	}
	
}
void guardar(fstream& leerDelArchivo) {
		ofstream ListaDeClientes("Lista De clientes.txt", ios::out);
		if (!ListaDeClientes)
		{
			cerr << "No se pudo crear el archivo." << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
		ListaDeClientes << left << setw(10) << "Cuenta" << setw(16)
			<< "Nombre: " << setw(16) << "Apellido: " << left << setw(10)
			<< right << "Identificacion: " << setw(14) << "Saldo:" << endl;
		Cliente cliente;
		leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
			sizeof(Cliente));
		while (!leerDelArchivo.eof())
		{
			if (cliente.obtenerNumeroCuenta() != 0)
				imprimirLineaClientes(ListaDeClientes, cliente);
			leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
				sizeof(Cliente));
		}
		
	}
void actualizarArchivoClientes(fstream& actualizarArchivo) {
	int numeroCuenta = obtenerCuenta("Escriba la cuenta a actualizar");
		actualizarArchivo.seekg((numeroCuenta - 1) * sizeof(Cliente));
		Cliente cliente;
		actualizarArchivo.read(reinterpret_cast<char*>(&cliente), sizeof(Cliente));
		if (cliente.obtenerNumeroCuenta() != 0)
		{
			imprimirLineaClientes(cout, cliente);
			cout << "\nEscriba el cargo(+) o pago (-)>";
			double transaccion;
			cin >> transaccion;
			double saldoAnterior = cliente.obtenerSaldo();
			cliente.establecerSaldo(saldoAnterior + transaccion);
			imprimirLineaClientes(cout, cliente);
			actualizarArchivo.seekg((numeroCuenta - 1) * sizeof(Cliente));
			actualizarArchivo.write(reinterpret_cast<const char*>(&cliente),
				sizeof(Cliente));
		}
		else
		{
			cerr << "La cuenta"<<numeroCuenta<<" no tiene informacion"<<endl;
		}
	}
void creartxt(fstream& leerDelArchivo) {
	ofstream clientesSalida("imprimirclientes.txt", ios::out);
	if (!clientesSalida)
	{
		cerr << "No se pudo abrir el archivo." << endl;
		exit(EXIT_FAILURE);
	}
	clientesSalida << left << setw(10) << "Cuenta" << setw(16)
		<< "Apellido" << setw(11) << "Nombre" << left<<setw(15)<<"Identificacion"
		<< setw(10) << right << "Saldo" << endl;
	Cliente cliente;
	leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
		sizeof(Cliente));
	while (!leerDelArchivo.eof())
	{
		if (cliente.obtenerNumeroCuenta() != 0)
			imprimirLineaClientes(clientesSalida, cliente);
		leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
			sizeof(Cliente));
	}
}

void listartxt() {
	ifstream ListaEntrada("Lista de Clientes.dat", ios::in | ios::binary);
	if (!ListaEntrada)
	{
		cerr << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	cout << left << setw(10) << "cuenta" << setw(16) << "apellido"
		<< setw(11) << "nombre" << setw(10) << setprecision(2) << "identificacion"
		<< setw(16) << right << "saldo" << endl;
	Cliente cliente;
	ListaEntrada.read(reinterpret_cast<char*>(&cliente), sizeof(Cliente));

	while (!ListaEntrada.eof())
	{
		if (cliente.obtenerNumeroCuenta() != 0)
			imprimirLineaClientes(cout, cliente);
		ListaEntrada.read(reinterpret_cast<char*>(&cliente), sizeof(Cliente));
	}
}

void imprimirLineaClientes(ostream& salida, const Cliente& clientes) {
	salida << left << setw(10) << clientes.obtenerNumeroCuenta()
		<< setw(16) << clientes.obtenerApellido()
		<< setw(11) << clientes.obtenerNombre()
		<< setw(10) << setprecision(2)
		<< clientes.obtenerIdentificacion() << setw(16) << right << fixed
		<< showpoint << clientes.obtenerSaldo() << endl;
}
//void imprimirConsola(int cuenta, string apellido, string nombre, string identificacion, double saldo) {
//	cout << left << setw(10) << cuenta << setw(16) << apellido
//		<< setw(11) << nombre << setw(10) << setprecision(2) << identificacion
//		<< setw(16) << right << saldo << endl;
//}
ofstream creardat() {
	ofstream ListaClientesSalida("Lista de Clientes.dat", ios::out | ios::binary);
	if (!ListaClientesSalida) {
		cerr << "No se pudo crear el archivo.";
		exit(EXIT_FAILURE);
	}
	Cliente usuarioBlanco;
	for (int i = 0; i < 100; i++)
		ListaClientesSalida.write(reinterpret_cast<const char*>(&usuarioBlanco),
			sizeof(Cliente));
	return ListaClientesSalida;
}
ofstream empleadobasedat() {
	ofstream ListaempleadosSalida("Lista de empleado Base.dat", ios::out | ios::binary);
	if (!ListaempleadosSalida) {
		cerr << "No se pudo crear el archivo.";
		exit(EXIT_FAILURE);
	}
	Cliente usuarioBlanco;
	for (int i = 0; i < 100; i++)
		ListaempleadosSalida.write(reinterpret_cast<const char*>(&usuarioBlanco),
			sizeof(Cliente));
	return ListaempleadosSalida;
}
void creartxtEmpleadobase(fstream& leerDelArchivo) {
	ofstream clientesSalida("imprimirEmpleadoBase.txt", ios::out);
	if (!clientesSalida)
	{
		cerr << "No se pudo abrir el archivo." << endl;
		exit(EXIT_FAILURE);
	}
	clientesSalida << left << setw(10) << "Cuenta" << setw(16)
		<< "Apellido" << setw(11) << "Nombre" << left
		<< setw(10) << right << "Salario Base" << endl;
	Cliente cliente;
	leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
		sizeof(Cliente));
	while (!leerDelArchivo.eof())
	{
		if (cliente.obtenerNumeroCuenta() != 0)
			imprimirLineaClientes(clientesSalida, cliente);
		leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
			sizeof(Cliente));
	}
}
ofstream empleadoTemporaldat() {
	ofstream ListaempleadosSalida("Lista de empleado Temporal.dat", ios::out | ios::binary);
	if (!ListaempleadosSalida) {
		cerr << "No se pudo crear el archivo.";
		exit(EXIT_FAILURE);
	}
	Cliente usuarioBlanco;
	for (int i = 0; i < 100; i++)
		ListaempleadosSalida.write(reinterpret_cast<const char*>(&usuarioBlanco),
			sizeof(Cliente));
	return ListaempleadosSalida;
}
void creartxtEmpleadoTemporal(fstream& leerDelArchivo) {
	ofstream clientesSalida("imprimirEmpleadoTemporal.txt", ios::out);
	if (!clientesSalida)
	{
		cerr << "No se pudo abrir el archivo." << endl;
		exit(EXIT_FAILURE);
	}
	clientesSalida << left << setw(10) << "Cuenta" << setw(16)
		<< "Apellido" << setw(11) << "Nombre" << setw(11)<<"Ventas"<<left
		<< setw(10) << right << "salario" << endl;
	Cliente cliente;
	leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
		sizeof(Cliente));
	while (!leerDelArchivo.eof())
	{
		if (cliente.obtenerNumeroCuenta() != 0)
			imprimirLineaClientes(clientesSalida, cliente);
		leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
			sizeof(Cliente));
	}
}
ofstream computadorasdat() {
	ofstream ListaempleadosSalida("Lista de computadoras.dat", ios::out | ios::binary);
	if (!ListaempleadosSalida) {
		cerr << "No se pudo crear el archivo.";
		exit(EXIT_FAILURE);
	}
	Cliente usuarioBlanco;
	for (int i = 0; i < 100; i++)
		ListaempleadosSalida.write(reinterpret_cast<const char*>(&usuarioBlanco),
			sizeof(Cliente));
	return ListaempleadosSalida;
}
void creartxtcomputadorasdat(fstream& leerDelArchivo) {
	ofstream clientesSalida("imprimircomputadoras.txt", ios::out);
	if (!clientesSalida)
	{
		cerr << "No se pudo abrir el archivo." << endl;
		exit(EXIT_FAILURE);
	}
	clientesSalida << left << setw(10) << "Modelo" << setw(16)
		<< "Numero de Maquina" << setw(11) << "Numero de registro" << left
		<< setw(10) << right << "Costo" << endl;
	Cliente cliente;
	leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
		sizeof(Cliente));
	while (!leerDelArchivo.eof())
	{
		if (cliente.obtenerNumeroCuenta() != 0)
			imprimirLineaClientes(clientesSalida, cliente);
		leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
			sizeof(Cliente));
	}
}
ofstream librodat() {
	ofstream ListaempleadosSalida("Lista de libros.dat", ios::out | ios::binary);
	if (!ListaempleadosSalida) {
		cerr << "No se pudo crear el archivo.";
		exit(EXIT_FAILURE);
	}
	Cliente usuarioBlanco;
	for (int i = 0; i < 100; i++)
		ListaempleadosSalida.write(reinterpret_cast<const char*>(&usuarioBlanco),
			sizeof(Cliente));
	return ListaempleadosSalida;
}
void creartxtlibro(fstream& leerDelArchivo) {
	ofstream clientesSalida("imprimirLibros.txt", ios::out);
	if (!clientesSalida)
	{
		cerr << "No se pudo abrir el archivo." << endl;
		exit(EXIT_FAILURE);
	}
	clientesSalida << left << setw(10) << "Nombre" << setw(16)
		<< "Autor" << setw(11) << "Publicacion" << left
		<< setw(10) << right << "Cantidad de existencia" << endl;
	Cliente cliente;
	leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
		sizeof(Cliente));
	while (!leerDelArchivo.eof())
	{
		if (cliente.obtenerNumeroCuenta() != 0)
			imprimirLineaClientes(clientesSalida, cliente);
		leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
			sizeof(Cliente));
	}
}
ofstream facturadat() {
	ofstream ListaempleadosSalida("Lista de facturas.dat", ios::out | ios::binary);
	if (!ListaempleadosSalida) {
		cerr << "No se pudo crear el archivo.";
		exit(EXIT_FAILURE);
	}
	Cliente usuarioBlanco;
	for (int i = 0; i < 100; i++)
		ListaempleadosSalida.write(reinterpret_cast<const char*>(&usuarioBlanco),
			sizeof(Cliente));
	return ListaempleadosSalida;
}
void creartxtfactura(fstream& leerDelArchivo) {
	ofstream clientesSalida("imprimirfacturas.txt", ios::out);
	if (!clientesSalida)
	{
		cerr << "No se pudo abrir el archivo." << endl;
		exit(EXIT_FAILURE);
	}
	clientesSalida << left << setw(10) << "usuario" << setw(16)
		<< "Tipo de Servicio" << setw(11) << "Fecha" << left
		<< setw(10) << right << "Saldo" << endl;
	Cliente cliente;
	leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
		sizeof(Cliente));
	while (!leerDelArchivo.eof())
	{
		if (cliente.obtenerNumeroCuenta() != 0)
			imprimirLineaClientes(clientesSalida, cliente);
		leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
			sizeof(Cliente));
	}
}
ofstream alquilerlibrodat() {
	ofstream ListaempleadosSalida("Lista de alquilerLibros.dat", ios::out | ios::binary);
	if (!ListaempleadosSalida) {
		cerr << "No se pudo crear el archivo.";
		exit(EXIT_FAILURE);
	}
	Cliente usuarioBlanco;
	for (int i = 0; i < 100; i++)
		ListaempleadosSalida.write(reinterpret_cast<const char*>(&usuarioBlanco),
			sizeof(Cliente));
	return ListaempleadosSalida;
}
void creartxtalquilerlibro(fstream& leerDelArchivo) {
	ofstream clientesSalida("imprimirAlquilerLibros.txt", ios::out);
	if (!clientesSalida)
	{
		cerr << "No se pudo abrir el archivo." << endl;
		exit(EXIT_FAILURE);
	}
	clientesSalida << left << setw(10) << "Nombre del Libro" << setw(16)
		<< "Apellido" << setw(11) << "Nombre" << left
		<< setw(10) << right << "Costo Alquiler" << endl;
	Cliente cliente;
	leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
		sizeof(Cliente));
	while (!leerDelArchivo.eof())
	{
		if (cliente.obtenerNumeroCuenta() != 0)
			imprimirLineaClientes(clientesSalida, cliente);
		leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
			sizeof(Cliente));
	}
}
ofstream alquilerComputdoradat() {
	ofstream ListaempleadosSalida("Lista de alquilerComputadoras.dat", ios::out | ios::binary);
	if (!ListaempleadosSalida) {
		cerr << "No se pudo crear el archivo.";
		exit(EXIT_FAILURE);
	}
	Cliente usuarioBlanco;
	for (int i = 0; i < 100; i++)
		ListaempleadosSalida.write(reinterpret_cast<const char*>(&usuarioBlanco),
			sizeof(Cliente));
	return ListaempleadosSalida;
}
void creartxtalquilerComputadora(fstream& leerDelArchivo) {
	ofstream clientesSalida("imprimirAlquilerComputadoras.txt", ios::out);
	if (!clientesSalida)
	{
		cerr << "No se pudo abrir el archivo." << endl;
		exit(EXIT_FAILURE);
	}
	clientesSalida << left << setw(10) << "usuario" << setw(16)
		<< "Numero de Maquina" << setw(15) << "Tiempo de uso" << left
		<< setw(10) << right << "Costo" << endl;
	Cliente cliente;
	leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
		sizeof(Cliente));
	while (!leerDelArchivo.eof())
	{
		if (cliente.obtenerNumeroCuenta() != 0)
			imprimirLineaClientes(clientesSalida, cliente);
		leerDelArchivo.read(reinterpret_cast<char*>(&cliente),
			sizeof(Cliente));
	}
}
ofstream clientedat()
{
	ofstream ListaClientesSalida("Lista de Clientes.dat", ios::out | ios::binary);
	if (!ListaClientesSalida) {
		cerr << "No se pudo crear el archivo.";
		exit(EXIT_FAILURE);
	}
	Cliente usuarioBlanco;
	for (int i = 0; i < 100; i++)
		ListaClientesSalida.write(reinterpret_cast<const char*>(&usuarioBlanco),
			sizeof(Cliente));
	return ListaClientesSalida;
}