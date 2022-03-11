#include<iostream>
#include <vector>
#include "Arista.h"
#include "Entrada.h"
#include "GRAFO.h"
using namespace std;

Grafo::Grafo(){
	inicio=NULL;
}
	Grafo::~Grafo(){
}
//Funciones para detectar la Palabras del AFND
vector<string> BP(string L, string Q);
	bool Grafo::BuscarPalabra(string P){
	string inicio = "q1";
	string fin = "q4";
	string temL, temE, temP = "";
	vector<string> AF,AF2,AF3,AF4;
	int c=0,T=0,c2=0,pos;
	bool N = false;
	temL = P[0];
	AF = BP(temL,inicio);
	T = AF.size() - 1;
	temP = temP + P[0];
	if( AF[0] != "no"){
		while(c != T){
		if(c>0){
			temP = "";
			temP = temP + P[0];
		}
		AF3.clear();
		temE = AF[c+1];
		for(int i=1;i<P.length();i++){
			AF3.push_back(temE);
			temL = P[i];
			AF2 = BP(temL,temE);
			if(AF2[0]=="si"){
				temP = temP + P[i];
				for(int j=0; j<AF2.size(); j++){
					if (AF2[j] == temE){
						c2 = 1;
						pos=j;
					}
				}
				if(c2 == 1 && AF2.size() > 2){
				if((P[i+2] == P[i]) && (P[i+1] == P[i])){
				temE = AF2[pos];
				}else if((P[i+2] != P[i]) && (P[i+1] == P[i])){
					temE = AF2[pos+1];
					temP = temP + P[i+1];
				i = i+1;
				}
				}else if(c2 == 1 && AF2.size() == 2){
					if(P[i+1] == P[i]){
					temE = AF2[pos];
				}else if(P[i+1] != P[i]){
					temL = P[i+1];
					AF4= BP(temL,AF2[pos]);
				if(AF4[0]=="si"){
					temE = AF4[1];
					temP = temP + P[i+1];
					i = i+1;
				}
				}
				}
			}else{
				break;
			}
		}
		if(temP == P){
			c=T;
			break;
		}
		c=c + 1;
		}
		if(temP == P){
			if(temE == fin){
				N=true;
			}else{
				N=false;
			}
		}else{
			N=false;
		}
	}else{
		N = false;
	}
	return N;
}

vector<string> Grafo::BP(string L, string Q){
	entrada*aux=inicio;
	vector<string> lista;
	string N="no", S="si";
	int c=0;
	if(inicio==NULL){
		lista.push_back(N);
	}else{
		while(aux!=NULL){
			if(aux->nombre == Q){
				arista* aux3=aux->enlA;
				if(aux3==NULL){
					lista.push_back(N);
				}else{
				while(aux3!=NULL){
					if(aux3->B == L){
						if(c==0){//no mas SIS
							lista.push_back(S);
							c=1;
						}
						lista.push_back(aux3->enlE->nombre);
					}
					aux3=aux3->sigA;
				}
				if(lista.empty()){
					lista.push_back(N);
				}
				}
			}
			aux=aux->sigE;
		}
	}
	return lista;
}


//Funciones insertar
void Grafo::incertarE(string n){
	entrada * nuevaE=new entrada(n);
	if(inicio==NULL){
		inicio=nuevaE;
	}else{
		entrada * aux=inicio;
		while(aux->sigE != NULL){
			aux=aux->sigE;
		}
		aux->sigE=nuevaE;
	}
}


void Grafo::incertarA(string da,entrada * o,entrada * d){
	arista *nuevaArista= new arista(da);
	nuevaArista->enlE=d;
	if (o->enlA==NULL){
		o->enlA=nuevaArista;
	}else{
		arista *aux2=o->enlA;
		while(aux2->sigA!=NULL){
			aux2=aux2->sigA;
		}
		aux2->sigA=nuevaArista;
	}
}

//Retorna una Q
entrada* Grafo::buscarE(string db){
	entrada*aux=inicio;
	if(inicio==NULL){
		cout<<"Vacio";
	}else{
		while(aux!=NULL){
			if(aux->nombre==db){
				 return aux;
				 aux=NULL;
			}else{
				aux=aux->sigE;
			}
		}
	}
	return NULL;
}

