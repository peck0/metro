#include "DatosEstaciones.h"

DatosEstaciones::DatosEstaciones()
{
}


std::vector<Estacion> DatosEstaciones::getLinea1(){
	lin.setId(1); lin.setLineaNombre("Linea 1");	
	id = 0;
	e.setDatos(++id, lin, "Mama Tingo",0,867);	
	linea1.push_back(e);
	e.setDatos(++id,lin,"Gregorio Urbano Gilbert",e.getSiguiente(),1210);	
	linea1.push_back(e);
	e.setDatos(++id,lin,"Gregorio Luperon",e.getSiguiente(),961);
	linea1.push_back(e);
	e.setDatos(++id,lin,"Jose Francisco Peña Gomez",e.getSiguiente(),828);
	linea1.push_back(e);
	e.setDatos(++id,lin,"Hermanas Mirabal",e.getSiguiente(),1060);
	linea1.push_back(e);
	e.setDatos(++id,lin,"Maximo Gomez",e.getSiguiente(),1000);
	linea1.push_back(e);		
	e.setDatos(++id,lin,"Los Tainos",e.getSiguiente(),695);
	linea1.push_back(e);
	e.setDatos(++id,lin,"Pedro Livio Cedeño",e.getSiguiente(),816);
	linea1.push_back(e);
	e.setDatos(++id,lin,"Manuel Arturo Peña",e.getSiguiente(),510);
	linea1.push_back(e);
	e.setDatos(++id,lin,"Juan Pablo Duarte",e.getSiguiente(),532);
	linea1.push_back(e);
	e.setDatos(++id,lin,"Juan Bosch",e.getSiguiente(),642);
	linea1.push_back(e);
	e.setDatos(++id,lin,"Casandra Damiron",e.getSiguiente(),782);
	linea1.push_back(e);
	e.setDatos(++id,lin,"Joaquin Balaguer",e.getSiguiente(),1010);
	linea1.push_back(e);
	e.setDatos(++id,lin,"Amin Abel Hasbun",e.getSiguiente(),897);
	linea1.push_back(e);
	e.setDatos(++id,lin,"Francisco Alberto Caamaño",e.getSiguiente(),644);
	linea1.push_back(e);	
	e.setDatos(++id,lin,"Centro de Los Heroes",e.getSiguiente(),0);
	linea1.push_back(e);	
	return linea1;
}
std::vector<Estacion> DatosEstaciones::getLinea2(){
	lin.setDatos(2, "Linea 2");
	id = 0;
	e.setDatos(++id,lin,"Maria Montes",0,655);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Pedro Francisco Bono",e.getSiguiente(),820);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Francisco Gregorio Billini",e.getSiguiente(),853);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Ulises F. Espaillat",e.getSiguiente(),635);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Pedro Mir",e.getSiguiente(),1050);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Freddy Veras Goico",e.getSiguiente(),1110);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Juan Ulises Garcia Saleta",e.getSiguiente(),610);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Juan Pablo Duarte",e.getSiguiente(),840);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Coronel Rafael Tomas Fernandez D.",e.getSiguiente(),660);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Mauricio Baez",e.getSiguiente(),853);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Ramon Caceres",e.getSiguiente(),446);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Horacio Vasquez",e.getSiguiente(),797);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Manuel De Jesus Galvan",e.getSiguiente(),720);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Eduardo Brito",e.getSiguiente(),1140);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Ercilia Pepin",e.getSiguiente(),670);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Rosa Duarte",e.getSiguiente(),710);
	linea2.push_back(e);
	e.setDatos(++id,lin,"Trina De Moya",e.getSiguiente(),722);
	linea2.push_back(e);	
	e.setDatos(++id,lin,"Concepcion Bona",e.getSiguiente(),0);
	linea2.push_back(e);
	

	return linea2;
}
std::vector<Estacion> DatosEstaciones::getTeleferico(){
	lin.setDatos(3,"Teleférico");	
	id = 0;	
	e.setDatos(++id,lin,"Terminal Gualey",0,1420);
	teleferico.push_back(e);
	e.setDatos(++id,lin,"Estacion Los 3 Brazos",e.getSiguiente(),2170);
	teleferico.push_back(e);
	e.setDatos(++id,lin,"Estacion 3",e.getSiguiente(),1580);
	teleferico.push_back(e);
	e.setDatos(++id,lin,"Estacion 4",e.getSiguiente(),0);
	teleferico.push_back(e);
	
	return teleferico;
}


