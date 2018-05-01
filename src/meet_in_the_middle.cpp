#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "utilities/utilities.h"

using namespace std;

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

    //Se agrega la mochila vacía para los casos en el que la mejor solución no es una combinación.
    filteredSet.emplace_back(Backpack(0, 0, 0));
    Backpack previousElement = Backpack(baseSet[0]);

    for (Backpack &b : baseSet) {
        if (previousElement.getLoad() < b.getLoad()) {
            filteredSet.push_back(previousElement);
        }
        previousElement.setLoad(b.getLoad());
        previousElement.setValue(max(previousElement.getValue(), b.getValue()));
    }

    //Para el último elemento
    if (filteredSet.empty() || filteredSet[filteredSet.size()-1].getLoad() < previousElement.getLoad()) {
        filteredSet.push_back(previousElement);
    } else if (filteredSet[filteredSet.size()-1].getValue() < previousElement.getValue()) {
        filteredSet[filteredSet.size()-1].setValue(previousElement.getValue());
    }
    return filteredSet;
}

unsigned long getMax(unsigned long bkpSize, vector<Backpack> &firstSet, vector<Backpack> &secondSet) {
    unsigned long maxValue = 0;

    for (Backpack &b : firstSet) {
        auto iterator = upper_bound(secondSet.begin(), secondSet.end(), Backpack(bkpSize, b.getFreeSpace(), 0));
        if (iterator != secondSet.begin()) {
            iterator--;
            if (b.getLoad() + iterator->getLoad() <= bkpSize) {
                maxValue = max(maxValue, b.getValue() + iterator->getValue());
            }
        }
    }
    return maxValue;
}


unsigned long meet_in_the_middle(unsigned long bkpSize, vector<Item> const &items) {
    /*
     * Meet in the middle divide el dominio del problema (el vector items) en dos, combinando más tarde las
     * subsoluciones para encontrar la solución global.
     * Primero usa una fuerza bruta modificada para cada mitad del vector items.
     * Luego evalúa los vectores resultantes para encontrar la mejor combinación de subsoluciones.
     */

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

    vector<Backpack> filteredFirstHalfBackpacks = filterSet(firstHalfBackpacks);
    vector<Backpack> filteredSecondHalfBackpacks = filterSet(secondHalfBackpacks);

    //Busco la combinación de mayor valor
    return getMax(bkpSize, filteredFirstHalfBackpacks, filteredSecondHalfBackpacks);
}
