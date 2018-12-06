#ifndef RECORER_H
#define RECORER_H
#include "Estacion.h"
#include<vector>
#include<set>
#include<list>
#include "DatosEstaciones.h"

class Recorer
{
	public:
//		static int VELOCIDAD = 65000;
		Recorer();
		
		void recorrer(Estacion e, Estacion s);
		void ruta();
		void estacionOrigen();
		void estacionDestino();
		std::vector<Estacion> eligeLinea();
		Estacion getOrigen();
		Estacion getDestino();	
		void listarEstaciones(std::vector<Estacion> e);	
		void hacerListaOrigen(std::vector<Estacion> v);	
		void hacerListaDestino(std::vector<Estacion> v);
		void verTiempo(int p, float v, int d);
		void setTime(int t);
		int getTime();
		void clearTime();		
		
		~Recorer();
	protected:
		Estacion origen;
		Estacion destino;
		std::list<Estacion> l_origen, l_destino;
		int time;
		
};

#endif
