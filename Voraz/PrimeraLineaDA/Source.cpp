
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct edificio{
	int ini;
	int fin;
};

struct comp_edificios{
	bool operator()(edificio const & e1au, edificio const & e2au){
		return e2au.fin < e1au.fin;
	}
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;

	if (N == 0)  // fin de la entrada
		return false;

	edificio e1,e2;
	priority_queue<edificio, vector<edificio>, comp_edificios>cola;
	int numP = 1;
	
	for (int i = 0; i < N; i++){
		cin >> e1.ini >> e1.fin;
		cola.push(e1);
	}

	e1 = cola.top();
	cola.pop();

	while (!cola.empty()){
		e2 = cola.top();
		cola.pop();

		if (e1.fin <= e2.ini){
			numP++;
			e1 = e2;
		}
	}

	// escribir sol
	cout << numP << endl;
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}