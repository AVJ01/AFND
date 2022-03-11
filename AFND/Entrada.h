#ifndef ENTRADA_H
#define ENTRADA_H
#include<string.h>
using namespace std;
class arista;

class entrada{
	private:
		string nombre;
		arista * enlA;
		entrada * sigE;
	public:
		entrada(string);
		~entrada();
		friend class Grafo;
};
#endif
