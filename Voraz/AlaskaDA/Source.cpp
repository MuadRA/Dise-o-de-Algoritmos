
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

bool resuelveCaso() {

	int n;
	cin >> n;

	if (n == 0)  // fin de la entrada
		return false;

	vector<int> v1(n);
	vector<int> v2(n);

	for (int i = 0; i < n; i++){
		cin >> v1[i];
	}

	for (int i = 0; i < n; i++){
		cin >> v2[i];
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += abs(v1[i] - v2[i]);
	}

	cout << sum << "\n";

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
