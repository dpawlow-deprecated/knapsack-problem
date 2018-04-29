#include <iostream>
#include <vector>
#include <cmath>
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

unsigned long meet_in_the_middle(unsigned long bkpSize, vector<Item> const &items) {
    auto first = items.begin();
    auto last = items.begin() + items.size()/2;
    vector<Item> firstHalf(first, last);

    first = items.begin() + (items.size()/2);
    last = items.begin() + items.size();
    vector<Item> secondHalf(first, last);

    vector<Backpack> firstHalfBackpacks;
    vector<Backpack> secondHalfBackpacks;
    solvePortion(bkpSize, firstHalf, firstHalfBackpacks);
    solvePortion(bkpSize, secondHalf, secondHalfBackpacks);

    //Busco la combinación de mayor valor
    Backpack maxValueBkp = Backpack(bkpSize);
    for (Backpack &b1 : firstHalfBackpacks) {
        for (Backpack &b2 : secondHalfBackpacks) {
            //if (b1.load + b2.load < bkpSize && b1.value + b2.value > maxValueBkp.value) {
                //maxValueBkp.value = b1.value + b2.value;
                //maxValueBkp.load = b1.load + b2.load;
            //}
        }
    }
    return maxValueBkp.getValue();
}
