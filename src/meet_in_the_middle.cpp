#include <iostream>
#include <vector>
#include <cmath>
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

backpack meet_in_the_middle(int bkpSize, vector<item> const &items) {
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

    //Busco la combinación de mayor valor
    backpack maxValueBkp;
    maxValueBkp.value = 0;
    maxValueBkp.size = bkpSize;
    for (backpack &b1 : firstHalfBackpacks) {
        for (backpack &b2 : secondHalfBackpacks) {
            if (b1.load + b2.load < bkpSize && b1.value + b2.value > maxValueBkp.value) {
                maxValueBkp.value = b1.value + b2.value;
                maxValueBkp.load = b1.load + b2.load;
                if (b1.items.size() > b2.items.size()) {
                    maxValueBkp.items = b1.items;
                    maxValueBkp.items.insert(maxValueBkp.items.end(), b2.items.begin(), b2.items.end());
                } else {
                    maxValueBkp.items = b2.items;
                    maxValueBkp.items.insert(maxValueBkp.items.end(), b1.items.begin(), b1.items.end());
                }
            }
        }
    }

    return maxValueBkp;
}
