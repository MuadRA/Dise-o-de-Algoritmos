
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>

#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;
using Camino = deque<int>;

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
		dist(g.V(), INF), ult(g.V()), pq(g.V()) {
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}
	bool hayCamino(int v) const { return dist[v] != INF; }
	Valor distancia(int v) const { return dist[v]; }
	Camino camino(int v) const {
		Camino cam;
		// recuperamos el camino retrocediendo
		AristaDirigida<Valor> a;
		for (a = ult[v]; a.desde() != origen; a = ult[a.desde()])
			cam.push_front(a);
		cam.push_front(a);
		return cam;
	}
private:
	const Valor INF = numeric_limits<Valor>::max();
	int origen;
	std::vector<Valor> dist;
	std::vector<AristaDirigida<Valor>> ult;
	IndexPQ<Valor> pq;
	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor(); ult[w] = a;
			pq.update(w, dist[w]);
		}
	}
};


bool resuelveCaso() {

	// leer los datos de la entrada
	int numCeldas, sal, seg, P;
	cin >> numCeldas >> sal >> seg >> P;

	if (!cin)  // fin de la entrada
		return false;

	DigrafoValorado<int> grafo(numCeldas + 1);
	int a, b, c, solucion = 0;

	for (int i = 1; i <= P; i++){
		cin >> a >> b >> c;
		grafo.ponArista({ b, a, c });
	}

	Dijkstra<int> dij(grafo, sal);
	int x;
	for (int i = 0; i < numCeldas; i++){
		x = dij.distancia(i + 1);
		if (x <= seg && ((i+1) != sal)){
			solucion++;
		}
	}
	cout << solucion << endl;

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