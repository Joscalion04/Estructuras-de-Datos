#include "Producto.h"
Producto::Producto()
{
	nombre = "";
	codigo = "";
	precioBase = 0.0;
	existencias = 0;
}
Producto::Producto(string name, string code, float priceB, int exist)
{
	nombre = name;
	codigo = code;
	precioBase = priceB;
	existencias = exist;
}
Producto::~Producto()
{
}
string Producto::getName()
{
	return nombre;
}
string Producto::getCode()
{
	return codigo;
}
float Producto::getPrice()
{
	return precioBase;
}
int Producto::getExis()
{
	return existencias;
}
void Producto::setName(string name)
{
	nombre = name;
}
void Producto::setCode(string code)
{
	codigo = code;
}
void Producto::setPriceB(float priceB)
{
	precioBase = priceB;
}
void Producto::setExist(int exist)
{
	existencias = exist;
}
string Producto::toString()
{
	stringstream s;
	s << "-------Producto-------" << endl;
	s << "Nombre: " << nombre << endl;
	s << "Codigo: " << codigo << endl;
	s << "Precio Base: " << precioBase << endl;
	s << "EIxistencias: " << existencias << endl;
	return s.str();
}
float Producto::PrecioVenta(float priceB) {
	float priceV;
	priceV = priceB + (priceB * 0.15);
	return priceV;
}