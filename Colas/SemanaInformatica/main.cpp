#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

struct actividad{
	int ini;
	int fin;
};

bool operator < (actividad const &a1, actividad const &a2){ // ordena por menor final
	return a1.fin < a2.fin;
}

int necesarios(PriorityQueue<actividad> &a){
	int nec = 0;
	int i = 1;
	int num = a.size();
	PriorityQueue<int> finales;

	actividad a1 = a.top();
	a.pop();
	finales.push(a1.fin);

	while (i < num){
		a1 = a.top();
		a.pop();

		if (a1.ini < finales.top()){
			nec++;
			finales.push(a1.fin);
		}
		else{
			finales.pop();
			finales.push(a1.fin);
		}

		i++;
	}

	return nec;
}

bool resuelveCaso(){
	int n;
	cin >> n;
	if (n == 0){ return false; }
	actividad a;
	PriorityQueue<actividad> v;

	for (int i = 0; i < n; i++){
		cin >> a.ini >> a.fin;
		v.push(a);
	}

	cout << necesarios(v) << "\n";

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