#ifndef LINEA_H
#define LINEA_H
#include<iostream>

class Linea
{
	public:
		Linea();
		Linea(int id, std::string);
		void setLineaNombre(std::string n);
		void setId(int i);
		void setDatos(int i, std::string s);
		
		std::string getLineaNombre();
		int getLineaId();	
		
		
		~Linea();
	protected:
		int id;
		std::string nombre;
};

#endif
