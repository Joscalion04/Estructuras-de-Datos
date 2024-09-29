#include"ListaCircular.h"
// #include<vector> // STL

int main() {
	
	ListaCircular* personas = new ListaCircular();

	personas->insertar(new Persona("Joseph",21,"Coronado"));
	personas->insertar(new Persona("Andrey", 22, "Desamparados"));
	personas->insertar(new Persona("Katherine", 22, "Pavas"));
	personas->insertar(new Persona("Santiago", 65, "Heredia"));

	std::cout << "LISTA DE PERSONAS" << endl;
	std::cout << personas->toString() << endl;

	std::cout << "BUSCAR UNA PERSONA" << endl;
	std::cout << personas->buscarPersona("Katherine")->toString();

	std::cout << "\nBORRAR UNA PERSONA: Katherine" << endl;
	personas->eliminarPersona("Katherine");

	std::cout << "\nLISTA DE PERSONAS" << endl;
	std::cout << personas->toString() << endl;


	return 0;
}