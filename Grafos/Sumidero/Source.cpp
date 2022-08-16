
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Digrafo.h"// propios o los de las estructuras de datos de clase

using namespace std;

bool resuelveCaso() {

	// leer los datos de la entrada
	int ver, ari;
	cin >> ver >> ari;

	if (!std::cin)  // fin de la entrada
		return false;

	int a, b, numSumideros = -1, i;
	Digrafo grafo(ver);
	int aux1 = 0, aux2 = 0;
	bool encontrado = false;

	for (i = 0; i < ari; i++){
		cin >> a >> b;
		grafo.ponArista(a, b);
	}

	i = 0;
	Digrafo inver = grafo.inverso();

	while (i < ver && !encontrado){
		aux1 = grafo.ady(i).size();
		aux2 = inver.ady(i).size();

		if ((aux1 == 0) && (aux2 == (ver - 1))){
			numSumideros = i;
			encontrado = true;
		}
		i++;
	}

	if (numSumideros == -1){
		cout << "NO\n";
	}
	else{
		cout << "SI " << numSumideros << "\n";
	}

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