#include <iostream>
#include <vector>
#include <algorithm>
#include "utilities/types.h"
#include "backtracking.h"

using namespace std;

bool isLighter(const item& a, const item& b) {
    return a.size < b.size;
}

bool isMoreValuable(const item& a, const item& b){
    return a.value > b.value;
}

//Poda de factibilidad: si ninguno de los items restantes entra en la mochila, corta la rama
bool hasRoomForMore(int i, backpack const &bkp, vector<item> const &items) {
    //Precondición: el vector items debe estar ordenado crecientemente por peso
    return items[i].size <= bkp.size - bkp.load;
}

int solveFractionalKnapsackProblem(int i, backpack const &bkp, vector<item> const &items) {
    int extraLoad = 0;
    int extraValue = 0;
    int j = i;
    while (bkp.load + extraLoad <= bkp.size && j < items.size()) {
        extraLoad += items[j].size;
        extraValue += items[j].value;
        j++;
    }
    return extraValue;
}

//Poda de optimalidad: si la suma del valor actual y de la suma del valor de los items que entran en la mochila
//no superan al máximo valor alcanzado hasta el momento, corta la rama
bool maxValueIsReachable(int i, backpack const &bkp, vector<item> const &items, int &maxValue) {
    //Precondición: el vector items debe estar ordenado crecientemente por peso
    int maxPossibleRemainingValue = solveFractionalKnapsackProblem(i, bkp, items);
    return bkp.value + maxPossibleRemainingValue > maxValue;
}

backpack backtrackingRecursion(int i, backpack bkp, vector<item> const &items, int maxValue) {
    if (i >= items.size() || !hasRoomForMore(i, bkp, items) || !maxValueIsReachable(i, bkp, items, maxValue)) {
        if (bkp.value > maxValue) {
            maxValue = bkp.value;
        }
        return bkp;
    }
    backpack backpackWithoutItem = backtrackingRecursion(i + 1, bkp, items, maxValue);

    if (bkp.load + items[i].size > bkp.size) {
        return backpackWithoutItem;
    }

    bkp.load += items[i].size;
    bkp.value += items[i].value;
    bkp.items.push_back(items[i]);
    backpack backpackWithItem = backtrackingRecursion(i + 1, bkp, items, maxValue);

    if (backpackWithItem.value > backpackWithoutItem.value) {
        return backpackWithItem;
    } else {
        return backpackWithoutItem;
    }
}

int backtracking(int bkpSize, vector<item> &items) {
    backpack bkp;
    bkp.value = 0;
    bkp.load = 0;
    bkp.size = bkpSize;

    //Se ordena primero por valor decreciente y luego con un algoritmo estable por tamaño creciente
    //El ordenamiento se usa en las podas
    sort(items.begin(), items.end(), isMoreValuable);
    stable_sort(items.begin(), items.end(), isLighter);

    return backtrackingRecursion(0, bkp, items, 0).value;
};