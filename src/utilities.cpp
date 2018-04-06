#include <iostream>
#include <vector>
#include <cmath>
#include "types.h"

using namespace std;

int isOdd(int x) {
    return x % 2 == 1;
}

void getCombination(int combination, backpack &bkp, vector<item> const &items) {
    while (combination > 0) {
        if (isOdd(combination)) {
            //log2 para obtener la posición del bit en el número
            double position = log2(combination);
            bkp.value += items[position].value;
            bkp.load += items[position].size;
            bkp.items.push_back(items[position]);
        }
        combination /= 2;
    }
}

