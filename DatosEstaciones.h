#ifndef DATOSESTACIONES_H
#define DATOSESTACIONES_H
#include "Estacion.h"
#include<vector>
#include "Linea.h"

class DatosEstaciones
{
	public:
		DatosEstaciones();
		std::vector<Estacion> getLinea1();
		std::vector<Estacion> getLinea2();	
		std::vector<Estacion> getTeleferico();
		

		
	protected:
		int id;
		Estacion e;
		std::vector<Estacion> linea1;
		std::vector<Estacion> linea2;
		std::vector<Estacion> teleferico;		
		Linea lin;
		

		
};

#endif
