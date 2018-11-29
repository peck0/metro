#ifndef RECORER_H
#define RECORER_H
#include "Estacion.h"
#include<vector>
#include<set>
#include<list>
#include "Resolver.h"

class Recorer
{
	public:
//		static int VELOCIDAD = 65000;
		Recorer();
		
		void recorrer(Estacion e, Estacion s);
		void ruta();
		void estacionOrigen();
		void estacionDestino();
		std::vector<Estacion> mostrar();
		Estacion getOrigen();
		Estacion getDestino();	
		void listarEstaciones(std::vector<Estacion> e);	
		void hacerListaOrigen(std::vector<Estacion> v);	
		void hacerListaDestino(std::vector<Estacion> v);
		void verTiempo(int p, int v, int d);		
		
		~Recorer();
	protected:
	/*	Resolver r;
		std::vector<Estacion> l1 = r.getLinea1();
		std::vector<Estacion> l2 = r.getLinea2();
		std::vector<Estacion> tl = r.getTeleferico();*/
		Estacion origen;
		Estacion destino;
		std::list<Estacion> l_origen, l_destino;
		


};

#endif
