#ifndef DYV_H
#define DYV_H

#include <vector>
#include <iostream>

template<typename T>
int busquedaBinaria(T val,std::vector<T>& V, int ini, int fin) {
	if (ini > fin) { std::cout << "No se encuentra en el array" << std::endl; return -1; }

	int medio = (ini + fin) / 2;
	
	if (V[medio] == val) return medio;
	else if (V[medio] > val) return busquedaBinaria(val, V, ini, medio - 1);
	else return  busquedaBinaria(val, V, medio + 1, fin);
}

template<typename T>
int Partition(std::vector<T>& V, int ini, int fin) {
	
	T x = V[fin];
	int i = ini;

	for (int j = ini; j < fin; j++) {
		if (V[j] <= x) {
			T aux = V[i];
			V[i] = V[j];
			V[j] = aux;
			i++;
		}
	}

	T aux = V[i];
	V[i] = V[fin];
	V[fin] = aux;

	
	return i;
}

template<typename T>
void quicksort(std::vector<T>& V, int ini, int fin) {
	if (ini < fin) {
	       int pivot = Partition(V, ini, fin);
       		quicksort(V, ini, pivot - 1);
 		quicksort(V, pivot + 1, fin);
	}
}	

#endif
