#include <iostream>
#include <vector>
#include <cstdlib>   //Para cerrar cmd
#include <string>    //para el ::tolower
#include <algorithm> // para el std::transform
#include <cmath>     //para usar trunc()

// Inicialización de Variables

float volRefri = 0, kgRefri = 0, pescAlmacenado = 0, precioKg = 0, kgTransac = 0, precioVenta = 0, contenedores = 0, kgTotal = 0, ingresoTotal = 0;

int numVenta = 0;

std::string ejecutarPrograma = "0", hacerVenta = "0", confVenta = "0", seleccionMenu = "0";

// Propuesta inicial para llevar kg vendidos y $ ingresados por cada venta // std::vector<vector<int>> transaccion;

// Prototipo Funciones

std::string ConvertirAMinusculas(std::string textoUsuario);

void Titulo();
void MensajeDeBienvenida();
void EjecutarPrograma();
void MenuSeleccion();
bool VerificadorValores(float, float, float);
void CalcCapacidadRefri();
void CalcPescAlmacenado();
void CalcPrecioPescado();
void Interfaz();
void HacerVenta();
void DatosEntradaInterfaz();
void ModuloVenta();
void InterfazModuloVenta();
void OtraVenta();
int CalcContenedores();
float CalcPescVendido();
float CalcIngreTotal();
void Transacciones();
void TitReport();
void SubtReportInv();
void DetReportInv();
void SubtReportVentas();
void EncReportVentas(int);
void DetReportVentas(float, float);
void Resumen();
void Reporte();
void Despedida();

// Main

int main()
{

	MensajeDeBienvenida();
	EjecutarPrograma();

	while (true) {


		MenuSeleccion();

		if (hacerVenta == "si") {
			ModuloVenta();
		}
	}
	//Reporte();
	return 0;
}

// Objetos

class Ventas
{
public:
	std::vector<float> kgVendidos, valorVenta;
};

Ventas ventas;

// Funciones

std::string ConvertirAMinusculas(std::string textoUsuario)
{

	std::transform(textoUsuario.begin(), textoUsuario.end(), textoUsuario.begin(), ::tolower);
	return textoUsuario;
}

void Titulo()
{
	system("cls");
	std::cout << "Gestor de Inventario y Venta de Pescado.\n\n";
}
void MensajeDeBienvenida()
{
	// Mensajes de bienvenida INICIO
	// std::cout << "Gestion de Inventario y Venta de Pescado.\n\n";
	Titulo();
	std::cout << "Este programa permite llevar control de su inventario\ncalculando la cantidad de pescado que puede almacenar,\nasi como realizar ventas calculando su precio.\n\n";
}

void EjecutarPrograma()
{

	// Verifica si se ejecuta o no el programa
	std::cout << "Desea ejecutar el programa? (SI o NO): ";

	while (true)
	{
		std::cin >> ejecutarPrograma;

		ejecutarPrograma = ConvertirAMinusculas(ejecutarPrograma);

		if (ejecutarPrograma == "si")
		{

			//std::cout << "Ejecutandose...\n";
			break;
		}

		else if (ejecutarPrograma == "no")
		{
			Despedida();
			/*
			system("pause");
			std::exit(0);
			*/
		}
		else
		{

			std::cout << "Por favor, escriba 'Si' para ejecutar el programa, o 'No' para cerrarlo\n";
		}
	}
}

void TituloInterfaz()
{

	std::cout << "Datos de Entrada\n\n";
}

void SubtituloInterfaz()
{

	std::cout << "Almacenamiento de la Pescaderia\n\n";
}

void LimpiarInterfaz()
{

	Titulo();
	TituloInterfaz();
	SubtituloInterfaz();
}

void MenuSeleccion() {
	while (true) {

		Titulo();
		std::cout << "Menu\n\n" << "#1 Inventario\n" << "#2 Venta\n" << "#3 Reporte\n" <<"#0 Salir\n\n" << "Seleccion: ";
		std::cin >> seleccionMenu;

		ConvertirAMinusculas(seleccionMenu);

		if (seleccionMenu == "1" || seleccionMenu == "inventario" || seleccionMenu == "#1") {
			Interfaz();
			break;


		}
		else if (seleccionMenu == "2" || seleccionMenu == "venta" || seleccionMenu == "#2") {
			HacerVenta();
			break;
		}

		else if (seleccionMenu == "3" || seleccionMenu == "reporte" || seleccionMenu == "#3") {

			Reporte();
			break;

		}
		else if (seleccionMenu == "0" || seleccionMenu == "salir" || seleccionMenu == "#0") {
			Despedida();
			
		}

		else {
			std::cout << "\nPor favor, ingrese un valor valido.\n\n";
			system("pause");
		}

	}
}

bool VerificadorValores(float varComprobar, float minimo, float maximo) {
	//Verifica que se haya ingresado un número y no letras
	if (std::cin.fail()) //verifica si el ultimo cin fallo
	{
		std::cin.clear(); // limpia el estado de error (porque al dar un dato incorrecto queda en error el cin)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta el resto de la línea (para poder meter datos nuevos en el proximo cin)
		std::cout << "\nPor favor, ingrese un valor valido.\n\n";
		system("pause");
		return false;

	}
	//

	else if (varComprobar < minimo || varComprobar >maximo) {
		std::cout << "\nPor favor, ingrese un valor valido.\n\n";
		system("pause");
		return false;

	}
	else {
		return true;
	}

}

void CalcCapacidadRefri() {

	while (true) {
		LimpiarInterfaz();
		std::cout << "Capacidad del refrigerador (100 - 600 L): ";

		std::cin >> volRefri;

		if (VerificadorValores(volRefri, 100, 600)) {
			kgRefri = (volRefri / 1.5);
			break;
		}

	}
}

void CalcPescAlmacenado() {

	float pescAlmacenadoTemp = 0;

	while (true) {

		LimpiarInterfaz();

		if (pescAlmacenado == 0) {

			std::cout << "Capacidad: " << volRefri << " L (" << kgRefri << " kg)\n\n";
			std::cout << "Cantidad de pescado a almacenar: ";

		}
		else {
			if (precioKg == 0) {

			
			std::cout << "Capacidad: " << volRefri << " L (" << kgRefri << " kg)\n";
			std::cout << "Pescado en Stock: " << pescAlmacenado << " kg\n\n";
			}
			else if (precioKg > 0) {
				DatosEntradaInterfaz();
			}
			std::cout << "Cantidad de pescado a almacenar: ";

		}


		//std::cout << "Maximo (" << (volRefri / 1.5) - pescAlmacenado << " kg): ";
		std::cin >> pescAlmacenadoTemp;

		//pescAlmacenado += pescAlmacenadoTemp;

		if (pescAlmacenadoTemp == 0) {
			system("pause");
			break;
		}
		else if (VerificadorValores(pescAlmacenadoTemp, 0.5, kgRefri-pescAlmacenado)) {
			pescAlmacenado += pescAlmacenadoTemp;


			//Este if es para hacer una pausa en el ingreso de pescado, si no se va a modificar el precio
			if (precioKg != 0) {
				LimpiarInterfaz();
				DatosEntradaInterfaz();
				std::cout << std::endl;
				system("pause");
			}
			break;
		}

	}
}
void CalcPrecioPescado() {

	while (true) {

		LimpiarInterfaz();

		std::cout << "Capacidad: " << volRefri << " L (" << (volRefri/1.5) << " kg)\n";
		std::cout << "Pescado en Stock: " << pescAlmacenado << " kg\n\n";

		std::cout << "Precio por kg de pescado: $";
		std::cin >> precioKg;

		if (VerificadorValores(precioKg, 0.1, 1000)) {
			LimpiarInterfaz();
			DatosEntradaInterfaz();
			system("pause");
			break;
		}

	}
}
void Interfaz()
{


	// Modulo de Inventario
	if (volRefri == 0) {
		CalcCapacidadRefri();
	}

	CalcPescAlmacenado();
	if (precioKg == 0) {
		CalcPrecioPescado();
	}


	//HacerVenta();

}

void HacerVenta() {

	while (true) {
		LimpiarInterfaz();
		DatosEntradaInterfaz();

		if (pescAlmacenado == 0) {
			std::cout << "No dispone de Stock para la venta\n";
			system("pause");
			break;
		}

		std::cout << "Desea realizar una venta? (SI o NO): ";
		std::cin >> hacerVenta;
		hacerVenta = ConvertirAMinusculas(hacerVenta);
		if (hacerVenta == "si") {
			ModuloVenta();
			break;
		}
		else if (hacerVenta == "no") {
			break;

		}
		else {
			std::cout << "\nPor favor, ingrese un valor valido.\n\n";
			system("pause");

		}

	}
}

void DatosEntradaInterfaz()
{

	std::cout << "Capacidad: " << volRefri << " L (" << kgRefri << " kg)\n";
	std::cout << "Pescado en Stock: " << pescAlmacenado << " kg\n";
	std::cout << "Precio por kg: $" << precioKg << "\n\n";
}
void ModuloVenta()
{
	while (hacerVenta == "si")
	{

		while (true) {

			LimpiarInterfaz();
			DatosEntradaInterfaz();

			std::cout << "Modulo de Venta\n\n";
			std::cout << "(Ingrese 0 para cancelar)\n\n";
			std::cout << "Cantidad de kg a vender: ";
			std::cin >> kgTransac;
		
			if (kgTransac == 0) {
				system("cls");
				LimpiarInterfaz();
				DatosEntradaInterfaz();
				std::cout << "Modulo de Venta\n\n";

				std::cout << "Venta Cancelada\n\n";
				hacerVenta = "no";
				system("pause");
				break;


			}

			else if (VerificadorValores(kgTransac, 0.1, pescAlmacenado)) {
				precioVenta = kgTransac * precioKg;

				LimpiarInterfaz();
				DatosEntradaInterfaz();
				std::cout << "Modulo de Venta\n\n";
				std::cout << "Cantidad: " << kgTransac << " kg\n";
				std::cout << "Precio: $" << precioVenta << "\n\n";

				while (true) {

					//Esto lo puedo meter en una funcion
					std::cout << "Confirmar venta (SI o NO): ";
					std::cin >> confVenta;
					confVenta = ConvertirAMinusculas(confVenta);

					if (confVenta == "si")
					{
						ventas.kgVendidos.push_back(kgTransac);   // transaccion[0, numVenta - 1] = kgTransac;  con el vector
						ventas.valorVenta.push_back(precioVenta); // transaccion[1, numVenta - 1] = precioVenta; con el vector
						pescAlmacenado -= kgTransac;
						numVenta++;
						OtraVenta();
						break;
					}
					else if (confVenta == "no")
					{

						//std::cout << "Venta cancelada\n";
						//hacerVenta = "no"; // Esto se puede hacer más eficiente tal vez, con confVenta
						HacerVenta();
						break;
					}
					else
					{

						std::cout << "\nError, responda correctamente.\n\n";
						system("pause");
						LimpiarInterfaz();
						DatosEntradaInterfaz();
						std::cout << "Modulo de Venta\n\n";
						std::cout << "Cantidad: " << kgTransac << " kg\n";
						std::cout << "Precio: $" << precioVenta << "\n\n";
					}
				}
				break;
			}
			
		}


	}
}

void InterfazModuloVenta()
{
	LimpiarInterfaz();
	DatosEntradaInterfaz();
	std::cout << "Modulo de Venta\n\n";
	std::cout << "Cantidad: " << kgTransac << " kg\n";
	std::cout << "Precio: $" << precioVenta << "\n\n";
}

void OtraVenta()
{
	while (true)
	{
		InterfazModuloVenta();
		std::cout << "Realizar otra venta? (SI o NO): ";
		std::cin >> hacerVenta; // Esto se puede hacer más eficiente tal vez, con confVenta
		hacerVenta = ConvertirAMinusculas(hacerVenta);

		if (hacerVenta == "si")
		{
			InterfazModuloVenta();
			ModuloVenta();
			break;
		}
		else if (hacerVenta == "no")
		{
			InterfazModuloVenta();
			//std::cout << "Venta cancelada";
			break;
		}
		else
		{
			InterfazModuloVenta();
			std::cout << "Error, responda correctamente.\n\n";
			system("pause");
		}
	}
}

int CalcContenedores()
{

	int pescAlmacInt = 0;
	pescAlmacInt = trunc(pescAlmacenado) / 20;

	if (pescAlmacenado / 20 == pescAlmacInt)
	{

		contenedores = pescAlmacInt;
	}
	else
	{

		contenedores = pescAlmacInt + 1;
	}

	return contenedores;
}

float CalcPescVendido()
{

	for (int i = 0; i < ventas.kgVendidos.size(); i++)
	{

		kgTotal += ventas.kgVendidos[i];
	}

	return kgTotal;
}

float CalcIngreTotal()
{

	for (int i = 0; i < ventas.valorVenta.size(); i++)
	{

		ingresoTotal += ventas.valorVenta[i];
	}

	return ingresoTotal;
}

void TitReport()
{
	std::cout << "Datos de salida\n\n";
}

void SubtReportInv()
{
	std::cout << "Inventario\n\n";
}

void DetReportInv()
{
	std::cout << "Capacidad del Refrigerador: " << volRefri << " L\n";
	std::cout << "Pescado en inventario: " << pescAlmacenado << " kg\n";
	std::cout << "Contenedores (30 L) en uso: " << CalcContenedores() << "\n"; // falta declarar variable y calcular
	std::cout << "Precio por kg de pescado: $" << precioKg << "\n\n";
}

void SubtReportVentas()
{
	std::cout << "Ventas\n\n";
}

void EncReportVentas(int numTransac)
{

	std::cout << "Transaccion #" << numTransac
		<< "\n";
}

void DetReportVentas(float transacKg, float transacValor)
{

	std::cout << "Pescado Vendido: " << transacKg
		<< " kg\n";
	std::cout << "Monto Ingresado: $" << transacValor
		<< "\n\n";
}

void Resumen()
{
	std::cout << "Resumen\n\n";
	std::cout << "Ventas realizadas: " << numVenta << "\n";
	std::cout << "Pescado Total Vendido: " << CalcPescVendido()
		<< " kg\n";
	std::cout << "Monto Total Ingresado: $" << CalcIngreTotal()
		<< "\n";
}

void Reporte()
{
	Titulo();
	TitReport();
	SubtReportInv();
	DetReportInv();
	SubtReportVentas();
	Transacciones();
	Resumen();
	std::cout << std::endl;
	system("pause");
}

void Transacciones()
{

	for (int i = 1; i <= numVenta; i++)
	{

		EncReportVentas(i);

		DetReportVentas(ventas.kgVendidos[i - 1], ventas.valorVenta[i - 1]);
	}
}


void Despedida() {
	system("cls");
	Titulo();
	std::cout << "Gracias por usar este programa.\n\n";
	system("pause");
	std::exit(0);
}