
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
	vector<Valor> dist;
	vector<AristaDirigida<Valor>> ult;
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
	int numPag;
	cin >> numPag;

	if (numPag == 0)
		return false;

	DigrafoValorado<int> paginas(numPag + 1);
	vector<int> tiempoCarga(numPag + 1);
	int m, a, b, c;

	for (int i = 0; i < numPag; i++){
		cin >> tiempoCarga[i + 1];
	}
	
	cin >> m;

	for (int i = 0; i < m; i++){
		cin >> a >> b >> c;
		paginas.ponArista({ a, b, c + tiempoCarga[a] });
	}

	Dijkstra<int> dij(paginas, 1);

	if (dij.hayCamino(numPag)){
		cout << dij.distancia(numPag) + tiempoCarga[numPag] << endl;
	}
	else{
		cout << "IMPOSIBLE" << endl;
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