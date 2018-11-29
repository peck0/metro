/*
	Name: class Estacion
	Copyright: 
	Author: Pedro Infante
	Date: 22/11/18 23:01
	Description: Clase para las estaciones
*/


#ifndef ESTACION_H
#define ESTACION_H
#include<iostream>
#include "Linea.h"

class Estacion
{
	public:
		Estacion();
		Estacion(int id, Linea l, std::string nombre, int ant, int sig);
		
		~Estacion();		
		
		void setId(int id);
		void setNombre(std::string nombre);
		void setAnterior(int anterior);
		void setSiguiente(int siguiente);
		void setLineaEst(Linea l);
		
		void setDatos(int i, Linea li, std::string n, int a, int s);
		void verEstacion();
		
		int getId();
		std::string getNombre();
		int getAnterior();
		int getSiguiente();
		Linea getLineaEst();
		
	protected:
		int id; 
		std::string nombre;
		int anterior;
		int siguiente;
		Linea linea;
};

#endif
