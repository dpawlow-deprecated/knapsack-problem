#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "utilities/utilities.h"

using namespace std;

bool isMoreValuableBackpack(const Backpack& a, const Backpack& b) {
    return a.getValue() < b.getValue();
}

void solvePortion(unsigned long bkpSize, vector<Item> const &items, vector<Backpack> &backpacks) {
    auto nOfCombinations = u_int(pow(2, items.size()));

    //El valor en binario de combination equivale al array de bools de items que están en la mochila
    for (int i = 1; i < nOfCombinations; i++) {
        Backpack bkp = Backpack(bkpSize);

        int combination = i;
        getCombination(combination, bkp, items);

        if (bkp.getLoad() <= bkpSize) {
            backpacks.push_back(bkp);
        }
    }
}

vector<Backpack> filterSet(vector<Backpack> &baseSet) {
    vector<Backpack> filteredSet;
    sort(baseSet.begin(), baseSet.end());

    Backpack previousElement = Backpack();

    for (Backpack &b : baseSet) {
        if (previousElement.getLoad() < b.getLoad()) {
            filteredSet.push_back(previousElement);
        }

        previousElement.setLoad(b.getLoad());
        previousElement.setValue(max(previousElement.getValue(), b.getValue()));

    }

    //Para el último elemento
    previousElement.setLoad(baseSet[baseSet.size()].getLoad());
    previousElement.setValue(max(previousElement.getValue(), baseSet[baseSet.size()].getValue()));
    filteredSet.push_back(previousElement);
    return filteredSet;
}

unsigned long getMax(unsigned long bkpSize, vector<Backpack> &firstSet, vector<Backpack> &secondSet) {
    unsigned long maxValue = 0;
    for (Backpack &b : firstSet) {
        Backpack bla = Backpack(bkpSize);
        bla.setLoad(bkpSize - b.getLoad());
        auto bkp = std::lower_bound(secondSet.begin(), secondSet.end(), bla);
        if (bkp->getValue() > maxValue) {
            maxValue = bkp->getValue();
        }
    }
    return maxValue;
}


unsigned long meet_in_the_middle(unsigned long bkpSize, vector<Item> const &items) {
    vector<Item>::const_iterator first = items.begin();
    vector<Item>::const_iterator last = items.begin() + items.size()/2;
    vector<Item> firstHalf(first, last);

    first = items.begin() + (items.size()/2);
    last = items.begin() + items.size();
    vector<Item> secondHalf(first, last);

    vector<Backpack> firstHalfBackpacks;
    vector<Backpack> secondHalfBackpacks;

    solvePortion(bkpSize, firstHalf, firstHalfBackpacks);
    solvePortion(bkpSize, secondHalf, secondHalfBackpacks);

    vector<Backpack> filteredSecondHalfBackpacks = filterSet(secondHalfBackpacks);

    //Busco la combinación de mayor valor
    return getMax(bkpSize, firstHalfBackpacks, filteredSecondHalfBackpacks);
}
