#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "utilities/types.h"
#include "utilities/utilities.h"

using namespace std;

void solvePortion(int bkpSize, vector<item> const &items, vector<backpack> &backpacks) {
    auto nOfCombinations = u_int(pow(2, items.size()));

    //El valor en binario de combination equivale al array de bools de items que están en la mochila
    for (int i = 1; i < nOfCombinations; i++) {
        backpack bkp;
        bkp.value = 0;
        bkp.load = 0;

        int combination = i;
        getCombination(combination, bkp, items);

        if (bkp.load <= bkpSize) {
            backpacks.push_back(bkp);
        }
    }
}

void filterSecondSet(vector<backpack> &baseSet, vector<backpack> &filteredSet) {
    sort(baseSet.begin(), baseSet.end(), isMoreValuableBackpack);
    stable_sort(baseSet.begin(), baseSet.end());

    backpack previousElement;
    previousElement.load = 0;
    previousElement.value = 0;

    for (backpack &b : baseSet) {
        if (previousElement.load < b.load) {
            filteredSet.push_back(previousElement);
        } else {
            previousElement.load = b.load;
            previousElement.value = max(previousElement.value, b.value);
        }
    }

    //Para el último elemento
    previousElement.load = baseSet[baseSet.size()].load;
    previousElement.value = max(previousElement.value, baseSet[baseSet.size()].value);
    filteredSet.push_back(previousElement);
}

int getMax(int bkpSize, vector<backpack> &firstSet, vector<backpack> &secondSet) {
    int maxValue = 0;
    for (backpack &b : firstSet) {
        auto bkp = std::lower_bound(secondSet.begin(), secondSet.end(), bkpSize - b.load);
        if (bkp->value > maxValue) {
            maxValue = bkp->value;
        }
    }
    return maxValue;
}

int meet_in_the_middle(int bkpSize, vector<item> const &items) {
    vector<item>::const_iterator first = items.begin();
    vector<item>::const_iterator last = items.begin() + items.size()/2;
    vector<item> firstHalf(first, last);

    first = items.begin() + (items.size()/2);
    last = items.begin() + items.size();
    vector<item> secondHalf(first, last);

    vector<backpack> firstHalfBackpacks;
    vector<backpack> secondHalfBackpacks;

    solvePortion(bkpSize, firstHalf, firstHalfBackpacks);
    solvePortion(bkpSize, secondHalf, secondHalfBackpacks);

    vector<backpack> filteredSecondHalfBackpacks;
    filterSecondSet(secondHalfBackpacks, filteredSecondHalfBackpacks);

    //Busco la combinación de mayor valor
    return getMax(bkpSize, firstHalfBackpacks, filteredSecondHalfBackpacks);
}
