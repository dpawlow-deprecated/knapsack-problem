#include <iostream>
#include <vector>
#include <cmath>
#include "types.h"
#include "Bruteforce.h"

using namespace std;


int isOdd(int x) {
    return x & 1;
}

backpack solveB(int bkpSize, vector<item> const &items) {
    backpack ansBackpack;
    ansBackpack.value = 0;
    ansBackpack.load = 0;
    auto nOfCombinations = u_int(pow(2, items.size()));

    //El valor en binario de combination equivale al array de bools de items que están en la mochila
    for (int combination = 1; combination < nOfCombinations; combination++) {
        backpack bkp;
        bkp.value = 0;
        bkp.load = 0;

        //Paso el número a binario, un 1 significa que el item está
        while (combination > 1) {
            if (isOdd(combination)) {
                bkp.value += items[combination].value;
                bkp.load += items[combination].size;
                bkp.items.push_back(items[combination]);
            }
            combination /= 2;
        }
        if (bkp.load <= bkpSize && bkp.value > ansBackpack.value) {
            ansBackpack = bkp;
        }
    }

    return ansBackpack;
}
