#ifndef RECORRE_H
#define RECORRE_H
#include "Estacion.h"

class Recorre
{
	public:
		Recorre();
		~Recorre();
		void hacerRecorrido();
	protected:
		Estacion origen, siguiente, anterior, destino;
		
		
};

#endif
