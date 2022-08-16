// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

#include "PriorityQueue.h"

using namespace std;

struct Atril{
	int numMusicos;
	int numPartituras;
};

bool operator >(Atril const &a1, Atril const &a2){
	int grupos1 = a1.numMusicos / a1.numPartituras;
	int grupos2 = a2.numMusicos / a2.numPartituras;

	if (a1.numMusicos % a1.numPartituras != 0)
		grupos1++;
	if (a2.numMusicos % a2.numPartituras != 0)
		grupos2++;

	return grupos1 > grupos2;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int p, n;
	cin >> p >> n;

	if (!std::cin)  // fin de la entrada
		return false;

	PriorityQueue<Atril, greater<Atril>> colaAtriles;
	int aux1;
	Atril aux;

	for (int i = 0; i < n; i++){
		cin >> aux1;
		aux.numMusicos = aux1;
		aux.numPartituras = 1;

		colaAtriles.push(aux);
	}

	int cont = n;
	while (cont < p){
		aux = colaAtriles.top();
		colaAtriles.pop();
		aux.numPartituras++;
		colaAtriles.push(aux);
		cont++;
	}
	

	// escribir sol
	aux = colaAtriles.top();
	int sol = aux.numMusicos / aux.numPartituras;

	if (aux.numMusicos%aux.numPartituras != 0)
		sol++;

	cout << sol << "\n";

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