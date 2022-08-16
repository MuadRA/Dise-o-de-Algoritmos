
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

struct tarea{
	int ini;
	int fin;
	int rep;
};

struct comp_tarea{
	bool operator()(tarea const &t1, tarea const &t2){
		return t2.ini <= t1.ini;
	}
};

bool resuelveCaso() {

	// leer los datos de la entrada
	int n, m, t;
	cin >> n >> m >> t;

	if (!cin)  
		return false;

	priority_queue<tarea, vector<tarea>, comp_tarea> cola;
	int in, fi, re;
	tarea tare;

	for (int i = 0; i < n; i++){
		cin >> in >> fi;
		tare.ini = in;
		tare.fin = fi;
		tare.rep = -1;
		cola.push(tare);
	}

	for (int i = 0; i < m; i++){
		cin >> in >> fi >> re;
		tare.ini = in;
		tare.fin = fi;
		tare.rep = re;
		cola.push(tare);
	}

	tarea tare2;
	bool valida = true;
	tare = cola.top();
	cola.pop();

	if (tare.rep != -1 && (tare.ini + tare.rep) < t){
		cola.push({ tare.ini + tare.rep, tare.fin + tare.rep, tare.rep });
	}

	while (tare.ini < t && valida && !cola.empty()){
			tare2 = cola.top();
			cola.pop();
			if (tare2.rep != -1 && (tare2.ini+tare2.rep) < t){
				cola.push({ tare2.ini + tare2.rep, tare2.fin + tare2.rep, tare2.rep });
			}
			if (tare.fin >= t){
				tare.fin = t;
			}
			if (tare.fin > tare2.ini){
				valida = false;
			}
			else{
				tare = tare2;
			}
	}

	if (valida){
		cout << "NO\n";
	}
	else{
		cout << "SI\n";
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
