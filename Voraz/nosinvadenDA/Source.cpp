
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;


bool resuelveCaso() {

	// leer los datos de la entrada
	int n;
	cin >> n;

	if (!cin)  // fin de la entrada
		return false;

	vector<int> atacantes(n);
	vector<int> defensa(n);

	for (int i = 0; i < n; i++){
		cin >> atacantes[i];
	}

	for (int i = 0; i < n; i++){
		cin >> defensa[i];
	}

	sort(defensa.begin(), defensa.end(), greater<int>());
	sort(atacantes.begin(), atacantes.end(), greater<int>());

	int numVictorias = 0;
	int indexDef = 0;

	for (int i = 0; i < n; i++){
		if (atacantes[i] <= defensa[indexDef]){
			numVictorias++;
			indexDef++;
		}
	}

	cout << numVictorias << "\n";

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
