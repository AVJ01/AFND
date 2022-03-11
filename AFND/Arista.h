#ifndef ARISTA_H
#define ARISTA_H
#include<string.h>
using namespace std;
class entrada;

class arista{
	private:
		string B;
		entrada * enlE;
		arista * sigA;
	public:
		arista(string);
		~arista();
		friend class Grafo;
};
#endif
