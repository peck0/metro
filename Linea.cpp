#include "Linea.h"

Linea::Linea()
{
}
Linea::Linea(int i, std::string n){}

Linea::~Linea()
{
}
void Linea::setLineaNombre(std::string s){nombre = s;}
void Linea::setId(int _id){id = _id;}
void Linea::setDatos(int _i, std::string _s){
			setId(_i);
			setLineaNombre(_s);
		}

std::string Linea::getLineaNombre(){return nombre;}
int Linea::getLineaId(){return id;}
