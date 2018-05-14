#include <iostream>
#include <vector>
#include "backpack.h"
#include <cmath>

using namespace std;

int isOdd(int x) {
    return x & 0x1;
}

void getCombination(int combination, Backpack &bkp, vector<Item> const &items) {
    //BitPosition para determinar en qué dígito del bit me estoy fijando
    int bitPosition = 0;
    while (combination > 0) {
        if (isOdd(combination)) {
            bkp.addItem(items[bitPosition]);
        }
        bitPosition++;
        combination = combination >> 1;
    }
}

