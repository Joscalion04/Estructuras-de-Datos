#pragma once
#include<iostream>
#include<sstream>
using namespace std;
class Producto
{
private:
	string nombre;
	string codigo;
	float precioBase;
	int existencias;
public:
	//Constructores//
	Producto(); //Predeterminado//
	Producto(string name, string code, float priceB, int exist);
	//Parametrizado//
	virtual ~Producto();//Destructor//
	//Accesores//
	string getName();
	string getCode();
	float getPrice();
	int getExis();
	//Mutadores//
	void setName(string name);
	void setCode(string code);
	void setPriceB(float priceB);
	void setExist(int exist);
	//ToString//
	string toString(); \
		//Metodos de Calculo//
		float PrecioVenta(float priceB);
};
