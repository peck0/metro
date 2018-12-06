/*
	Name: class Estacion
	Copyright: 
	Author: Pedro Infante
	Date: 22/11/18 23:01
	Description: Clase para las estaciones
*/
#include<iostream>
#include "Estacion.h"
#include "Metro.h"
#include "Recorer.h"
#include <vector>
#include "DatosEstaciones.h"
#include "Linea.h"
#include <list>
#include<locale.h>

int main(){
	setlocale(LC_CTYPE, "spanish");//para mostrar caracteres del español
	std::list<Estacion> list;
	DatosEstaciones datos;
	std::vector<Estacion> linea1, linea2, t;
	int opc;
	Recorer run;
	
	
	do{
		std::cout<<"\n\t\t*** ELIJE UNA OPCION ***\n\n";
		std::cout<<" [ 1 ] Hacer un recorrido.\n";
		std::cout<<" [ 0 ] Salir.\n";
		std::cin>>opc;	
		
		if(opc == 1){
			run.clearTime();
			run.ruta();
		}		
		
	}while(opc !=0);
	

	
	
	

	
}
