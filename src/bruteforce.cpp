#include <iostream>
#include <vector>
#include <cmath>
#include "types.h"
#include "Bruteforce.h"

using namespace std;


int isOdd(int x) {
    return x % 2 == 1;
}

backpack solveB(int bkpSize, vector<item> const &items) {
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

        if (bkp.load <= bkpSize && bkp.value >= ansBackpack.value) {
            ansBackpack = bkp;
        }
    }

    return ansBackpack;
}
