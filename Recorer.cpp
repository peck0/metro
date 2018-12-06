#include "Recorer.h"


Recorer::Recorer()
{
}

Recorer::~Recorer()
{
}

void Recorer::ruta(){
	estacionOrigen();
	estacionDestino();
	recorrer(origen, destino);
	
}


std::vector<Estacion> Recorer::eligeLinea(){
	DatosEstaciones datos;
	Estacion e;
	std::vector<Estacion> linea;
	int sel;		
	do{
		system("cls");
		std::cout<<"\n\tA cual linea pertenece la estacion... \n";
		std::cout<<"\t[ 1 ] Linea 1\n\t[ 2 ] Linea 2\n\t[ 3 ] Teleferico\n";
		std::cin>>sel;
		if(sel==1){
			linea = datos.getLinea1();
			return linea;
			break;
		}else if(sel==2){
			linea = datos.getLinea2();
			return linea;
			break;
		}else if(sel==3){
			linea = datos.getTeleferico();
			return linea;
			break;
		}else{
			system("cls");
			std::cout<<"No elegiste nada.\n";
		}
		
	}while(sel!=0);	
	
}

void Recorer::listarEstaciones(std::vector<Estacion> e){
	std::cout<<"\nESTACIONES DE ESTA LINEA:\n";
	std::vector<Estacion>::iterator t;	
	for(t = e.begin(); t != e.end(); t++){
		t->verEstacion();
	}

}

void Recorer::estacionOrigen(){
	std::vector<Estacion> v;
	std::vector<Estacion>::iterator it;
	int estId;
	v = eligeLinea();
	do{
		system("cls");
		listarEstaciones(v);
		std::cout<<"\nElija número de la estación de origen...\n";
		std::cin>>estId;
		if(estId < 1 || estId > v.size()){
			std::cout<<"La Estacion "<<estId<<" no existe.\n";
			system("pause");
		}else{
			for(it = v.begin(); it != v.end(); it++){
				if(estId== it->getId()){
					origen = *it;
				}
			}
		}
	}while(estId < 1 || estId > v.size());
	
}

void Recorer::estacionDestino(){
	std::vector<Estacion> v;
	std::vector<Estacion>::iterator it;
	int estId;
	v = eligeLinea();
	do{
		listarEstaciones(v);
		std::cout<<"\nElija número de la estación de destino...\n";
		std::cin>>estId;
		if(estId < 1 || estId > v.size()){
			std::cout<<"La Estacion "<<estId<<" no existe.\n";
			system("pause");
		}else{
			for(it = v.begin(); it != v.end(); it++){
				if(estId== it->getId()){
					destino = *it;
				}
			}
		}			
	}while(estId < 1 || estId > v.size());	
}

void Recorer::hacerListaOrigen(std::vector<Estacion> v){
	l_origen.clear();
	std::list<Estacion> l;
	std::vector<Estacion>::iterator i;
	for(i = v.begin(); i != v.end(); i++){
		l_origen.push_back(*i);
	}
}

void Recorer::hacerListaDestino(std::vector<Estacion> v){
	l_destino.clear();
	std::list<Estacion> l;
	std::vector<Estacion>::iterator i;
	for(i = v.begin(); i != v.end(); i++){
		l_destino.push_back(*i);
	}
}


void Recorer::recorrer(Estacion e, Estacion s){
	DatosEstaciones datos;
	std::list<Estacion>::iterator it;
	std::vector<Estacion> inicio ,fin;	
	std::list<Estacion> recorrido;
	std::list<Estacion>::iterator it_;	
	
	//Seleccioinar la linea de origen e inicio de recorrido
	if(origen.getLineaEst().getLineaId() == 1){
		inicio = datos.getLinea1();
	}else if(origen.getLineaEst().getLineaId() == 2){
		inicio = datos.getLinea2();
	}else if(origen.getLineaEst().getLineaId() == 3){
		inicio = datos.getTeleferico();
	}
	hacerListaOrigen(inicio);
	//seleccionar la linea de destino y fin de recorrido
	if(destino.getLineaEst().getLineaId() == 1){
		fin = datos.getLinea1();
	}else if(destino.getLineaEst().getLineaId() ==2){
		fin = datos.getLinea2();
	}else if(destino.getLineaEst().getLineaId()){
		fin = datos.getTeleferico();
	}
	hacerListaDestino(fin);

	//id de las estaciones para empezar y terminar el recorrido
	int idEstDestino = destino.getId();//id de la estacion destino
	int idEstOrigen = origen.getId();//id de la estacion origen
	int idLineaOrigen = origen.getLineaEst().getLineaId();
	int idLineaDestino = destino.getLineaEst().getLineaId();
	int transfer = 0;
//	int distancia = 0;
		
//	std::cout<<"ver id de lineas...."<<idLineaOrigen<<" y "<<idLineaDestino<<"\n";//PRUEBAS	
//	std::cout<<"ver id de estaciones."<<idEstOrigen<<" y "<<idEstDestino<<"\n";//PRUEBAS
	
/*#################################################################################################33*/
	if(idLineaOrigen == idLineaDestino){//RECORRIDO EN LA MISMA LINEA
//		std::cout<<"Las estaciones estan en la misma linea del metro.";
		if(idEstOrigen < idEstDestino){//SI ORIGEN ES MENOR QUE DESTINO
			for(it = l_origen.begin(); it != l_origen.end(); it ++){
				if(it->getId()>=idEstOrigen && it->getId() <= idEstDestino){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
//					distancia = distancia + it->getSiguiente();//sumar la distancia recorrida NO SUMA INDIVIDUAL
				}		
			}
		}else{//SI ORIGEN ES MAYOR QUE DESTINO
				l_origen.reverse();
				for(it = l_origen.begin(); it != (l_origen.end()); it++){
				if(it->getId()<=idEstOrigen && it->getId() >= idEstDestino){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
		}

/*#####################################################################################################3*/
	}else if(idLineaOrigen == 1 && idLineaDestino == 2){//EMPEZAMOS EN 1 Y TERMINAMOS EN 2
		transfer = 10;
		///SI EL ORIGEN ES MENOR QUE EL TRANSFER 
		if(idEstOrigen < transfer){//para linea 1
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()>=idEstOrigen && it->getId() <= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 8;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() < transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() > transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}else{//EL ORIGEN ES MAYOR QUE EL TRANSFER
			transfer = 10;
			l_origen.reverse();
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()<=idEstOrigen && it->getId() >= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 8;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() < transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() > transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}
/*#########################################################################################################33*/		
	}else if(idLineaOrigen == 2 && idLineaDestino == 1){//EMPEZAMOS EN LA 2 Y TERMINAMOS EN 1
		transfer = 8;
//		std::cout<<"Las estaciones estan en lineas diferentes.";
		///SI EL ORIGEN ES MENOR QUE EL TRANSFER 
		if(idEstOrigen < transfer){//para linea 1
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()>=idEstOrigen && it->getId() <= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 10;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() < transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() > transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}else{//EL ORIGEN ES MAYOR QUE EL TRANSFER
			transfer = 8;
			l_origen.reverse();
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()<=idEstOrigen && it->getId() >= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 10;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() < transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() > transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}
/*###########################################################################################################*/		
	}else if(idLineaOrigen == 1 && idLineaDestino == 3){
		/* TODO (#1#): de la linea 1 al telefrico */
		transfer = 10;
//		std::cout<<"Las estaciones estan en lineas diferentes.";
		///SI EL ORIGEN ES MENOR QUE EL TRANSFER 
		if(idEstOrigen < transfer){//para linea 1
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()>=idEstOrigen && it->getId() <= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 1;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() < transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() >= transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}else{//EL ORIGEN ES MAYOR QUE EL TRANSFER
			transfer = 10;
			l_origen.reverse();
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()<=idEstOrigen && it->getId() >= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 1;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() <= transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() >= transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}
/*####################################################################################################33*/		
	}else if(idLineaOrigen == 2 && idLineaDestino == 3){
		/* TODO (#1#): de la linea 1 al telefrico */
		transfer = 8;
//		std::cout<<"Las estaciones estan en lineas diferentes.";
		///SI EL ORIGEN ES MENOR QUE EL TRANSFER 
		if(idEstOrigen < transfer){//para linea 1
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()>=idEstOrigen && it->getId() <= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 1;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() < transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() >= transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}else{//EL ORIGEN ES MAYOR QUE EL TRANSFER
			transfer = 8;
			l_origen.reverse();
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()<=idEstOrigen && it->getId() >= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 1;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() <= transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() >= transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}
/*######################################################################################################*/		
	}else if(idLineaOrigen == 3 && idLineaDestino == 1){
		/* TODO (#1#): de la linea 1 al telefrico */
		transfer = 1;
//		std::cout<<"Las estaciones estan en lineas diferentes.";
		///SI EL ORIGEN ES MENOR QUE EL TRANSFER 
		if(idEstOrigen < transfer){//para linea 1
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()>=idEstOrigen && it->getId() <= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 10;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() < transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() >= transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}else{//EL ORIGEN ES MAYOR QUE EL TRANSFER
			transfer = 1;
			l_origen.reverse();
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()<=idEstOrigen && it->getId() >= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 10;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() <= transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() >= transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}
/*#########################################################################################################3*/		
	}else if(idLineaOrigen == 3 && idLineaDestino == 2){
		/* TODO (#1#): de la linea 1 al telefrico */
		transfer = 1;
//		std::cout<<"Las estaciones estan en lineas diferentes.";
		///SI EL ORIGEN ES MENOR QUE EL TRANSFER 
		if(idEstOrigen < transfer){//para linea 1
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()>=idEstOrigen && it->getId() <= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 8;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() < transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() >= transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}else{//EL ORIGEN ES MAYOR QUE EL TRANSFER
			transfer = 1;
			l_origen.reverse();
			for(it = l_origen.begin(); it != l_origen.end(); it ++){			
				if(it->getId()<=idEstOrigen && it->getId() >= transfer){
					recorrido.push_back(*it);//	llenar el recorrido con las estaciones
				}		
			}
			transfer = 8;
			if(idEstDestino < transfer){//Y EL DESTINO ES MENOR QUE TRANSFER
				l_destino.reverse();
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 menor que el transfer			
					if(it->getId() <= transfer && it->getId() >= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}else{
				for(it = l_destino.begin(); it != l_destino.end(); it ++){//para linea 2 mayor que el transfer			
					if(it->getId() >= transfer && it->getId() <= idEstDestino){
						recorrido.push_back(*it);//	llenar el recorrido con las estaciones
					}		
				}
			}
		}
		
	}
	
/*################################################################################33##############3*/
//	int suma = 0;
	it_ = recorrido.begin();
	int cont = 0;
	int distancia = 0;
	int velocidadTeleferico = 5.0;//18.056 m/s
	float velocidadMetro = 18.06;
	int parada = 0;
	int trayecto = it_->getId();
	
	system("cls");
	std::cout<<"\n\nEL RECORRIDO...\n";
	for(it_ = recorrido.begin(); it_ != recorrido.end(); it_++){
		cont ++;
		int dist = 0;
		if(trayecto < it_->getId()){//si el recorrido es hacia adelante
		/* TODO (#1#): condicion del transfer */
			if(transfer == 8 && it_->getLineaEst().getLineaId() == 1 && it_->getId() == 10){
				distancia = distancia + 180;
			}
			if(cont == 1){
				dist = it_->getAnterior();
				distancia = distancia - dist;
				trayecto = it_->getId();
				std::cout<<"Aui no hay nada.\n";
			}else{	
//				std::cout<<"Aui si hay MUCHO.\n";			
				dist = it_->getAnterior();	
				distancia = distancia + dist;//it_->getAnterior();
				trayecto = it_->getId();
			}
		}
		if(trayecto >= it_->getId()){//si el recorrido es hacia atras
			if(transfer == 1 && it_->getLineaEst().getLineaId() == 3 && it_->getId() == 1){
				distancia = distancia - 1420;				
			}
			dist = it_->getSiguiente();
			distancia = distancia + dist;//it_->getSiguiente();
			trayecto = it_->getId();
//			condicion del transfer
			if(transfer == 10 && it_->getLineaEst().getLineaId() == 2 && it_->getId() == 8){
				distancia = distancia - 306;//15811
			}
			if(transfer == 10 && it_->getLineaEst().getLineaId() == 1 && it_->getId() == 10){
				distancia = distancia - 510;
			}

		}
		
		std::cout<<"|-> "<<it_->getLineaEst().getLineaNombre()<<" Estación ";
		std::cout<<it_->getNombre()<<"\n";
	/*	std::cout<<"Transfer: "<<transfer<<"\n";
		std::cout<<"trayecto: "<<trayecto<<"\n";
		std::cout<<"Distancia: "<<distancia<<"\t"<<"Dist: "<<dist<<"\n";
		std::cout<<"Contador "<<cont<<"\n";
		std::cout<<"Estacion ID: "<<it_->getId()<<"...\n";
		std::cout<<"Linea ID: "<<it_->getLineaEst().getLineaId()<<"...\n";*/
		std::cout<<"Distancia recorrida: "<<distancia<<" Mts.\n";
		/* controlar la velocidad, metro o teleferico */
		if(it_->getLineaEst().getLineaId() == 3){
			if(transfer != 0 && it_->getId()==1){
				verTiempo(0,1,0);
			}else{
				verTiempo(parada, velocidadTeleferico, dist);
//				std::cout<<"parada "<<parada<<"\n\n";
				parada = parada + 10;
			}			
		}else{
			verTiempo(parada, velocidadMetro, dist);
//			std::cout<<"parada "<<parada<<"\n\n";
			parada = parada + 10;	
		}
			
	}	
}
void Recorer::verTiempo(int p_, float v_, int d_){	
	int min, seg, i;
	float tiempo;
	tiempo = d_ / v_;
	tiempo = tiempo + p_;
	
	i = (float) tiempo;
	setTime(i);
	min = getTime() /60;
	seg = getTime()%60;
	std::cout<<"Tiempo transcurrido: ";
	if(min < 10)std::cout<<0;std::cout<<min<<":";
	if(seg < 10)std::cout<<0;std::cout<<seg<<"\n\n";
//	std::cout<<"tiempo: "<<getTime()<<"\n";	
}

void Recorer::setTime(int _t){
	time = time + _t;
}

int Recorer::getTime(){
	return time;
}

void Recorer::clearTime(){
	time = 0;
}
