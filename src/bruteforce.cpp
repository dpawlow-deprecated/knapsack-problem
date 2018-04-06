#include <iostream>
#include <vector>
#include <cmath>
#include "types.h"
#include "bruteforce.h"
#include "utilities.h"

using namespace std;

backpack solveA(int bkpSize, vector<item> const &items) {
    backpack ansBackpack;
    ansBackpack.value = 0;
    ansBackpack.load = 0;
    auto nOfCombinations = u_int(pow(2, items.size()));

    //El valor en binario de combination equivale al array de bools de items que están en la mochila
    for (int i = 1; i < nOfCombinations; i++) {
        backpack bkp;
        bkp.value = 0;
        bkp.load = 0;
    
        int combination = i;
        getCombination(combination, bkp, items);

        if (bkp.load <= bkpSize && bkp.value >= ansBackpack.value) {
            ansBackpack = bkp;
        }
    }

    return ansBackpack;
}
