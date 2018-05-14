#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <math.h>

#include "../bruteforce.h"
#include "../meet_in_the_middle.h"
#include "../backtracking.h"
#include "../dynamic_programming.h"
#include "config.h"

void nEqualBkpSize(unsigned int max_n, unsigned int repetitions) {
    /*
     * Se comparan bruteforce vs meet in the middle vs backtracking vs dinámica
     * La mochila toma tamaño n
     * Valores aleatorios para el tamaño de los items
     * Los items pueden ser
     * ∀ w: w ≤ W
     */

    random_device rd;
    mt19937 mt(rd());

    for (unsigned int n = 28; n < max_n; n++) {
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

            if (n < 28) {
                auto start_bruteforce = chrono::steady_clock::now();
                bkp = bruteforce(bkpSize, items);
                auto end_bruteforce = chrono::steady_clock::now();
                auto diff_bruteforce = end_bruteforce - start_bruteforce;

                cout << "compare_algorithms;nEqualBkpSize;bruteforce;"  << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_bruteforce).count() << "ms" << endl;
            }
            if (n < max_n_exponentials) {

                auto start_meet_in_the_middle = chrono::steady_clock::now();
                bkp = meet_in_the_middle(bkpSize, items);
                auto end_meet_in_the_middle = chrono::steady_clock::now();
                auto diff_meet_in_the_middle = end_meet_in_the_middle - start_meet_in_the_middle;

                cout << "compare_algorithms;nEqualBkpSize;meet_in_the_middle;"  << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_meet_in_the_middle).count() << "ms" << endl;

                auto start_backtracking = chrono::steady_clock::now();
                bkp = backtracking(bkpSize, items);
                auto end_backtracking = chrono::steady_clock::now();
                auto diff_backtracking = end_backtracking - start_backtracking;

                cout << "compare_algorithms;nEqualBkpSize;backtracking;"  << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_backtracking).count() << "ms" << endl;
            }

            auto start_dynamic_programming = chrono::steady_clock::now();
            bkp = dynamicProgramming(bkpSize, items);
            auto end_dynamic_programmic = chrono::steady_clock::now();
            auto diff_dynamic_programming = end_dynamic_programmic - start_dynamic_programming;

            cout << "compare_algorithms;nEqualBkpSize;dynamic_programming;"  << bkpSize << ";" << n << ";"
                 << chrono::duration <double, milli> (diff_dynamic_programming).count() << "ms" << endl;
        }
    }
}

void fixedBkpSize(unsigned long bkpSize, unsigned int max_n, unsigned int repetitions) {
    /*
     * Se comparan bruteforce vs meet in the middle vs backtracking vs dinámica
     * La mochila toma tamaño fijo
     * Valores aleatorios para el tamaño y valor de los items
     * ∀ w: w ≤ W
     */

    random_device rd;
    mt19937 mt(rd());

    for (unsigned int n = 2; n < max_n; n++) {
        uniform_real_distribution<double> size(1.0, bkpSize/2);
        uniform_real_distribution<double> value(1.0, 100.0);
        for (int r = 0; r < repetitions; r++) {
            vector<Item> items;
            for (int i = 0; i < n; i++) {
                Item item = Item((unsigned long) value(mt), (unsigned long) size(mt));
                items.push_back(item);
            }

            unsigned long bkp;

            if (n < 28) {
                auto start_bruteforce = chrono::steady_clock::now();
                bkp = bruteforce(bkpSize, items);
                auto end_bruteforce = chrono::steady_clock::now();
                auto diff_bruteforce = end_bruteforce - start_bruteforce;

                cout << "compare_algorithms;fixedBkpSize;bruteforce;" << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_bruteforce).count() << "ms" << endl;
            }
            if (n < max_n_exponentials) {

                auto start_meet_in_the_middle = chrono::steady_clock::now();
                bkp = meet_in_the_middle(bkpSize, items);
                auto end_meet_in_the_middle = chrono::steady_clock::now();
                auto diff_meet_in_the_middle = end_meet_in_the_middle - start_meet_in_the_middle;

                cout << "compare_algorithms;fixedBkpSize;meet_in_the_middle;" << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_meet_in_the_middle).count() << "ms" << endl;

                auto start_backtracking = chrono::steady_clock::now();
                bkp = backtracking(bkpSize, items);
                auto end_backtracking = chrono::steady_clock::now();
                auto diff_backtracking = end_backtracking - start_backtracking;

                cout << "compare_algorithms;fixedBkpSize;backtracking;" << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_backtracking).count() << "ms" << endl;
            }

            auto start_dynamic_programming = chrono::steady_clock::now();
            bkp = dynamicProgramming(bkpSize, items);
            auto end_dynamic_programmic = chrono::steady_clock::now();
            auto diff_dynamic_programming = end_dynamic_programmic - start_dynamic_programming;

            cout << "compare_algorithms;fixedBkpSize;dynamic_programming;" << bkpSize << ";" << n << ";"
                 << chrono::duration <double, milli> (diff_dynamic_programming).count() << "ms" << endl;
        }
    }
}

void allItemsSize1_nEqualsW(unsigned int max_n, unsigned int repetitions) {
    /*
     * Se comparan bruteforce vs meet in the middle vs backtracking vs dinámica
     * La mochila toma tamaño fijo
     * Valores aleatorios para el tamaño y valor de los items
     * ∀ w: w ≤ W
     */

    random_device rd;
    mt19937 mt(rd());

    for (unsigned int n = 2; n < max_n; n++) {
        unsigned long bkpSize = n;

        uniform_real_distribution<double> value(1.0, 100.0);
        for (int r = 0; r < repetitions; r++) {
            vector<Item> items;
            for (int i = 0; i < n; i++) {
                Item item = Item((unsigned long) value(mt), 1);
                items.push_back(item);
            }

            unsigned long bkp;

            if (n < 28) {
                auto start_bruteforce = chrono::steady_clock::now();
                bkp = bruteforce(bkpSize, items);
                auto end_bruteforce = chrono::steady_clock::now();
                auto diff_bruteforce = end_bruteforce - start_bruteforce;

                cout << "compare_algorithms;allItemsSize1_nEqualsW;bruteforce;"  << bkpSize << ";" << n << ";"
                        << chrono::duration<double, milli>(diff_bruteforce).count() << "ms" << endl;
            }

            if (n < max_n_exponentials) {
                auto start_meet_in_the_middle = chrono::steady_clock::now();
                bkp = meet_in_the_middle(bkpSize, items);
                auto end_meet_in_the_middle = chrono::steady_clock::now();
                auto diff_meet_in_the_middle = end_meet_in_the_middle - start_meet_in_the_middle;

                cout << "compare_algorithms;allItemsSize1_nEqualsW;meet_in_the_middle;"  << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_meet_in_the_middle).count() << "ms" << endl;

                auto start_backtracking = chrono::steady_clock::now();
                bkp = backtracking(bkpSize, items);
                auto end_backtracking = chrono::steady_clock::now();
                auto diff_backtracking = end_backtracking - start_backtracking;

                cout << "compare_algorithms;allItemsSize1_nEqualsW;backtracking;"  << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_backtracking).count() << "ms" << endl;
            }

            auto start_dynamic_programming = chrono::steady_clock::now();
            bkp = dynamicProgramming(bkpSize, items);
            auto end_dynamic_programmic = chrono::steady_clock::now();
            auto diff_dynamic_programming = end_dynamic_programmic - start_dynamic_programming;

            cout << "compare_algorithms;allItemsSize1_nEqualsW;dynamic_programming;"  << bkpSize << ";" << n << ";"
                 << chrono::duration <double, milli> (diff_dynamic_programming).count() << "ms" << endl;
        }
    }
}


void allItemsSize1Value1_nEqualsW(unsigned int max_n, unsigned int repetitions) {
    /*
     * Se comparan bruteforce vs meet in the middle vs backtracking vs dinámica
     * La mochila toma tamaño fijo
     * Valores aleatorios para el tamaño y valor de los items
     * ∀ w: w ≤ W
     */

    random_device rd;
    mt19937 mt(rd());

    for (unsigned int n = 2; n < max_n; n++) {
        unsigned long bkpSize = n;

        uniform_real_distribution<double> value(1.0, 100.0);
        for (int r = 0; r < repetitions; r++) {
            vector<Item> items;
            for (int i = 0; i < n; i++) {
                Item item = Item(1, 1);
                items.push_back(item);
            }

            unsigned long bkp;

            if (n < 28) {
                auto start_bruteforce = chrono::steady_clock::now();
                bkp = bruteforce(bkpSize, items);
                auto end_bruteforce = chrono::steady_clock::now();
                auto diff_bruteforce = end_bruteforce - start_bruteforce;

                cout << "compare_algorithms;allItemsSize1Value1_nEqualsW;bruteforce;"  << bkpSize << ";" << n << ";"
                        << chrono::duration<double, milli>(diff_bruteforce).count() << "ms" << endl;
            }

            if (n < max_n_exponentials) {

                auto start_meet_in_the_middle = chrono::steady_clock::now();
                bkp = meet_in_the_middle(bkpSize, items);
                auto end_meet_in_the_middle = chrono::steady_clock::now();
                auto diff_meet_in_the_middle = end_meet_in_the_middle - start_meet_in_the_middle;

                cout << "compare_algorithms;allItemsSize1Value1_nEqualsW;meet_in_the_middle;"  << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_meet_in_the_middle).count() << "ms" << endl;

                auto start_backtracking = chrono::steady_clock::now();
                bkp = backtracking(bkpSize, items);
                auto end_backtracking = chrono::steady_clock::now();
                auto diff_backtracking = end_backtracking - start_backtracking;

                cout << "compare_algorithms;allItemsSize1Value1_nEqualsW;backtracking;"  << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_backtracking).count() << "ms" << endl;
            }

            auto start_dynamic_programming = chrono::steady_clock::now();
            bkp = dynamicProgramming(bkpSize, items);
            auto end_dynamic_programmic = chrono::steady_clock::now();
            auto diff_dynamic_programming = end_dynamic_programmic - start_dynamic_programming;

            cout << "compare_algorithms;allItemsSize1Value1_nEqualsW;dynamic_programming;"  << bkpSize << ";" << n << ";"
                 << chrono::duration <double, milli> (diff_dynamic_programming).count() << "ms" << endl;
        }
    }
}


void bkpSizeExponential(unsigned int max_n, unsigned int repetitions) {
    random_device rd;
    mt19937 mt(rd());

    for (unsigned int n = 2; n < max_n; n++) {
        auto bkpSize = (unsigned long) pow(2,n);
        uniform_real_distribution<double> size(1.0, bkpSize/2);
        uniform_real_distribution<double> value(1.0, 100.0);
        for (int r = 0; r < repetitions; r++) {

            vector<Item> items;
            for (int i = 0; i < n; i++) {
                Item item = Item((unsigned long) value(mt), (unsigned long) size(mt));
                items.push_back(item);
            }

            unsigned long bkp;

            if (n < 28) {
                auto start_bruteforce = chrono::steady_clock::now();
                bkp = bruteforce(bkpSize, items);
                auto end_bruteforce = chrono::steady_clock::now();
                auto diff_bruteforce = end_bruteforce - start_bruteforce;

                cout << "compare_algorithms;bkpSizeExponential;bruteforce;"  << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_bruteforce).count() << "ms" << endl;
            }
            if (n < max_n_exponentials) {

                auto start_meet_in_the_middle = chrono::steady_clock::now();
                bkp = meet_in_the_middle(bkpSize, items);
                auto end_meet_in_the_middle = chrono::steady_clock::now();
                auto diff_meet_in_the_middle = end_meet_in_the_middle - start_meet_in_the_middle;

                cout << "compare_algorithms;bkpSizeExponential;meet_in_the_middle;"  << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_meet_in_the_middle).count() << "ms" << endl;

                auto start_backtracking = chrono::steady_clock::now();
                bkp = backtracking(bkpSize, items);
                auto end_backtracking = chrono::steady_clock::now();
                auto diff_backtracking = end_backtracking - start_backtracking;

                cout << "compare_algorithms;bkpSizeExponential;backtracking;"  << bkpSize << ";" << n << ";"
                     << chrono::duration<double, milli>(diff_backtracking).count() << "ms" << endl;
            }

            auto start_dynamic_programming = chrono::steady_clock::now();
            bkp = dynamicProgramming(bkpSize, items);
            auto end_dynamic_programmic = chrono::steady_clock::now();
            auto diff_dynamic_programming = end_dynamic_programmic - start_dynamic_programming;

            cout << "compare_algorithms;bkpSizeExponential;dynamic_programming;"  << bkpSize << ";" << n << ";"
                 << chrono::duration <double, milli> (diff_dynamic_programming).count() << "ms" << endl;
        }
    }
}