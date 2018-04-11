#include <iostream>
#include <vector>
#include <cmath>
#include "types.h"

using namespace std;

int isOdd(int x) {
    return x % 2 == 1;
}

void getCombination(int combination, backpack &bkp, vector<item> const &items) {
    //BitPosition para determinar en qué dígito del bit me estoy fijando
    int bitPosition = 0;
    vector<char> prueba;
    while (combination > 0) {
        if (isOdd(combination)) {
            bkp.value += items[bitPosition].value;
            bkp.load += items[bitPosition].size;
            bkp.items.push_back(items[bitPosition]);

        }
        bitPosition++;
        combination /= 2;
    }
}

