#include <iostream>
#include <vector>
#include <cmath>

#include "bruteforce.h"

#include "utilities/types.h"
#include "utilities/utilities.h"
#include "utilities/backpack.h"

using namespace std;

unsigned long bruteforce(unsigned long bkpSize, vector<Item> const &items) {
    Backpack ansBackpack = Backpack(bkpSize);
    auto nOfCombinations = u_int(pow(2, items.size()));

    //El valor en binario de combination equivale al array de bools de items que están en la mochila
    for (int i = 1; i < nOfCombinations; i++) {
        Backpack bkp = Backpack(bkpSize);
    
        int combination = i;
        getCombination(combination, bkp, items);

        if (bkp.getLoad() <= bkpSize && bkp.getValue() > ansBackpack.getValue()) {
            ansBackpack = bkp;
        }
    }

    return ansBackpack.getValue();
}
