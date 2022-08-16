
// Nombre y Apellidos

#include <iostream>
#include <fstream>
#include <vector>

#include "GrafoValorado.h"

using namespace std;

class GrafoCamion{
public:
	GrafoCamion(GrafoValorado<int> gr, int origen, int destino, int anchura) :marcas(gr.V(), false){
		anchu = anchura;
		dfs(gr, origen, anchura);
		esPosible = marcas[destino];
	}

	bool hayCamino(){
		return esPosible;
	}

private:
	vector<bool> marcas;
	bool esPosible;
	int anchu;

	void dfs(GrafoValorado<int> const& G, int v, int umbral) {
		marcas[v] = true;
		for (auto a : G.ady(v)) {
			if (a.valor() >= umbral) {
				int w = a.otro(v);
				if (!marcas[w])
					dfs(G, w, anchu);
			}
		}
	}

};


bool resuelveCaso() {

	// leer los datos de la entrada
	int V, A;
	cin >> V >> A;

	if (!std::cin)  // fin de la entrada
		return false;

	GrafoValorado<int> grafo(V);
	int u, v, valor;

	for (int i = 0; i < A; ++i) {
		cin >> u >> v >> valor;
		u--;
		v--;
		grafo.ponArista({ u, v, valor });
	}

	int cons, ori, dest, anch;
	cin >> cons;

	for (int i = 0; i < cons; i++){
		cin >> ori >> dest >> anch;
		ori--;
		dest--;
		GrafoCamion sol = GrafoCamion(grafo, ori, dest, anch);

		if (sol.hayCamino()){
			cout << "SI\n";
		}
		else{
			cout << "NO\n";
		}
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