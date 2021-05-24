#include<iostream>
using namespace std;  
	int const filas=4;
	int const columnas=5;
	void LimpiezaMatriz(bool Disponibilidad[filas][columnas],int Pesos[filas][columnas]);
	void ImprimirDisponibilidad(bool Disponibilidad[filas][columnas]);
	void ImprimirPeso(int Pesos[filas][columnas]);
	void ImprimirMatricesString (string Matriz[filas][columnas]);
	void LlenarVectorNombresPuertos(string NombresPuertos[], int Puertos);
	float PorcentajeOcupacion (bool Disponibilidad[filas][columnas]);	
	void CantidadContenedoresIngresados(bool Disponibilidad[filas][columnas]);
	void CantidadContenedoresPorPuertosMayorMenor(int VectorContenedores[], string NombresPuertos[], int Puertos);
	void ListadoMarcasEnEconomica(bool Disponibilidad[filas][columnas], string Marcas[filas][columnas]);
	void ListadoMarcasEnPremium(bool Disponibilidad[filas][columnas], string Marcas[filas][columnas]);
	void InformacionAlDarNombreEmpresa(string Marcas[filas][columnas]);
	float PromedioPesoContenedores(bool Disponibilidad[filas][columnas], int Pesos[filas][columnas]);
	int FilaMayorCarga(int Pesos[filas][columnas]);
	int ColumnaMenorCarga(int Pesos[filas][columnas]);
	int ContenedoresClaseConsultada(string TipoArticulo[filas][columnas], string ClaseConsultada);
	float PromedioPesoPuertoPreguntado(string PuertoOrigen[filas][columnas], int Pesos[filas][columnas], string PuertoConsultado);
	string EmpresaContenedorMayorPeso(string Marcas[filas][columnas], int Pesos[filas][columnas]);
	string EmpresaContenedorMenorPeso(string Marcas[filas][columnas], int Pesos[filas][columnas]);
	int DineroRecaudadoPuertoActual(bool Disponibilidad[filas][columnas], string PuertoOrigen[filas][columnas], string PuertoActual);
	
int main(){
	int Puertos=0;
	cout<<"Ingrese la cantidad de puertos a visitar"<<endl; 
	cin>>Puertos; 
	string NombresPuertos[Puertos]; 
	LlenarVectorNombresPuertos(NombresPuertos, Puertos);

	//Definicion de matrices
	bool Disponibilidad[filas][columnas];
	string Marcas[filas][columnas];
	int Pesos[filas][columnas];
	string PuertoOrigen[filas][columnas];
	string TipoArticulo[filas][columnas];
	
	//Definicion de otras variables
	int Contenedores=0;
	int coordenadaFila=-1;
	int coordenadaColumna=-1;
	bool Desicion=1; 
	float PorcentajeOcupacionActual=0; 
	int VectorContenedores[Puertos];
	float PromedioPesos=0.0;
	int FilaConMayorCarga=0;
	int ColumnaConMenorCarga=0;
	string ClaseConsultada="";
	int ContenedoresTipoIngresado=0;
	string PuertoConsultado="";
	float PromedioPuertoIngresado=0.0;
	string MarcaContenedorPesado="";
	string MarcaContenedorLiviano="";
	string PuertoActual="";
	int RecaudadoPuertoActual=0;
	
    LimpiezaMatriz(Disponibilidad, Pesos);
	
	//Llenado del barco
	for (int i=0;i<Puertos;i++){
		cout<<"Bienvenido al puerto: "<<NombresPuertos[i]<<endl;
		PuertoActual=NombresPuertos[i];
		cout<<"¿Cuantos contenedores quiere ingresar en el barco?"<<endl; 
		cin>>Contenedores;
		VectorContenedores[i]=Contenedores;
		for(int countContenedor=1;countContenedor<=Contenedores;countContenedor++){
			cout<<"¿En que posicion quiere ingresar el contenedor #"<<countContenedor<<endl;
			cout<<"Las coordenadas disponibles para ingresar el contenedor se muestran a continuacion:"<<endl;
			cout<<"Recuerde que las posiciones se clasifican en zona economica y zona premium"<<endl;
			ImprimirDisponibilidad(Disponibilidad);
			do{			
				cout<<"Ingrese la coordenada de la fila deseada: "<<endl; 
				cin>>coordenadaFila;
				cout<<"Ingrese la coordenada de la columna deseada: "<<endl;
				cin>>coordenadaColumna;
				if (coordenadaFila>=0 && coordenadaFila<filas && coordenadaColumna>=0 && coordenadaColumna<columnas && Disponibilidad[coordenadaFila][coordenadaColumna]!=0){
					cout<<"La coordenada ingresada esta disponible"<<endl;
					Desicion=1;
					Disponibilidad[coordenadaFila][coordenadaColumna]=0;
					cout<<"Ingrese la marca del contenedor: "<<endl;
					cin>>Marcas[coordenadaFila][coordenadaColumna]; 
					cout<<"Ingrese el peso del contenedor: "<<endl;
					cin>>Pesos[coordenadaFila][coordenadaColumna];
					PuertoOrigen[coordenadaFila][coordenadaColumna]=NombresPuertos[i];
					cout<<"Ingrese el tipo de aticulo que contiene el contenedor. Ingrese: A->Alimentos  B->Dispositivos electronicos  C->Ropa y demas textiles "<<endl;
					cin>>TipoArticulo[coordenadaFila][coordenadaColumna];
				}else{
					cout<<"La coordenada ingresada es invalida"<<endl;
					Desicion=0;
				}
			}while(Desicion!=1);
		}
		PorcentajeOcupacionActual=PorcentajeOcupacion(Disponibilidad); 
		cout<<"El porcentaje de ocupacion actual del barco es del "<<PorcentajeOcupacionActual<<"%"<<endl;
		RecaudadoPuertoActual=DineroRecaudadoPuertoActual(Disponibilidad, PuertoOrigen, PuertoActual);
		cout<<"El valor recaudado en el puerto actual es= "<<RecaudadoPuertoActual<<endl;
	} 
	
	//Procedimientos 
	CantidadContenedoresIngresados(Disponibilidad);
	CantidadContenedoresPorPuertosMayorMenor(VectorContenedores, NombresPuertos, Puertos);
	ListadoMarcasEnEconomica(Disponibilidad, Marcas);
	ListadoMarcasEnPremium(Disponibilidad, Marcas);
	InformacionAlDarNombreEmpresa(Marcas);
	
	//Funciones
	PromedioPesos=PromedioPesoContenedores(Disponibilidad, Pesos);
	cout<<"El promedio de peso de todos los contenedores ingresados es= "<<PromedioPesos<<endl;
	FilaConMayorCarga=FilaMayorCarga(Pesos);
	cout<<"La fila con mayor carga es la fila: "<<FilaConMayorCarga<<endl;
	ColumnaConMenorCarga=ColumnaMenorCarga(Pesos);
	cout<<"La columna con menor carga es la columna: "<<ColumnaConMenorCarga<<endl;
	cout<<"Ingrese el tipo de articulo que desea consultar: A->Alimentos B->Dispositivos C->Ropa y textiles"<<endl;
	cin>>ClaseConsultada;
	ContenedoresTipoIngresado=ContenedoresClaseConsultada(TipoArticulo, ClaseConsultada);
	cout<<"La cantidad de contenedores del tipo de articulo ingresado es= "<<ContenedoresTipoIngresado<<endl;
	cout<<"Ingrese el nombre del puerto del que quiere consultar el promedio de peso ingresado en este mismo"<<endl;
	cin>>PuertoConsultado;
	PromedioPuertoIngresado=PromedioPesoPuertoPreguntado(PuertoOrigen, Pesos, PuertoConsultado);
	cout<<"El promedio de peso ingresado en este puerto es= "<<PromedioPuertoIngresado<<endl;
	MarcaContenedorPesado=EmpresaContenedorMayorPeso(Marcas, Pesos);
	cout<<"La empresa que posee el contenedor mas pesado es: "<<MarcaContenedorPesado<<endl;
	MarcaContenedorLiviano=EmpresaContenedorMenorPeso(Marcas, Pesos);
	cout<<"La empresa que posee el contenedor mas liviano es: "<<MarcaContenedorLiviano<<endl;
	
	//Imprimir matrices (final)
	cout<<"El barco fue cargado de la siguiente manera: "<<endl;
	cout<<"Segun la marca: "<<endl;
	ImprimirMatricesString(Marcas);
	cout<<"Segun el peso: "<<endl;
	ImprimirPeso(Pesos);
	cout<<"Segun el puerto de origen: "<<endl;
	ImprimirMatricesString(PuertoOrigen);
	cout<<"Segun el tipo de articulo: "<<endl;
	ImprimirMatricesString(TipoArticulo);
	
	return 0; 
}

void LlenarVectorNombresPuertos(string NombresPuertos[], int Puertos){
	for (int i=0;i<Puertos;i++){
		cout<<"Ingrese el nombre del puerto "<<i<<endl; 
		cin>>NombresPuertos[i];
	}	
}

void LimpiezaMatriz(bool Disponibilidad[filas][columnas],int Pesos[filas][columnas]){
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			Disponibilidad[i][j]=1;
			Pesos [i][j]=0.0;
		}
	}	
}

void ImprimirDisponibilidad(bool Disponibilidad[filas][columnas]){
	cout<<"Las coordenadas disponibles en la zona premium son: "<<endl;
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			if (Disponibilidad[i][j]==1 && (i==1 || i==2) && (j==1 || j==2 || j==3)){
				cout<<"("<<i<<","<<j<<")"<<"\t";
			}
		}
		cout<<endl;
	}
		cout<<"Las coordenadas disponibles en la zona economica son: "<<endl;
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			if (Disponibilidad[i][j]==1 && ((i==0 || i==3)||(i==1 && (j==0||j==4))||(i==2 && (j==0||j==4)))){
				cout<<"("<<i<<","<<j<<")"<<"\t";
			}else{
				cout<<"        ";
			}
		}
		cout<<endl;
	}
}

void ImprimirPeso(int Pesos[filas][columnas]){
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			cout<<Pesos[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void ImprimirMatricesString (string Matriz[filas][columnas]){
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			cout<<Matriz[i][j]<<"\t,";
		}
		cout<<endl;
	}
}

float PorcentajeOcupacion(bool Disponibilidad[filas][columnas]){
	int ContadorPosicionesOcupadas=0;
	float Porcentaje=0.0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(Disponibilidad[i][j]==0){
				ContadorPosicionesOcupadas=ContadorPosicionesOcupadas+1;
			}
		}
	}
	Porcentaje=(ContadorPosicionesOcupadas*100)/(filas*columnas);
	return Porcentaje;
}


void CantidadContenedoresIngresados(bool Disponibilidad[filas][columnas]){
	int TotalContenedores=0;
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			if (Disponibilidad[i][j]==0){
				TotalContenedores=TotalContenedores+1;
			}
		}
	}
	cout<<"La cantidad total de contenedores ingresados en los diferentes puertos es= "<<TotalContenedores<<endl;
}

void CantidadContenedoresPorPuertosMayorMenor(int VectorContenedores[], string NombresPuertos[], int Puertos){
	for(int i=0;i<Puertos;i++){
		for(int j=0;j<Puertos;j++){
			if(VectorContenedores[i]>VectorContenedores[j]){
				int aux=VectorContenedores[i];
				string auxNombres=NombresPuertos[i];
				VectorContenedores[i]=VectorContenedores[j];
				NombresPuertos[i]=NombresPuertos[j];
				VectorContenedores[j]=aux;
				NombresPuertos[j]=auxNombres;
			}
		}
	}
	cout<<"Reporte de la cantidad de contenedores por puerto ordenado de mayor a menor: "<<endl;
	for(int i=0;i<Puertos;i++){
		cout<<NombresPuertos[i]<<"->"<<VectorContenedores[i]<<endl;
	}
}

void ListadoMarcasEnEconomica(bool Disponibilidad[filas][columnas], string Marcas[filas][columnas]){
	cout<<"Las marcas de contenedores que van en la zona economica son: "<<endl;
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			if (Disponibilidad[i][j]==0 && ((i==0 || i==3)||(i==1 && (j==0||j==4))||(i==2 && (j==0||j==4)))){
				cout<<Marcas[i][j]<<endl;			
			}
		}
	}
}

void ListadoMarcasEnPremium(bool Disponibilidad[filas][columnas], string Marcas[filas][columnas]){
	cout<<"Las marcas de contenedores que van en la zona premium son: "<<endl;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(Disponibilidad[i][j]==0 && (i==1 || i==2) && (j==1 || j==2 || j==3)){
				cout<<Marcas[i][j]<<endl;
			}
		}
	}
}

void InformacionAlDarNombreEmpresa(string Marcas[filas][columnas]){
	string NombreEmpresa="";
	int ContenedoresEconomicos=0;
	int ContenedoresPremium=0;
	int TotalPagar=0;
	cout<<"Ingrese el nombre de la empresa que desea consultar"<<endl;
	cin>>NombreEmpresa;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(Marcas[i][j]==NombreEmpresa && (i==1 || i==2) && (j==1 || j==2 || j==3)){
				ContenedoresPremium=ContenedoresPremium+1;
			}else{
				if(Marcas[i][j]==NombreEmpresa && ((i==0 || i==3)||(i==1 && (j==0||j==4))||(i==2 && (j==0||j==4)))){
					ContenedoresEconomicos=ContenedoresEconomicos+1;
				}
			}
		}
	}
	TotalPagar=(ContenedoresPremium*300)+(ContenedoresEconomicos*100);
	cout<<"Empresa: "<<NombreEmpresa<<endl;
	cout<<"Cantidad de contenedores en zona premium: "<<ContenedoresPremium<<endl;
	cout<<"Cantidad de contenedores en zona economica: "<<ContenedoresEconomicos<<endl;
	cout<<"La empresa en total debe pagar por sus contenedores: "<<TotalPagar<<" USD"<<endl;
}

float PromedioPesoContenedores(bool Disponibilidad[filas][columnas], int Pesos[filas][columnas]){
	int AcumuladorPesos=0;
	int ContadorPesos=0;
	float Promedio=0.0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if (Disponibilidad[i][j]==0){
				AcumuladorPesos=AcumuladorPesos+Pesos[i][j];
				ContadorPesos=ContadorPesos+1;
			}
		}
	}
	Promedio=AcumuladorPesos/ContadorPesos;
	return Promedio;
}

int FilaMayorCarga(int Pesos[filas][columnas]){
	int SumaFila=0;
	int MayorCarga=INT_MIN;
	int FilaMayor=-1;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			SumaFila=SumaFila+Pesos[i][j];
		}
		if (SumaFila>MayorCarga){
			MayorCarga=SumaFila;
			FilaMayor=i;
		}
		SumaFila=0;	
	}
	return FilaMayor;
}

int ColumnaMenorCarga(int Pesos[filas][columnas]){
	int SumarColumnas=0;
	int MenorCarga=INT_MAX;
	int ColumnaMenor=-1;
	for(int j=0;j<columnas;j++){
		for(int i=0;i<filas;i++){
			SumarColumnas=SumarColumnas+Pesos[i][j];
		}
		if (SumarColumnas<MenorCarga){
			MenorCarga=SumarColumnas;
			ColumnaMenor=j;
		}
		SumarColumnas=0;	
	}
	return ColumnaMenor;
}

int ContenedoresClaseConsultada(string TipoArticulo[filas][columnas], string ClaseConsultada){
	int ContadorContenedores=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if (TipoArticulo[i][j]==ClaseConsultada){
				ContadorContenedores=ContadorContenedores+1;
			}
		}
	}
	return ContadorContenedores;
}

float PromedioPesoPuertoPreguntado(string PuertoOrigen[filas][columnas], int Pesos[filas][columnas], string PuertoConsultado){
	int AcumuladorPesos=0;
	int ContadorPesos=0;
	float Promedio=0.0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if (PuertoOrigen[i][j]==PuertoConsultado){
				AcumuladorPesos=AcumuladorPesos+Pesos[i][j];
				ContadorPesos=ContadorPesos+1;
			}
		}
	}
	Promedio=AcumuladorPesos/ContadorPesos;
	return Promedio;
}

string EmpresaContenedorMayorPeso(string Marcas[filas][columnas], int Pesos[filas][columnas]){
	int PesoMayor=INT_MIN;
	string MarcaMayorPeso="";
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(Pesos[i][j]>PesoMayor){
				PesoMayor=Pesos[i][j];
				MarcaMayorPeso=Marcas[i][j];
			}
		}
	}
	return MarcaMayorPeso;
}

string EmpresaContenedorMenorPeso(string Marcas[filas][columnas], int Pesos[filas][columnas]){
	int PesoMenor=INT_MAX;
	string MarcaMenorPeso="";
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(Pesos[i][j]>0 && Pesos[i][j]<PesoMenor){
				PesoMenor=Pesos[i][j];
				MarcaMenorPeso=Marcas[i][j];
			}
		}
	}
	return MarcaMenorPeso;
}

int DineroRecaudadoPuertoActual(bool Disponibilidad[filas][columnas], string PuertoOrigen[filas][columnas], string PuertoActual){
	int ContadorPremium=0;
	int ContadorEconomico=0;
	int TotalActualRecaudado=0;
	int ValorRecaudado=0;
	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if (Disponibilidad[i][j]==0){
				if (PuertoOrigen[i][j]==PuertoActual){
					if((i==1 || i==2) && (j==1 || j==2 || j==3)){
						ContadorPremium=ContadorPremium+1;
					}else{
						ContadorEconomico=ContadorEconomico+1;
					}
				}
			}
		}
	}
	TotalActualRecaudado=(ContadorPremium*300)+(ContadorEconomico*100);
	ValorRecaudado=TotalActualRecaudado;
	
	ContadorPremium=0;
	ContadorEconomico=0;
	TotalActualRecaudado=0;
	
	return ValorRecaudado;
}

