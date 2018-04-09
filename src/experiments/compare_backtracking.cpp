#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "../types.h"
#include "backtracking_sin_poda.h"
#include "backtracking_poda_factibilidad.h"
#include "config.h"

using namespace std;

void randomValuesAndSizes() {
    //Se comparan backtracking puro vs poda1 vs poda2, incrementando cantidad de items
    //Valores aleatorios para el tamaño de la mochila y el tamaño y valor de los items
    //∀ w: w ≤ W

    random_device rd;
    mt19937 mt(rd());

    for (int n = 0; n < cantidadMaximaDeItems; n++) {
        uniform_real_distribution<double> size(1.0, n/2);
        uniform_real_distribution<double> value(1.0, 100.0);
        for (int repeticiones = 0; repeticiones < cantidadRepeticiones; repeticiones++) {
            vector<item> items;
            for (int i = 0; i < n; i++) {
                item item;
                item.size = int(size(mt));
                item.value = int(value(mt));
                items.push_back(item);
            }
            auto start_sin_podas = chrono::steady_clock::now();
            backpack bkp = backtrackingSinPoda(n, items);
            auto end_sin_podas = chrono::steady_clock::now();
            auto diff_sin_podas = end_sin_podas - start_sin_podas;

            cout << "compare_backtracking;randomValuesAndSizes;backtracking_sin_poda" << n << ";"
                 << chrono::duration <double, milli> (diff_sin_podas).count() << "ms" << endl;

            auto start_factibilidad = chrono::steady_clock::now();
            bkp = backtrackingPodaFactibilidad(n, items);
            auto end_factibilidad = chrono::steady_clock::now();
            auto diff_factibilidad = end_factibilidad - start_factibilidad;

            cout << "compare_backtracking;randomValuesAndSizes;backtracking_factibilidad" << n << ";"
                 << chrono::duration <double, milli> (diff_factibilidad).count() << "ms" << endl;


        }
    }
}

void constantSizesRandomValues() {
    //Se comparan backtracking puro vs poda1 vs poda2, incrementando cantidad de items
    //Todos lso items tienen el mismo tamaño, valores aleatorios
    //∀ i, j: wi = wj ^ wi ≤ W/2
}

void randomSizesConstantValues() {
    //Se comparan backtracking puro vs poda1 vs poda2, incrementando cantidad de items
    //Tamaños aleatorios, todos tienen el mismo valor
    //∀ i, j: pi = pj
    //∀ w: w ≤ W
}

void checkIfSortingItemsEnhances() {
    //Se evalúa si ordenar los items en backtracking con todas las podas aplicadas mejora la eficiencia,
    //incrementando cantidad de items
    //Valores aleatorios para el tamaño de la mochila y el tamaño y valor de los items
    //∀ w: w ≤ W
};