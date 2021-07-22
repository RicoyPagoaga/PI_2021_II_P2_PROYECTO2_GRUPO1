//#include <iostream>
//#include <string>
//#include <stdexcept>
//#include <cstdlib>
//#include <fstream>
//#include <iomanip>
//#include "Cliente.h"
//#include "Libro.h"
//#include "EmpleadoBase.h"
//#include "EmpleadoTemporal.h"
//
//using namespace std;
//const int TAM = 3;
//int escribirOpcionCliente() {
//	cout << "\nMenu Clientes\n";
//	cout << "(1) Nuevo registro de cliente (necesita numero de cuenta).\n"
//		<< "(2) Actualizar un archivo excistente.\n"
//		<< "(3) Administración Empleados.\n"
//		<< "(4) Eliminar cliente (necesita numero de cuenta).\n"
//		<< "(5) Imprimir lista clientes\n"
//		<< "(6) Salir.\n";
//	int opcionCliente;
//	cin >> opcionCliente;
//	return opcionCliente;
//}
//void crearArchivoClientes(ofstream&);
//void actualizarArchivoClientes(fstream&);
//void nuevoRegistroClientes(fstream&);
//void eliminarRegistroClientes(fstream&);
//int obtenerNumeroDeCuenta(const char* const);
//void imprimirLineaClientes(ostream&, const Cliente&);
//void leerDat();
//int escribirOpcionEmpleado();
//void crearArchivoEmpleado(fstream&);
//void actualizarEmpleado(fstream&);
//void nuevoEmpleado(fstream&);
//void eliminarEmpleado(fstream&);
//void imprimirEmpleado(ostream&, const EmpleadoTemporal&);
//void escribirListado(fstream&);
//int obtenerCuenta(const char* const);
//void administracion(fstream&);
//enum OpcionEmpleado {
//	CREAR_LISTADO = 1, LEER_LISTADO, CREAR_EMPLEADO,
//	ACTUALIZAR_EMPLEADO, NUEVO_EMPLEADO, ELIMINAR_EMPLEADO
//};
//void creacionDatEB();
//void escribirListadoEB(fstream&);
//void crearArchivoEB(fstream&);
//void actualizarEB(fstream&);
//void nuevoEB(fstream&);
//void eliminarEB(fstream&);
//enum OpcionEmpleadoBase { CREARLISTADO = 7, CREAREMP, ACTUALIZAREMP, NUEVOEMP, ELIMINAREMP, FINALIZAR };
//enum OpcionesCliente { NUEVO_CLIENTE = 1, ACTUALIZAR_CLIENTE, ADMINISTRACION, ELIMINAR_CLIENTE, IMPRIMIR, TERMINAR };
//
//
//int main() {
//	ofstream ListaClientesEntrada("Lista de Clientes.dat", ios::out | ios::binary);
//	if (!ListaClientesEntrada) {
//		cerr << "No se pudo crear el archivo.";
//		exit(EXIT_FAILURE); //El archivo no se crea y te saca de consola.
//	}
//	Cliente usuarioBlanco;
//	for (int i = 0; i < 100; i++)
//		ListaClientesEntrada.write(reinterpret_cast<const char*>(&usuarioBlanco),
//			sizeof(Cliente));
//
//	int opcionCliente;
//	while (opcionCliente = escribirOpcionCliente() != TERMINAR)
//	{
//		switch (opcionCliente)
//		{
//		case NUEVO_CLIENTE:
//			crearArchivoClientes(ListaClientesEntrada);
//			break;
//
//		case ACTUALIZAR_CLIENTE:
//			actualizarArchivoClientes(ListaClientes);
//			break;
//
//		case ADMINISTRACION:
//            administracion(ListaClientes);
//			break;
//
//		case ELIMINAR_CLIENTE:
//			eliminarRegistroClientes(ListaClientes);
//			break;
//
//		case IMPRIMIR: 			
//			//imprimirLineaClientes(cout, );
//			break;
//
//		default:
//			cerr << "Opcion Invalida";
//			break;
//		}
//	}
//	
//	system("pause");
//	return 0;
//}
//void crearArchivoClientes(ofstream& leerDelArchivo) {
//	int numeroCuenta;
//	fstream ClienteSalida("Lista de Clientes.dat", ios::out | ios::binary);
//		if (!ClienteSalida)
//		{
//			cerr << "No se pudo crear el archivo" << endl;
//			exit(EXIT_FAILURE);
//		}
//		Cliente nuevoCliente;
//		cout << "Escriba el numero de cuenta de 1 a 100, 0 para terminar\n";
//			cin >> numeroCuenta;
//			while (numeroCuenta > 0 && numeroCuenta <= 100)
//			{
//				nuevoCliente.agregarCliente();
//				ClienteSalida.seekp((nuevoCliente.obtenerNumeroCuenta() -1 ) *
//					sizeof(Cliente));
//				ClienteSalida.write(reinterpret_cast<const char*>(&nuevoCliente),
//					sizeof(Cliente));
//				cout << "Escriba el numero de cuenta\n";
//				cin >> numeroCuenta;
//	}
//}
//void actualizarArchivoClientes(fstream& actualizarArchivo) {
//	int numeroCuenta = obtenerNumeroDeCuenta("Escriba la cuenta a actualizar");
//	actualizarArchivo.seekg((numeroCuenta - 1) * sizeof(Cliente));
//	Cliente cliente;
//	actualizarArchivo.read(reinterpret_cast<char*>(&cliente), sizeof(Cliente));
//	if (cliente.obtenerNumeroCuenta() != 0)
//	{
//		imprimirLineaClientes(cout, cliente);
//		string nombre, apellido, identificacion;
//		cout << "Escriba la nueva informacion ( nombre,apellido e identificacion)" << endl;
//		cin >> nombre, apellido, identificacion;
//		cliente.establecerNombre(nombre);
//		cliente.establecerApellido(apellido);
//		cliente.establecerIdentificacion(identificacion);
//	}
//	else
//	{
//		cerr << "La cuenta no tiene informacion";
//	}
//}
//void nuevoRegistroClientes(fstream& insertarArchivo) {
//	int numeroCuenta = obtenerNumeroDeCuenta("Escriba el numero de cuenta");
//	insertarArchivo.seekg((numeroCuenta - 1) * sizeof(Cliente));
//	Cliente cliente;
//	insertarArchivo.read(reinterpret_cast<char*>(&cliente), sizeof(Cliente));
//	if (cliente.obtenerNumeroCuenta() == 0)
//	{
//		string nombre, apellido, identificacion;
//		cout << "Escriba la informacion ( nombre,apellido e identificacion)" << endl;
//		cin >> nombre, apellido, identificacion;
//		cliente.establecerNombre(nombre);
//		cliente.establecerApellido(apellido);
//		cliente.establecerIdentificacion(identificacion);
//		insertarArchivo.seekp((numeroCuenta - 1) * sizeof(Cliente));
//		insertarArchivo.write(reinterpret_cast<const char*>(&cliente), sizeof(Cliente));
//	}
//	else
//	{
//		cerr << "La cuenta ya esta en uso.";
//	}
//}
//void eliminarRegistroClientes(fstream& eliminarDelArchivo) {
//	int numeroCuenta = obtenerNumeroDeCuenta("Escriba el numero de cuenta a eliminar");
//	eliminarDelArchivo.seekg((numeroCuenta - 1) * sizeof(Cliente));
//	Cliente cliente;
//	eliminarDelArchivo.read(reinterpret_cast<char*>(&cliente), sizeof(Cliente));
//	if (cliente.obtenerNumeroCuenta() != 0)
//	{
//		Cliente clienteVacio;
//		eliminarDelArchivo.seekg((numeroCuenta - 1) * sizeof(Cliente));
//		eliminarDelArchivo.write(reinterpret_cast<const char*>(&clienteVacio), sizeof(Cliente));
//		cout << "Se elimino correctamente" << endl;
//	}
//	else
//	{
//		cerr << "La cuenta no contiene datos";
//	}
//}
//int obtenerNumeroDeCuenta(const char* const indicador) {
//	int numeroCuenta;
//	do
//	{
//		cout << indicador << "Ingrese el numero de cuenta (1-100)" << endl;
//		cin >> numeroCuenta;
//	} while (numeroCuenta > 1 && numeroCuenta < 100);
//	return numeroCuenta;
//}
//void imprimirLineaClientes(ostream& salida, const Cliente& clientes) {
//	ifstream ListaClientesEntrada("Lista de Clientes.dat", ios::in | ios::binary);
//	if (!ListaClientesEntrada)
//	{
//		cerr << "No se pudo abrir el archivo." << endl;
//		exit(EXIT_FAILURE);
//	}
//	cout << left << setw(10) << "Cuenta" << setw(16)
//		<< "Apellido" << setw(11) << "Nombre" << left
//		<< setw(10) << right << "Saldo" << endl;
//	Cliente cliente;
//	ListaClientesEntrada.read(reinterpret_cast<char*>(&cliente),
//		sizeof(Cliente));
//	while (ListaClientesEntrada && !ListaClientesEntrada.eof())
//	{
//		if (cliente.obtenerNumeroCuenta() != 0)
//			imprimirLineaClientes(cout, cliente);
//		ListaClientesEntrada.read(reinterpret_cast<char*>(&cliente),
//			sizeof(Cliente));
//	}
//	/*salida << left << setw(10) << clientes.obtenerNumeroCuenta()
//		<< setw(16) << clientes.obtenerApellido()
//		<< setw(11) << clientes.obtenerNombre()
//		<< setw(10) << setprecision(2) << right << fixed
//		<< showpoint << clientes.obtenerIdentificacion() << endl;*/
//}
//void leerDat() {
//    ifstream listaEmpleado("Empleados.dat", ios::in | ios::binary);
//    if (!listaEmpleado) {
//        cerr << "No se pudo abrir el archivo" << endl;
//        system("pause");
//        exit(EXIT_FAILURE);
//    }
//    cout << left << setw(10) << "Cuenta"
//        << setw(16) << "Apellido"
//        << setw(11) << "Nombre" << left
//        << setw(10) << "Ventas" << setw(10) << right << "Salario" << endl;
//    EmpleadoTemporal empleado;
//    listaEmpleado.read(reinterpret_cast<char*>(&empleado),
//        sizeof(EmpleadoTemporal));
//    while (listaEmpleado && !listaEmpleado.eof()) //mientras se pueda leer, se estara ejecutando
//    {
//        if (empleado.obtenerNumeroCuenta() != 0)
//            imprimirEmpleado(cout, empleado);
//        listaEmpleado.read(reinterpret_cast<char*>(&empleado),
//            sizeof(EmpleadoTemporal));
//    }
//}
//
//int escribirOpcionEmpleado() {
//    cout << "\n Escriba su opcion" << endl
//        << " -- Para Empleado Temporal -- " << endl
//        << "1 - crear listado en archivo . dat" << endl
//        << "2 - leer archivo .dat" << endl
//        << "3 - crear un archivo de texto con forma de cuentas" << endl
//        << " llamado Empleado.txt " << endl
//        << "4 - actualizar una cuenta" << endl
//        << "5 - agregar una nueva cuenta" << endl
//        << "6 - eliminar una cuenta" << endl
//        << " -- Para Empleado Base --" << endl
//        << "7 - crear listado en archivo . dat" << endl
//        << "8 - crear un archivo de texto con forma de cuentas" << endl
//        << " llamado EmpleadosBase.txt" << endl
//        << "9 - actualizar una cuenta" << endl
//        << "10 - agregar una nueva cuenta" << endl
//        << "11- eliminar una cuenta" << endl
//        << "12 - finalizar" << endl;
//    int opcion;
//    cin >> opcion;
//    return opcion;
//}
//
//void escribirListado(fstream& listaEmpleado) {
//    int numerocuenta;
//    string nombre, apellido;
//    double ventas;
//    EmpleadoTemporal empleado;
//    cout << "Escriba el numero de cuenta de 1 a 100, 0 para terminar" << endl;
//    cin >> numerocuenta;
//    while (numerocuenta > 0 && numerocuenta <= 100) {
//        cout << "Escriba nombre" << endl;
//        cin >> nombre;
//        cout << "Escriba apellido" << endl;
//        cin >> apellido;
//        cout << "Escriba las ventas realizadas" << endl;
//        cin >> ventas;
//        empleado.establecerNumeroCuenta(numerocuenta);
//        empleado.establecerNombre(nombre);
//        empleado.establecerApellido(apellido);
//        empleado.establecerVentas(ventas);
//        listaEmpleado.seekp((empleado.obtenerNumeroCuenta() - 1) *
//            sizeof(EmpleadoTemporal));
//        listaEmpleado.write(reinterpret_cast<const char*> (&empleado),
//            sizeof(EmpleadoTemporal));
//        cout << "Escriba el numero de cuenta de 1 a 100, 0 para terminar" << endl;
//        cin >> numerocuenta;
//    }
//}
//
//void crearArchivoEmpleado(fstream& leerDelArchivo) {
//    ofstream listaEmpleado("Empleado.txt", ios::out);
//    if (!listaEmpleado) {
//        cerr << "No se pudo abrir el archivo" << endl;
//        system("pause");
//        exit(EXIT_FAILURE);
//    }
//    listaEmpleado << left << setw(10) << "Cuenta"
//        << setw(16) << "Apellido"
//        << setw(11) << "Nombre" << left
//        << setw(10) << "Ventas" << setw(10) << right << "Salario" << endl;
//    EmpleadoTemporal empleado;
//    leerDelArchivo.read(reinterpret_cast<char*>(&empleado),
//        sizeof(EmpleadoTemporal));
//    while (!leerDelArchivo.eof())
//    {
//        if (empleado.obtenerNumeroCuenta() != 0)
//            imprimirEmpleado(listaEmpleado, empleado);
//        leerDelArchivo.read(reinterpret_cast<char*>(&empleado),
//            sizeof(EmpleadoTemporal));
//    }
//}
//
//void actualizarEmpleado(fstream& actualizarArchivo) {
//    int numeroCuenta = obtenerCuenta("Escriba la cuenta que se debe actualizar ");
//    actualizarArchivo.seekg((numeroCuenta - 1) * sizeof(EmpleadoTemporal));
//    EmpleadoTemporal empleado;
//    actualizarArchivo.read(reinterpret_cast<char*>(&empleado),
//        sizeof(EmpleadoTemporal));
//    if (empleado.obtenerNumeroCuenta() != 0)
//    {
//        imprimirEmpleado(cout, empleado);
//        cout << "\nEscriba las ventas realizadas";
//        double ventas;
//        cin >> ventas;
//        empleado.establecerVentas(ventas);
//        imprimirEmpleado(cout, empleado);
//        actualizarArchivo.seekg((numeroCuenta - 1) * sizeof(EmpleadoTemporal));
//        actualizarArchivo.write(reinterpret_cast<const char*>(&empleado),
//            sizeof(EmpleadoTemporal));
//    }
//    else
//        cerr << "La cuenta " << numeroCuenta << " no tiene informacion" << endl;
//}
//
//void nuevoEmpleado(fstream& insertarEnArchivo) {
//    int numeroCuenta = obtenerCuenta("Escriba el nuevo numero de cuenta");
//    insertarEnArchivo.seekg((numeroCuenta - 1) * sizeof(EmpleadoTemporal));
//    EmpleadoTemporal empleado;
//    insertarEnArchivo.read(reinterpret_cast<char*>(&empleado),
//        sizeof(EmpleadoTemporal));
//    if (empleado.obtenerNumeroCuenta() == 0)
//    {
//        string apellido;
//        string nombre;
//        double ventas;
//        cout << "Escriba nombre" << endl;
//        cin >> setw(10) >> nombre;
//        cout << "Escriba apellido" << endl;
//        cin >> setw(15) >> apellido;
//        cout << "Escriba las ventas realizadas" << endl;
//        cin >> ventas;
//        empleado.establecerNumeroCuenta(numeroCuenta);
//        empleado.establecerApellido(apellido);
//        empleado.establecerNombre(nombre);
//        empleado.establecerVentas(ventas);
//        insertarEnArchivo.seekp((numeroCuenta - 1) *
//            sizeof(EmpleadoTemporal));
//        insertarEnArchivo.write(reinterpret_cast<const char*>(&empleado),
//            sizeof(EmpleadoTemporal));
//    }
//    else
//        cerr << "La cuenta " << numeroCuenta << " ya tiene informacion" << endl;
//}
//
//void eliminarEmpleado(fstream& eliminarDelArchivo) {
//    int numeroCuenta = obtenerCuenta("Escriba la cuenta a eliminar");
//    eliminarDelArchivo.seekg((numeroCuenta - 1) * sizeof(EmpleadoTemporal));
//    EmpleadoTemporal empleado;
//    eliminarDelArchivo.read(reinterpret_cast<char*>(&empleado),
//        sizeof(EmpleadoTemporal));
//    if (empleado.obtenerNumeroCuenta() != 0)
//    {
//        EmpleadoTemporal empleadoEnBlanco;
//        eliminarDelArchivo.seekp((numeroCuenta - 1) *
//            sizeof(EmpleadoTemporal));
//        eliminarDelArchivo.write(reinterpret_cast<const char*>(&empleadoEnBlanco),
//            sizeof(EmpleadoTemporal));
//        cout << "La cuenta " << numeroCuenta << " se elimino\n";
//    }
//    else
//        cerr << "La cuenta " << numeroCuenta << " esta vacia" << endl;
//}
//
//void imprimirEmpleado(ostream& salida, const EmpleadoTemporal& registro) {
//    salida << left << setw(10) << registro.obtenerNumeroCuenta()
//        << setw(16) << registro.obtenerApellido()
//        << setw(11) << registro.obtenerNombre()
//        << setw(10) << setprecision(2) << fixed
//        << showpoint << registro.obtenerVentas()
//        << setw(10) << setprecision(2) << right << fixed
//        << showpoint << registro.calcularIngresos() << endl;
//}
//
//int obtenerCuenta(const char* const indicador) {
//    int numeroCuenta;
//    do
//    {
//        cout << indicador << " 1-100 ";
//        cin >> numeroCuenta;
//    } while (numeroCuenta < 1 || numeroCuenta > 100);
//    return numeroCuenta;
//}
//
//void creacionDatEB() {
//    ofstream listaEmpleadoBase("EmpleadosBase.dat", ios::out | ios::binary);
//    if (!listaEmpleadoBase) {
//        cerr << "No se pudo crear el archivo" << endl;
//        system("pause");
//        exit(EXIT_FAILURE);
//    }
//    EmpleadoBase empleadoenBlanco;
//    for (int i = 0; i < 100; i++)
//        listaEmpleadoBase.write(reinterpret_cast<const char*> (&empleadoenBlanco),
//            sizeof(EmpleadoBase));
//}
//
//void escribirListadoEB(fstream& listaEmpleadoBase) {
//    int numerocuenta;
//    string nombre, apellido;
//    double ventas, salario;
//    EmpleadoBase empleado;
//    cout << "Escriba el numero de cuenta de 1 a 100, 0 para terminar" << endl;
//    cin >> numerocuenta;
//    while (numerocuenta > 0 && numerocuenta <= 100) {
//        cout << "Escriba nombre" << endl;
//        cin >> nombre;
//        cout << "Escriba apellido" << endl;
//        cin >> apellido;
//        cout << "Escriba las ventas realizadas" << endl;
//        cin >> ventas;
//        cout << "Escriba el salario base" << endl;
//        cin >> salario;
//        empleado.establecerNumeroCuenta(numerocuenta);
//        empleado.establecerNombre(nombre);
//        empleado.establecerApellido(apellido);
//        empleado.establecerVentas(ventas);
//        empleado.establecerSalarioBase(salario);
//        listaEmpleadoBase.seekp((empleado.obtenerNumeroCuenta() - 1) *
//            sizeof(EmpleadoTemporal));
//        listaEmpleadoBase.write(reinterpret_cast<const char*> (&empleado),
//            sizeof(EmpleadoTemporal));
//        cout << "Escriba el numero de cuenta de 1 a 100, 0 para terminar" << endl;
//        cin >> numerocuenta;
//    }
//}
//
//void crearArchivoEB(fstream& leerDelArchivo) {
//    ofstream listaEmpleadoBase("EmpleadosBase.txt", ios::out);
//    if (!listaEmpleadoBase) {
//        cerr << "No se pudo abrir el archivo" << endl;
//        system("pause");
//        exit(EXIT_FAILURE);
//    }
//    listaEmpleadoBase << left << setw(10) << "Cuenta"
//        << setw(16) << "Apellido"
//        << setw(11) << "Nombre" << left
//        << setw(10) << "Ventas" << setw(10) << right << "Salario" << endl;
//    EmpleadoBase empleado;
//    leerDelArchivo.read(reinterpret_cast<char*>(&empleado),
//        sizeof(EmpleadoBase));
//    while (!leerDelArchivo.eof())
//    {
//        if (empleado.obtenerNumeroCuenta() != 0)
//            imprimirEmpleado(listaEmpleadoBase, empleado);
//        leerDelArchivo.read(reinterpret_cast<char*>(&empleado),
//            sizeof(EmpleadoBase));
//    }
//}
//
//void actualizarEB(fstream& actualizarArchivo) {
//    int numeroCuenta = obtenerCuenta("Escriba la cuenta que se debe actualizar ");
//    actualizarArchivo.seekg((numeroCuenta - 1) * sizeof(EmpleadoBase));
//    EmpleadoBase empleado;
//    actualizarArchivo.read(reinterpret_cast<char*>(&empleado),
//        sizeof(EmpleadoBase));
//    if (empleado.obtenerNumeroCuenta() != 0)
//    {
//        imprimirEmpleado(cout, empleado);
//        cout << "\nEscriba las ventas realizadas";
//        double ventas;
//        cin >> ventas;
//        empleado.establecerVentas(ventas);
//        imprimirEmpleado(cout, empleado);
//        actualizarArchivo.seekg((numeroCuenta - 1) * sizeof(EmpleadoBase));
//        actualizarArchivo.write(reinterpret_cast<const char*>(&empleado),
//            sizeof(EmpleadoBase));
//    }
//    else
//        cerr << "La cuenta " << numeroCuenta << " no tiene informacion" << endl;
//}
//
//void nuevoEB(fstream& insertarEnArchivo) {
//    int numeroCuenta = obtenerCuenta("Escriba el nuevo numero de cuenta");
//    insertarEnArchivo.seekg((numeroCuenta - 1) * sizeof(EmpleadoBase));
//    EmpleadoBase empleado;
//    insertarEnArchivo.read(reinterpret_cast<char*>(&empleado),
//        sizeof(EmpleadoBase));
//    if (empleado.obtenerNumeroCuenta() == 0)
//    {
//        string apellido;
//        string nombre;
//        double ventas, salario;
//        cout << "Escriba nombre" << endl;
//        cin >> setw(10) >> nombre;
//        cout << "Escriba apellido" << endl;
//        cin >> setw(15) >> apellido;
//        cout << "Escriba las ventas realizadas" << endl;
//        cin >> ventas;
//        cout << "Escriba el salario base" << endl;
//        cin >> salario;
//        empleado.establecerNumeroCuenta(numeroCuenta);
//        empleado.establecerApellido(apellido);
//        empleado.establecerNombre(nombre);
//        empleado.establecerVentas(ventas);
//        empleado.establecerSalarioBase(salario);
//        insertarEnArchivo.seekp((numeroCuenta - 1) *
//            sizeof(EmpleadoBase));
//        insertarEnArchivo.write(reinterpret_cast<const char*>(&empleado),
//            sizeof(EmpleadoBase));
//    }
//    else
//        cerr << "La cuenta " << numeroCuenta << " ya tiene informacion" << endl;
//}
//
//void eliminarEB(fstream& eliminarDelArchivo) {
//    int numeroCuenta = obtenerCuenta("Escriba la cuenta a eliminar");
//    eliminarDelArchivo.seekg((numeroCuenta - 1) * sizeof(EmpleadoBase));
//    EmpleadoBase empleado;
//    eliminarDelArchivo.read(reinterpret_cast<char*>(&empleado),
//        sizeof(EmpleadoBase));
//    if (empleado.obtenerNumeroCuenta() != 0)
//    {
//        EmpleadoBase empleadoEnBlanco;
//        eliminarDelArchivo.seekp((numeroCuenta - 1) *
//            sizeof(EmpleadoBase));
//        eliminarDelArchivo.write(reinterpret_cast<const char*>(&empleadoEnBlanco),
//            sizeof(EmpleadoBase));
//        cout << "La cuenta " << numeroCuenta << " se elimino\n";
//    }
//    else
//        cerr << "La cuenta " << numeroCuenta << " esta vacia" << endl;
//}
//void administracion(fstream&) {
//    fstream listaEmpleado("Empleados.dat", ios::in | ios::out | ios::binary);
//    if (!listaEmpleado)
//    {
//        cerr << "No se pudo abrir el archivo" << endl;
//        system("pause");
//        exit(EXIT_FAILURE);
//    }
//    fstream listaEmpleadoBase("EmpleadosBase.dat", ios::in | ios::out | ios::binary);
//    if (!listaEmpleadoBase)
//    {
//        cerr << "No se pudo abrir el archivo" << endl;
//        system("pause");
//        exit(EXIT_FAILURE);
//    }
//    int opcion;
//    while ((opcion = escribirOpcionEmpleado()) != FINALIZAR)
//    {
//        switch (opcion)
//        {
//        case CREAR_LISTADO:
//            escribirListado(listaEmpleado);
//            break;
//        case LEER_LISTADO:
//            leerDat();
//            break;
//        case CREAR_EMPLEADO:
//            crearArchivoEmpleado(listaEmpleado);
//            break;
//        case ACTUALIZAR_EMPLEADO:
//            actualizarEmpleado(listaEmpleado);
//            break;
//        case NUEVO_EMPLEADO:
//            nuevoEmpleado(listaEmpleado);
//            break;
//        case ELIMINAR_EMPLEADO:
//            eliminarEmpleado(listaEmpleado);
//            break;
//        case CREARLISTADO:
//            escribirListadoEB(listaEmpleadoBase);
//            break;
//        case CREAREMP:
//            crearArchivoEB(listaEmpleadoBase);
//            break;
//        case ACTUALIZAREMP:
//            actualizarEB(listaEmpleadoBase);
//            break;
//        case NUEVOEMP:
//            nuevoEB(listaEmpleadoBase);
//            break;
//        case ELIMINAREMP:
//            eliminarEB(listaEmpleadoBase);
//            break;
//        default:
//            cerr << "Opcion incorrecta" << endl;
//            break;
//        }
//        listaEmpleado.clear();
//    }
//}