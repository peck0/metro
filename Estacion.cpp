/*
	Name: class Estacion
	Copyright: 
	Author: Pedro Infante
	Date: 22/11/18 23:01
	Description: Clase para las estaciones
*/

#include "Estacion.h"

Estacion::Estacion(){}
Estacion::Estacion(int _id, Linea l, std::string _n, int ant, int sig){}


Estacion::~Estacion(){}

void Estacion::setId(int _id){id = _id;};
void Estacion::setNombre(std::string _nombre){nombre = _nombre;}
void Estacion::setAnterior(int a){anterior = a;}
void Estacion::setSiguiente(int s){siguiente = s;}
void Estacion::setLineaEst(Linea _l){linea = _l;}

void Estacion::setDatos(int i, Linea l, std::string n, int ant, int sig){
	setId(i);
	setNombre(n);
	setAnterior(ant);
	setLineaEst(l);
	setSiguiente(sig);
};

void Estacion::verEstacion(){
	Linea l;
	std::cout<<" "<<getId()<<"\t"<<getNombre()<<"\n";
	
}

int Estacion::getId(){return id;}
std::string Estacion::getNombre(){return nombre;}
int Estacion::getAnterior(){return anterior;}
int Estacion::getSiguiente(){return siguiente;}
Linea Estacion::getLineaEst(){return linea;}
