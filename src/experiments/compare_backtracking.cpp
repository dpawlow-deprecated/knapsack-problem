#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "backtracking_sin_poda.h"
#include "backtracking_poda_factibilidad.h"
#include "backtracking_poda_optimalidad.h"
#include "../backtracking.h"
#include "config.h"

using namespace std;
/*
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
            vector<Item> items;
            for (int i = 0; i < n; i++) {
                Item item = Item(long(value(mt)), long(size(mt)));
                items.push_back(item);
            }
            auto start_sin_podas = chrono::steady_clock::now();
            unsigned long bkp = backtrackingSinPoda(n, items);
            auto end_sin_podas = chrono::steady_clock::now();
            auto diff_sin_podas = end_sin_podas - start_sin_podas;

            cout << "compare_backtracking;randomValuesAndSizes;backtracking_sin_poda;" << n << ";"
                 << chrono::duration <double, milli> (diff_sin_podas).count() << "ms" << endl;

            auto start_factibilidad = chrono::steady_clock::now();
            bkp = backtrackingPodaFactibilidad(n, items);
            auto end_factibilidad = chrono::steady_clock::now();
            auto diff_factibilidad = end_factibilidad - start_factibilidad;

            cout << "compare_backtracking;randomValuesAndSizes;backtracking_factibilidad;" << n << ";"
                 << chrono::duration <double, milli> (diff_factibilidad).count() << "ms" << endl;

            auto start_optimalidad = chrono::steady_clock::now();
            bkp = backtrackingPodaOptimalidad(n, items);
            auto end_optimalidad = chrono::steady_clock::now();
            auto diff_optimalidad = end_optimalidad - start_optimalidad;

            cout << "compare_backtracking;randomValuesAndSizes;backtracking_optimalidad;" << n << ";"
                 << chrono::duration <double, milli> (diff_optimalidad).count() << "ms" << endl;

            auto start_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            bkp = backtrackingPodaOptimalidad(n, items);
            auto end_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            auto diff_backtrackingPodaOptimalidad = end_backtrackingPodaOptimalidad - start_backtrackingPodaOptimalidad;

            cout << "compare_backtracking;randomValuesAndSizes;backtracking_dos_podas;" << n << ";"
                 << chrono::duration <double, milli> (diff_backtrackingPodaOptimalidad).count() << "ms" << endl;


        }
    }
}

/*
void constantSizesRandomValues() {
    //Se comparan backtracking puro vs poda1 vs poda2, incrementando cantidad de items
    //Todos lso items tienen el mismo tamaño, valores aleatorios
    //∀ i, j: wi = wj ^ wi ≤ W/2

    random_device rd;
    mt19937 mt(rd());

    for (int n = 0; n < cantidadMaximaDeItems; n++) {
        uniform_real_distribution<double> size(1.0, n/2);
        uniform_real_distribution<double> value(1.0, 100.0);
        for (int repeticiones = 0; repeticiones < cantidadRepeticiones; repeticiones++) {
            vector<item> items;
            int constantSize = int(size(mt));
            for (int i = 0; i < n; i++) {
                item item;
                item.size = constantSize;
                item.value = int(value(mt));
                items.push_back(item);
            }
            auto start_sin_podas = chrono::steady_clock::now();
            int bkp = backtrackingSinPoda(n, items);
            auto end_sin_podas = chrono::steady_clock::now();
            auto diff_sin_podas = end_sin_podas - start_sin_podas;

            cout << "compare_backtracking;constantSizesRandomValues;backtracking_sin_poda;" << n << ";"
                 << chrono::duration <double, milli> (diff_sin_podas).count() << "ms" << endl;

            auto start_factibilidad = chrono::steady_clock::now();
            bkp = backtrackingPodaFactibilidad(n, items);
            auto end_factibilidad = chrono::steady_clock::now();
            auto diff_factibilidad = end_factibilidad - start_factibilidad;

            cout << "compare_backtracking;constantSizesRandomValues;backtracking_factibilidad;" << n << ";"
                 << chrono::duration <double, milli> (diff_factibilidad).count() << "ms" << endl;

            auto start_optimalidad = chrono::steady_clock::now();
            bkp = backtrackingPodaOptimalidad(n, items);
            auto end_optimalidad = chrono::steady_clock::now();
            auto diff_optimalidad = end_optimalidad - start_optimalidad;

            cout << "compare_backtracking;constantSizesRandomValues;backtracking_optimalidad;" << n << ";"
                 << chrono::duration <double, milli> (diff_optimalidad).count() << "ms" << endl;

            auto start_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            bkp = backtrackingPodaOptimalidad(n, items);
            auto end_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            auto diff_backtrackingPodaOptimalidad = end_backtrackingPodaOptimalidad - start_backtrackingPodaOptimalidad;

            cout << "compare_backtracking;constantSizesRandomValues;backtracking_dos_podas;" << n << ";"
                 << chrono::duration <double, milli> (diff_backtrackingPodaOptimalidad).count() << "ms" << endl;


        }
    }
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
};*/


void bt_nEqualBkpSize(unsigned int max_n, unsigned int repetitions) {
    /*
     * Se comparan backtrackingSinPoda vs meet in the middle vs backtracking vs dinámica
     * La mochila toma tamaño n
     * Valores aleatorios para el tamaño de los items
     * Los items pueden ser
     * ∀ w: w ≤ W
     */

    random_device rd;
    mt19937 mt(rd());

    for (unsigned int n = 1; n < max_n; n++) {
        uniform_real_distribution<double> size(1.0, n/2);
        uniform_real_distribution<double> value(1.0, 100.0);
        for (int r = 0; r < repetitions; r++) {
            unsigned long bkpSize = n;

            vector<Item> items;
            for (int i = 0; i < n; i++) {
                Item item = Item((unsigned long) value(mt), (unsigned long) size(mt));
                items.push_back(item);
            }

            unsigned long bkp;

            if (n<47){
                auto start_backtrackingSinPoda = chrono::steady_clock::now();
                bkp = backtrackingSinPoda(bkpSize, items);
                auto end_backtrackingSinPoda = chrono::steady_clock::now();
                auto diff_backtrackingSinPoda = end_backtrackingSinPoda - start_backtrackingSinPoda;

                cout << "compare_backtracking;nEqualBkpSize;backtrackingSinPoda;"  << bkpSize << ";" << n << ";"
                        << chrono::duration<double, milli>(diff_backtrackingSinPoda).count() << "ms" << endl;
            }

            if (n < 51) {
                auto start_backtrackingPodaFactibilidad = chrono::steady_clock::now();
                bkp = backtrackingPodaFactibilidad(bkpSize, items);
                auto end_backtrackingPodaFactibilidad = chrono::steady_clock::now();
                auto diff_backtrackingPodaFactibilidad = end_backtrackingPodaFactibilidad - start_backtrackingPodaFactibilidad;

                cout << "compare_backtracking;nEqualBkpSize;backtrackingPodaFactibilidad;" << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_backtrackingPodaFactibilidad).count() << "ms" << endl;
            }

            auto start_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            bkp = backtrackingPodaOptimalidad(bkpSize, items);
            auto end_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            auto diff_backtrackingPodaOptimalidad = end_backtrackingPodaOptimalidad - start_backtrackingPodaOptimalidad;

            cout << "compare_backtracking;nEqualBkpSize;backtrackingPodaOptimalidad;"  << bkpSize << ";" << n << ";"
                 << chrono::duration<double, milli>(diff_backtrackingPodaOptimalidad).count() << "ms" << endl;

            auto start_backtracking = chrono::steady_clock::now();
            bkp = backtracking(bkpSize, items);
            auto end_dynamic_programmic = chrono::steady_clock::now();
            auto diff_backtracking = end_dynamic_programmic - start_backtracking;

            cout << "compare_backtracking;nEqualBkpSize;backtracking;"  << bkpSize << ";" << n << ";"
                 << chrono::duration <double, milli> (diff_backtracking).count() << "ms" << endl;
        }
    }
}

void bt_fixedBkpSize(unsigned long bkpSize, unsigned int max_n, unsigned int repetitions) {
    /*
     * Se comparan backtrackingSinPoda vs meet in the middle vs backtracking vs dinámica
     * La mochila toma tamaño fijo
     * Valores aleatorios para el tamaño y valor de los items
     * ∀ w: w ≤ W
     */

    random_device rd;
    mt19937 mt(rd());

    for (unsigned int n = 1; n < max_n; n++) {
        uniform_real_distribution<double> size(1.0, bkpSize/2);
        uniform_real_distribution<double> value(1.0, 100.0);
        for (int r = 0; r < repetitions; r++) {
            vector<Item> items;
            for (int i = 0; i < n; i++) {
                Item item = Item((unsigned long) value(mt), (unsigned long) size(mt));
                items.push_back(item);
            }

            unsigned long bkp;

            if (n<40) {
                auto start_backtrackingSinPoda = chrono::steady_clock::now();
                bkp = backtrackingSinPoda(bkpSize, items);
                auto end_backtrackingSinPoda = chrono::steady_clock::now();
                auto diff_backtrackingSinPoda = end_backtrackingSinPoda - start_backtrackingSinPoda;

                cout << "compare_backtracking;fixedBkpSize;backtrackingSinPoda;" << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_backtrackingSinPoda).count() << "ms" << endl;
            }

            if (n<40) {
                auto start_backtrackingPodaFactibilidad = chrono::steady_clock::now();
                bkp = backtrackingPodaFactibilidad(bkpSize, items);
                auto end_backtrackingPodaFactibilidad = chrono::steady_clock::now();
                auto diff_backtrackingPodaFactibilidad = end_backtrackingPodaFactibilidad - start_backtrackingPodaFactibilidad;

                cout << "compare_backtracking;fixedBkpSize;backtrackingPodaFactibilidad;" << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_backtrackingPodaFactibilidad).count() << "ms" << endl;
            }

            auto start_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            bkp = backtrackingPodaOptimalidad(bkpSize, items);
            auto end_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            auto diff_backtrackingPodaOptimalidad = end_backtrackingPodaOptimalidad - start_backtrackingPodaOptimalidad;

            cout << "compare_backtracking;fixedBkpSize;backtrackingPodaOptimalidad;" << bkpSize << ";" << n << ";"
                 << chrono::duration<double, milli>(diff_backtrackingPodaOptimalidad).count() << "ms" << endl;


            auto start_backtracking = chrono::steady_clock::now();
            bkp = backtracking(bkpSize, items);
            auto end_dynamic_programmic = chrono::steady_clock::now();
            auto diff_backtracking = end_dynamic_programmic - start_backtracking;

            cout << "compare_algorithms;fixedBkpSize;backtracking;" << bkpSize << ";" << n << ";"
                 << chrono::duration <double, milli> (diff_backtracking).count() << "ms" << endl;
        }
    }
}

void bt_allItemsSize1_nEqualsW(unsigned int max_n, unsigned int repetitions) {
    /*
     * Se comparan backtrackingSinPoda vs meet in the middle vs backtracking vs dinámica
     * La mochila toma tamaño fijo
     * Valores aleatorios para el tamaño y valor de los items
     * ∀ w: w ≤ W
     */

    random_device rd;
    mt19937 mt(rd());

    for (unsigned int n = 1; n < max_n; n++) {
        unsigned long bkpSize = n;

        uniform_real_distribution<double> value(1.0, 100.0);
        for (int r = 0; r < repetitions; r++) {
            vector<Item> items;
            for (int i = 0; i < n; i++) {
                Item item = Item((unsigned long) value(mt), 1);
                items.push_back(item);
            }

            unsigned long bkp;

            if (n<25) {
                auto start_backtrackingSinPoda = chrono::steady_clock::now();
                bkp = backtrackingSinPoda(bkpSize, items);
                auto end_backtrackingSinPoda = chrono::steady_clock::now();
                auto diff_backtrackingSinPoda = end_backtrackingSinPoda - start_backtrackingSinPoda;

                cout << "compare_backtracking;allItemsSize1_nEqualsW;backtrackingSinPoda;" << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_backtrackingSinPoda).count() << "ms" << endl;
            }

            if (n<25) {
                auto start_backtrackingPodaFactibilidad = chrono::steady_clock::now();
                bkp = backtrackingPodaFactibilidad(bkpSize, items);
                auto end_backtrackingPodaFactibilidad = chrono::steady_clock::now();
                auto diff_backtrackingPodaFactibilidad = end_backtrackingPodaFactibilidad - start_backtrackingPodaFactibilidad;

                cout << "compare_algorithms;allItemsSize1_nEqualsW;backtrackingPodaFactibilidad;" << bkpSize << ";" << n
                     << ";"
                     << chrono::duration<double, milli>(diff_backtrackingPodaFactibilidad).count() << "ms" << endl;
            }

            auto start_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            bkp = backtrackingPodaOptimalidad(bkpSize, items);
            auto end_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            auto diff_backtrackingPodaOptimalidad = end_backtrackingPodaOptimalidad - start_backtrackingPodaOptimalidad;

            cout << "compare_backtracking;allItemsSize1_nEqualsW;backtrackingPodaOptimalidad;"  << bkpSize << ";" << n << ";"
                 << chrono::duration<double, milli>(diff_backtrackingPodaOptimalidad).count() << "ms" << endl;

            auto start_backtracking = chrono::steady_clock::now();
            bkp = backtracking(bkpSize, items);
            auto end_dynamic_programmic = chrono::steady_clock::now();
            auto diff_backtracking = end_dynamic_programmic - start_backtracking;

            cout << "compare_backtracking;allItemsSize1_nEqualsW;backtracking;"  << bkpSize << ";" << n << ";"
                 << chrono::duration <double, milli> (diff_backtracking).count() << "ms" << endl;
        }
    }
}


void bt_allItemsSize1Value1_nEqualsW(unsigned int max_n, unsigned int repetitions) {
    /*
     * Se comparan backtrackingSinPoda vs meet in the middle vs backtracking vs dinámica
     * La mochila toma tamaño fijo
     * Valores aleatorios para el tamaño y valor de los items
     * ∀ w: w ≤ W
     */

    random_device rd;
    mt19937 mt(rd());

    for (unsigned int n = 1; n < max_n; n++) {
        unsigned long bkpSize = n;

        uniform_real_distribution<double> value(1.0, 100.0);
        for (int r = 0; r < repetitions; r++) {
            vector<Item> items;
            for (int i = 0; i < n; i++) {
                Item item = Item(1, 1);
                items.push_back(item);
            }

            unsigned long bkp;

            if (n<25) {
                auto start_backtrackingSinPoda = chrono::steady_clock::now();
                bkp = backtrackingSinPoda(bkpSize, items);
                auto end_backtrackingSinPoda = chrono::steady_clock::now();
                auto diff_backtrackingSinPoda = end_backtrackingSinPoda - start_backtrackingSinPoda;

                cout << "compare_backtracking;allItemsSize1Value1_nEqualsW;backtrackingSinPoda;" << bkpSize << ";" << n
                     << ";"
                     << chrono::duration<double, milli>(diff_backtrackingSinPoda).count() << "ms" << endl;
            }

            if (n<25) {
                auto start_backtrackingPodaFactibilidad = chrono::steady_clock::now();
                bkp = backtrackingPodaFactibilidad(bkpSize, items);
                auto end_backtrackingPodaFactibilidad = chrono::steady_clock::now();
                auto diff_backtrackingPodaFactibilidad = end_backtrackingPodaFactibilidad - start_backtrackingPodaFactibilidad;

                cout << "compare_backtracking;allItemsSize1Value1_nEqualsW;backtrackingPodaFactibilidad;" << bkpSize
                     << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_backtrackingPodaFactibilidad).count() << "ms" << endl;
            }

            auto start_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            bkp = backtrackingPodaOptimalidad(bkpSize, items);
            auto end_backtrackingPodaOptimalidad = chrono::steady_clock::now();
            auto diff_backtrackingPodaOptimalidad = end_backtrackingPodaOptimalidad - start_backtrackingPodaOptimalidad;

            cout << "compare_backtracking;allItemsSize1Value1_nEqualsW;backtrackingPodaOptimalidad;"  << bkpSize << ";" << n << ";"
                 << chrono::duration<double, milli>(diff_backtrackingPodaOptimalidad).count() << "ms" << endl;

            auto start_backtracking = chrono::steady_clock::now();
            bkp = backtracking(bkpSize, items);
            auto end_dynamic_programmic = chrono::steady_clock::now();
            auto diff_backtracking = end_dynamic_programmic - start_backtracking;

            cout << "compare_backtracking;allItemsSize1Value1_nEqualsW;backtracking;"  << bkpSize << ";" << n << ";"
                 << chrono::duration <double, milli> (diff_backtracking).count() << "ms" << endl;
        }
    }
}


