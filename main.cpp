#include<iostream>
#include<string.h>
#include<conio.h>
#include <vector>
#include<fstream>
#include<stdlib.h>
using namespace std;
#include "Arista.h"
#include "Entrada.h"
#include "GRAFO.h"
main(){
	
	int opc,opc2,e;
	string dato,datoB;
	bool EX;	
	 Grafo * obj=new Grafo();
	 entrada * o;
	 entrada* d;
	 fstream archivo("entradas.txt");
	 fstream origen("origen.txt");
	 fstream destino("destino.txt");
	 fstream valor("valor.txt");
	 string linea,lineaO,lineaD,lineaV;
	if(!archivo.is_open()){
		archivo.open("entradas.txt",ios::in);
	}
	while(getline(archivo, linea)){	
		obj->incertarE(linea);
	}
	archivo.close();

	if(!origen.is_open()){
		origen.open("origen.txt",ios::in);
	}
	if(!destino.is_open()){
		destino.open("destino.txt",ios::in);
	}
	if(!valor.is_open()){
		valor.open("valor.txt",ios::in);
	}
	while((getline(valor, lineaV))&&(getline(destino, lineaD))&&(getline(origen, lineaO))){
	 	o= obj->buscarE(lineaO);
		d= obj->buscarE(lineaD);
		obj->incertarA(lineaV,o,d);
	}
	destino.close();
	origen.close();
	valor.close();
	do{
		system("cls");
		cout<<endl;
		cout<<" 1)Comprovar Palabra"<<endl;
		cout<<endl;
		cout<<" 2)Salir"<<endl;
		cout<<endl;
		cin>>opc;
		switch(opc){
			case 1:
				cout<<" Ingrese palabra a verificar: ";
				cin>>dato;
				EX = obj->BuscarPalabra(dato);
				if(EX){
					cout<<" El AFND si puede crear esta palabra: "<< dato;
				}else{
					cout<<" El AFND no puede crear la palabra: "<< dato;
				}
				getch();
			break;
		}
	 }while(opc!=2);
	getch();
}
