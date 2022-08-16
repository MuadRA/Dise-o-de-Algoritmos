
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Matriz.h"// propios o los de las estructuras de datos de clase
using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;

	if (!std::cin)  // fin de la entrada
		return false;

	Matriz<int> mat(N + 1, N + 2, 0);

	for (int i = 1; i < N+1; i++){
		for (int j = 1; j < N + 1; j++){
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i < N + 1; i++){
		for (int j = 1; j < N + 1; j++){
			mat[i][j] = max(max(mat[i - 1][j - 1], mat[i - 1][j]), mat[i - 1][j + 1]) + mat[i][j];
		}
	}

	int mayor = 0, col;
	for (int j = 1; j <= N; j++){
		if (mat[N][j] > mayor){
			mayor = mat[N][j];
			col = j;
		}
	}

	cout << mayor << " " << col << endl;

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
