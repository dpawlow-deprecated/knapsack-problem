#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "../bruteforce.h"
#include "../meet_in_the_middle.h"
#include "../backtracking.h"
#include "../dynamic_programming.h"
#include "config.h"

void randomValuesSizesBkp() {
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

            unsigned long bkp;

            if (n < 48) {
                auto start_bruteforce = chrono::steady_clock::now();
                bkp = bruteforce(n, items);
                auto end_bruteforce = chrono::steady_clock::now();
                auto diff_bruteforce = end_bruteforce - start_bruteforce;

                cout << "compare_algorithms;randomValuesAndSizes;bruteforce;" << n << ";"
                     << chrono::duration<double, milli>(diff_bruteforce).count() << "ms" << endl;

                auto start_meet_in_the_middle = chrono::steady_clock::now();
                bkp = meet_in_the_middle(n, items);
                auto end_meet_in_the_middle = chrono::steady_clock::now();
                auto diff_meet_in_the_middle = end_meet_in_the_middle - start_meet_in_the_middle;

                cout << "compare_algorithms;randomValuesAndSizes;meet_in_the_middle;" << n << ";"
                     << chrono::duration<double, milli>(diff_meet_in_the_middle).count() << "ms" << endl;

                auto start_backtracking = chrono::steady_clock::now();
                bkp = backtracking(n, items);
                auto end_backtracking = chrono::steady_clock::now();
                auto diff_backtracking = end_backtracking - start_backtracking;

                cout << "compare_algorithms;randomValuesAndSizes;backtracking;" << n << ";"
                     << chrono::duration<double, milli>(diff_backtracking).count() << "ms" << endl;
            }

            auto start_dynamic_programming = chrono::steady_clock::now();
            unsigned long value = dynamicProgramming(n, items);
            auto end_dynamic_programmic = chrono::steady_clock::now();
            auto diff_dynamic_programming = end_dynamic_programmic - start_dynamic_programming;

            cout << "compare_algorithms;randomValuesAndSizes;dynamic_programming;" << n << ";"
                 << chrono::duration <double, milli> (diff_dynamic_programming).count() << "ms" << endl;
        }
    }
}