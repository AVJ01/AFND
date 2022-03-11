#include<iostream>
#include "Arista.h"
#include "Entrada.h"
#include "Grafo.h"
using namespace std;

arista::arista(string da){
	B=da;
	enlE=NULL;
	sigA=NULL;
}
arista::~arista(){}
