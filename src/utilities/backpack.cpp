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

void Backpack::setSize(unsigned long size) {
    Backpack::size = size;
}

void Backpack::setValue(unsigned long value) {
    Backpack::value = value;
}

void Backpack::setLoad(unsigned long load) {
    Backpack::load = load;
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

unsigned long Backpack::getFreeSpace() const {
    return size - load;
}

bool Backpack::operator<(const Backpack& bkp) const {
    return load < bkp.getLoad();
}

bool Backpack::operator>(const Backpack& bkp) const {
    return load > bkp.getLoad();
}