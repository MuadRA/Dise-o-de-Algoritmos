
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <algorithm>

#include "Matriz.h"// propios o los de las estructuras de datos de clase

using namespace std;

struct cofre{
	int profundidad;
	int oro;
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int T,C,i,j;

	cin >> T;

	if (!std::cin)  // fin de la entrada
		return false;

	cin >> C;
	vector<cofre> cofres(C+1);
	Matriz<int> Mat(C + 1, T + 1, -1);
	i = 1;

	for (i = 1; i < C + 1; i++){
		cin >> cofres[i].profundidad >> cofres[i].oro;
	}

	i = 0;
	j = 0;

	for (i = 0; i < C + 1; i++){
		for (j = 0; j < T + 1; j++){
			if (i == 0 || j == 0){
				Mat[i][j] = 0;
			}
			else if (cofres[i].profundidad*3 > j){
				Mat[i][j] = Mat[i - 1][j];
			}
			else if (cofres[i].profundidad*3 <= j){
				Mat[i][j] = max(Mat[i - 1][j], Mat[i - 1][j - 3 * cofres[i].profundidad] + cofres[i].oro);
			}
		}
	}

	cout << Mat[C][T] << "\n";
	vector<bool> elegidos(C+1);
	int nCofres = 0;
	int tiempo = T;

	for (int i = C; i >= 1; i--){
		if (Mat[i][tiempo] == Mat[i - 1][tiempo]){
			elegidos[i] = false;
		}
		else{
			elegidos[i] = true;
			tiempo -= cofres[i].profundidad + (2 * cofres[i].profundidad);
			nCofres++;
		}
	}

	cout << nCofres << "\n";
	for (j = 1; j < C+1; j++){
		if (elegidos[j]){
			cout << cofres[j].profundidad << " " << cofres[j].oro << "\n";
		}
	}
	cout << "---\n";

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