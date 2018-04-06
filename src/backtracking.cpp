#include <iostream>
#include <vector>
#include <algorithm>
#include "types.h"
#include "backtracking.h"

using namespace std;

bool isLighter(const item& a, const item& b) {
    return a.size < b.size;
}

//Poda de factibilidad: si ninguno de los items restantes entra en la mochila, corta la rama
bool hasRoomForMore(int i, backpack const &bkp, vector<item> const &items) {
    //Precondición: el vector items debe estar ordenado crecientemente por peso
    return items[i].size <= bkp.size - bkp.load;
}

//Poda de optimalidad: si la suma del valor actual y de la suma del valor de los items que entran en la mochila
//no superan al máximo valor alcanzado hasta el momento, corta la rama
bool maxValueIsReachable(int i, backpack const &bkp, vector<item> const &items, int &maxValue) {
    //Precondición: el vector items debe estar ordenado crecientemente por peso
    int sum = 0;
    for (int j = i; j < items.size(); j++) {
        if (items[j].size < bkp.size - bkp.load) {
            sum += items[j].value;
        }
    }
    return bkp.value + sum > maxValue;
}

backpack backtracking(int i, backpack bkp, vector<item> const &items, int maxValue) {
    if (i >= items.size() || !hasRoomForMore(i, bkp, items) || !maxValueIsReachable(i, bkp, items, maxValue)) {
        if (bkp.value > maxValue) {
            maxValue = bkp.value;
        }
        return bkp;
    }
    backpack backpackWithoutItem = backtracking(i + 1, bkp, items, maxValue);

    if (bkp.load + items[i].size > bkp.size) {
        return backpackWithoutItem;
    }

    bkp.load += items[i].size;
    bkp.value += items[i].value;
    bkp.items.push_back(items[i]);
    backpack backpackWithItem = backtracking(i + 1, bkp, items, maxValue);

    if (backpackWithItem.value > backpackWithoutItem.value) {
        return backpackWithItem;
    } else {
        return backpackWithoutItem;
    }
}

backpack solveC(int bkpSize, vector<item> &items) {
    backpack bkp;
    bkp.value = 0;
    bkp.load = 0;
    bkp.size = bkpSize;

    //Se ordena para la poda
    sort(items.begin(), items.end(), isLighter);

    return backtracking(0, bkp, items, 0);
};


void test() {
    item item1; item item2; item item3; item item4; item item5; item itemA; item itemB;
    itemA.size = 15; itemA.value = 2;
    itemB.size = 15; itemB.value = 3;
    item1.size = 3; item1.value = 10;
    item2.size = 4; item2.value = 10;
    item3.size = 1; item3.value = 100;
    item4.size = 10; item4.value = 20;
    item5.size = 5; item5.value = 15;

    vector<item> items = {itemA, item1, item2, item3, item4, item5, itemB};

    backpack bkp = solveC(15, items);

    cout<<bkp.value<<endl;
    cout<<bkp.load;
}