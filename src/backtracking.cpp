#include <iostream>
#include <vector>
#include <algorithm>
#include "backtracking.h"
#include "utilities/item.h"
#include "utilities/backpack.h"

using namespace std;

bool isMoreEfficient(const Item& a, const Item& b) {
    return a.getValue() / a.getSize() > b.getValue() / b.getSize();
}

//Poda de factibilidad: si ninguno de los items restantes entra en la mochila, corta la rama
bool hasRoomForMore(int i, const Backpack &bkp, vector<Item> const &items) {
    Item smallestItem = items[i];
    for (int j = i; j < items.size(); j++) {
        if (items[j].isLighter(smallestItem)) {
            smallestItem = items[j];
        }
    }
    return smallestItem.getSize() <= bkp.getSize() - bkp.getLoad();
}

void solveFractionalKnapsackProblem(int i, Backpack &bkp, vector<Item> const &items) {
    //Precondición: el vector  debe estar ordenado decrecientemente por valor/peso
    for (int j = i; j < items.size(); j++) {
        if (items[j].getSize() <= bkp.getFreeSpace()) {
            bkp.addItem(items[j]);
        } else {
            unsigned long fitableValue = ((items[j].getValue() / items[j].getSize()) * bkp.getFreeSpace());
            bkp.setValue(bkp.getValue() + fitableValue);
            bkp.setLoad(bkp.getSize());
            return;
        }
    }
}

//Poda de optimalidad: si la suma del valor actual y de la suma del valor de los items que entran en la mochila
//no superan al máximo valor alcanzado hasta el momento, corta la rama
bool maxValueIsReachable(int i, const Backpack &bkp, vector<Item> const &items, unsigned long &maxValue) {
    //Precondición: el vector debe estar ordenado decrecientemente por valor/peso
    Backpack subBackpack = Backpack(bkp.getSize() - bkp.getLoad());

    solveFractionalKnapsackProblem(i, subBackpack, items);
    return bkp.getValue() + subBackpack.getValue() > maxValue;
}

Backpack backtrackingRecursion(int i, Backpack bkp, vector<Item> const &items, unsigned long &maxValue) {
    if (i >= items.size() || !hasRoomForMore(i, bkp, items) || !maxValueIsReachable(i, bkp, items, maxValue)) {
        if (bkp.getValue() > maxValue) {
            maxValue = bkp.getValue();
        }
        return bkp;
    }
    Backpack backpackWithoutItem = backtrackingRecursion(i + 1, bkp, items, maxValue);

    if (bkp.getLoad() + items[i].getSize() > bkp.getSize()) {
        return backpackWithoutItem;
    }

    bkp.addItem(items[i]);

    Backpack backpackWithItem = backtrackingRecursion(i + 1, bkp, items, maxValue);

    if (backpackWithItem.getValue() > backpackWithoutItem.getValue()) {
        return backpackWithItem;
    } else {
        return backpackWithoutItem;
    }
}

unsigned long backtracking(unsigned long bkpSize, vector<Item> &items) {
    Backpack bkp = Backpack(bkpSize);

    //Se ordena decrecientemente por coeficiente valor/peso
    sort(items.begin(), items.end(), isMoreEfficient);

    unsigned long maxValue = 0;

    return backtrackingRecursion(0, bkp, items, maxValue).getValue();
};