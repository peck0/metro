#ifndef RESOLVER_H
#define RESOLVER_H
#include "Estacion.h"
#include<vector>
#include "Linea.h"

class Resolver
{
	public:
		Resolver();
		std::vector<Estacion> getLinea1();
		std::vector<Estacion> getLinea2();	
		std::vector<Estacion> getTeleferico();
			
//		void listEstaciones();

		
	protected:
		int id;
		Estacion e;
		std::vector<Estacion> linea1;
		std::vector<Estacion> linea2;
		std::vector<Estacion> teleferico;		
		Linea lin;

		
};

#endif
