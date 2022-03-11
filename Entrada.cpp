#include<iostream>
#include<string.h>
#include "Arista.h"
#include "Entrada.h"
#include "Grafo.h"
using namespace std;

entrada::entrada(string n){
	nombre=n;
	sigE=NULL;
	enlA=NULL;
}
entrada::~entrada(){}

