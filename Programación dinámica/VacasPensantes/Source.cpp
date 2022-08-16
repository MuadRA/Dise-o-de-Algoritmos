
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"// propios o los de las estructuras de datos de clase

using namespace std;

bool resuelveCaso() {

	// leer los datos de la entrada
	int n;
	cin >> n;

	if (n == 0)  // fin de la entrada
		return false;

	vector<int> comida(n + 1, 0);

	for (int i = 1; i <= n; i++){
		cin >> comida[i];
	}

	int N = comida.size();

	Matriz<int> mat(N, N, 0);

	for (int i = 1; i < N - 1; i++){
		mat[i][i + 1] = max(comida[i], comida[i + 1]);
	}

	for (int i = 1; i < N; i++){
		mat[i][i] = comida[i];
	}

	for (int d = 2; d < N - 1; d++){
		for (int i = 1; i < N - d; i++){
			int j = i + d;

			int izqda, dcha;

			if (comida[j] > comida[i + 1]){
				izqda = mat[i + 1][j - 1] + comida[i];
			}
			else{
				izqda = mat[i + 2][j] + comida[i];
			}

			if (comida[i] < comida[j - 1]){
				dcha = mat[i][j - 2] + comida[j];
			}
			else{
				dcha = mat[i + 1][j - 1] + comida[j];
			}

			mat[i][j] = max(izqda, dcha);
		}
	}

	int x = mat[1][N - 1];

	cout << x << endl;

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	while (resuelveCaso());

	// para dejar todo como estaba al principio
	/*#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}
