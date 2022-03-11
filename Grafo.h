#ifndef GRAFO_H
#define GRAFO_H
#include "Arista.h"
#include "Entrada.h"
#include <vector>
class Grafo{
	private:
		entrada * inicio ;
	public:
		Grafo();
		~Grafo();
		void incertarE(string);
		void incertarA(string,entrada* ,entrada* );
		void mostrarA();
		void mostrarE();
		entrada* buscarE(string);
		int buscarEE(string);
		bool BuscarPalabra(string P);
		vector<string> BP(string L, string Q);
};
#endif

