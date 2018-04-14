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
    while (combination > 0) {
        if (combination & 0x1) {
            bkp.value += items[bitPosition].value;
            bkp.load += items[bitPosition].size;
        }
        bitPosition++;
        combination = combination >> 1;
    }
}

bool isLighter(const item& a, const item& b) {
    return a.size < b.size;
}

bool isMoreValuable(const item& a, const item& b){
    return a.value > b.value;
}

bool isMoreValuableBackpack(const backpack& a, const backpack& b) {
    return a.value > b.value;
}

