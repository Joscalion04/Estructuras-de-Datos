#pragma once
#include"Producto.h"
class Productos
{
private:
	Producto** vec;
	int cant;
	int tam;
public:
	Productos(int can); //Constructor//
	virtual~Productos(); //Destructor Dinamico//
	//Mutadores//
	void setCant(int can);
	void setTam(int tama);
	//Ingresar Objetos//
	bool ingresar(Producto* produc);
	//Imprime el Producto//
	string toString();
	bool existeProducto(const string& cod);
	string mostrarProductoCod(const string& cod);
	string prodExistMin();
	bool buscarProducto(const string& cod);
	Producto* retornaProducto(const string& cod);
	int posDelProduc(const string& cod);
	void EliminarProducto(const string& cod);
	//Metodos de Calculo//

};
