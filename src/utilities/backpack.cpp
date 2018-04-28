#include "backpack.h"

using namespace std;

Backpack::Backpack() {
    size = 0;
    value = 0;
    load = 0;
}

Backpack::Backpack(unsigned long size) {
    Backpack::size = size;
    value = 0;
    load = 0;
}

void Backpack::addItem(Item const &item) {
    Backpack::items.push_back(item);
    load += item.getSize();
    value += item.getValue();
}

unsigned long Backpack::getSize() const {
    return size;
}

unsigned long Backpack::getValue() const {
    return value;
}

unsigned long Backpack::getLoad() const {
    return load;
}