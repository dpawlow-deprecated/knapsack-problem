#include <iostream>
#include <vector>
#include <cmath>
#include "types.h"
#include "utilities.h"

using namespace std;

void solvePortion(int bkpSize, vector<item> const &items, struct backpack *backpacks) {
    auto nOfCombinations = u_int(pow(2, items.size()));

    //El valor en binario de combination equivale al array de bools de items que están en la mochila
    for (int i = 1; i < nOfCombinations; i++) {
        backpack bkp;
        bkp.value = 0;
        bkp.load = 0;

        int combination = i;
        getCombination(combination, bkp, items);

        //Bucketsort de mochilas por peso, considerando sólo la de mayor valor para cada peso
        if (bkp.load <= bkpSize && backpacks[bkp.load].value < bkp.value) {
            backpacks[bkp.load] = bkp;
        }
    }
}

backpack solveB(int bkpSize, vector<item> const &items) {
    vector<item>::const_iterator first = items.begin();
    vector<item>::const_iterator last = items.begin() + items.size()/2;
    vector<item> firstHalf(first, last);

    first = items.begin() + (items.size()/2);
    last = items.begin() + items.size();
    vector<item> secondHalf(first, last);

    int firstHalfSize = 0;
    for (item &e : firstHalf) {
        firstHalfSize += e.size;
    }

    int secondHalfSize = 0;
    for (item &e : secondHalf) {
        secondHalfSize += e.size;
    }

    struct backpack bkpFirstItems[firstHalfSize + 1];
    struct backpack bkpSecondItems[secondHalfSize + 1];

    backpack bkpVacio;
    bkpVacio.size = bkpSize;
    bkpVacio.load = 0;
    bkpVacio.value = 0;

    for (int i = 0; i < firstHalfSize + 1; i++) {
        bkpFirstItems[i] = bkpVacio;
    }
    for (int i = 0; i < secondHalfSize + 1; i++) {
        bkpSecondItems[i] = bkpVacio;
    }

    solvePortion(bkpSize, firstHalf, bkpFirstItems);
    solvePortion(bkpSize, secondHalf, bkpSecondItems);

    //Busco la combinación de mayor valor
    backpack maxValueBkp;
    maxValueBkp.value = 0;
    maxValueBkp.size = bkpSize;
    for (backpack &b1 : bkpFirstItems) {
        for (int j = 0; j < bkpSize - b1.load; j++) {
            if (b1.value + bkpSecondItems[j].value > maxValueBkp.value) {
                maxValueBkp.value = b1.value + bkpSecondItems[j].value;
                maxValueBkp.load = b1.load + bkpSecondItems[j].load;
                maxValueBkp.items.reserve(b1.items.size() + bkpSecondItems[j].items.size());
                maxValueBkp.items.insert(maxValueBkp.items.end(), b1.items.begin(), b1.items.end());
                maxValueBkp.items.insert(maxValueBkp.items.end(), bkpSecondItems[j].items.begin(), bkpSecondItems[j].items.end());
            }
        }
    }

    return maxValueBkp;
}
