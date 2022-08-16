
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

#include "GrafoValorado.h" // propios o los de las estructuras de datos de clase
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
using namespace std;
using Camino = deque<Arista<int>>;

template <typename Valor>
class ARM_Kruskal {
private:
	std::vector<Arista<Valor>> _ARM;
	Valor coste;
	vector<bool> visit;
	bool allVisited;

	void visitados(){
		for (int i = 1; i < visit.size(); i++){
			if (!visit[i]){
				allVisited = false;
			}
		}
	}

	void dfs(GrafoValorado<int> const& G, int v) {
		visit[v] = true;
		for (auto a : G.ady(v)) {
			int w = a.otro(v);
			if (!visit[w])
			dfs(G, w);
		}
	}
public:
	Valor costeARM() const {
		return coste;
	}

	vector<Arista<Valor>> const& ARM() const {
		return _ARM;
	}

	bool todosVisitados() const {
		return allVisited;
	}

	ARM_Kruskal(GrafoValorado<Valor> const& g, int origen) : coste(0), visit(g.V()), allVisited(true) {
		PriorityQueue<Arista<Valor>> pq(g.aristas());
		ConjuntosDisjuntos cjtos(g.V());
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				_ARM.push_back(a); coste += a.valor();
				if (_ARM.size() == g.V() - 1) break;
			}
		}
		dfs(g, origen);
		visitados();
	}
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int ver, ari;
	cin >> ver >> ari;

	if (!std::cin)  // fin de la entrada
		return false;

	GrafoValorado<int> grafo(ver + 1);
	int a, b, c;

	for (int i = 0; i < ari; i++){
		cin >> a >> b >> c;
		grafo.ponArista({ a, b, c });
	}

	ARM_Kruskal<int> krus(grafo, 1);
	
	if (krus.todosVisitados()){
		cout << krus.costeARM() << endl;
	}
	else{
		cout << "Imposible\n";
	}

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
